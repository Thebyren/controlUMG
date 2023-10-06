#ifndef MANAGER_H
#define MANAGER_H
#pragma once
#include <string.h>
#include <iostream>
#include <ncurses.h>
// clases principales
class registros
{
public:
    class estudiante
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
    };
    class catedratico
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
    };
    class curso
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
    };
    class nota
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
    };
    class pago
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
    };
    class boleta
    {
    public:
        static bool nuevo();
        static bool eliminar();
        static bool imprimir();
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
extern bool (*estudiantes[])();

// Para Catedráticos
extern bool (*catedraticos[])();

// Para Cursos
extern bool (*cursos[])();

// Para Notas
extern bool (*notas[])();

// Para Pagos
extern bool (*pagos[])();

// Para Boletas
extern bool (*boletas[])();

extern void (*funAdministracion[])();

#endif