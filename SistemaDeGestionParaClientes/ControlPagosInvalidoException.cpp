#include "ControlPagosInvalidoException.h"

ControlPagosInvalidoException::ControlPagosInvalidoException(std::string mensaje_):
	mensaje(mensaje_)
{
}

const char* ControlPagosInvalidoException::what() const noexcept
{
	return mensaje.c_str();
}