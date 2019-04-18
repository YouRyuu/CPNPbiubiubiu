//
// Created by youryuu on 19-4-18.
//

#include "../lib/unnp.h"

void udpclient()
{
    int sockfd;
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SEVE_PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    udp_cli_str(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));
    exit(0);
}

int main()
{
    udpclient();
    return 0;
}

