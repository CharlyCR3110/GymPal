#pragma once
#include <stdexcept>
class DeportistaNoEncontradoException : std::exception
{
public:
	const char* what() const throw();
};