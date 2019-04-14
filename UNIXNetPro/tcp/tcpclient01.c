//
// Created by youryuu on 19-4-7.
// TCP客户端
//

#include "../lib/unnp.h"

void tcpclient() {
    int sockfd;
    struct sockaddr_in serveraddr;
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SEVE_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);
    Connect(sockfd, (SA *) &serveraddr, sizeof(serveraddr));
    str_cli(stdin, sockfd);
    exit(0);
}

void main() {
    tcpclient();
}
