#include"../headers/manager.h"


bool registros::boleta::nuevo()
{
    return true;
}
bool registros::boleta::eliminar()
{
    return true;
    
}

bool registros::boleta::imprimir()
{
    return true;
}

bool (*boletas[])() = {
    &registros::boleta::nuevo,
    &registros::boleta::eliminar,
    &registros::boleta::imprimir};
    