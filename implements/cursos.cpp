#include"../headers/manager.h"
bool (*cursos[])() = {
    &registros::curso::nuevo,
    &registros::curso::eliminar,
    &registros::curso::imprimir};


bool registros::curso::nuevo()
{
    return true;

}
bool registros::curso::eliminar()
{
    return true;
    
}

bool registros::curso::imprimir()
{
    return true;
}
