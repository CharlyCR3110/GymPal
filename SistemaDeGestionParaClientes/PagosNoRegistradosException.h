#pragma once
#include <stdexcept>
class PagosNoRegistradosException : public std::exception
{
public:
	const char* what() const throw();
};