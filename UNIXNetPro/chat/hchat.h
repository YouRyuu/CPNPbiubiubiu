#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

#define SERVERPORT 6666     //端口号
#define LISTENQ 1024        //监听队列长度
#define SA struct sockaddr

#define MAXLEN 1024     //缓冲区最大字节
#define USERLEN 50      //用户名和密码最大长度
#define MSG_REG 0   //注册
#define MSG_LOGIN 1     //登录
#define MSG_EXIT 2      //退出
#define MSG_CHAT 3      //一对一聊天
#define MSG_ADMIN 4     //管理员广播
#define LOGIN_SUCC 6    //登录成功

typedef struct msgHeader {      //消息头
    int type;       //消息类型:0.注册消息MSG_REG, 1.登录消息MSG_LOGIN, 2.退出消息MSG_EXIT, 3.一对一聊天MSG_CHAT, 4.管理员广播MSG_ADMIN
    int sender;     //发送者id
    int recver;     //接收者
    char content[MAXLEN];     //消息正文
};

typedef struct regMsg {     //注册
    msgHeader msgheader;    //content保存用户的用户名
    char password[USERLEN];
};

typedef struct friendsList {
    msgHeader msgheader;
    int *friendsId[USERLEN];
    char *friendsName[USERLEN];
};

//函数原型
void err_throw(char *errmsg);   //抛出错误
void Shutdown(int fd, int how) ;
void Connect(int fd, const struct sockaddr *sa, socklen_t salen) ;
int Socket(int family, int type, int protocol);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Close(int fd);