/**
 * 聊天程序服务器端v1.0
 * 使用poll
 */

#include "hchat.h"

void msgHandler(msgHeader* msg, int sockfd, char *buff);
void tcpserver_init();

void tcpserver_init()
{
    msgHeader msg;
    bzero(&msg, sizeof(msgHeader));
    int maxi, nready;
    ssize_t n;
    socklen_t clilen;
    struct pollfd client[FOPEN_MAX];
    struct sockaddr_in clientaddr, serveraddr;
    int listenfd, connfd, sockfd;
    char buff[MAXLEN];
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVERPORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    Bind(listenfd, (SA*)&serveraddr, sizeof(serveraddr));
    Listen(listenfd, LISTENQ);
    client[0].fd = listenfd;
    client[0].events = POLLRDNORM;
    for(int i=1;i<FOPEN_MAX;++i)
        client[i].fd = -1;      //初始化,-1为未连接
    maxi = 0;
    int i;
    for(;;)
    {
        nready = Poll(client, maxi+1, -1);
        if(client[0].revents & POLLRDNORM)
        {
            clilen = sizeof(clientaddr);
            connfd = Accept(listenfd, (SA *)&clientaddr, &clilen);
            for(i=1;i<FOPEN_MAX;++i)
            {
                if(client[i].fd < 0)
                {
                    client[i].fd = connfd;
                    break;
                }
            }
            if(i==FOPEN_MAX)
                err_throw("客户端已满");
            client[i].events = POLLRDNORM;
            if(i>maxi)
                maxi = i;
            if(--nready<=0)
                continue;
        }
        for(i=1;i<=maxi;++i)
        {
            if((sockfd = client[i].fd)<0)
                continue;
            if(client[i].revents & (POLLRDNORM | POLLERR))
            {
                if((n = read(sockfd, buff, MAXLEN)) < 0)
                {
                    if(errno == ECONNRESET)
                    {
                        Close(sockfd);
                        client[i].fd = -1;
                    }
                    else
                    {
                        err_throw("read error");
                    }
                }
                else if(n==0)
                {
                    Close(sockfd);
                    client[i].fd = -1;
                }
                else    //处理客户端发过来的字符
                {
                    msgHandler((msgHeader *)buff, sockfd, buff);
                }
                if(--nready<=0)
                    break;
            }
        }
    }
}

void msgHandler(msgHeader* msg, int sockfd, char *buff)
{
    switch (msg->type)
    {
    case MSG_LOGIN:     // 登录选项
        /* code */
        if(msg->sender==10000 && !strcmp(msg->content, "123456"))
        {
            printf("用户%d登录成功\n", msg->sender);
            msgHeader *rpmsg = (msgHeader *)calloc(1,sizeof(msgHeader));
            rpmsg->type = LOGIN_SUCC;        //登录成功
            rpmsg->sender = 10000;
            rpmsg->recver = msg->sender;
            strcpy(rpmsg->content, "登录成功");
            char *rpmsgString = (char *)calloc(sizeof(msgHeader), 1);
            memcpy(rpmsgString, rpmsg, sizeof(msgHeader));
            if(write(sockfd, rpmsgString, sizeof(msgHeader))<0)
            {
                err_throw("write error");
            }
        }
        break;
    
    default:
        break;
    }
}

int main()
{
    tcpserver_init();
    return 0;
}