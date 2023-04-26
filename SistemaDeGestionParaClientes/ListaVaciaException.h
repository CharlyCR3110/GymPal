#pragma once
#include <stdexcept>
#include <iostream>

class ListaVaciaException : public std::exception
{
public:
	const char* what() const throw();
};