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
    char* cwd;
    cwd = getcwd(NULL, 30);
    DIR *dirent;
 //   dirent = readdir(filename);
    printw("currunt file is %s\n",cwd);

}
void initmdir()
{
    echo();
    //remove all file
//    rmfile();
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
        initmdir();
    }
    else 
    {
        initmdir();
        clear();
        chdir("../subleader");
        initmdir();
        clear();
        chdir("../crew");
        initmdir();
        clear();
        chdir("..");
    }    
}