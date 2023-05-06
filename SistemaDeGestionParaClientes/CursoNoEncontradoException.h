#pragma once
#include <stdexcept>
class CursoNoEncontradoException : public std::exception
{
public:
	const char* what() const throw();
};

