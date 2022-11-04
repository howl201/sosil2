#include"pmenu.h"
#include<ncurses.h>
void pinit()
{
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *initp;
    WINDOW *managep;
    WINDOW *exitp;
    initp = newwin(1, 5, 20, 18);
    managep = newwin(1, 5, 20, 25);
    exitp = newwin(1, 5, 20, 32);
    wbkgd(initp, COLOR_PAIR(1));
    wbkgd(managep, COLOR_PAIR(2));
    wbkgd(exitp, COLOR_PAIR(2));
    wprintw(initp, "init");
    wprintw(managep, "manage");
    wprintw(exitp, "exit");
    wrefresh(initp);
    wrefresh(managep);
    wrefresh(exitp);
}

void pmanage()
{
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *initp;
    WINDOW *managep;
    WINDOW *exitp;
    initp = newwin(1, 5, 20, 18);
    managep = newwin(1, 5, 20, 25);
    exitp = newwin(1, 5, 20, 32);
    wbkgd(initp, COLOR_PAIR(2));
    wbkgd(managep, COLOR_PAIR(1));
    wbkgd(exitp, COLOR_PAIR(2));
    wprintw(initp, "init");
    wprintw(managep, "manage");
    wprintw(exitp, "exit");
    wrefresh(initp);
    wrefresh(managep);
    wrefresh(exitp);
}
void pexit()
{
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *initp;
    WINDOW *managep;
    WINDOW *exitp;
    initp = newwin(1, 5, 20, 18);
    managep = newwin(1, 5, 20, 25);
    exitp = newwin(1, 5, 20, 32);
    wbkgd(initp, COLOR_PAIR(2));
    wbkgd(managep, COLOR_PAIR(2));
    wbkgd(exitp, COLOR_PAIR(1));
    wprintw(initp, "init");
    wprintw(managep, "manage");
    wprintw(exitp, "exit");
    wrefresh(initp);
    wrefresh(managep);
    wrefresh(exitp);
}
void ppselect()
{
    int stat=0;
    int ch;
    keypad(stdscr, TRUE);
    pinit();
    noecho();
    while(1)
    {
        ch = getch();
        if(ch == 10)
        {
            if(stat == 0)
            {
                break;
            }
        }
        else if(stat == 0)
        {
            if(ch == KEY_RIGHT)
            {
                stat = 1;
                pmanage();
            }
        }
        else if(stat == 1)
        {
            if(ch == KEY_RIGHT)
            {
                stat = 2;
                pexit();
            }
            else if(ch == KEY_LEFT)
            {
                stat = 0;
                pinit();
            }
        }
        else if(stat == 2)
        {
            if(ch == KEY_LEFT)
            {
                stat = 1;
                pmanage();
            }
        }
    }
}