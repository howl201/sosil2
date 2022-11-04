#include "worker.h"
#include "pmenu.h"
#include <ncurses.h>
#include <unistd.h>
void pp1() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *p1;
    WINDOW *p2;
    WINDOW *p3;
    WINDOW *dri;
    p1 = newwin(1, 5, 20, 18);
    p2 = newwin(1, 5, 20, 25);
    p3 = newwin(1, 5, 24, 18);
    dri = newwin(1, 5, 24, 25);
    wbkgd(p1, COLOR_PAIR(1));
    wbkgd(p2, COLOR_PAIR(2));
    wbkgd(p3, COLOR_PAIR(2));
    wbkgd(dri, COLOR_PAIR(2));
    wprintw(p1, "1p");
    wprintw(p2, "2p");
    wprintw(p3, "3p");
    wprintw(dri, "driver");
    wrefresh(p1);
    wrefresh(p2);
    wrefresh(p3);
    wrefresh(dri);
}
void pp2() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *p1;
    WINDOW *p2;
    WINDOW *p3;
    WINDOW *dri;
    p1 = newwin(1, 5, 20, 18);
    p2 = newwin(1, 5, 20, 25);
    p3 = newwin(1, 5, 24, 18);
    dri = newwin(1, 5, 24, 25);
    wbkgd(p1, COLOR_PAIR(2));
    wbkgd(p2, COLOR_PAIR(1));
    wbkgd(p3, COLOR_PAIR(2));
    wbkgd(dri, COLOR_PAIR(2));
    wprintw(p1, "1p");
    wprintw(p2, "2p");
    wprintw(p3, "3p");
    wprintw(dri, "driver");
    wrefresh(p1);
    wrefresh(p2);
    wrefresh(p3);
    wrefresh(dri);
}
void pp3() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *p1;
    WINDOW *p2;
    WINDOW *p3;
    WINDOW *dri;
    p1 = newwin(1, 5, 20, 18);
    p2 = newwin(1, 5, 20, 25);
    p3 = newwin(1, 5, 24, 18);
    dri = newwin(1, 5, 24, 25);
    wbkgd(p1, COLOR_PAIR(2));
    wbkgd(p2, COLOR_PAIR(2));
    wbkgd(p3, COLOR_PAIR(1));
    wbkgd(dri, COLOR_PAIR(2));
    wprintw(p1, "1p");
    wprintw(p2, "2p");
    wprintw(p3, "3p");
    wprintw(dri, "driver");
    wrefresh(p1);
    wrefresh(p2);
    wrefresh(p3);
    wrefresh(dri);
}
void driver() {
    if (has_colors() == FALSE) {
        puts("error");
        endwin();
        return;
    } else {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
    }
    WINDOW *p1;
    WINDOW *p2;
    WINDOW *p3;
    WINDOW *dri;
    p1 = newwin(1, 5, 20, 18);
    p2 = newwin(1, 5, 20, 25);
    p3 = newwin(1, 5, 24, 18);
    dri = newwin(1, 5, 24, 25);
    wbkgd(p1, COLOR_PAIR(2));
    wbkgd(p2, COLOR_PAIR(2));
    wbkgd(p3, COLOR_PAIR(2));
    wbkgd(dri, COLOR_PAIR(1));
    wprintw(p1, "1p");
    wprintw(p2, "2p");
    wprintw(p3, "3p");
    wprintw(dri, "driver");
    wrefresh(p1);
    wrefresh(p2);
    wrefresh(p3);
    wrefresh(dri);
}
void workerselect() {
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10) {
            if (stat == 0) {
                chdir("1p");
                ppselect();
                chdir("..");
            } else if (stat == 1) {
                chdir("2p");
                ppselect();
                chdir("..");
            } else if (stat == 2) {
                chdir("3p");
                ppselect();
                chdir("..");
            } else if (stat == 3) {
                chdir("driver");

            }
        }
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                pp2();
                stat = 1;
            } else if (ch == KEY_DOWN) {
                pp3();
                stat = 2;
            }
        } else if (stat == 1) {
            if (ch == KEY_LEFT) {
                pp1();
                stat = 0;
            } else if (ch == KEY_DOWN) {
                driver();
                stat = 3;
            }
        } else if (stat == 2) {
            if (ch == KEY_UP) {
                pp1();
                stat = 0;
            } else if (ch == KEY_RIGHT) {
                driver();
                stat = 3;
            }
        } else if (stat == 3) {
            if (ch == KEY_LEFT) {
                pp3();
                stat = 2;
            } else if (ch == KEY_UP) {
                pp2();
                stat = 1;
            }
        }
    }
}
