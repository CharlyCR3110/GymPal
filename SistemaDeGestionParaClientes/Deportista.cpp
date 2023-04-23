#include "Deportista.h"


Deportista::Deportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, char estado_):
    cedula(cedula_),
	nombre(nombre_),
	telefono(telefono_),
	estado(estado_)
{
    try {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
	}
    catch (FechaInvalidaException& e) 
    {
		throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }
}

Deportista::Deportista(const Deportista& deportista_): 
    cedula(deportista_.cedula),
    nombre(deportista_.nombre),
    telefono(deportista_.telefono),
    estado(deportista_.estado)
{
    try {
		this->fechaNacimiento = new Fecha(*deportista_.fechaNacimiento);
	}
    catch (FechaInvalidaException& e)
    {
		throw DeportistaInvalidoException("Fecha de nacimiento invalida");
	}
}

void Deportista::setCedula(string cedula_)
{
    this->cedula = cedula_;
}

void Deportista::setNombre(string nombre_)
{
    this->nombre = nombre_;
}

void Deportista::setTelefono(string telefono_)
{
    this->telefono = telefono_;
}

void Deportista::setFechaNacimiento(Fecha* fechaNacimiento_)
{
    try
    {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
    }
    catch (FechaInvalidaException& e)
    {
        throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }
}

void Deportista::setEstado(char estado)
{
    this->estado = estado;
}

const string Deportista::getCedula() const
{
    return this->cedula;
}

const string Deportista::getNombre() const
{
    return this->nombre;
}

const string Deportista::getTelefono() const
{
    return this->telefono;
}

Fecha* Deportista::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

const char Deportista::getEstado() const
{
    return this->estado;
}

Deportista& Deportista::operator=(const Deportista& deportista_)
{
    if (this != &deportista_)
    {
		this->cedula = deportista_.cedula;
		this->nombre = deportista_.nombre;
		this->telefono = deportista_.telefono;
		this->fechaNacimiento = deportista_.fechaNacimiento;
		this->estado = deportista_.estado;
	}
    return *this;
}

bool Deportista::operator!=(const Deportista& deportista_) const
{
    return this->cedula != deportista_.cedula;  // unicamente depende de la cedula porque lo demas puede coincidir
}

ostream& operator<<(ostream& out, Deportista& deportista_)
{
    out << deportista_.toString();
    return out;
}