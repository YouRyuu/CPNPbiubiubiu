/**
 * 包裹后的库函数
 */

#include "hchat.h"

// ssize_t Read(int fd, void *ptr, size_t nbytes) {
//     ssize_t n;
//     if ((n = read(fd, ptr, nbytes)) == -1) {
//         err_sys("READ发生错误");
//     }
//     return n;
// }

// ssize_t writen(int fd, const void *vptr, size_t n)  //向描述符中写n个数据
// {
//     size_t nleft;
//     ssize_t nwritten;
//     const char *ptr;
//     ptr = vptr;
//     nleft = n;
//     while (nleft > 0) {
//         if ((nwritten = write(fd, ptr, nleft)) <= 0) {
//             if (nwritten < 0 && errno == EINTR)
//                 nwritten = 0;        /* and call write() again */
//             else
//                 return (-1);            /* error */
//         }

//         nleft -= nwritten;
//         ptr += nwritten;
//     }
//     return (n);
// }

// /* end writen */

// void
// Writen(int fd, void *ptr, size_t nbytes) {
//     if (writen(fd, ptr, nbytes) != nbytes)
//         err_sys("writen error");
// }

void Shutdown(int fd, int how) {
    int n;
    if ((n = shutdown(fd, how)) < 0) {
        err_throw("shutdown error");
    }
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen) {
    if (connect(fd, sa, salen) < 0)
        err_throw("connect error");
}

int Socket(int family, int type, int protocol) {
    int n;
    if ((n = socket(family, type, protocol)) < 0) {
        err_throw("socket error");
    }
    return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen) {
    if (bind(fd, sa, salen) < 0)
        err_throw("bind error");
}

void Listen(int fd, int backlog) {
    if (listen(fd, backlog) < 0)
        err_throw("listen error");
}

int Poll(struct pollfd *fdarray, unsigned long nfds, int timeout)
{
    int n;
    if((n = poll(fdarray, nfds, timeout)) < 0)
        err_throw("poll error");
    return n;
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;
    again:
    if ( (n = accept(fd, sa, salenptr)) < 0) {
#ifdef	EPROTO
        if (errno == EPROTO || errno == ECONNABORTED)
#else
            if (errno == ECONNABORTED)
#endif
            goto again;
        else
            err_throw("accept error");
    }
    return(n);
}

void Close(int fd)
{
    if(close(fd) == -1)
        err_throw("close error");
}

