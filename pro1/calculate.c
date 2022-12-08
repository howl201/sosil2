#include<stdio.h>
#include<ncurses.h>
#include"calculate.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>   
#include<dirent.h>
void calculatemember()
{
    echo();
    time_t start, current;
    start = time(NULL);
    struct tm user_stime;
    int tm_day;
    double diff;
    int year, month , day;
    int difday = 0;
    char a[4] = {"\0"};
    user_stime.tm_year = 2022 - 1900;
    user_stime.tm_mon = 7 - 1;
    user_stime.tm_mday = 1;
    user_stime.tm_hour = 0;
    user_stime.tm_min = 0;
    user_stime.tm_sec = 0;
    user_stime.tm_isdst = 0;
    start = mktime(&user_stime);

    chdir("1p/leader");//1pp
    int fd1 = open("membernum", O_RDONLY);
    char p1l[3] = {"\0"};
    read(fd1, p1l, 2);
    int p1lnum = atoi(p1l);
    int* p1Leader = (int *)malloc(p1lnum * sizeof(int));
    char filename[8] = {"\0"};
    //printf("%d\n", p1lnum);
    int i=0;
    //printf("%d\n", i);
    for(i=0; i<p1lnum; i++)
    {
        sprintf(filename, "%d", i);
        p1Leader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    //printw("1p leader\n");
    chdir("../subleader");
    int fd2 = open("membernum", O_RDONLY);
    char p1sl[3] = {"\0"};
    read(fd2, p1sl, 2);
    int p1slnum = atoi(p1sl);
    int* p1SubLeader = (int *)malloc(p1slnum * sizeof(int));
    for(int i=0; i<p1slnum; i++)
    {
        sprintf(filename, "%d", i);
        p1SubLeader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    //printw("1p sleader\n");
    chdir("../crew");
    int fd3 = open("membernum", O_RDONLY);
    char p1c[3] = {"\0"};
    read(fd3, p1c, 2);
    int p1cnum = atoi(p1c);
    int* p1Crew = (int *)malloc(p1cnum * sizeof(int));
    for(int i=0; i<p1cnum; i++)
    {
        sprintf(filename, "%d", i);
        p1Crew[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../..");
    //printw("1p crew\n");

    chdir("2p/leader");//2pp
    int fd4 = open("membernum", O_RDONLY);
    char p2l[3] = {"\0"};
    read(fd4, p2l, 2);
    int p2lnum = atoi(p2l);
    int* p2Leader = (int *)malloc(p2lnum * sizeof(int));
    for(int i=0; i<p2lnum; i++)
    {
        sprintf(filename, "%d", i);
        p2Leader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../subleader");
    //printw("2p leader\n");
    int fd5 = open("membernum", O_RDONLY);
    char p2sl[3] = {"\0"};
    read(fd5, p2sl, 2);
    int p2slnum = atoi(p2sl);
    int* p2SubLeader = (int *)malloc(p2slnum * sizeof(int));
    for(int i=0; i<p2slnum; i++)
    {
        sprintf(filename, "%d", i);
        p2SubLeader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../crew");
    //printw("2p sleader\n");
    int fd6 = open("membernum", O_RDONLY);
    char p2c[3] = {"\0"};
    read(fd6, p2c, 2);
    int p2cnum = atoi(p2c);
    int* p2Crew = (int *)malloc(p2cnum * sizeof(int));
    for(int i=0; i<p2cnum; i++)
    {
        sprintf(filename, "%d", i);
        p2Crew[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../..");
    //printw("2p crew\n");
    chdir("3p/leader");//3pp
    int fd7 = open("membernum", O_RDONLY);
    char p3l[3] = {"\0"};
    read(fd7, p3l, 2);
    int p3lnum = atoi(p3l);
    int* p3Leader = (int *)malloc(p3lnum * sizeof(int));
    for(int i=0; i<p3lnum; i++)
    {
        sprintf(filename, "%d", i);
        p3Leader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    //printw("3p leader\n");
    chdir("../subleader");
    int fd8 = open("membernum", O_RDONLY);
    char p3sl[3] = {"\0"};
    read(fd8, p3sl, 2);
    int p3slnum = atoi(p3sl);
    int* p3SubLeader = (int *)malloc(p3slnum * sizeof(int));
    for(int i=0; i<p3slnum; i++)
    {
        sprintf(filename, "%d", i);
        p3SubLeader[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../crew");
    //printw("3p sublea\n");
    int fd9 = open("membernum", O_RDONLY);
    char p3c[3] = {"\0"};
    read(fd9, p3c, 2);
    int p3cnum = atoi(p3c);
    int* p3Crew = (int *)malloc(p3cnum * sizeof(int));
    for(int i=0; i<p3cnum; i++)
    {
        sprintf(filename, "%d", i);
        p3Crew[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("../..");
    //printw("3p crew\n");
    chdir("driver");
    int fd10 = open("membernum", O_RDONLY);
    char di[3] = {"\0"};
    read(fd10, di, 2);
    int dirnum = atoi(di);
    int* Driver = (int *)malloc(dirnum * sizeof(int));
    for(int i=0; i<dirnum; i++)
    {
        sprintf(filename, "%d", i);
        Driver[i] = open(filename, O_RDONLY);
        memset(filename, 0, 3);
    }
    chdir("..");

    while(1)
    {
        
        printw("year: ");
        getstr(a);
        year = atoi(a);
        memset(a, 0, 4);
        printw("month: ");
        getstr(a);
        month = atoi(a);
        memset(a, 0, 4);
        printw("day: ");
        getstr(a);
        day = atoi(a);
        memset(a, 0, 4);
        if(year == 0 && month == 0 && day == 0)
            break;
        user_stime.tm_year = year - 1900;
        user_stime.tm_mon = month - 1;
        user_stime.tm_mday = day;
        user_stime.tm_hour = 0;
        user_stime.tm_min = 0;
        user_stime.tm_sec = 0;
        user_stime.tm_isdst = 0;
        current = mktime(&user_stime);
        diff = difftime(current, start);
        difday = diff/(60*60*24);
        printw("%d\n", difday);
        int rightday = 0;
        // if((difday%7) != 0)
        // {
        //     printw("wrong day\n");
        // }
        if(1){
            if(difday/7%3 != 0)
            {
                printw("different co\n");
            }
            else{
                int weekday = difday/7/3/3;
                if(difday/7/3%3 == 0)
                {
                    printw("1p\n");
                    int weekleader = weekday%p1lnum;
                    int weeksubleader = weekday%p1slnum;
                    int weekcrew = weekday%(3 * p1cnum);
                    int weekdriver = (difday/7/3)%dirnum;
                    char name[10] = {"\0"};
                    read(p1Leader[weekleader], name, 10);
                    printw("Leader: %s\n", name);
                    lseek(p1Leader[weekleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    read(p1SubLeader[weeksubleader], name, 10);
                    printw("SubLeader: %s\n", name);
                    lseek(p1SubLeader[weeksubleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    printw("Crew: ");
                    for(int j=0; j<3; j++)
                    {
                        read(p1Crew[(weekcrew+j)%p1cnum], name, 10);
                        printw("%s ", name);
                        lseek(p1Crew[(weekcrew+j)%p1cnum], 0, SEEK_SET);
                        memset(name, 0, 10);
                    }
                    printw("\n");
                    read(Driver[weekdriver], name, 10);
                    printw("Driver: %s", name);
                    lseek(Driver[weekdriver], 0, SEEK_SET);
                    memset(name, 0, 10);
                }
                else if(difday/7/3%3 == 1)
                {
                    printf("2p\n");
                    int weekleader = weekday%p2lnum;
                    int weeksubleader = weekday%p2slnum;
                    int weekcrew = weekday%(3 * p2cnum);
                    int weekdriver = (difday/7/3)%dirnum;
                    char name[10] = {"\0"};
                    read(p2Leader[weekleader], name, 10);
                    printw("Leader: %s\n", name);
                    lseek(p2Leader[weekleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    read(p2SubLeader[weeksubleader], name, 10);
                    printw("SubLeader: %s\n", name);
                    lseek(p2SubLeader[weeksubleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    printw("Crew: ");
                    for(int j= 0; j<3; j++)
                    {
                        read(p2Crew[(weekcrew+j)%p1cnum], name, 10);
                        printw("%s ", name);
                        lseek(p2Crew[(weekcrew+j)%p1cnum], 0, SEEK_SET);
                        memset(name, 0, 10);
                    }
                    printw("\n");
                    read(Driver[weekdriver], name, 10);
                    printw("Driver: %s", name);
                    lseek(Driver[weekdriver], 0, SEEK_SET);
                    memset(name, 0, 10);
                    
                }
                else if (difday/7/3%3 == 2)
                {
                    printw("3p\n");
                    int weekleader = weekday%p3lnum;
                    int weeksubleader = weekday%p3slnum;
                    int weekcrew = weekday%(3 * p3cnum);
                    int weekdriver = (difday/7/3)%dirnum;
                    char name[10] = {"\0"};
                    read(p3Leader[weekleader], name, 10);
                    printw("Leader: %s\n", name);
                    lseek(p3Leader[weekleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    read(p3SubLeader[weeksubleader], name, 10);
                    printw("SubLeader: %s\n", name);
                    lseek(p3SubLeader[weeksubleader], 0, SEEK_SET);
                    memset(name, 0, 10);
                    printw("Crew: ");
                    for(int j=0; j<3; j++)
                    {
                        read(p3Crew[(weekcrew+j)%p1cnum], name, 10);
                        printw("%s ", name);
                        lseek(p3Crew[(weekcrew+j)%p1cnum], 0, SEEK_SET);
                        memset(name, 0, 10);
                    }
                    printw("\n");
                    read(Driver[weekdriver], name, 10);
                    printw("Driver: %s\n", name);
                    lseek(Driver[weekdriver], 0, SEEK_SET);
                    memset(name, 0, 10);
                }
            }
        }
        getch();
        clear();
    }
}