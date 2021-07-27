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

& 用来建立锚点（defaults），<< 表示合并到当前数据，* 用来引用锚点。