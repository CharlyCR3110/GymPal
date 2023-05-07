#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

class ListaEnlazadasExceptions : public std::exception
{
private:
	string mensaje;
public:
	ListaEnlazadasExceptions (string mensaje_);
	virtual const char* what() const noexcept;
};