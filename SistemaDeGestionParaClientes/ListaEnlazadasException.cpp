#include "ListaEnlazadasException.h"

ListaEnlazadasExceptions::ListaEnlazadasExceptions(string mensaje_)
    : mensaje(mensaje_)
{
}

const char* ListaEnlazadasExceptions::what() const noexcept
{
    return this->mensaje.c_str();
}