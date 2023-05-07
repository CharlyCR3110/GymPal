#include "DeportistaNoMatriculadoException.h"

DeportistaNoMatriculadoException::DeportistaNoMatriculadoException(std::string mensaje_):
    mensaje(mensaje_)
{
}

const char* DeportistaNoMatriculadoException::what() const noexcept
{
    return mensaje.c_str();
}
