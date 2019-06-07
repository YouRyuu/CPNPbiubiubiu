#include "../header.h"

pthread_once_t init = PTHREAD_ONCE_INIT;

void once()
{
    printf("once被调用%ld!\n", pthread_self());
}

void *run()
{
    printf("thread:%ld\n", pthread_self());
    pthread_once(&init, once);
}

int main()
{
    pthread_t pid1, pid2, pid3;
    pthread_create(&pid1, NULL, run, NULL);
    pthread_create(&pid2, NULL, run, NULL);
    pthread_create(&pid3, NULL, run, NULL);
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);
    printf("exit done\n");
    return 0;
}