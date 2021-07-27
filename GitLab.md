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
  
### 1.3 引用
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
> 
![](img/gitlab_workflow_example.png)

> GitLab中的[预定义变量](https://docs.gitlab.com/ee/ci/variables/predefined_variables.html)

|Variable|GitLab|Runner|Description|   
|-----|-----|----|----|  
|GITLAB_USER_LOGIN|10.0|all|The username of the user who started the job.|  
|CI_SERVER_HOST|12.1|all|The host of the GitLab instance URL, without protocol or port. For example gitlab.example.com.|  
|...|...|...|...|

> GitLab中的一些 [Concepts](https://docs.gitlab.com/ee/ci/#concepts)

|Concept|Description|  
|-----|-----|  
|Pipelines|Structure your CI/CD process through pipelines.|  
|CI/CD variables|Reuse values based on a variable/value key pair.|  
|Job artifacts|Output, use, and reuse job artifacts.|  
|Environments|Deploy your application to different environments (e.g., staging, production).|  
|Cache dependencies	|Cache your dependencies for a faster execution.|  
|GitLab Runner|Configure your own runners to execute your scripts.|  
|Pipeline efficiency|Configure your pipelines to run quickly and efficiently.|  
|Test cases|Configure your pipelines to run quickly and efficiently.|  
### 2.1 CI/CD pipelines
Piplines由两部分组成：
* Jobs 定义做什么，由runners执行。
* Stages 什么时候跑jobs   
  
注：**在同一Stages中的多个Jobs之间并行执行。** jobs在执行成功之后进入下一阶段，若失败则pipline停止在当前阶段。
### 2.2 jobs 执行条件
通过设置限制条件限定jobs执行：
* rules  
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
    - /^release/.*$/@gitlab-org/gitlab```