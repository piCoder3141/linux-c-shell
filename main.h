#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

#ifdef __unix__
    #define IS_POSIX 1
    #include<unistd.h>
#else
    #define IS_POSIX 0
#endif
