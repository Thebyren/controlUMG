#include "../headers/manager.h"
bool (*estudiantes[])() = {
    &registros::estudiante::nuevo,
    &registros::estudiante::eliminar,
    &registros::estudiante::imprimir};

bool registros::estudiante::nuevo()
{
    return true;
}
bool registros::estudiante::eliminar()
{
    return true;
}

bool registros::estudiante::imprimir()
{
    return true;
}
