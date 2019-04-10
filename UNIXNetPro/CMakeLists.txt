cmake_minimum_required(VERSION 3.13)
project(UNIXNetPro C)


set(CMAKE_C_STANDARD 99)

add_executable(UNIXNetPro main.c lib/unnp.h lib/sock_ntop.c tcp/tcpserver01.c)