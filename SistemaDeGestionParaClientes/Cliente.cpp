#include "Cliente.h"

Cliente::Cliente(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, string sexo_, DatosBiometricos* datosBiometricos_)
{
    try 
    {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
    }
    catch (FechaInvalidaException& e)
    {
		throw ClienteInvalidoException("Fecha de nacimiento invalida");
    }

    try
    {
		this->datosBiometricos = new DatosBiometricos(*datosBiometricos_);
	}
    catch (DatosBiometricosInvalidosException& e)
    {
		throw ClienteInvalidoException("Datos biometricos invalidos");
	}

    this->cedula = cedula_;
	this->nombre = nombre_;
	this->telefono = telefono_;
	this->sexo = sexo_;
}

Cliente::~Cliente()
{
}

void Cliente::setCedula(string cedula_)
{
    this->cedula = cedula_;
}

void Cliente::setNombre(string nombre_)
{
    this->nombre = nombre_;
}

void Cliente::setTelefono(string telefono_)
{
    this->telefono = telefono_;
}

void Cliente::setFechaNacimiento(Fecha* fechaNacimiento_)
{
    try
    {
		this->fechaNacimiento = new Fecha(*fechaNacimiento_);
	}
    catch (FechaInvalidaException& e)
    {
		throw ClienteInvalidoException("Fecha de nacimiento invalida");
	}
}

void Cliente::setSexo(string sexo_)
{
    this->sexo = sexo_;
}

void Cliente::setDatosBiometricos(DatosBiometricos* datosBiometricos_)
{
    try
    {
        this->datosBiometricos = new DatosBiometricos(*datosBiometricos_);
    }
	catch (DatosBiometricosInvalidosException& e)
    {
        throw ClienteInvalidoException("Datos biometricos invalidos");
    }
}

const string Cliente::getCedula() const
{
    return this->cedula;
}

const string Cliente::getNombre() const
{
    return this->nombre;
}

const string Cliente::getTelefono() const
{
    return this->telefono;
}

const Fecha* Cliente::getFechaNacimiento() const
{
    return this->fechaNacimiento;
}

const string Cliente::getSexo() const
{
    return this->sexo;
}

const DatosBiometricos* Cliente::getDatosBiometricos() const
{
    return this->datosBiometricos;
}