#pragma once
#include <iostream>
using namespace std;

class DatosBiometricosInvalidosException 
	: public exception
{
private:
	string campo;
	string mensaje;
public:
	DatosBiometricosInvalidosException(string campo_ = "", string mensaje_ = "");
	virtual const char* what() const noexcept;
	const string& getCampo() const;
};