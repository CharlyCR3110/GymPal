#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;
class FechaInvalidaException : public std::exception
{
private:
	string mensaje;
public:
	FechaInvalidaException(string mensaje_);
	virtual const char* what() const noexcept;
};