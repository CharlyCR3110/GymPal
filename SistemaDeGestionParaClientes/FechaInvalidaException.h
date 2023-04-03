#pragma once
#include <iostream>
#include <exception>

using namespace std;
class FechaInvalidaException
{
private:
	string mensaje;
public:
	FechaInvalidaException(string mensaje_);
	virtual const char* what();
};

