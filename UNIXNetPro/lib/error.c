//
// Created by youryuu on 19-4-14.
// 错误处理

#include "unnp.h"

void
err_sys(const char *fmt, ...)
{
    printf("%s\n", fmt);
    exit(1);
}

void
err_quit(const char *fmt, ...)
{
    printf("%s\n", fmt);
    exit(1);
}