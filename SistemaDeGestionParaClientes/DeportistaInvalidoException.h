#pragma once
#include <exception>
#include <iostream>
using namespace std;

class DeportistaInvalidoException :
	public exception
{
private:
	string mensaje;
public:
	DeportistaInvalidoException(string mensaje_);
	const char* what() const noexcept;
};