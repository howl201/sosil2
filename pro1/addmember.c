#include<ncurses.h>
#include"addmember.h"
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>   
#include<dirent.h>
#include<string.h>
#include<stdio.h>
void addmember()
{
    echo();
    char name[10] = {"\0"};
    char mnum[3] = {"\0"};
    int fd1 = open("membernum", O_RDWR);
    read(fd1, mnum, 3);//read member num
    int num = atoi(mnum);
    char newmnum[10] = {"\0"};
    sprintf(newmnum, "%d", num+1);//add memberfile name
    lseek(fd1, 0, SEEK_SET);
    write(fd1, newmnum, strlen(newmnum));
    close(fd1);
    int fd2 = open(mnum, O_WRONLY | O_CREAT, 0755);
    printw("member name: ");   
    getstr(name);
    write(fd2, name, 10);
    close(fd2);
}