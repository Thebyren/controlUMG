#include"../headers/manager.h"
#include<chrono>
#include<thread>

void registros::boleta::nuevo(WINDOW* win, int y, int x)
{
     SQLiteManager manager("base.db");
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    start_color();

    WINDOW *screen = newwin(y, x, 0, 0);
    wattron(screen, COLOR_PAIR(1));
    box(screen, 0, 0);
    wattroff(screen, COLOR_PAIR(1));
    Boleta a;
    a.nombre = input(screen, 3,3,"ingrese el nombre del alumno: ");
    a.carnet = input(screen, 5, 3, "ingrese el carnet del alumno: " );
    a.banco = input(screen, 7,3, "ingrese el banco que eligio: ");
    a.campus = input(screen, 9, 3, "ingrese el nombre del campus eligido: ");
    a.semestre = input(screen, 11, 3, "ingrese el semestre: ");
    a.totalBoleta = 800;
    manager.querryDataBase(manager.newBoleta(a));

    wrefresh(screen); // Actualiza la ventana
    continuar(screen, y, x, "probando cosas xd");
    clear();

    delwin(screen);
    manager.closeDataBase();
}
void registros::boleta::eliminar(WINDOW* win, int y, int x)
{
    WINDOW *screen = newwin(y, x, 0, 0);
    SQLiteManager manager("base.db");
    int codigo = std::stoi(input(screen, 4, 4, "ingrese el codigo de la a borrar: "));
    manager.querryDataBase(manager.delBoleta(codigo));
    manager.closeDataBase();
    
}

void registros::boleta::imprimir(WINDOW* win, int y, int x)
{
    
}

    