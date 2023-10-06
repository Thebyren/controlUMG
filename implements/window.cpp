#include <iostream>
#include <ncurses.h>
#include <strings.h>

void continuar(WINDOW*win, int y, int x, std::string msg){
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    box(win, 0,0);
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win,y-1,(x/2)-(msg.length()/2),msg.c_str());
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);
    wgetch(win);
}

std::string input(WINDOW *win, int y, int x, const std::string &message)
{
    echo();
    wmove(win, y, x);
    wprintw(win, message.c_str());
    // Dibuja la línea horizontal para simular el campo de entrada
    wattron(win, COLOR_PAIR(8));
    mvwhline(win, y + 1, x + message.length(), ACS_S1, message.length());
    wattroff(win, COLOR_PAIR(8));
    wrefresh(win);

    std::string input;
    int ch;
    int col = x + message.length();

    while ((ch = mvwgetch(win, y, col)) != KEY_F(2))
    {
        if (ch == '\n')
        {
            break;
        }
        else if (ch == KEY_BACKSPACE || ch == 127)
        { // Tecla retroceso
            if (!input.empty())
            {
                input.pop_back();
                col--;
                // mvwaddch(win, y, col, ' '); // Borra el caracter en la pantalla
                mvwaddstr(win, y, col, "    ");
                wrefresh(win);
            }
        }
        else
        {
            input += static_cast<char>(ch);
            col++;
            wrefresh(win);
        }
    }
    noecho();
    return input;
}
