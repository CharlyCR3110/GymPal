#include "Cliente.h"

Cliente::Cliente(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, string sexo_, char estado, DatosBiometricos* datosBiometricos_)
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
    this->estado = estado;
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

void Cliente::setEstado(char estado)
{
    this->estado = estado;
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

Fecha* Cliente::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

const string Cliente::getSexo() const
{
    return this->sexo;
}

DatosBiometricos* Cliente::getDatosBiometricos()
{
    return this->datosBiometricos;
}

const char Cliente::getEstado() const
{
    return this->estado;
}

const string Cliente::toString() const
{
    stringstream ss;
    ss << "Cedula: " << this->cedula << endl;
    ss << "Nombre: " << this->nombre << endl;    ss << "Telefono: " << this->telefono << endl;
    ss << "Fecha de nacimiento: " << this->fechaNacimiento->toString() << endl;
    ss << "Sexo: " << this->sexo << endl;
    ss << "Estado: " << this->estado << endl;
    ss << this->datosBiometricos->toString() << endl;
    return ss.str();
}