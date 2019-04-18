//
// Created by youryuu on 19-4-18.
//
#include "unnp.h"

void udp_cli_str(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE+1];
    while((fgets(sendline, MAXLINE, stdin))!=NULL)
    {
        sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        recvline[MAXLINE] = 0;
        fputs(recvline, stdout);
    }
}

