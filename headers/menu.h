#ifndef MENU_H
#define MENU_H
#include <ncurses.h>
#include<vector>
#include<string>
#include<cstdarg>
#include<string.h>
class printMenu{
    public:
    printMenu(WINDOW *win, const std::vector<std::string> &choices, int yMAX, int xMAX);
    int getSelected();
    int selected;
};

class printMenuSimple{
    public:
    printMenuSimple(WINDOW *win, const std::vector<std::string> &choices, int yMAX, int xMAX);
    int getSelected();
    int selected;
};

#endif /* MENU_H*/
