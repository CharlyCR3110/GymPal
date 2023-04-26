#pragma once
#include <stdexcept>
#include <iostream>

class ListaVaciaException
{
public:
	const char* what() const throw();
};

