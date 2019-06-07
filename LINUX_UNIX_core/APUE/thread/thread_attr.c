#include "../header.h"

#include<syslog.h>
#include<sys/resource.h>
#include<fcntl.h>
void t()
{
    int i,fd0,fd1,fd2;
    pid_t pid;
    struct rlimit r1;
    struct  sigaction sa;
    umask(0);
    if(getrlimit(RLIMIT_NOFILE, &r1)<0)
    {
        printf("error\n");
        exit(1);
    }
    pid = fork();
    if(pid<0)
    exit(2);
    else if(pid!=0) exit(0);
    setsid();
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGHUP, &sa, NULL)<0)
    exit(3);
    if(chdir("/")<0)exit(4);
    if(r1.rlim_max==RLIM_INFINITY) r1.rlim_max=1024;
    for(i=0;i<r1.rlim_max;i++)
    close(i);
    fd0=open("/dev/null", O_RDWR);
    fd1=dup(fd0);
    fd2=dup(fd0);

    
}

void main()
{
    t();
}