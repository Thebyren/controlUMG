#ifndef MAIN_H
#define MAIN_H

// librerias utilizadas no propias
#include <ncurses.h>
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

// librerias propias del proyecto
#include "managerData.h"
#include "window.h"
#include "manager.h"
#include "menu.h"

// variables utilizadas
std::string name = "defect1";
std::string pass = "defect2";
std::string pas2 = "defect3";
pWin ventana;
bool activo = TRUE;
std::string flag;
std::vector<administracion::user> autorizados;
std::vector<std::string> inicio = {
    " login ",
    " create new user ",
    " salir "};
std::vector<std::string> dataAdmin = {
    " datos de boleta de inscripcion ",
    " alumnos ",
    " cursos",
    " catedraticos ",
    " notas ",
    " pagos",
    " salir "};

//banner


std::vector<std::string> banner = {
"                            ********#                           ",
"                      *++*##*##-##*###*+++#                     ",
"                  *++##---##*:=.#+:+#.#.#=#*+*                  ",
"                +*##.##.*-*#=+*=*+*:=--#*:##:##+*               ",
"              +**:-#-=.+###**+++++++*###+++-=#=:#+*             ",
"            +**#-=#:###++###############+*##==+:+##+*           ",
"          *+#*#.+**#+*#######@@@@@####+####+*#+#::#**+          ",
"         *+#::.:##+*###############%-=:..%###**#=+.###+         ",
"        ***.##:#*+#############***##.::-:.#####+####++#+        ",
"       #+#-.*+#**############......:...*########+##*##-#+       ",
"       +#-=#*#*############+........%############+#=####**      ",
"      **+:.:-#+###########......-...+#############+##-.*#+      ",
"      +#-*###+###########..=-.*.......############*#=#***+#     ",
"      +#..=*#+###########............-#############+######+     ",
"      +#-==-#+###########-....:.%%...:%############+#*+.:#*     ",
"      +#*#=-#+#############....###....-############+##*+-#*     ",
"      +#*.**#+#############*...%#*.:#...%##########*-..:***     ",
"      **#####*###########+.....##:.###*...%%######+#+**:#+      ",
"       +#*#*:#+#######*.....####%....#%**########**---=+#+      ",
"       ****####+##*:..-.:=-:....-................+####-#+       ",
"        +*######+...-.=...::........:..........:*######**       ",
"         +###..##*-..=.:+#=-=+-++-+.--*=-:....=###.:##**        ",
"          **#######+-.*@........::......+%-:=*#######+*         ",
"           *+####.=+##+:.*#=+--....=++*..-+##.*#####+           ",
"             +*#-#=##.###*+=:.......:=+*#=*##=*-##+*            ",
"               ++###.#*##.#==*######-+#.+#.*-*##+*              ",
"                 *+*#*#++.##.#*=*#+.=:#:#.###++                 ",
"                    *++*###+=#=--#-+**###*+**                   ",
"                         *++++++++++++*%                        "};

// funciones
void start()
{
    autorizados.push_back({"name", "pass"});
    initscr();
    getmaxyx(stdscr, ventana.y, ventana.x);
    box(stdscr, 0, 0);
    start_color();
}

void end()
{
    wclear(stdscr);
    refresh();
    wdeleteln(stdscr);
}

void (*funAdministracion[])() = {
    administracion::login,
    administracion::newUser};

bool managment(WINDOW *win, int y, int x)
{
    bool admin = true;
    while (admin)
    {
        printMenuSimple menu(win, dataAdmin, y, x);
        size_t n = menu.getSelected();
        //(*elecciones[menu.getSelected()])();
        if ( n == dataAdmin.size() - 1)
        {
            // opcion para salir del programa
            admin = false;
            clear();
            return false;
        }
    }
    return false;
    clear();
}
void administracion::newUser()
{
    clear();
    std::string key = input(stdscr, 3, 3, "ingrese la llave de seguridad");
    if (key != "1234")
    {
        continuar(stdscr, ventana.y, ventana.x, "acceso no autorizado");
    }
    else
    {
        while (pass != pas2)
        {
            name = input(stdscr, 5, 3, "ingrese su usuario: ");
            pass = input(stdscr, 7, 3, "ingrese su ingrese la contrasenia: ");
            pas2 = input(stdscr, 9, 3, "confirme su contrasenia ");
        }
        autorizados.push_back({name, pass});
    }
}
void administracion::login()
{
    clear();
    name = input(stdscr, 3, 3, "ingrese su usuario: ");
    pass = input(stdscr, 5, 3, "ingrese su ingrese la contrasenia: ");
    bool autorizado = false;
    for (const auto &user : autorizados)
    {
        if (name == user.name || pass == user.pass)
        {
            autorizado = true;
        }
    }
    if (!autorizado)
    {
        mvwprintw(stdscr, 7, 3, "usuario o contrasenia invalidos");
        continuar(stdscr, ventana.y, ventana.x, "presione enter para continuar");
    }
    else{
        mvwprintw(stdscr, 7, 3, "ingreso exitoso");
        managment(stdscr, ventana.y, ventana.x);
    }
}


#endif /*MAIN_H*/