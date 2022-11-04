#include "initmenu.h"
#include "mainmenu.h"
#include <dirent.h>
#include <ncurses.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void makedir(int conum);
int main() {
    char co[10];
    initscr();
    refresh();
    if (opendir("./.1co") == NULL && opendir("./.2co") == NULL &&
        opendir("./.3co") == NULL) {
        int conum = initselectmenu();
        makedir(conum);
        clear();
    }
    while (1) {
        int mainstat = mainselect();
        if (mainstat == 2)
            break;
    }
//    getch();

    endwin();

    return 0;
}
void makedir(int conum) {
    char co[10];
    sprintf(co, ".%dco", conum + 1);
    mkdir(co, 0755);
    chdir(co);
    mkdir("1p", 0755);
    mkdir("2p", 0755);
    mkdir("3p", 0755);
    mkdir("driver", 0755);
    chdir("1p");
    mkdir("leader", 0755);
    mkdir("subleader", 0755);
    mkdir("crew", 0755);
    chdir("..");
    chdir("2p");
    mkdir("leader", 0755);
    mkdir("subleader", 0755);
    mkdir("crew", 0755);
    chdir("..");
    chdir("3p");
    mkdir("leader", 0755);
    mkdir("subleader", 0755);
    mkdir("crew", 0755);
    chdir("..");
}
