#include "CupoMaximoExcedido.h"

CupoMaximoExcedido::CupoMaximoExcedido(string mensaje_)
	: mensaje(mensaje_)
{
}

const char* CupoMaximoExcedido::what() const noexcept
{
	return this->mensaje.c_str();
}