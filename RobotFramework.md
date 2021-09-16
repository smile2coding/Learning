# Robot Framework
Robot Framework（[User Guide Link](http://robotframework.org/robotframework/#user-guide)）是一个基于python的，可扩展的**<font color =red>关键字驱动</font>的自动化测试框架**。
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
### 2.2 * Setting *

>  每一个test case都有自己的setting区域，用“[]”包裹用以来区分其他关键字。

* [Documentation]

  Used for specifying a [test case documentation](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-case-name-and-documentation).

* [Tags]

  Used for [tagging test cases](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#tagging-test-cases).

* [Setup], [Teardown]

  Specify [test setup and teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-setup-and-teardown).

* [Template]

  Specifies the [template keyword](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-templates) to use. The test itself will contain only data to use as arguments to that keyword.

* [Timeout]

  Used for setting a [test case timeout](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-case-timeout). [Timeouts](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#timeouts) are discussed in their own section.

### 2.3 arguments

```robot
*** Test Cases ***
Example
    Create Directory    ${TEMPDIR}/stuff
    Copy File    ${CURDIR}/file.txt    ${TEMPDIR}/stuff
    No Operation
```

​		大多数关键字都需要特定数目的参数，上述的关键字“Create Directory”、“Copy File”来自<font color=red>“OperatingSystem” library</font>。常规的libraries（normal libraries）：

- [BuiltIn](http://robotframework.org/robotframework/latest/libraries/BuiltIn.html)
- [Collections](http://robotframework.org/robotframework/latest/libraries/Collections.html)
- [DateTime](http://robotframework.org/robotframework/latest/libraries/DateTime.html)
- [Dialogs](http://robotframework.org/robotframework/latest/libraries/Dialogs.html)
- [OperatingSystem](http://robotframework.org/robotframework/latest/libraries/OperatingSystem.html)
- [Process](http://robotframework.org/robotframework/latest/libraries/Process.html)
- [Screenshot](http://robotframework.org/robotframework/latest/libraries/Screenshot.html)
- [String](http://robotframework.org/robotframework/latest/libraries/String.html)
- [Telnet](http://robotframework.org/robotframework/latest/libraries/Telnet.html)
- [XML](http://robotframework.org/robotframework/latest/libraries/XML.html)

### 2.4 * Variables *

robotframework中有三种变量：标量、列表、字典

1. 标量

   1. ${str}  hello world

2. 列表

   1. @{str}	first    second    third

3. 字典

   1. &{USER 1}       name=Matti    address=xxx         phone=123

常见的已定义的变量：

* #### Operating-system variables

| Variable   | Explanation                                                  |
| ---------- | ------------------------------------------------------------ |
| ${CURDIR}  | An absolute path to the directory where the test data file is located. This variable is case-sensitive. |
| ${TEMPDIR} | An absolute path to the system temporary directory. In UNIX-like systems this is typically */tmp*, and in Windows *c:\Documents and Settings\<user>\Local Settings\Temp*. |
| ${EXECDIR} | An absolute path to the directory where test execution was started from. |
| ${/}       | The system directory path separator. `/` in UNIX-like systems and \ in Windows. |
| ${:}       | The system path element separator. `:` in UNIX-like systems and `;` in Windows. |
| ${\n}      | The system line separator. \n in UNIX-like systems and \r\n in Windows. |

* #### Automatic variables

| Variable               | Explanation                                                  | Available                                                    |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ${TEST NAME}           | The name of the current test case.                           | Test case                                                    |
| @{TEST TAGS}           | Contains the tags of the current test case in alphabetical order. Can be modified dynamically using *Set Tags* and *Remove Tags* keywords. | Test case                                                    |
| ${TEST DOCUMENTATION}  | The documentation of the current test case. Can be set dynamically using using *Set Test Documentation* keyword. | Test case                                                    |
| ${TEST STATUS}         | The status of the current test case, either PASS or FAIL.    | [Test teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-setup-and-teardown) |
| ${TEST MESSAGE}        | The message of the current test case.                        | [Test teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#test-setup-and-teardown) |
| ${PREV TEST NAME}      | The name of the previous test case, or an empty string if no tests have been executed yet. | Everywhere                                                   |
| ${PREV TEST STATUS}    | The status of the previous test case: either PASS, FAIL, or an empty string when no tests have been executed. | Everywhere                                                   |
| ${PREV TEST MESSAGE}   | The possible error message of the previous test case.        | Everywhere                                                   |
| ${SUITE NAME}          | The full name of the current test suite.                     | Everywhere                                                   |
| ${SUITE SOURCE}        | An absolute path to the suite file or directory.             | Everywhere                                                   |
| ${SUITE DOCUMENTATION} | The documentation of the current test suite. Can be set dynamically using using *Set Suite Documentation* keyword. | Everywhere                                                   |
| &{SUITE METADATA}      | The free metadata of the current test suite. Can be set using *Set Suite Metadata* keyword. | Everywhere                                                   |
| ${SUITE STATUS}        | The status of the current test suite, either PASS or FAIL.   | [Suite teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#suite-setup-and-teardown) |
| ${SUITE MESSAGE}       | The full message of the current test suite, including statistics. | [Suite teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#suite-setup-and-teardown) |
| ${KEYWORD STATUS}      | The status of the current keyword, either PASS or FAIL.      | [User keyword teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-teardown) |
| ${KEYWORD MESSAGE}     | The possible error message of the current keyword.           | [User keyword teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-teardown) |
| ${LOG LEVEL}           | Current [log level](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#log-levels). | Everywhere                                                   |
| ${OUTPUT FILE}         | An absolute path to the [output file](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#output-file). | Everywhere                                                   |
| ${LOG FILE}            | An absolute path to the [log file](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#log-file) or string NONE when no log file is created. | Everywhere                                                   |
| ${REPORT FILE}         | An absolute path to the [report file](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#report-file) or string NONE when no report is created. | Everywhere                                                   |
| ${DEBUG FILE}          | An absolute path to the [debug file](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#debug-file) or string NONE when no debug file is created. | Everywhere                                                   |
| ${OUTPUT DIR}          | An absolute path to the [output directory](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#output-directory). | Everywhere                                                   |

### 2.5 keywords

* [Documentation]

  Used for setting a [user keyword documentation](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-documentation).

* [Tags]

  Sets [tags](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-tags) for the keyword.

* [Arguments]

  Specifies [user keyword arguments](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-arguments).

* [Return]

  Specifies [user keyword return values](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-return-values).

* [Teardown]

  Specify [user keyword teardown](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-teardown).

* [Timeout]

  Sets the possible [user keyword timeout](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#user-keyword-timeout). [Timeouts](http://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#timeouts) are discussed in a section of their own.



## 3.创建测试用例 



