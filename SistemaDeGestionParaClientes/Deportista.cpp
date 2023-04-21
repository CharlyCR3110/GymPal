#include "Deportista.h"

Deportista::Deportista(const Deportista& deportista_)
{
    try
    {
        this->fechaNacimiento = new Fecha(*deportista_.fechaNacimiento);
    }
    catch (FechaInvalidaException& e)
    {
        throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }
    try
    {
        this->datosBiometricos = new DatosBiometricos(*deportista_.datosBiometricos);
    }
    catch (DatosBiometricosInvalidosException& e)
    {
        throw DeportistaInvalidoException("Datos biometricos invalidos");
    }
    this->cedula = deportista_.cedula;
    this->nombre = deportista_.nombre;
    this->telefono = deportista_.telefono;
    this->sexo = deportista_.sexo;
    this->estado = deportista_.estado;
}

Deportista::Deportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, string sexo_, char estado, DatosBiometricos* datosBiometricos_)
{
    try
    {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
    }
    catch (FechaInvalidaException& e)
    {
        throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }

    try
    {
        this->datosBiometricos = new DatosBiometricos(*datosBiometricos_);
    }
    catch (DatosBiometricosInvalidosException& e)
    {
        throw DeportistaInvalidoException("Datos biometricos invalidos");
    }

    this->cedula = cedula_;
    this->nombre = nombre_;
    this->telefono = telefono_;
    this->sexo = sexo_;
    this->estado = estado;
}

Deportista::~Deportista()
{
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

void Deportista::setSexo(string sexo_)
{
    this->sexo = sexo_;
}

void Deportista::setDatosBiometricos(DatosBiometricos* datosBiometricos_)
{
    try
    {
        this->datosBiometricos = new DatosBiometricos(*datosBiometricos_);
    }
    catch (DatosBiometricosInvalidosException& e)
    {
        throw DeportistaInvalidoException("Datos biometricos invalidos");
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

const string Deportista::getSexo() const
{
    return this->sexo;
}

DatosBiometricos* Deportista::getDatosBiometricos()
{
    return this->datosBiometricos;
}

const char Deportista::getEstado() const
{
    return this->estado;
}

const string Deportista::toString() const
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

Deportista& Deportista::operator=(const Deportista& deportista_)
{
    try
    {
        this->fechaNacimiento = new Fecha(*deportista_.fechaNacimiento);
    }
    catch (FechaInvalidaException& e)
    {
        throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }
    try
    {
        this->datosBiometricos = new DatosBiometricos(*deportista_.datosBiometricos);
    }
    catch (DatosBiometricosInvalidosException& e)
    {
        throw DeportistaInvalidoException("Datos biometricos invalidos");
    }
    this->cedula = deportista_.cedula;
    this->nombre = deportista_.nombre;
    this->telefono = deportista_.telefono;
    this->sexo = deportista_.sexo;
    this->estado = deportista_.estado;
    return *this;
}

ostream& operator<<(ostream& out, Deportista& deportista_)
{
    out << deportista_.toString();
    return out;
}