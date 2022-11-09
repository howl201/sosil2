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
        int fileent[10] = {"\0"};
        read(fd2, fileent, 10);
        printw("%s\n", fileent);
        close(fd2);
    }
}