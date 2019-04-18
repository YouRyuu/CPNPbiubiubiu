//
// Created by youryuu on 19-4-18.
//
#include "unnp.h"

void udp_str(int sockfd, SA *pcliaddr, socklen_t clilen)
{
    int n;
    socklen_t len;
    char msg[MAXLINE];

    for(;;)
    {
        len = clilen;
        n = recvfrom(sockfd, msg, MAXLINE, 0, pcliaddr, &len);
        sendto(sockfd, msg, n, 0, pcliaddr, len);
    }
}