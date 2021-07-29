# Ceedling
> Ceedling 是一个**用 Ruby 语言编写**的自动化测试框架，一个 C 项目构建系统，是对 Ruby Rake 的一个延申。Ceedling 主要目标是以测试为驱动的 C 语言开发，集成CMock、Unity、CException三个开源项目。 
## 1.环境搭建
### 1.1 Ruby环境
Windows下，我们使用官方的RubyInstaller安装Ruby环境。[RubyInstaller Archives Link <-----](https://rubyinstaller.org/downloads/archives/
)，选择合适的Ruby版本。
```
PS C:\Users\z004ccvf> Ruby -v
ruby 2.7.2p137 (2020-10-01 revision 5445e04352) [x64-mingw32]
PS C:\Users\z004ccvf> Ruby --version
ruby 2.7.2p137 (2020-10-01 revision 5445e04352) [x64-mingw32]
```
### 1.2 Ceedling安装
首先我们要知道 **gem** （类似于 python 的 pip 、Ubuntu 中的 apt-get 、Node.js 的 NPM 等等）是一个管理 Ruby 库和程序的标准包，通过 gem 可以十分便捷的安装、升级和卸载软件。  
常见的 Ruby gem 指令：  
|Command|Description|
|----|-----|
|gem -v|gem版本|
|gem -h|help|
|gem install -h|install帮助|
|gem update|更新所有包|
|gem install <PACKAGENAME> -v PACKAGEVERSION|安装指定版本的软件包|
|gem environment|查看gem的环境|

有了上面的知识储备，我们现在来安装 Ceedling  
`gem install Ceedling -v 0.30.0`
### 1.3 GCC编译器
对于 Linux 操作系统，可能会自带 GCC 编译环境，但是Windows想要使用 GCC 编译器，一般需要安装 MINGW 或者 Cygwin 。  
这里我们使用 [MINGW](http://mingw-w64.org/doku.php/download) 支持 GCC 编译。
## 2. Demo测试
### 2.1 生成一个 Sample 项目
`ceedling example temp_sensor`
### 2.2 项目测试
`ceedling test:all`