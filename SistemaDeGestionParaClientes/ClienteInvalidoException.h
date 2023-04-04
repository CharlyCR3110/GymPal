#pragma once
#include <exception>
#include <iostream>
using namespace std;

class ClienteInvalidoException
{
private:
	string mensaje;
public:
	ClienteInvalidoException(string mensaje_);
	const char* what() const noexcept;
};