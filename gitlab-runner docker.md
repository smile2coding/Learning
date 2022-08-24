## 在 Docker 容器里面使用 `docker run`/`docker build`？

Docker 容器技术目前是微服务/持续集成/持续交付领域的第一选择。而在 DevOps 中，我们需要将各种后端/前端的测试/构建环境打包成 Docker 镜像，然后在需要的时候，Jenkins 会使用这些镜像启动容器以执行 Jenkins 任务。

为了方便维护，我们的 CI 系统如 Jenkins，也会使用 Docker 方式部署。
Jenkins 任务中有些任务需要将微服务构建成 Docker 镜像，然后推送到 Harbor 私有仓库中。
或者我们所有的 Jenkins Master 镜像和 Jenkins Slave 镜像本身都不包含任何额外的构建环境，执行任务时都需要启动包含对应环境的镜像来执行任务。

我们的 Jenkins Master、Jenkins Slaves 都是跑在容器里面的，**该如何在这些容器里面调用 `docker run` 命令启动包含 CI 环境的镜像呢？
在这些 CI 镜像里面，我们从源码编译完成后，又如何通过 `docker build` 将编译结果打包成 Docker 镜像，然后推送到内网仓库呢？**

答案下面揭晓。

## 一、原理说明：`/var/run/docker.sock`

Docker 采取的是 Client/Server 架构，我们常用的 `docker xxx` 命令工具，只是 docker 的 client，我们通过该命令行执行命令时，实际上是在通过 client 与 docker engine 通信。

我们通过 apt/yum 安装 docker-ce 时，会自动生成一个 systemd 的 service，所以安装完成后，需要通过 `sudo systemctl enable docker.service` 来启用该服务。
这个 Docker 服务启动的，就是 docker engine，查看 `/usr/lib/systemd/system/docker.service`，能看到有这样一条语句：

```
ExecStart=/usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
```

默认情况下，Docker守护进程会生成一个 socket（`/var/run/docker.sock`）文件来进行本地进程通信，因此只能在本地使用 docker 客户端或者使用 Docker API 进行操作。
sock 文件是 UNIX 域套接字，它可以通过文件系统（而非网络地址）进行寻址和访问。

因此只要以数据卷的形式将 docker 客户端和上述 socket 套接字挂载到容器内部，就能实现 "Docker in Docker"，在容器内使用 docker 命令了。具体的命令见后面的「示例」部分。

要记住的是，真正执行我们的 docker 命令的是 docker engine，而这个 engine 跑在宿主机上。所以这并不是真正的 "Docker in Docker".

## 二、示例

在容器内部使用宿主机的 docker，方法有二：

1. 命令行方式：将

    

   ```
   /usr/bin/docker
   ```

    

   映射进容器内部，然后直接在容器内部使用这个命令行工具

    

   ```
   docker
   ```

   - 需要的时候，也可以将 `/etc/docker` 文件夹映射到容器内，这样容器内的 `docker` 命令行工具也会使用与宿主机同样的配置。

2. 编程方式：在容器内部以编程的方式使用 docker

   - 通过 python 使用 docker: 在 Dockerfile 中通过 `pip install docker` 将 docker client 安装到镜像中来使用

容器的启动方式也有两种，如下：

### 1. 直接通过 docker 命令启动

示例命令如下：

```shell
docker run --name <name> \
    -v /var/run/docker.sock:/var/run/docker.sock \
    -v /usr/bin/docker:/usr/bin/docker \
    --user root \
    <image-name>:<tag>
```

**必须以 root 用户启动！（或者其他有权限读写 `/var/run/docker.sock` 的用户）**然后，在容器内就能正常使用 docker 命令，或者访问宿主机的 docker api 了。

### 2. 使用 docker-compose 启动

docker-compose.yml 文件内容如下：

```yaml
version: '3.3'
services:
  jenkins-master:
    image: jenkinsci/blueocean:latest
    container_name: jenkins-master
    environment:
      - TZ=Asia/Shanghai  # 时区
    ports:
      - "8080:8080"
      - "50000:50000"
    volumes:
      - ./jenkins_home:/var/jenkins_home  # 将容器中的数据映射到宿主机
      - /usr/bin/docker:/usr/bin/docker  # 为容器内部提供 docker 命令行工具（这个随意）
      - /var/run/docker.sock:/var/run/docker.sock  # 容器内部通过 unix socket 使用宿主机 docker engine
    user: root  # 必须确保容器以 root 用户启动！（这样它才有权限读写 docker.socket）
    restart: always
```

然后通过 `docker-compose up -d` 即可后台启动容器。

## Docker 中的 uid 与 gid

通过上面的操作，我们在容器内执行 `docker ps` 时，还是很可能会遇到一个问题：**权限问题**。

如果你容器的默认用户是 root，那么你不会遇到这个问题，因为 `/var/run/docker.sock` 的 owner 就是 root.

但是一般来说，为了限制用户的权限，容器的默认用户一般都是 uid 和 gid 都是 1000 的普通用户。这样我们就没有权限访问 `/var/run/docker.sock` 了。

解决办法：

方法一（不一定有效）：在构建镜像时，最后一层添加如下内容：

```
# docker 用户组的 id，通常都是 999
RUN groupadd -g 999 docker \
    && usermod -aG docker <your_user_name>
```

这样我们的默认用户，就能使用 docker 命令了。

> P.S. `999` 不一定是 docker 用户组，所以上述方法某些情况下可能失效。这时还是老老实实通过 `docker run -u root` 启动容器吧。（或者在 `docker-compose.yml` 中添加 `user: root` 属性）

## 参考

- [Docker in Docker - 王柏元](https://wangbaiyuan.cn/docker-in-docker.html)