# Unity Test
> [Unity Test](http://www.throwtheswitch.org/unity)是 throwtheswitch.org 的一个主流项目，该项目100%由C语言构建的，遵循ANSI标准、支持大多数嵌入式编译器。

## 1. 支持断言（Assertion）
Unity最明显的一个特点就是断言。断言是我们希望在嵌入式系统是正确的陈述性语句。例如下面
```c
int a = 1;
TEST_ASSERT( a == 1 ); //this one will pass
TEST_ASSERT( a == 2 ); //this one will fail
```
当执行Failed会给出下面报错  

```shell
TestMyModule.c:15:test_One:FAIL
```
虽然，Unity会给出提示，但并不是很友好。我们可以用另外的方法解决。  

`TEST_ASSERT_MESSAGE( a == 2 , "a isn't 2, end of the world!");`

```
TestMyModule.c:15:test_one:FAIL:a isn't 2, end of the world!
```
一些其他的断言  
|Assertion|Description|
|------|------|
|TEST_ASSERT_EQUAL_INT(2, a);|测试a是否为整型的2|
|TEST_ASSERT_EQUAL_HEX8(5, a);|...|
|TEST_ASSERT_EQUAL_UINT16(0x8000, a);|...|
## 2. 



