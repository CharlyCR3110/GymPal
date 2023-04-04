#include "FechaInvalidaException.h"

FechaInvalidaException::FechaInvalidaException(string mensaje_)
    : mensaje(mensaje_)
{
}

const char* FechaInvalidaException::what() const noexcept
{
    return this->mensaje.c_str();
}