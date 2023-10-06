#include"../headers/manager.h"
bool (*notas[])() = {
    &registros::nota::nuevo,
    &registros::nota::eliminar,
    &registros::nota::imprimir};

bool registros::nota::nuevo()
{
    return true;

}
bool registros::nota::eliminar()
{
    return true;
    
}

bool registros::nota::imprimir()
{
    return true;
}
