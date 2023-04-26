#include "PagosNoRegistradosException.h"

const char* PagosNoRegistradosException::what() const throw()
{
    return "No hay pagos registrados";
}