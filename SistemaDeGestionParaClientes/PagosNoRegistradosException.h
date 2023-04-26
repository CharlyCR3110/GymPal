#pragma once
#include <stdexcept>
class PagosNoRegistradosException : std::exception
{
public:
	const char* what() const throw();
};