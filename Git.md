# Git学习
>[Git](https://git-scm.com/) 是一个开源的分布式版本控制系统，前身是BitKeeper。
## 1.Git基本概念
版本控制系统分类：   
* 分布式版本控制
* 集中式版本控制。如，SVN   

|Command|Description|   
|----|-----| 
|git add |file : Working Dreictory -----> Stage| 
|git commit|file : Stage -----> Repository|
|git push|file : Local Repository -----> Remote Repository|
|CTRL + C|Clear the screen|
|echo 'xxxx'|消息输出|
|git status||
|git pull|file : Remote Repository -----> Local Repository|
|git log|打印当前branch的commit日志|

Git优势：  
1. 回滚
2. 分布式
3. 全量
## 2.Git账户设置
|Command|Description|   
|----|-----| 
|git config [--global][--system][--local] user.name "userName"|set a username| 
|git config [--global][--system][--local] user.eamil "xxx.xx.com"|set a eamil address|
|git config [--global][--system][--local]--unset user.name "userName"|unset a username| 
|git config [--global][--system][--local]--unset user.eamil "xxx.xx.com"|unset a eamil address|
|||

**注：**  
1. git config [--global][--system] 的设置可以在"C:/User/xxx/.gitconfig"查看  
   
    ```
    cd C:/User/xxx/
    cat .gitconfig
    ```
2. git config --local 的设置在 "/.git/config"中

## 3.Git操作及ignore