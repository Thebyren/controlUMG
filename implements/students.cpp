#include "../headers/manager.h"
#include "../headers/window.h"
#include <algorithm>
#include <fstream>

// Datos por ingreso de boleta de inscripción:
// Fecha, Carné, Nombre del alumno, Semestre, Campus, Listado de bancos del sistema para
// pagar: (Agregue listado) Total de Inscripción: Q.800.00
void registros::estudiante::nuevo(WINDOW *win, int y, int x)
{
    SQLiteManager manager("base.db");
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    start_color();

    WINDOW *screen = newwin(y, x, 0, 0);
    wattron(screen, COLOR_PAIR(1));
    box(screen, 0, 0);
    wattroff(screen, COLOR_PAIR(1));
    Alumno a;
    a.nombre = input(screen, 3, 3, "Ingresa el nombre del alumno: ");
    a.apellido = input(screen, 5, 3, "Ingresa el apellido del alumno: ");
    a.carnet = input(screen, 7, 3, "Ingresa el carnet del alumno: ");
    a.correoElectronico = input(screen, 9, 3, "Ingresa el correo electrónico del alumno: ");
    try
    {
        std::string temp = input(screen, 11, 3, "Ingresa la edad del alumno: ");
        if (!temp.empty())
        {
            temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c)
                                      { return !std::isdigit(c); }),
                       temp.end());
            a.edad = std::stoi(temp); // Convertir la cadena a un número entero
        }
        else
        {
            a.edad = 18;
        }
    }
    catch (const std::invalid_argument &e)
    {
        mvwprintw(screen, y / 2, x / 2, "hubo un error");
        wrefresh(screen);
    }
    a.direccion = input(screen, 13, 3, "Ingresa la dirección del alumno: ");
    a.fechaNacimiento = input(screen, 15, 3, "Ingresa la fecha de nacimiento del alumno: ");
    a.profesionDiversificado = input(screen, 17, 3, "Ingresa la profesión diversificado del alumno: ");

    try
    {
        std::string temp = input(screen, 19, 3, "Ingresa el número de teléfono: ");
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
    manager.querryDataBase(manager.newAlumno(a));

    wrefresh(screen); // Actualiza la ventana
    continuar(screen, y, x, "probando cosas xd");
    clear();

    delwin(screen);
    manager.closeDataBase();
}
void registros::estudiante::eliminar(WINDOW *win, int y, int x)
{
    WINDOW *screen = newwin(y, x, 0, 0);
    SQLiteManager manager("base.db");
    std::string carnet = input(screen, 4, 4, "ingrese el carnet del estudiante a borrar: ");
    manager.querryDataBase(manager.delAlumno(carnet));
    manager.closeDataBase();
}

void registros::estudiante::imprimir(WINDOW *win, int y, int x)
{
}
