#pragma once
#include <stdexcept>
#include <iostream>
class ControlPagosInvalidoException : public std::exception
{
private:
	std::string mensaje;
public:
	ControlPagosInvalidoException(std::string mensaje_);
	virtual const char* what() const noexcept;
};