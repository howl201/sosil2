#include "mainmenu.h"
#include <ncurses.h>
void mainworker() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *worker;
    WINDOW *print;
    WINDOW *exit;
    worker = newwin(1, 8, 20, 18);
    print = newwin(1, 8, 20, 28);
    exit = newwin(1, 8, 20, 38);
    wbkgd(worker, COLOR_PAIR(1));
    wbkgd(print, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(worker, "worker");
    wprintw(print, "print");
    wprintw(exit, "exit");
    wrefresh(worker);
    wrefresh(print);
    wrefresh(exit);
}
void mainprint() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *worker;
    WINDOW *print;
    WINDOW *exit;
    worker = newwin(1, 8, 20, 18);
    print = newwin(1, 8, 20, 28);
    exit = newwin(1, 8, 20, 38);
    wbkgd(worker, COLOR_PAIR(2));
    wbkgd(print, COLOR_PAIR(1));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(worker, "worker");
    wprintw(print, "print");
    wprintw(exit, "exit");
    wrefresh(worker);
    wrefresh(print);
    wrefresh(exit);
}
void mainexit() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *worker;
    WINDOW *print;
    WINDOW *exit;
    worker = newwin(1, 8, 20, 18);
    print = newwin(1, 8, 20, 28);
    exit = newwin(1, 8, 20, 38);
    wbkgd(worker, COLOR_PAIR(2));
    wbkgd(print, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(1));
    wprintw(worker, "worker");
    wprintw(print, "print");
    wprintw(exit, "exit");
    wrefresh(worker);
    wrefresh(print);
    wrefresh(exit);
}
int mainselect() {
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10)
            return stat;
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                stat = 1;
                mainprint();
            }
        } else if (stat == 1) {
            if (ch == KEY_RIGHT) {
                stat = 2;
                mainexit();
            } else if (ch == KEY_LEFT) {
                stat = 0;
                mainworker();
            }
        } else if (stat == 2) {
            if (ch == KEY_LEFT) {
                stat = 1;
                mainprint();
            }
        }
    }
}
