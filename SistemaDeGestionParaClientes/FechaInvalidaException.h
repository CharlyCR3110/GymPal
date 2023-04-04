#pragma once
#include <iostream>
#include <exception>

using namespace std;
class FechaInvalidaException 
	: public exception
{
private:
	string mensaje;
public:
	FechaInvalidaException(string mensaje_);
	virtual const char* what() const noexcept;
};