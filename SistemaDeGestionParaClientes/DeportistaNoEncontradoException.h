#pragma once
#include <stdexcept>
class DeportistaNoEncontradoException : public std::exception
{
public:
	const char* what() const throw();
};