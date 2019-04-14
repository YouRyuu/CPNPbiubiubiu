//
// Created by youryuu on 19-4-14.
//tcp server , poll
//

/**
 * todo:
 *      包裹READ和WRITE函数,正确处理换行符和莫名其妙的乱码
 */
#include "../lib/unnp.h"

void tcpserver() {
    int i, maxi, listenfd, connfd, sockfd;
    int nready;
    ssize_t n;
    char buff[MAXLINE];
    socklen_t clilen;
    struct pollfd client[FOPEN_MAX];
    struct sockaddr_in cliaddr, serveraddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SEVE_PORT);
    Bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));
    Listen(listenfd, LISTENQ);
    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for (i = 1; i < FOPEN_MAX; i++)
        client[i].fd = -1;  //初始化,-1为未连接
    maxi = 0;
    for (;;) {
        nready = Poll(client, maxi + 1, -1);        //-1代表永远等待
        if (client[0].revents & POLLRDNORM) {       //有新的客户端加入
            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
            for (i = 1; i < FOPEN_MAX; i++) {
                if (client[i].fd < 0) {
                    client[i].fd = connfd;      //保存新加入客户
                    break;
                }
            }
            if (i == FOPEN_MAX)
                err_quit("客户端已满");
            client[i].events = POLLRDNORM;      //读取数据
            if (i > maxi)
                maxi = i;       //客户端数量
            if (--nready <= 0)      //没有更多的可读数据
                continue;
        }
        for (i = 1; i <= maxi; i++) {
            if ((sockfd = client[i].fd) < 0)
                continue;       //寻找已经连接的客户端
            if (client[i].revents & (POLLRDNORM | POLLERR))  //可读或者发生错误
                if ((n = read(sockfd, buff, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                        Close(sockfd);  //客户端重置连接
                        client[i].fd = -1;
                    } else {
                        err_sys("read error");
                    }
                } else if (n == 0) {
                    Close(sockfd);
                    client[i].fd = -1;      //客户端关闭连接
                } else {
                    printf("server:----%s-----\n", buff);
                    Writen(sockfd, buff, n);
                }
            if (--nready <= 0)
                break;
        }
    }
}

int main() {
    tcpserver();
    return 0;
}

