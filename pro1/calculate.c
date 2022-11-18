#include<stdio.h>
#include<ncurses.h>
#include"calculate.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
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
    start = mktime(&user_stime);
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
        current = mktime(&user_stime);
        diff = difftime(current, start);
        difday = diff/(60*60*24);
        printw("%d", difday);
    }
}