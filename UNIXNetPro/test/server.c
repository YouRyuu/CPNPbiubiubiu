#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 套接字头文件
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>     //并发
#include <sys/types.h>
#include <errno.h>
#include <signal.h>  //信号处理
#include <sys/un.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/time.h>
#include <limits.h>

struct msg
{
    int num;
    char text[1024];
};

int main()
{
    int listenfd, connfd;
    struct sockaddr_in serveraddr, clientaddr;
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9090);
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        printf("socket error\n");
        exit(1);
    }
    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)))
    {
        printf("bind error\n");
        exit(2);
    }
    if(listen(listenfd, 1024))
    {
        printf("listen error\n");
        exit(3);
    }
    for(;;)
    {
        char buf[4096];
        socklen_t len = sizeof(clientaddr);
        if((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &len))<0)
        {
            printf("accept error\n");
            exit(4);
        }
        printf("conn from:%s\n", inet_ntop(AF_INET, &clientaddr.sin_addr, buf, sizeof(buf)));
        int length = sizeof(struct msg);
        struct msg *m = (struct msg*)calloc(1, sizeof(struct msg));
        m->num = 111;
        strcpy(m->text, "this is test to endian and socket trans struct");
        char *sendmsg = (char *)calloc(1, sizeof(struct msg));
        memcpy(sendmsg, m, sizeof(struct msg));
        write(connfd, sendmsg, sizeof(struct msg));
        free(m);
        free(sendmsg);
        close(connfd);
        printf("send ok\n");
    }

}