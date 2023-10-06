#include"../headers/manager.h"

 bool (*catedraticos[])() = {
    &registros::catedratico::nuevo,
    &registros::catedratico::eliminar,
    &registros::catedratico::imprimir};

bool registros::catedratico::nuevo()
{
    return true;

}
bool registros::catedratico::eliminar()
{
    return true;
    
}

bool registros::catedratico::imprimir()
{
    return true;
}
