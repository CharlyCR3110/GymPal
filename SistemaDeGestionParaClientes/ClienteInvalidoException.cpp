#include "ClienteInvalidoException.h"

ClienteInvalidoException::ClienteInvalidoException(string mensaje_)
    :mensaje(mensaje_)
{
}

const char* ClienteInvalidoException::what() const noexcept
{
    return this->mensaje.c_str();
}