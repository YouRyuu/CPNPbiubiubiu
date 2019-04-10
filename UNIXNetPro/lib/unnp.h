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
#include <signal.h>
#include <sys/un.h>
#include <sys/stat.h>

#define SEVE_PORT 49969 //tcp,udp端口号;
#define LISTENQ 1024
#define SA struct sockaddr

char *sock_ntop(const struct sockaddr *sa, socklen_t salen);


