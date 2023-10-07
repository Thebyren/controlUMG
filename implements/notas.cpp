#include"../headers/manager.h"

void registros::nota::nuevo(WINDOW * win, int x, int y)
{
     SQLiteManager manager("base.db");
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    start_color();

    WINDOW *screen = newwin(y, x, 0, 0);
    wattron(screen, COLOR_PAIR(1));
    box(screen, 0, 0);
    wattroff(screen, COLOR_PAIR(1));
    Nota a;
    a.carnet = input(screen, 3,3,"ingrese el carnet del estudiante: ");
    a.codigoCatedratico= input(screen, 5, 3, "ingrese el codigo del catedratico:" );
    a.codigoCurso = input(screen,7, 3, "ingrese el codigo del curso");
    try
    {
        std::string temp = input(screen, 9, 3, "ingrese el punteo primer parciar: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.punteoPrimerParcial= std::stoi(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.punteoPrimerParcial = 0;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
    
try
    {
        std::string temp = input(screen, 11, 3, "ingrese el punteo segundo parcial: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.punteoSegundoParcial= std::stod(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.punteoSegundoParcial = 0;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
        
try
    {
        std::string temp = input(screen, 11, 3, "ingrese el punteo del examen final: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.examenFinal= std::stod(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.examenFinal = 0;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
        
try
    {
        std::string temp = input(screen, 11, 3, "ingrese el punteo examen extraordinario ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.examenRetrasada= std::stod(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.examenRetrasada = 0;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
    
    manager.querryDataBase(manager.newNota(a));

    wrefresh(screen); // Actualiza la ventana
    continuar(screen, y, x, "probando cosas xd");
    clear();

    delwin(screen);
    manager.closeDataBase();

}
void registros::nota::eliminar(WINDOW * win, int x, int y)
{
    
       WINDOW *screen = newwin(y, x, 0, 0);
    SQLiteManager manager("base.db");
    int codigo = std::stoi(input(screen, 4, 4, "ingrese el codigo de la a borrar: "));
    manager.querryDataBase(manager.delNota(codigo));
    manager.closeDataBase();
    
}

void registros::nota::imprimir(WINDOW * win, int x, int y)
{
    
}
