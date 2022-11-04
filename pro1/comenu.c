#include "comenu.h"
#include <ncurses.h>
void initmember() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *init;
    WINDOW *manage;
    WINDOW *exitb;
    init = newwin(1, 5, 20, 18);
    manage = newwin(1, 5, 20, 25);
    exitb = newwin(1, 5, 20, 32);
    wbkgd(init, COLOR_PAIR(1));
    wbkgd(manage, COLOR_PAIR(2));
    wbkgd(exitb, COLOR_PAIR(2));
    wprintw(init, "1co");
    wprintw(manage, "2co");
    wprintw(exitb, "3co");
    wrefresh(init);
    wrefresh(manage);
    wrefresh(exitb);
}
void manage() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *init;
    WINDOW *manage;
    WINDOW *exitb;
    init = newwin(1, 5, 20, 18);
    manage = newwin(1, 5, 20, 25);
    exitb = newwin(1, 5, 20, 32);
    wbkgd(init, COLOR_PAIR(2));
    wbkgd(manage, COLOR_PAIR(1));
    wbkgd(exitb, COLOR_PAIR(2));
    wprintw(init, "1co");
    wprintw(manage, "2co");
    wprintw(exitb, "3co");
    wrefresh(init);
    wrefresh(manage);
    wrefresh(exitb);
}
void coexit() {
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
        WINDOW *init;
        WINDOW *manage;
        WINDOW *exitb;
        init = newwin(1, 5, 20, 18);
        manage = newwin(1, 5, 20, 25);
        exitb = newwin(1, 5, 20, 32);
        wbkgd(init, COLOR_PAIR(2));
        wbkgd(manage, COLOR_PAIR(2));
        wbkgd(exitb, COLOR_PAIR(1));
        wprintw(init, "1co");
        wprintw(manage, "2co");
        wprintw(exitb, "3co");
        wrefresh(init);
        wrefresh(manage);
        wrefresh(exitb);
    }
}
int comenu() {
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    initmember();
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10)
            return stat;
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                stat = 1;
                manage();
            }
        } else if (stat == 1) {
            if (ch == KEY_RIGHT) {
                stat = 2;
                coexit();
            } else if (ch == KEY_LEFT) {
                stat = 0;
                initmember();
            }
        } else if (stat == 2) {
            if (ch == KEY_LEFT) {
                stat = 1;
                coexit();
            }
        }
    }
}
