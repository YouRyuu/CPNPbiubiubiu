//
// Created by youryuu on 19-4-7.
//

#include "../lib/unnp.h"

void tcpclient()
{
    char send[1024], recv[1024];
    int sockfd;
    struct sockaddr_in serveraddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SEVE_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);
    connect(sockfd, (SA *)&serveraddr, sizeof(serveraddr));
    while(1)
    {
        printf("\nsend to server:");
        fgets(send, 1024, stdin);
        write(sockfd, send, strlen(send));
        printf("\nrecv from server:");
        read(sockfd, recv, 1024);
        fputs(recv, stdout);
    }
}

void main()
{
    tcpclient();
}
