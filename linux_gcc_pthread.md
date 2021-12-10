# pthread.h

For C ,Linux and GCC, if we want to create a multiple threads application, we should include this header <pthread.h>.

However there is a caution we need to take. When we use GCC to compile the source code, we should add suffix , -lpthread, to combine to compilation command.

```cmake
gcc test.c -o -pthread
```

**Reason:**

*GCC compilation will not link the thread library by default.*

