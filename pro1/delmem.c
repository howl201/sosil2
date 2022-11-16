#include "delmem.h"
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>   
#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include <ncurses.h>
void deletemem()
{
    echo();
    int fd1 = open("membernum", O_RDONLY);
    char cnum[3] = {"\0"};
    read(fd1, cnum, 3);
    close(fd1);
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
    printw("delete member number: ");
    getstr(cn);
    if(atoi(cn) >= num)
    {
        printw("error\n");
        return;
    }
    else 
    {
        remove(cn);
        int start = atoi(cn);
        for(int i = start; i<num - 1; i++)
        {
            char filename[3] = {"\0"};
            char newname[3] = {"\0"};
            sprintf(filename, "%d", i+1);
            sprintf(newname, "%d", i);
            rename(filename, newname);
            
        }
        char newnum[3] = {"\0"};
        sprintf(newnum, "%d", num-1);
        int fd3 = open("membernum", O_WRONLY);
        lseek(fd3, 0, SEEK_SET);
        write(fd3, newnum, 3);
        close(fd3);
    }
    

}