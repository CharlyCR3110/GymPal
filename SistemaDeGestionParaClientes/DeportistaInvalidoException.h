#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

class DeportistaInvalidoException : public std::exception
{
private:
	string mensaje;
public:
	DeportistaInvalidoException(string mensaje_);
	const char* what() const noexcept;
};