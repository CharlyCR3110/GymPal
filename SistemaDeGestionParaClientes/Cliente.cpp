#include "Cliente.h"

Cliente::Cliente()
	: cedula(""), nombre(""), telefono(""), fechaNacimiento(nullptr), sexo(""), estado(' '), datosBiometricos(nullptr)
{
}

Cliente::Cliente(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, string sexo_, char estado, DatosBiometricos* datosBiometricos_)
	: cedula(cedula_), nombre(nombre_), telefono(telefono_), fechaNacimiento(fechaNacimiento_), sexo(sexo_), estado(estado), datosBiometricos(datosBiometricos_)
{
}

Cliente::Cliente(const Cliente& cliente_)
{
	try
	{
		this->fechaNacimiento = new Fecha(*cliente_.fechaNacimiento);
	}
	catch (FechaInvalidaException& e)
	{
		throw ClienteInvalidoException("Fecha de nacimiento invalida");
	}
	try
	{
		this->datosBiometricos = new DatosBiometricos(*cliente_.datosBiometricos);
	}
	catch (DatosBiometricosInvalidosException& e)
	{
		throw ClienteInvalidoException("Datos biometricos invalidos");
	}
	this->cedula = cliente_.cedula;
	this->nombre = cliente_.nombre;
	this->telefono = cliente_.telefono;
	this->sexo = cliente_.sexo;
	this->estado = cliente_.estado;
}

Cliente& Cliente::operator=(const Cliente& cliente_)
{
	try
	{
		this->fechaNacimiento = new Fecha(*cliente_.fechaNacimiento);
	}
	catch (FechaInvalidaException& e)
	{
		throw ClienteInvalidoException("Fecha de nacimiento invalida");
	}
	try
	{
		this->datosBiometricos = new DatosBiometricos(*cliente_.datosBiometricos);
	}
	catch (DatosBiometricosInvalidosException& e)
	{
		throw ClienteInvalidoException("Datos biometricos invalidos");
	}
	this->cedula = cliente_.cedula;
	this->nombre = cliente_.nombre;
	this->telefono = cliente_.telefono;
	this->sexo = cliente_.sexo;
	this->estado = cliente_.estado;
	return *this;
}

ostream& operator<<(ostream& out, const Cliente& cliente_)
{
	out << cliente_.toString();
	return out;
}