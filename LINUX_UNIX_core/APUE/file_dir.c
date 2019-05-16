#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

/**
 * 实现类似于ls -l的功能
 */

extern int errno;

int getFileStat(char *filename)
{
    char cwd[1024];
    getcwd(cwd, 1024);
    //printf("当前工作目录:%s\n", cwd);
    struct stat buf;
    printf("%-20s", filename);
    if(stat(filename, &buf)<0)
    {
        printf("stat error");
        printf("%s", strerror(errno));
        exit(1);
    }
    printf("%-8d", buf.st_ino);
    if(S_ISREG(buf.st_mode))
        printf("-");
    else if(S_ISDIR(buf.st_mode))
        printf("d");
    else if(S_ISCHR(buf.st_mode))
        printf("c");
    else if(S_ISBLK(buf.st_mode))
        printf("b");
    else if(S_ISFIFO(buf.st_mode))
        printf("f");
    else if(S_ISLNK(buf.st_mode))
        printf("l");
    else
    {
        printf("?");
    }
    //printf("st_mode:%d\n", buf.st_uid);
    if(buf.st_mode&S_IRUSR)
        printf("r");
    else
        printf("-");
    if(buf.st_mode&S_IWUSR)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXUSR)
        printf("x");
    else
        printf("-");
    if(buf.st_mode&S_IRGRP)
        printf("r");
    else
        printf("-");
    if(buf.st_mode&S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXGRP)
        printf("x");
    else 
        printf("-");
    if(buf.st_mode&S_IROTH)
        printf("r");
    else 
        printf("-");
    if(buf.st_mode&S_IWOTH)
        printf("w");
    else 
        printf("-");
    if(buf.st_mode&S_IXOTH)
        printf("x");
    else 
        printf("-");    
    printf("%6d", buf.st_uid);
    printf("%6d", buf.st_gid);
    printf("%6d", buf.st_size);
    return 0;
}

int getDir(char *pathname)
{
    struct stat buf;
    DIR *dr;
    struct dirent *rdr;
    if(lstat(pathname, &buf)<0)
    {
        printf("lstat error");
        exit(1);
    }
    if(S_ISDIR(buf.st_mode)==0)     //不是目录
    {
        return getFileStat(pathname);
    }
    if((dr=opendir(pathname))==NULL)
    {
        printf("can't read this dir");
        exit(2);
    }
    chdir(pathname);        //更改当前工作目录
    while((rdr=readdir(dr))!=NULL)
    {
        if((strcmp(rdr->d_name, ".")==0) || strcmp(rdr->d_name, "..")==0)
           continue;
        getFileStat(rdr->d_name);
        printf("\n");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    getDir(argv[1]);
    //getFileStat(argv[1]);
    exit(0);
}