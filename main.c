#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define PMD_REGISTER_DRIVER(d)\
void devinitfn_ ##d(void);\
void __attribute__((constructor, used)) devinitfn_ ##d(void)\
{\
        rte_eal_driver_register(&d);\
}

//main函数之前执行的函数
void rte_eal_driver_register()
{
    printf ("Enter rte_eal_driver_register...\n");
}
int drive = 0;
PMD_REGISTER_DRIVER(drive);

//main函数之后执行的函数
void atexit_test()
{
    printf("Enter atexit_test ...\n");   
}

int main()
{
     printf("Enter main ....\n");
     atexit(atexit_test);
    atexit(atexit_test);
    printf("main: exit func will causes  all buffered output data to be flushed (written to the file)");
     
    //_exit(0); //如果放开此行或下一行，上一行的printf信息将不会被输出
    //abort();   
    return 0; //等价于调用exit(0);
}