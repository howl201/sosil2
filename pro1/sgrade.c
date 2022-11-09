#include"sgrade.h"
#include<ncurses.h>
void sleader()
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
    WINDOW *leader;
    WINDOW *subleader;
    WINDOW *crew;
    WINDOW *exit;
    leader = newwin(1, 5, 20, 18);
    subleader = newwin(1, 5, 20, 25);
    crew = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(leader, COLOR_PAIR(1));
    wbkgd(subleader, COLOR_PAIR(2));
    wbkgd(crew, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(leader, "leader");
    wprintw(subleader, "subleader");
    wprintw(crew, "crew");
    wprintw(exit, "exit");
    wrefresh(leader);
    wrefresh(subleader);
    wrefresh(crew);
    wrefresh(exit);
}
void ssubleader()
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
    WINDOW *leader;
    WINDOW *subleader;
    WINDOW *crew;
    WINDOW *exit;
    leader = newwin(1, 5, 20, 18);
    subleader = newwin(1, 5, 20, 25);
    crew = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(leader, COLOR_PAIR(2));
    wbkgd(subleader, COLOR_PAIR(1));
    wbkgd(crew, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(leader, "leader");
    wprintw(subleader, "subleader");
    wprintw(crew, "crew");
    wprintw(exit, "exit");
    wrefresh(leader);
    wrefresh(subleader);
    wrefresh(crew);
    wrefresh(exit);
}
void screw()
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
    WINDOW *leader;
    WINDOW *subleader;
    WINDOW *crew;
    WINDOW *exit;
    leader = newwin(1, 5, 20, 18);
    subleader = newwin(1, 5, 20, 25);
    crew = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(leader, COLOR_PAIR(2));
    wbkgd(subleader, COLOR_PAIR(2));
    wbkgd(crew, COLOR_PAIR(1));
    wbkgd(exit, COLOR_PAIR(2));
    wprintw(leader, "leader");
    wprintw(subleader, "subleader");
    wprintw(crew, "crew");
    wprintw(exit, "exit");
    wrefresh(leader);
    wrefresh(subleader);
    wrefresh(crew);
    wrefresh(exit);
}
void sexit()
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
    WINDOW *leader;
    WINDOW *subleader;
    WINDOW *crew;
    WINDOW *exit;
    leader = newwin(1, 5, 20, 18);
    subleader = newwin(1, 5, 20, 25);
    crew = newwin(1, 5, 24, 18);
    exit = newwin(1, 5, 24, 25);
    wbkgd(leader, COLOR_PAIR(2));
    wbkgd(subleader, COLOR_PAIR(2));
    wbkgd(crew, COLOR_PAIR(2));
    wbkgd(exit, COLOR_PAIR(1));
    wprintw(leader, "leader");
    wprintw(subleader, "subleader");
    wprintw(crew, "crew");
    wprintw(exit, "exit");
    wrefresh(leader);
    wrefresh(subleader);
    wrefresh(crew);
    wrefresh(exit);
}
int selectselect()
{
    int stat = 0;
    int ch;
    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        ch = getch();
        if (ch == 10) {
            if (stat == 0) {
                clear();
                return stat;
            } else if (stat == 1) {
                clear();
                return stat;
            } else if (stat == 2) {
                clear();
                return stat;
            } else if (stat == 3) {
                clear();
                break;
            }
        }
        if (stat == 0) {
            if (ch == KEY_RIGHT) {
                ssubleader();
                stat = 1;
            } else if (ch == KEY_DOWN) {
                screw();
                stat = 2;
            }
        } else if (stat == 1) {
            if (ch == KEY_LEFT) {
                sleader();
                stat = 0;
            } else if (ch == KEY_DOWN) {
                sexit();
                stat = 3;
            }
        } else if (stat == 2) {
            if (ch == KEY_UP) {
                sleader();
                stat = 0;
            } else if (ch == KEY_RIGHT) {
                sexit();
                stat = 3;
            }
        } else if (stat == 3) {
            if (ch == KEY_LEFT) {
                screw();
                stat = 2;
            } else if (ch == KEY_UP) {
                ssubleader();
                stat = 1;
            }
        }
    }
}