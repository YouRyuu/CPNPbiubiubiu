//
// Created by youryuu on 19-4-7.
//tcp服务器

#include "../lib/unnp.h"

void tcpserver() {
    char buff[1024];
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, serveraddr;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket fail");
        exit(0);
    }
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SEVE_PORT);
    if (bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr))) {
        printf("bind error");
        exit(0);
    }
    if (listen(listenfd, LISTENQ)) {
        printf("listen error");
        exit(0);
    }
    //for (;;) {
    ssize_t n;
    clilen = sizeof(cliaddr);
    if ((connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
        printf("accept error");
        exit(0);
    }
    printf("connection from:%s, port:%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
           ntohs(cliaddr.sin_port));
    memset(buff, 0, sizeof(buff));
    //while ((n = read(connfd, buff, 1024)) > 0) {
    char status[] = "HTTP/1.0 200 OK\r\n";
    char header[] = "Server: DWBServer\r\nContent-Type: text/html;charset=utf-8\r\n\r\n";
    char body[] = "<html><head><title>C语言构建小型Web服务器</title></head><body><h2>欢迎</h2><p>Hello，World</p></body></html>";
    read(connfd, buff, 1024);
    printf("client say:%s\n", buff);
    //snprintf(buff, sizeof(buff), "%s", "server recv succ");
    write(connfd, status, strlen(status));
    write(connfd, header, sizeof(header));
    write(connfd, body, strlen(body));
    //memset(buff, 0, sizeof(buff));
    //}
    close(connfd);
    close(listenfd);
    //}
}

void main() {
    tcpserver();
}



