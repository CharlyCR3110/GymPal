#pragma once
#include <exception>
#include <iostream>
using namespace std;\

class CupoMaximoExcedido 
    : public exception
{
private:
    string mensaje;
public:
    CupoMaximoExcedido(string mensaje_);
	virtual const char* what() const noexcept;
};