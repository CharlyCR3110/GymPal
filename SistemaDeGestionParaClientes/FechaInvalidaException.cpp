#include "FechaInvalidaException.h"

FechaInvalidaException::FechaInvalidaException(string mensaje_)
    : mensaje(mensaje_)
{
}

const char* FechaInvalidaException::what()
{
    return this->mensaje.c_str();
}
