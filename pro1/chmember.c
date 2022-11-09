#include "chmember.h"
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>   
#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include <ncurses.h>
void changemem()
{
    echo();
    int fd1 = open("membernum", O_RDONLY);
    char cnum[3] = {"\0"};
    read(fd1, cnum, 3);
    int num = atoi(cnum);
    for(int i=0; i<num; i++)
    {
        char filename[2] = {"\0"};
        sprintf(filename, "%d", i);
        int fd2 = open(filename, O_RDONLY);
        char fileent[10] = {"\0"};
        read(fd2, fileent, 10);
        printw("%d: %s\n", i, fileent);
        close(fd2);
    }
    char cn[3] = {"\0"};
    printw("change memvber number: ");
    getstr(cn);
    if(atoi(cn) >= num)
    {
        printw("error\n");
        return;
    }
    else 
    {
        int fd3 = open(cn, O_WRONLY);
        lseek(fd3, 0, SEEK_SET);
        char name[10] = {"\0"};
        printw("name: ");
        getstr(name);
        write(fd3, name, 10);
        close(fd3);
        clear();
    }
}