#include "../headers/manager.h"
#include "../headers/window.h"
#include <ncurses.h>
void menuEstudiante(WINDOW* win, int y,int x){

}
void menuCatedratico(WINDOW* win, int y,int x){

}
void menuNota (WINDOW* win, int y,int x){

}
void menuPago(WINDOW* win, int y,int x){

}
void menuCurso(WINDOW* win, int y,int x){

}
void menuBoleta(WINDOW* win, int y,int x){

}

void (*menus[])(WINDOW* win, int y, int x) = {
    &menuBoleta,
    &menuEstudiante,
    &menuCurso,
    &menuCatedratico,
    &menuNota,
    &menuPago
};