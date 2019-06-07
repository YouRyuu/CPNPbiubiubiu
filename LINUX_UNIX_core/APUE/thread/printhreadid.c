#include "../header.h"

void *func(void *args)
{
    printf("thread runing\n");
    return (void *)0;
}

/**
 * tid不能唯一确定线程
 * join的顺序不同,产生的tid也不同
 * 如果是create立马join,则产生的两个线程的标识符是相同的
 *  pthread_create(&t1, NULL, func, NULL);
    printf("%lx\n", t1);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, func, NULL);
    printf("%lx\n", t2);
    pthread_join(t2, NULL);
 * 如果一起create后再一起join,产生的标识符又是不同的
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 */

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func, NULL);
    printf("%lx\n", t1);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, func, NULL);
    printf("%lx\n", t2);
    pthread_join(t2, NULL);
    
    return 0;
}