#include "DeportistaYaMatriculadoException.h"

DeportistaYaMatriculadoException::DeportistaYaMatriculadoException(std::string mensaje_):
    mensaje(mensaje_)
{
}

const char* DeportistaYaMatriculadoException::what() const noexcept
{
    return mensaje.c_str();
}
