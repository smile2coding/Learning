# Capture signal and ignore some exceptions in LINUX

Sometimes we need the application skip some exceptions and continue to execute subsequent code, such as acceptance for **divided by zero error**, **access free memory** and etc. 

For these conditions, signal of OS(Operating System) can solve these.

**Common signals**

```c
#define NSIG 23

#define SIGINT 2
#define SIGILL 4
#define SIGABRT_COMPAT 6
#define SIGFPE 8
#define SIGSEGV 11
#define SIGTERM 15
#define SIGBREAK 21
#define SIGABRT 22       /* used by abort, replace SIGIOT in the future */
#define SIGABRT2 22

```

Detailed information to <signal.h>.

**Example**

Here we present a demo about access bad memory.

```c
#include <setjmp.h>
#include "signal.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

void handler(int sig)
{
    printf("The cause the signal is %d\n", sig);
    longjmp(env, 1);
}

void main()
{
    signal(SIGFPE, handler);
    
    // store context
    int r = setjmp(env);
    if (r == 0)
    {
        // it maybe cause error
        int res = 10/0;
    else
    {
        printf("jump this code !!");
    }
}
```



**NOTE**

As you can see we also have used the header, <longjmp.h>, which is a little same as goto and usually used to skip some exception in C language. [More details.](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/longjmp?view=msvc-170)

