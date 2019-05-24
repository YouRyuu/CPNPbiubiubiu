/**
 * 聊天程序客户端
 */

#include "hchat.h"

void msgHandler(FILE *fp, int sockfd);

void tcpclient_init()
{
    int sockfd;
    struct sockaddr_in serveraddr;
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVERPORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);
    Connect(sockfd, (SA *)&serveraddr, sizeof(serveraddr));
    //信息处理函数
    msgHandler(stdin, sockfd);
    exit(0);
}

void msgHandler(FILE *fp, int sockfd)
{
    int maxfdp1, stdioeof;
    fd_set rset;
    char buff[MAXLEN];
    int n;
    stdioeof = 0;
    FD_ZERO(&rset);
    int nready;
    for(;;)
    {
        if(stdioeof==0)
            FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = (fileno(fp)>sockfd?fileno(fp):sockfd) + 1;
        nready = select(maxfdp1, &rset, NULL,NULL,NULL);
        if(FD_ISSET(sockfd, &rset))     //socket可读
        {
            if((n=read(sockfd, buff, MAXLEN))==0)
            {
                if(stdioeof==1)
                    return;     //正常结束
                else
                {
                    err_throw("服务器宕机");
                }
            }
            else if(n<0)
                err_throw("socket read error");
            else
            {
                cout << "来自服务器的回答:" <<endl;
                write(fileno(stdout), ((msgHeader *)buff)->content, strlen(((msgHeader *)buff)->content));
            }
            if(--nready<=0)
                continue;
        }

        if(FD_ISSET(fileno(fp), &rset))     //输入端可读
        {
            if((n = read(fileno(fp), buff, MAXLEN))==0)       //EOF
            {
                stdioeof = 1;
                Shutdown(sockfd, SHUT_WR);  //发送FIN,关闭输入
                FD_CLR(fileno(fp), &rset);
                continue;
            }
            else if(n<0)
                err_throw("stdin read error");
            else
            {
                //buff[n-1] = '\0';
                msgHeader *inmsg = (msgHeader *)calloc(sizeof(msgHeader), 1);
                inmsg->type = MSG_LOGIN;
                inmsg->sender = 10000;
                inmsg->recver = 10000;
                strcpy(inmsg->content, buff);
                char *msgString = (char *)calloc(sizeof(msgHeader), 1);
                memcpy(msgString, inmsg, sizeof(msgHeader));
                write(sockfd, msgString, sizeof(msgHeader));
                cout << "发送至服务器成功" <<endl;
                free(inmsg);
                free(msgString);
            }
        }
    }
}

int main()
{
    tcpclient_init();
    return 0;
}