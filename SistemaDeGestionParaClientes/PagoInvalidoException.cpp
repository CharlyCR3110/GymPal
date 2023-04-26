#include "PagoInvalidoException.h"

const char* PagoInvalidoException::what() const throw()
{
    return "Pago invalido";
}