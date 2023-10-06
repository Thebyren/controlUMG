#include"../headers/manager.h"

bool (*pagos[])() = {
    &registros::pago::nuevo,
    &registros::pago::eliminar,
    &registros::pago::imprimir};

bool registros::pago::nuevo()
{
    return true;

}
bool registros::pago::eliminar()
{
    return true;
    
}

bool registros::pago::imprimir()
{
    return true;
}
