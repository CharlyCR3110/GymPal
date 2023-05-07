#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

class CupoMaximoExcedido : public std::exception
{
private:
    string mensaje;
public:
    CupoMaximoExcedido(string mensaje_);
	virtual const char* what() const noexcept;
};