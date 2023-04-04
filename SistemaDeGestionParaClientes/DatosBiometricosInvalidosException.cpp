#include "DatosBiometricosInvalidosException.h"

DatosBiometricosInvalidosException::DatosBiometricosInvalidosException(string campo_, string mensaje_)
    : campo(campo_), mensaje(mensaje_)
{
}

const char* DatosBiometricosInvalidosException::what() const noexcept
{
    return mensaje.c_str();
}

const string& DatosBiometricosInvalidosException::getCampo() const
{
    return this->campo;
}
