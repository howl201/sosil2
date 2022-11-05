#include "driveracc.h"
#include <ncurses.h>
void addmem()
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
    WINDOW *add;
    WINDOW *chm;
    WINDOW *del;
    WINDOW *exit;
    add = newwin(1, 5, 20, 18);
    chm = newwin(1, 5, 20, 25);
    del = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(add, COLOR_PAIR(1));
    wbkgd(chm, COLOR_PAIR(2));
    wbkgd(del, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(add, "add");
    wprintw(chm, "chm");
    wprintw(del, "3p");
    wprintw(exit, "driver");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void chmem()
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
    WINDOW *add;
    WINDOW *chm;
    WINDOW *del;
    WINDOW *exit;
    add = newwin(1, 5, 20, 18);
    chm = newwin(1, 5, 20, 25);
    del = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(add, COLOR_PAIR(2));
    wbkgd(chm, COLOR_PAIR(1));
    wbkgd(del, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(add, "add");
    wprintw(chm, "chm");
    wprintw(del, "3p");
    wprintw(exit, "driver");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void delmem()
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
    WINDOW *add;
    WINDOW *chm;
    WINDOW *del;
    WINDOW *exit;
    add = newwin(1, 5, 20, 18);
    chm = newwin(1, 5, 20, 25);
    del = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(add, COLOR_PAIR(2));
    wbkgd(chm, COLOR_PAIR(2));
    wbkgd(del, COLOR_PAIR(1));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(add, "add");
    wprintw(chm, "chm");
    wprintw(del, "3p");
    wprintw(exit, "driver");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void exit()
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
    WINDOW *add;
    WINDOW *chm;
    WINDOW *del;
    WINDOW *exit;
    add = newwin(1, 5, 20, 18);
    chm = newwin(1, 5, 20, 25);
    del = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(add, COLOR_PAIR(2));
    wbkgd(chm, COLOR_PAIR(2));
    wbkgd(del, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(1));
    wprintw(add, "add");
    wprintw(chm, "chm");
    wprintw(del, "3p");
    wprintw(exit, "driver");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void dirselect();