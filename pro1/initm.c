#include<ncurses.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>   
#include<dirent.h>
#include<string.h>
#include<stdio.h>
#include"initm.h"
void rmfile()
{
    char num[3] = {"\0"};
    int mnum = 0;
    int fd1 = open("membernum", O_RDONLY);
    read(fd1, num, 3);
    mnum = atoi(num);
    for(int i=0; i<mnum; i++)
    {
        char rmfile[10] = {"\0"};
        sprintf(rmfile, "%d", i);
        unlink(rmfile);
    }
    unlink("membernum");

}
void initmdir()
{
    echo();
    //remove all file
    rmfile();
    int fd1=0;
    char mnum[3] ={"\0"};
    printw("how many?: ");
    getstr(mnum);
    int num = atoi(mnum);
    fd1 = open("membernum", O_WRONLY | O_CREAT, 0755);
    write(fd1, mnum, 3);//member number write
    close(fd1);
    for(int i=0; i<num; i++)
    {
        int fd2=0;
        printw("type name: ");
        char name[10] = {"\0"};
        getstr(name);
        char fname[10] = {"\0"};
        sprintf(fname, "%d", i);
        fd2 = open(fname, O_WRONLY | O_CREAT, 0755);
        write(fd2, name, strlen(name));
        close(fd2);
    }
}
void initial()
{
    if(chdir("leader") == -1){
        printw("driver\n");
        initmdir();
    }
    else 
    {
        printw("leader\n");
        initmdir();
        clear();
        chdir("../subleader");
        printw("subleater\n");
        initmdir();
        clear();
        chdir("../crew");
        printw("crew\n");
        initmdir();
        clear();
        chdir("..");
    }    
}