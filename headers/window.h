#ifndef BFEB78CC_5D8D_4054_94D4_24600DDE6DF6
#define BFEB78CC_5D8D_4054_94D4_24600DDE6DF6
#include<iostream>
#include<strings.h>
#include<cstdarg>
#include<ncurses.h>
std::string input(WINDOW *win, int y, int x, const std::string &message);
void continuar(WINDOW*win, int y, int x, std::string mensaje);

struct pWin{
    WINDOW *win;
    int     x;
    int     y;
};

#endif /* BFEB78CC_5D8D_4054_94D4_24600DDE6DF6 */
