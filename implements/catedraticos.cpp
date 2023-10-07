#include "../headers/manager.h"
#include "../headers/window.h"
#include <algorithm>

void registros::catedratico::nuevo(WINDOW *win, int y, int x)
{

    SQLiteManager manager("base.db");
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    start_color();

    WINDOW *screen = newwin(y, x, 0, 0);
    wattron(screen, COLOR_PAIR(1));
    box(screen, 0, 0);
    wattroff(screen, COLOR_PAIR(1));
    Catedratico a;
    a.nombre = input(screen, 3, 3, "Ingresa el nombre del catedratico: ");
    a.apellido = input(screen, 5, 3, "Ingresa el apellido del catedratico: ");
    a.codigoCatedratico = input(screen, 7, 3, "Ingresa el codigo del catedratico: ");
    a.correoElectronico = input(screen, 9, 3, "Ingresa el correo electrónico del catedratico: ");
    a.profesion = input(screen, 11, 3, "ingrese la profesion del catedratico: ");
    a.direccion = input(screen, 13,3,"ingrese la direccion del catedratico: ");
    try
    {
        std::string temp = input(screen, 15, 3, "Ingresa el número de teléfono: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.telefono = std::stoi(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.telefono = 10101010;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
    manager.querryDataBase(manager.newCatedratico(a));

    wrefresh(screen); // Actualiza la ventana
    continuar(screen, y, x, "probando cosas xd");
    clear();

    delwin(screen);
    manager.closeDataBase();
}
void registros::catedratico::eliminar(WINDOW *win, int y, int x)
{
    WINDOW *screen = newwin(y, x, 0, 0);
    SQLiteManager manager("base.db");
    std::string carnet = input(screen, 4, 4, "ingrese el codigo del Catedratico a borrar a borrar: ");
    manager.querryDataBase(manager.delCatedratico(carnet));
    manager.closeDataBase();
}

void registros::catedratico::imprimir(WINDOW *win, int y, int x)
{
}
