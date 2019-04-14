//
// Created by youryuu on 19-4-14.
// 客户端信息处理程序
//

#include "unnp.h"
// select版客户端字符处理函数
void str_cli(FILE *fp, int sockfd)
{
    int maxfdp1, stdioeof;
    fd_set rset;
    char buff[MAXLINE];
    int n;
    stdioeof = 0;
    FD_ZERO(&rset);
    for(;;)
    {
        if(stdioeof==0)
            FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = (fileno(fp)>sockfd?fileno(fp):sockfd) + 1;
        Select(maxfdp1, &rset, NULL,NULL,NULL);
        if(FD_ISSET(sockfd, &rset))     //socket可读
        {
            if((n=Read(sockfd, buff, MAXLINE))==0)
            {
                if(stdioeof==1)
                    return;     //正常结束
                else
                {
                    err_sys("服务器宕机\n");
                }
            }
            Writen(fileno(stdout), buff, n);
        }

        if(FD_ISSET(fileno(fp), &rset))     //输入端可读
        {
            if((n = Read(fileno(fp), buff, MAXLINE))==0)       //EOF
            {
                stdioeof = 1;
                Shutdown(sockfd, SHUT_WR);  //发送FIN,关闭输入
                FD_CLR(fileno(fp), &rset);
                continue;
            }
            printf("client:---%s---\n", buff);
            Writen(sockfd, buff, n);
        }
    }
}

