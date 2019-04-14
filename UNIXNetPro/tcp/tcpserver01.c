//
// Created by youryuu on 19-4-7.
//tcp服务器,select实现

#include "../lib/unnp.h"

//使用client数组实现多客户端并发的服务器
void tcpserver() {
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buff[MAXLINE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, serveraddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SEVE_PORT);
    Bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));

    Listen(listenfd, LISTENQ);
    maxfd = listenfd;   //初始化
    maxi = -1;      //client数组的索引
    for (i = 0; i < FD_SETSIZE; i++)
        client[i] = -1;     //初始化,-1代表没有客户端连接
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    for (;;) {
        rset = allset;
        nready = Select(maxfd+1, &rset, NULL, NULL, NULL);
        if(FD_ISSET(listenfd, &rset))   //新客户端连接进来
        {
            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
            for (i = 0; i < FD_SETSIZE; i++) {
                if (client[i] < 0) {
                    client[i] = connfd;
                    break;
                }
            }
            if (i == FD_SETSIZE)
                err_quit("客户连接已满");
            FD_SET(connfd, &allset);
            if (connfd > maxfd)
                maxfd = connfd;
            if (i > maxi)
                maxi = i;
            if (--nready <= 0)       //select中没有更多的可读描述符
                continue;
        }

        for(i=0; i<=maxi;i++)
        {
            if((sockfd = client[i]) < 0)
                continue;       //寻找客户端
            if(FD_ISSET(sockfd, &rset))     //收到了客户端的消息
            {
                if((n = Read(sockfd, buff, MAXLINE)) == 0)
                {
                    // 客户退出
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                } else {
                    printf("server:----%s-----\n", buff);
                    Writen(sockfd, buff, n);
                }
                if(--nready <= 0)
                    break;
            }
        }
    }
}

//void main() {
//    tcpserver();
//}



