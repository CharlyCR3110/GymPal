#pragma once
#include <stdexcept>

class PagoInvalidoException : std::exception
{
public:
	const char* what() const throw();
};