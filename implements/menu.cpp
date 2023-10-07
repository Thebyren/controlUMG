#include "../headers/menu.h"
printMenu::printMenu(WINDOW *win, const std::vector<std::string> &choices, int yMAX, int xMAX)
{
    selected = 0;
    int choice;
    WINDOW *titulo = newwin(yMAX / 3, xMAX - 10, 1, 5);
    WINDOW *creditos = newwin(yMAX / 3, xMAX - 10, 4 + yMAX / 2, 4);
    keypad(win, true);
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(6, COLOR_BLACK, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_RED);
    init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(10, COLOR_YELLOW, COLOR_BLACK);
    init_pair(12, COLOR_RED, COLOR_BLACK);

    const std::string aviso = " use las flechas del teclado para desplazarse, use enter para seleccionar";
    while (1)
    {
        werase(win); // Borrar el contenido de la ventana
        box(win, 0, 0);
        box(titulo, 0, 0);
        for (size_t i = 1; i < 1 + choices.size(); i++)
        {

            box(titulo, 0, 0);
            if (i - 1 == selected)
                wattron(win, COLOR_PAIR(i));
            box(win, 0, 0);
            mvwprintw(win, ((yMAX / 2) - choices.size()) + i, (xMAX / 2) - (choices[i - 1].length() / 2), choices[i - 1].c_str());
            wattroff(win, COLOR_PAIR(i));

            wattron(win, COLOR_PAIR(7));

            mvwprintw(win, yMAX - 1, (xMAX / 2) - (aviso.length() / 2), aviso.c_str());
            wattroff(win, COLOR_PAIR(7));
        }

        box(titulo, 0, 0);
        wrefresh(win);
        wattron(creditos, COLOR_PAIR(12));
        box(creditos, 0, 0);
        std::string integrante1 = "byron yobani escobar quinonez";
        std::string integrante2 = "kein eduardo salguero monzon";
        std::string integrante3 = "victor daniel sosa lopez";
        std::string integrante4 = "luis alejandro jimenes medrano";
        std::string integrante5 = "byron rene pastor flores";
        std::string integrante6 = "kevin emanol medrano castillo";
        mvwprintw(creditos, 3, -3 + (xMAX / 2) - (integrante1.size() / 2), integrante1.c_str());
        mvwprintw(creditos, 4, -3 + (xMAX / 2) - (integrante2.size() / 2), integrante2.c_str());
        mvwprintw(creditos, 5, -3 + (xMAX / 2) - (integrante3.size() / 2), integrante3.c_str());
        mvwprintw(creditos, 6, -3 + (xMAX / 2) - (integrante4.size() / 2), integrante4.c_str());
        mvwprintw(creditos, 7, -3 + (xMAX / 2) - (integrante5.size() / 2), integrante5.c_str());
        mvwprintw(creditos, 8, -3 + (xMAX / 2) - (integrante6.size() / 2), integrante6.c_str());
        wattroff(creditos, COLOR_PAIR(12));
        wrefresh(creditos);

        wattron(titulo, COLOR_PAIR(10));


        std::string mariano1 = "           o                     o     |         |              ";
        std::string mariano2 = ".  . .--.   .    . .-. .--..--.  .  .-.| .-.  .-.|              ";
        std::string mariano3 = "|  | |  |  | \\  / (.-' |   `--.  | (   |(   )(   |             ";
        std::string mariano4 = "`--` '  '  '  `'   `--'    `--'  '  `-'` `-'` `-'`-             ";
        std::string mariano5 = "                                               .                ";
        std::string mariano6 = "                 o                             |                ";
        std::string mariano7 = ".--.--. .-.  .-- .  .-.  .--. .-.    .-.. .-.  |.    . .-. ---. ";
        std::string mariano8 = "|  |  |(   ) |   | (   ) |  |(   )  (   |(   ) | \\  / (.-'  .' ";
        std::string mariano9 = "'  '  ` `-'` '   '  `-'` '  ` `-'    `-`| `-'` `  `'   `--''--- ";
        std::string mariano10= "                                     ._.'                       ";

        mvwprintw(titulo, 1, (xMAX / 2) - (5 + mariano9.length() / 2), mariano1.c_str());
        mvwprintw(titulo, 2, (xMAX / 2) - (5 + mariano9.length() / 2), mariano2.c_str());
        mvwprintw(titulo, 3, (xMAX / 2) - (5 + mariano9.length() / 2), mariano3.c_str());
        mvwprintw(titulo, 4, (xMAX / 2) - (5 + mariano9.length() / 2), mariano4.c_str());
        mvwprintw(titulo, 5, (xMAX / 2) - (5 + mariano9.length() / 2), mariano5.c_str());
        mvwprintw(titulo, 6, (xMAX / 2) - (5 + mariano9.length() / 2), mariano6.c_str());
        mvwprintw(titulo, 7, (xMAX / 2) - (5 + mariano9.length() / 2), mariano7.c_str());
        mvwprintw(titulo, 8, (xMAX / 2) - (5 + mariano9.length() / 2), mariano8.c_str());
        mvwprintw(titulo, 9, (xMAX / 2) - (5 + mariano9.length() / 2), mariano9.c_str());
        mvwprintw(titulo, 10, (xMAX / 2) - (5 + mariano9.length() / 2), mariano10.c_str());

        wattroff(titulo, COLOR_PAIR(10));
        wrefresh(titulo);

        choice = wgetch(win);
        switch (choice)
        {
        case KEY_UP:
            selected--;
            if (selected < 0)
                selected = 0;
            break;
        case KEY_DOWN:
            selected++;
            if (selected >= choices.size())
                selected = choices.size() - 1;
            break;
        default:
            break;
        }

        if (choice == 10) // Enter
            break;
    }
}
int printMenu::getSelected()
{
    return selected;
}
printMenuSimple::printMenuSimple(WINDOW *win, const std::vector<std::string> &choices, int yMAX, int xMAX)
{
    selected = 0;
    int choice;
    keypad(win, true);
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(6, COLOR_BLACK, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_RED);
    init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(10, COLOR_YELLOW, COLOR_BLACK);
    init_pair(12, COLOR_RED, COLOR_BLACK);

    const std::string aviso = " use las flechas del teclado para desplazarse, use enter para seleccionar";
    while (1)
    {
        werase(win); // Borrar el contenido de la ventana
        box(win, 0, 0);
        for (size_t i = 1; i < 1 + choices.size(); i++)
        {

            if (i - 1 == selected)
                wattron(win, COLOR_PAIR(i));
            box(win, 0, 0);
            mvwprintw(win, ((yMAX / 2) - choices.size()) + i, (xMAX / 2) - (choices[i - 1].length() / 2), choices[i - 1].c_str());
            wattroff(win, COLOR_PAIR(i));
            wattron(win, COLOR_PAIR(7));

            mvwprintw(win, yMAX - 1, (xMAX / 2) - (aviso.length() / 2), aviso.c_str());
            wattroff(win, COLOR_PAIR(7));
        }

        wrefresh(win);
        choice = wgetch(win);
        switch (choice)
        {
        case KEY_UP:
            selected--;
            if (selected < 0)
                selected = 0;
            break;
        case KEY_DOWN:
            selected++;
            if (selected >= choices.size())
                selected = choices.size() - 1;
            break;
        default:
            break;
        }

        if (choice == 10) // Enter
            break;
    }
}
int printMenuSimple::getSelected()
{
    return selected;
}
