#ifndef MANAGER_H
#define MANAGER_H
#pragma once
#include <string.h>
#include <iostream>
#include <ncurses.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include "managerData.h"
#include "window.h"
// clases principales
class registros
{
public:
    class estudiante
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
    class catedratico
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
    class curso
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
    class nota
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
    class pago
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
    class boleta
    {
    public:
        static void nuevo(WINDOW * win, int y, int x);
        static void eliminar(WINDOW * win, int y, int x);
        static void imprimir(WINDOW * win, int y, int x);
    };
};
class administracion
{
private:
    bool acceso = false;

public:
    struct user
    {
        std::string name;
        std::string pass;
    };
    static void login();
    static void newUser();
};
extern void (*menus[])(WINDOW*win, int y, int x);
// arrays de punteros
extern void (*impresiones[])(WINDOW*win, int y, int x);

// Para Catedráticos
extern void (*eliminaciones[])(WINDOW*win, int y, int x);

// Para Cursos
extern void (*ingresos[])(WINDOW*win, int y, int x);


extern void (*funAdministracion[])();

#endif