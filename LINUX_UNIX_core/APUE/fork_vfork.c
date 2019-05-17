/**
 * fork和vfork的区别:
 *      vfork产生的子进程的目的是exec一个新程序,而fork则不一定,在子进程调用exec之前,vfork的子进程在父进程的空间中运行,也就是说子进程修改数据会影响到父进程,
 * 这一点和fork的不一样.此外,vfork保证子进程先运行,在子进程调用exec或者exit之后父进程才可能杯调度运行
 * */

#include "header.h"

int fork_vfork()
{
    pid_t ch;
    int var;
    pid_t pid;
    var = 88;
    printf("before vfork\n");
    if((pid=vfork())<0)
    {
        printf("vfork error\n");
        exit(1);
    }
    else if(pid==0)
    {
        var++;
        //printf("%d\n", var);
        //sleep(3);
        //return 0;
        exit(0);
    }
    printf("%d,,,%d,,,%d\n", var, getpid(), getppid());
    exit(0);
}

void pr_exit(int status)
{
    //此函数打印进程的终止状态说明
    if(WIFEXITED(status))
        printf("正常退出,exit status=%d\n", WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("abnormal exit, signal num:%d,%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status)?"core dump":"");
#else
        "");
#endif
    else if(WIFSTOPPED(status))
        printf("child stop, sig num:%d\n", WSTOPSIG(status));
}

int wait()
{
    /**
     * 正常退出,exit status=7
        abnormal exit, signal num:6,core dump
        abnormal exit, signal num:8,core dump
    */
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        printf("fork error\n");
        exit(1);
    }
    else if(pid==0)
        exit(7);
    if(wait(&status)!=pid)
    {
        printf("wait error");
        exit(1);
    }
    pr_exit(status);

    pid = fork();
    if(pid<0)
    {
        printf("fork error\n");
        exit(1);
    }
    else if(pid==0)
        abort();
    if(wait(&status)!=pid)
    {
        printf("wait error");
        exit(1);
    }
    pr_exit(status);

    pid=fork();

    if(pid<0)
    {
        printf("fork error\n");
        exit(1);
    }
    else if(pid==0)
        status/=0;
    if(wait(&status)!=pid)
    {
        printf("wait error");
        exit(1);
    }
    pr_exit(status);
    exit(0);
}

int main()
{

}