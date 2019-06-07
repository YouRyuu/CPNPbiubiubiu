#include "../header.h"

/**
 * 线程特定数据,
 * 每个线程对于一个key有不同的value
 */

pthread_key_t key;
pthread_once_t once = PTHREAD_ONCE_INIT;

typedef struct p
{
    pthread_t tid;
    char *tname;
}p;

void de(p *value)
{
    free(value);
}

void init()
{
    pthread_key_create(&key, de);
}

void *start(void *args)
{
    pthread_once(&once, init);
    p *value = (p*)malloc(sizeof(p));
    value->tid = pthread_self();
    value->tname = (char *)args;
    p *temp;
    pthread_setspecific(key, value);
    printf("%s set k ey:%p\n", (char*)args, value);
    temp = pthread_getspecific(key);
    printf("get:%ld,%s\n", temp->tid, (char *)(temp->tname));
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, start, (void *)"t1");
    printf("%lx\n", t1);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, start, (void *)"t2");
    printf("%lx\n", t2);
    pthread_join(t2, NULL);
    return 0;
}