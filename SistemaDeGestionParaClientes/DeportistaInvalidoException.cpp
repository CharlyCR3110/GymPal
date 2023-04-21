#include "DeportistaInvalidoException.h"

DeportistaInvalidoException::DeportistaInvalidoException(string mensaje_)
    :mensaje(mensaje_)
{
}

const char* DeportistaInvalidoException::what() const noexcept
{
    return this->mensaje.c_str();
}