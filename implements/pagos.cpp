#include"../headers/manager.h"


void registros::pago::nuevo(WINDOW * win, int y, int x)
{
      SQLiteManager manager("base.db");
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    start_color();

    WINDOW *screen = newwin(y, x, 0, 0);
    wattron(screen, COLOR_PAIR(1));
    box(screen, 0, 0);
    wattroff(screen, COLOR_PAIR(1));
    Pago a;
    a.nombrePago = input(screen, 3,3,"ingrese el proposito del pago: ");
    try
    {
        std::string temp = input(screen, 15, 3, "Ingresa el monto del pago: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.cuotaPago= std::stoi(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.cuotaPago = 10101010;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
    manager.querryDataBase(manager.newPago(a));

    wrefresh(screen); // Actualiza la ventana
    continuar(screen, y, x, "probando cosas xd");
    clear();

    delwin(screen);
    manager.closeDataBase();

}
void registros::pago::eliminar(WINDOW * win, int y, int x)
{
    
    
}

void registros::pago::imprimir(WINDOW * win, int y, int x)
{
    
}
