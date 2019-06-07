//子线程任意一线程调用exit族函数都会导致进程退出
//pthread_join将指定线程的返回码存于第二个参数中
//pthread_join的第二个参数不能使线程栈变量
//调用线程会等待join线程
#include "../header.h"

void *th1(void *arg)
{
    printf("th1 return\n");
    return ((void *)2);
}

void *th2(void *arg)
{
    printf("th2 exit\n");
    pthread_exit(2);
}

int main()
{
    int err;
    pthread_t t1, t2;
    void *rt;
    err = pthread_create(&t1, NULL, th1, NULL);
    if(err)
    exit(1);
    err = pthread_create(&t2, NULL, th2, NULL);
    if(err)
    exit(2);
    err = pthread_join(t1, &rt);
    if(err)
    exit(3);
    printf("th1 exit code:%d\n", rt);
    err = pthread_join(t2, &rt);
    if(err)
    exit(4);
    printf("th2 exit code:%d", rt);
    exit(0);
}