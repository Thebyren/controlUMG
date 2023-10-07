#include"../headers/manager.h"
#include<chrono>
#include<thread>

void registros::boleta::nuevo(WINDOW* win, int y, int x)
{
    
}
void registros::boleta::eliminar(WINDOW* win, int y, int x)
{
    mvwprintw(win, 5,5,"eliminando boleta ");
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
}

void registros::boleta::imprimir(WINDOW* win, int y, int x)
{
    
}

    