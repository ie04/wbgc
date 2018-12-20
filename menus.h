
/* 
 * File:   menus.h
 * Author: ie04
 *
 * Created on December 19, 2018, 7:49 PM
 */

#ifndef MENUS_H
#define MENUS_H
#include <ncurses.h>
void start_menu(){
    initscr();
    cbreak();
    noecho();
    printw("This is a test");
    refresh();
    getch();
    clear();
}


#endif /* MENUS_H */

