#include "headers/main.h"

void load(){
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    noecho();
    WINDOW* load = newwin(ventana.y, ventana.x, 0,0);
    box(load, 0,0);
    for(size_t i =0; i<banner.size(); i++){
        mvwprintw(load, (ventana.y/2)-(banner.size()/2)+i, (ventana.x/2)-(banner[1].size()/2),"%s", banner[i].c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        wrefresh(load);
    }
    for(size_t i =0; i<banner.size(); i++){
        wattron(load, COLOR_PAIR(4));
        mvwprintw(load, (ventana.y/2)-(banner.size()/2)+i, (ventana.x/2)-(banner[1].size()/2),"%s", banner[i].c_str());
        wattroff(load, COLOR_PAIR(4));
        wrefresh(load);
    }
    wrefresh(load);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    delwin(
    load);
    echo();
}
int main()
{
    start();
    load();
    box(stdscr, 0, 0);
    while (activo)
    {

        printMenu menu(stdscr, inicio, ventana.y, ventana.x);

        if (menu.getSelected() == 2)
        {
            // opcion para salir del programa
            activo = false;
        }
        if(menu.getSelected() == 1){
            (*funAdministracion[1])();
        }
        if (menu.getSelected() == 0)
        {
            (*funAdministracion[0])();
        }
    }
    end();
    return 0;
}
