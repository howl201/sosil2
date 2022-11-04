#include "initmenu.h"
#include <ncurses.h>
#include <stdio.h>
void initmenu1() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *co1;
    WINDOW *co2;
    WINDOW *co3;
    co1 = newwin(1, 5, 20, 18);
    co2 = newwin(1, 5, 20, 25);
    co3 = newwin(1, 5, 20, 32);
    wbkgd(co1, COLOR_PAIR(1));
    wbkgd(co2, COLOR_PAIR(2));
    wbkgd(co3, COLOR_PAIR(2));
    wprintw(co1, "1co");
    wprintw(co2, "2co");
    wprintw(co3, "3co");
    wrefresh(co1);
    wrefresh(co2);
    wrefresh(co3);
}
void initmenu2() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *co1;
    WINDOW *co2;
    WINDOW *co3;
    co1 = newwin(1, 5, 20, 18);
    co2 = newwin(1, 5, 20, 25);
    co3 = newwin(1, 5, 20, 32);
    wbkgd(co1, COLOR_PAIR(2));
    wbkgd(co2, COLOR_PAIR(1));
    wbkgd(co3, COLOR_PAIR(2));
    wprintw(co1, "1co");
    wprintw(co2, "2co");
    wprintw(co3, "3co");
    wrefresh(co1);
    wrefresh(co2);
    wrefresh(co3);
    refresh();
}
void initmenu3() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *co1;
    WINDOW *co2;
    WINDOW *co3;
    co1 = newwin(1, 5, 20, 18);
    co2 = newwin(1, 5, 20, 25);
    co3 = newwin(1, 5, 20, 32);
    wbkgd(co1, COLOR_PAIR(2));
    wbkgd(co2, COLOR_PAIR(2));
    wbkgd(co3, COLOR_PAIR(1));
    wprintw(co1, "1co");
    wprintw(co2, "2co");
    wprintw(co3, "3co");
    wrefresh(co1);
    wrefresh(co2);
    wrefresh(co3);
    refresh();
}
int initselectmenu() {
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    initmenu1();
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10)
            return stat;
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                stat = 1;
                initmenu2();
            }
        } else if (stat == 1) {
            if (ch == KEY_RIGHT) {
                stat = 2;
                initmenu3();
            } else if (ch == KEY_LEFT) {
                stat = 0;
                initmenu1();
            }
        } else if (stat == 2) {
            if (ch == KEY_LEFT) {
                stat = 1;
                initmenu2();
            }
        }
    }
}
