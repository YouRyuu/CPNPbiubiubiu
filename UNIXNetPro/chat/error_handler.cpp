/**
 * 错误处理函数
 */

#include "hchat.h"

void err_throw(char *errmsg)
{
    printf("%s:", errmsg);
    printf("%s\n", strerror(errno));
    exit(1);
}