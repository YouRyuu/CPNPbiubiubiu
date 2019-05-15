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

struct msg{
    int num;
    char text[1024];
};

int main()
{
    int sockfd;
    struct sockaddr_in serveraddr;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        printf("socket error\n");
        exit(1);
    }
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9090);
    inet_pton(AF_INET, "172.29.220.10", &serveraddr.sin_addr);
    if(connect(sockfd, (struct socketaddr*)&serveraddr, sizeof(serveraddr))<0)
    {
        printf("conn error\n");
        exit(2);
    }
    //struct msg *m = (struct msg*)calloc(1, sizeof(struct msg));
    char *recvmsg = (char *)calloc(1, sizeof(struct msg));
    if(read(sockfd, recvmsg, sizeof(struct msg))==-1)
    {
        printf("read error\n");
        exit(3);
    }
    printf("%d--%s\n", ((struct msg *)recvmsg)->num, ((struct msg *)recvmsg)->text);
    free(recvmsg);
    return 0;
}