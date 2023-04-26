#include "DeportistaNoEncontradoException.h"

const char* DeportistaNoEncontradoException::what() const throw()
{
    return "Deportista no encontrado";
}