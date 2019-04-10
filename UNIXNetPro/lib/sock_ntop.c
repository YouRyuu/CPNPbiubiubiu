//
// Created by youryuu on 19-4-7.
//
#include "unnp.h"

/*
 * 指向某个套接字地址结构的指针作为参数，调用适当的函数返回该地址的表达格式
 * IPv4：10.0.0.1:80
 */
char *sock_ntop(const struct sockaddr *sa, socklen_t salen)
{
    char portstr[8];
    static char str[128];
    switch (sa->sa_family)
    {
        case AF_INET:   //IPv4
        {
            struct sockaddr_in *sin = (struct sockaddr_in *) sa;
            if(inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str))==NULL)  //将地址的数值格式转换为十进制表达格式
                return NULL;
            if(ntohs(sin->sin_port)!=0)     //返回主机字节序
            {
                snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
                strcat(str, portstr);
            }
            return (str);
        }
    }
}


