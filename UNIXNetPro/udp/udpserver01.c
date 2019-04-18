//
// Created by youryuu on 19-4-18.
//
#include "../lib/unnp.h"

void udpserver()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SEVE_PORT);
    Bind(sockfd, (SA *)&servaddr, sizeof(servaddr));
    udp_str(sockfd, (SA *)&servaddr, sizeof(cliaddr));
}

int main()
{
    udpserver();
    return 0;
}