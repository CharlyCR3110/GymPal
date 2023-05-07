#include "DeportistaNoEncontradoException.h"

const char* DeportistaNoEncontradoException::what() const throw()
{
    return "Error: Deportista no encontrado";
}