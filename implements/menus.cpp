#include "../headers/manager.h"
#include "../headers/menu.h"
#include <ncurses.h>
bool flag = true;
std::vector<std::string> fun = {
    " Estudiantes ",
    " Catedraticos ",
    " Cursos ",
    " Pagos ",
    " Boletas de Inscripcion ",
    " Notas ",
    " salir "};
void (*ingresos[])(WINDOW *win, int y, int x) = {
    &registros::estudiante::nuevo,
    &registros::catedratico::nuevo,
    &registros::curso::nuevo,
    &registros::pago::nuevo,
    &registros::boleta::nuevo,
    &registros::nota::nuevo};
void (*impresiones[])(WINDOW *win, int y, int x) = {
    &registros::estudiante::imprimir,
    &registros::catedratico::imprimir,
    &registros::curso::imprimir,
    &registros::pago::imprimir,
    &registros::boleta::imprimir,
    &registros::nota::imprimir};
void (*eliminaciones[])(WINDOW *win, int y, int x) = {
    &registros::estudiante::eliminar,
    &registros::catedratico::eliminar,
    &registros::curso::eliminar,
    &registros::pago::eliminar,
    &registros::boleta::eliminar,
    &registros::nota::eliminar};
std::vector<std::string> funCopy = fun; // Hacer una copia del vector original

void menuIngresar(WINDOW *win, int y, int x)
{
    while (flag)
    {

        std::string concatString = " ingresar";
        for (std::string &s : funCopy)
        {
            if (s != " salir ")
            { // Evitar concatenar "salir"
                s = concatString + s;
            }
        }
        printMenuSimple menu(win, funCopy, y, x);
        size_t n = menu.getSelected();
        if (n == fun.size() - 1)
        {
            flag = false;
            // opcion para salir del programa
            clear();
        }
        else
        {
            (*ingresos[menu.getSelected()])(win, y, x);
        }
        funCopy = fun;
    }
    flag = true;
}
void menuImprimir(WINDOW *win, int y, int x)
{
    std::string concatString = " imprimir datos de";
    while (flag)
    {

        for (std::string &s : funCopy)
        {
            if (s != " salir ")
            { // Evitar concatenar "salir"
                s = concatString + s;
            }
        }
        printMenuSimple menu(win, funCopy, y, x);
        size_t n = menu.getSelected();
        if (n == fun.size() - 1)
        {
            // opcion para salir del programa
            flag = false;
            clear();
        }
        else
        {
            (*impresiones[menu.getSelected()])(win, y, x);
        }
        funCopy = fun;
    }
    flag = true;
}
void menuEliminar(WINDOW *win, int y, int x)
{

    std::string concatString = " borrar";
    while (flag)
    {
        for (std::string &s : funCopy)
        {
            if (s != " salir ")
            { // Evitar concatenar "salir"
                s = concatString + s;
            }
        }
        printMenuSimple menu(win, funCopy, y, x);
        size_t n = menu.getSelected();
        if (n == fun.size() - 1)
        {
            // opcion para salir del programa
            flag = false;
            clear();
        }
        else
        {
            (*eliminaciones[menu.getSelected()])(win, y, x);
        }
        funCopy = fun;
    }
    flag = true;
}

void (*menus[])(WINDOW *win, int y, int x) = {
    &menuIngresar,
    &menuEliminar,
    &menuImprimir};