#include "header.h"
/**
 * exec族函数:execl, execv, execle, execve, execlp, execvp, fexecve
 * l代表参数通过以(char *)0结尾的参数列表传递,即:char *arg1, char*arg2,...,(char *)0
 * v代表参数通过一个char *args[]的数组传递
 * e代表传递环境变量:char *env[]
 * f代表使用文件描述符
 * 最后这几个函数都是通过系统调用execve实现的
 * execlp               execl               execle
 *    |argv              |argv               |argv
 * execvp------------->execv--------------->execve(系统调用)
 *                                           |
 *                                          fexecve 
 * 成功不返回,出错返回-1  
 */

extern int errno;

int main()
{
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
        printf("fork err\n");
        exit(1);
    }
    else if(pid==0)
    {
        if(execl("/home/youryuu/YL/Github/MakeMoreTime/LINUX_UNIX_core/APUE/test", "test", ".", (char *)0)<0)
        {
            printf("execl error\n");
            printf("%s\n", strerror(errno));
            exit(2);
        }
    }
    else
    {
        /* code */
    }
    printf("done\n");
    exit(0);
    
}