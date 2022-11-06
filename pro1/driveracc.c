#include "driveracc.h"
#include <ncurses.h>
void addmem() {
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
    wprintw(del, "delmem");
    wprintw(exit, "exit");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void chmem() {
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
    wprintw(del, "delmem");
    wprintw(exit, "exit");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void delmem() {
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
    wprintw(del, "delmem");
    wprintw(exit, "exit");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void driexit() {
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
    wprintw(del, "delmem");
    wprintw(exit, "exit");
    wrefresh(add);
    wrefresh(chm);
    wrefresh(del);
    wrefresh(exit);
}
void dirselect() {
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10) {
            if (stat == 3) {
                clear();
                break;
            }
        }
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                chmem();
                stat = 1;
            } else if (ch == KEY_DOWN) {
                delmem();
                stat = 2;
            }
        } else if (stat == 1) {
            if (ch == KEY_LEFT) {
                addmem();
                stat = 0;
            } else if (ch == KEY_DOWN) {
                driexit();
                stat = 3;
            }
        } else if (stat == 2) {
            if (ch == KEY_UP) {
                addmem();
                stat = 0;
            } else if (ch == KEY_RIGHT) {
                driexit();
                stat = 3;
            }
        } else if (stat == 3) {
            if (ch == KEY_LEFT) {
                delmem();
                stat = 2;
            } else if (ch == KEY_UP) {
                chmem();
                stat = 1;
            }
        }
    }
}
