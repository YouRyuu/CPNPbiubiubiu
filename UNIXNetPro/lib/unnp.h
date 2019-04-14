//
// Created by youryuu on 19-4-7.
// 头文件API
//

#ifndef UNIXNETPRO_UNNP_H
#define UNIXNETPRO_UNNP_H

#endif //UNIXNETPRO_UNNP_H

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

#define SEVE_PORT 49969 //tcp,udp端口号;
#define LISTENQ 1024
#define SA struct sockaddr
#define MAXLINE 1024  //缓冲区最大字节

char *sock_ntop(const struct sockaddr *sa, socklen_t salen);
void str_cli(FILE *fp, int sockfd);
void err_sys(const char *fmt, ...);
void err_quit(const char *fmt, ...);
void Writen(int fd, void *ptr, size_t nbytes);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Shutdown(int fd, int how);
void Connect(int fd, const struct sockaddr *sa,socklen_t *salen);
int Socket(int family, int type, int protocol);
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);
void Bind(int fd, const struct  sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Select(int fd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Close(int fd);

