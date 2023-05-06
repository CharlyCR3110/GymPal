#pragma once
#include <stdexcept>

class PagoInvalidoException : public std::exception
{
public:
	const char* what() const throw();
};