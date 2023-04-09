#pragma once
#include <exception>
#include <iostream>
using namespace std;

class ListaEnlazadasExceptions 
	: public exception
{
private:
	string mensaje;
public:
	ListaEnlazadasExceptions (string mensaje_);
	virtual const char* what() const noexcept;
};