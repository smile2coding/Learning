---

---

# Docker
## 1. Docker概述
Docker是**go语言**开发的项目！

### 1.1 Docker为什么出现？
版本不同，导致服务不可用！开发、打包、部署一条龙！  
Docker的思想来源于集装箱。  
JRE--多个应用（端口冲突）--原来都是交叉的！  
隔离--Docker核心思想！打包装箱！每个箱子都是相互隔离的！

### 1.2 Docker的历史
2010年，几个IT年轻人，美国创建了dotCloud，做云计算服务！LXC有关的容器技术！Docker和虚拟机都是一种**虚拟化技术**！  
```c
VM：一个完整的原生镜像

Docker：隔离，镜像（最核心的环境 4MB jdk+mysql）
```
### 1.3 虚拟机技术or容器化技术
**虚拟机技术：** 

**容器化技术：** 容器化技术不是模拟一个完整的系统。容器的应用是直接运行在宿主机的内核，容器是没有自己的内核的。

## 2. Docker安装
## 3. Docker命令
|Command|Description|Example|
|-----|------|---|
|docker version|docker 版本||
|docker info|显示docker的系统信息||
|docker 命令 --help|帮助命令||
|docker images|显示本地主机的镜像||
|docker search 镜像|搜索镜像||
|docker pull 镜像名[:xx.xx]|下载镜像|docker pull mysql:5.7|
|docker rmi 镜像id [容器id] [容器id]|删除镜像||
|## 4. Docker镜像|||
|## 5. 容器数据卷|||
|## 6. DockerFile|||
|## 7. Docker网络原理|||
|## 8. IDEA 整合Docker|||
|## 9. Docker Compose|||
|## 10. Docker Swarm|||
|## 11. CI/CD jenkins ||
