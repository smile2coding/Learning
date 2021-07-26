# Robot Framework
Robot Framework（[User Guide Link](http://robotframework.org/robotframework/#user-guide)）是一个基于python的，可扩展的**关键字驱动的自动化测试框架**。
## 1.安装
如果已经安装了python环境，则执行下面语句，  
`pip install robotframework`
## 2.创建测试数据
### 2.1测试数据语法
> 数据使用范围

|范围|用途|
|-------|--------|
|Settings|1) Importing test libraries, resource files and variable files.
|        |2) Defining metadata for test suites and test cases.|
|Variables|Defining variables that can be used elsewhere in the test data.|
|Test Cases|Creating test cases from available keywords.|
|Tasks|	Creating tasks using available keywords. Single file can only contain either tests or tasks.|
|Keywords|	Creating user keywords from existing lower-level keywords|
|Comments|	Additional comments or data. Ignored by Robot Framework.|   
通过标题行区分不同的区域，例如，
* \*\*\*Settings\*\*\*
* \*\*\*Variables\*\*\*
* \*\*\*Test Cases\*\*\*

>Robot Framework支持的文件格式
* **Space separated format**（空格）

```*** Settings ***
Documentation     Example using the space separated format.
Library           OperatingSystem

*** Variables ***
${MESSAGE}        Hello, world!

*** Test Cases ***
My Test
    [Documentation]    Example test.
    Log    ${MESSAGE}
    My Keyword    ${CURDIR}

Another Test
    Should Be Equal    ${MESSAGE}    Hello, world!

*** Keywords ***
My Keyword
    [Arguments]    ${path}
    Directory Should Exist    ${path}
```
* **Pipe separated format**（管道）
```| *** Settings ***   |
| Documentation      | Example using the pipe separated format.
| Library            | OperatingSystem

| *** Variables ***  |
| ${MESSAGE}         | Hello, world!

| *** Test Cases *** |                 |               |
| My Test            | [Documentation] | Example test. |
|                    | Log             | ${MESSAGE}    |
|                    | My Keyword      | ${CURDIR}     |
| Another Test       | Should Be Equal | ${MESSAGE}    | Hello, world!

| *** Keywords ***   |                        |         |
| My Keyword         | [Arguments]            | ${path} |
|                    | Directory Should Exist | ${path} |  
```

* **reStructuredText format**
```reStructuredText example
------------------------

This text is outside code blocks and thus ignored.

.. code:: robotframework

   *** Settings ***
   Documentation    Example using the reStructuredText format.
   Library          OperatingSystem

   *** Variables ***
   ${MESSAGE}       Hello, world!

   *** Test Cases ***
   My Test
       [Documentation]    Example test.
       Log    ${MESSAGE}
       My Keyword    ${CURDIR}

   Another Test
       Should Be Equal    ${MESSAGE}    Hello, world!

Also this text is outside code blocks and ignored. Code blocks not
containing Robot Framework data are ignored as well.

.. code:: robotframework

   # Both space and pipe separated formats are supported.

   | *** Keyword ***  |                        |         |
   | My Keyword       | [Arguments]            | ${path} |
   |                  | Directory Should Exist | ${path} |

.. code:: python

   # This code block is ignored.
   def example():
       print('Hello, world!')  
```
## 3.创建测试用例 


   
