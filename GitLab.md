# GitLab
> 一个基于Git的在线代码仓库托管软件。

## 1.YAML
[YAML](https://yaml.org/)（"YAML Ain`t a Markup Language"），YAML不是一种标记语言。在开发的这种语言时，YAML 的意思其实是："Yet Another Markup Language"（仍是一种标记语言）。这种语言**以数据做为中心**.

### 1.1 基本语法
* <font color=red>大小写敏感</font>
* 使用缩进表示层级关系（类似python）
* <font color=red>缩进不允许使用tab，只允许空格</font>
* 缩进的空格数不重要，只要相同的层级元素左对齐即可
* '#'表示注释
  
### 1.2 数据类型
* 对象：键值对（类比JSON）  
  * 简单对象 
  ``` 
    key: 
      child-key: value
      child-key2: value2
  ```
  * 复杂对象：使用问号加一个空格代表一个复杂的 key，配合一个冒号加一个空格代表一个 value    
  ``` 
    ?  
      - complexkey1
      - complexkey2
    :
      - complexvalue1
      - complexvalue2
  ```

<font color=red>注：</font>上述复杂对象的定义说明，对象是一个数组，value也是一个数组。
* 数组  
  * YAML数组：以 - 开头的行表示构成一个数组。
* **纯量**(scalar)
  * 纯量是最基本的，不可再分的值，包括：字符串、布尔值、整数、浮点数、NULL、时间、日期。  
  
### 1.3 引用（Anchor）
 & 锚点和 * 别名，可以用来引用。
   ``` 
    defaults: &defaults
    adapter:  postgres
    host:     localhost

    development:
    database: myapp_development
    <<: *defaults

    test:
    database: myapp_test
    <<: *defaults
   ```


相当于：

```   
 defaults:
    adapter:  postgres
    host:     localhost

    development:
    database: myapp_development
    adapter:  postgres
    host:     localhost

    test:
    database: myapp_test
    adapter:  postgres
    host:     localhost  

```

<font color=red>& 用来建立锚点（defaults），<< 表示合并到当前数据，* 用来引用锚点。</font>
## 2.GitLab CI/CD
[GitLab CI/CD](https://docs.gitlab.com/ee/ci/) is a tool built into GitLab for software development through the continuous methodologies(持续的方法):

* Continuous Integration (CI，持续集成)
* Continuous Delivery (CD，持续交付)
* Continuous Deployment (CD，持续部署)  
  

这些方法可以帮助在早期开发发现bugs和errors。GitLab CI/CD 由一个名为 .gitlab-ci.yml 的文件进行配置，该文件位于仓库的根目录下。文件中指定的脚本由GitLab Runner执行。
> GitLab CI/CD 工作流  



![](img/gitlab_workflow_example.png)

> GitLab中的[预定义变量](https://docs.gitlab.com/ee/ci/variables/predefined_variables.html)

| Variable          | GitLab | Runner | Description                                                                                    |
| ----------------- | ------ | ------ | ---------------------------------------------------------------------------------------------- |
| GITLAB_USER_LOGIN | 10.0   | all    | The username of the user who started the job.                                                  |
| CI_SERVER_HOST    | 12.1   | all    | The host of the GitLab instance URL, without protocol or port. For example gitlab.example.com. |
| ...               | ...    | ...    | ...                                                                                            |

> GitLab中的一些 [Concepts](https://docs.gitlab.com/ee/ci/#concepts)

| Concept             | Description                                                                    |
| ------------------- | ------------------------------------------------------------------------------ |
| Pipelines           | Structure your CI/CD process through pipelines.                                |
| CI/CD variables     | Reuse values based on a variable/value key pair.                               |
| Job artifacts       | Output, use, and reuse job artifacts.                                          |
| Environments        | Deploy your application to different environments (e.g., staging, production). |
| Cache dependencies  | Cache your dependencies for a faster execution.                                |
| GitLab Runner       | Configure your own runners to execute your scripts.                            |
| Pipeline efficiency | Configure your pipelines to run quickly and efficiently.                       |
| Test cases          | Configure your pipelines to run quickly and efficiently.                       |

### 2.1 CI/CD pipelines
Piplines由两部分组成：
* Jobs 定义做什么，由runners执行。
* Stages 什么时候跑jobs   
  

注：**在同一Stages中的多个Jobs之间并行执行。** jobs在执行成功之后进入下一阶段，若失败则pipeline停止在当前阶段。
### 2.2 jobs 执行条件
通过设置限制条件限定jobs执行：
* rules  
  **rules定义的规则：**
  * if
  * changes
  * exists
  * allow_failure
  * variables
  * when  
    合法的value见下
    * on_success
    * on_failure
    * always
    * manual
    * delayed
    * never
``` 
job:
script: echo "Hello, Rules!"
rules:
- if: '$CI_PIPELINE_SOURCE == "merge_request_event"'
    when: manual
    allow_failure: true
- if: '$CI_PIPELINE_SOURCE == "schedule"'
```

* only
* except  
```
job:
only:
    - branches@gitlab-org/gitlab
except:
    - main@gitlab-org/gitlab
    - /^release/.*$/@gitlab-org/gitlab
```
**有时不想执行job，既可以注释掉同时也可以在job名前加'.'**，见下。
1. 注释  
```
# hidden_job:
#   script:
#     - run test
```
2. 添加'.'
```
.hidden_job:
  script:
    - run test
```
<font color=red>注：**job不被添加到pipeline的情况见下**</font>  
* rules不匹配
* rules匹配但是有"when never"条件
### 2.3 [job常用的关键字](https://docs.gitlab.com/ee/ci/yaml/)

<font color = red>Note</font> (important):

| Keyword       | Description                                                  |
| :------------ | :----------------------------------------------------------- |
| script        | 被runner执行的shell脚本                                      |
| image         | Use Docker images.                                           |
| after_script  | Override a set of commands that are executed after job.      |
| before_script | Override a set of commands that are executed before job.     |
| include       | 包含一个外部YAML文件                                         |
| only          | Control when jobs are created.                               |
| rules         | List of conditions to evaluate and determine selected attributes of a job, and whether or not it’s created. |
| ...           | ...                                                          |

<img src="img/job_structure.png" style="zoom:200%;" />

#### 2.3.1 [stages](https://docs.gitlab.com/ee/ci/yaml/#stages)

* 如果job没有被声明在某一个stage，则job默认在test阶段
* 如果stage被声明但是并没有job，则该stage则不会出现在pipeline中
* 在pipeline中有5个默认stage  
  * .pre
  * build
  * test
  * deploy
  * .post

#### 2.3.2 extends

extends可以用来复用配置，相当于YAML语法中的引用，该关键字也可以复用include的配置文件。
#### 2.3.3 tags
可以使用tags来选择特定的runner来执行。例如，
```
job:
  tags:
    - ruby
    - postgres
```
#### 2.3.4 [environment](https://docs.gitlab.com/ee/ci/yaml/#environment)
使用environment关键字定义一个job部署需要的环境。例如，
```
deploy to production:
  stage: deploy
  script: git push production HEAD:main
  environment: production
```

#### 2.3.5 [after_script](https://docs.gitlab.com/ee/ci/yaml/#after_script)

Job执行完成后，执行对应的脚本指令。

#### 2.3.6 allow_failure



