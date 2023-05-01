#include "Ciclista.h"

Ciclista::Ciclista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, int horasEntrenamiento_, double temperaturaPromedio_) :
    Deportista(cedula_, nombre_, telefono_, fechaNacimiento_),
    horasEntrenamiento(horasEntrenamiento_),
    temperaturaPromedio(temperaturaPromedio_)
{
}

Ciclista::Ciclista(const Ciclista& ciclista_)
    : Deportista(ciclista_),
    horasEntrenamiento(ciclista_.horasEntrenamiento),
    temperaturaPromedio(ciclista_.temperaturaPromedio)
{
}

void Ciclista::setHorasEntrenamiento(int horasEntrenamiento_)
{
    this->horasEntrenamiento = horasEntrenamiento_;
}

void Ciclista::setTemperaturaPromedio(double temperaturaPromedio_)
{
    this->temperaturaPromedio = temperaturaPromedio_;
}

const int Ciclista::getHorasEntrenamiento() const
{
    return this->horasEntrenamiento;
}

const double Ciclista::getTemperaturaPromedio() const
{
    return this->temperaturaPromedio;
}

const string Ciclista::toString() const
{
    stringstream ss;
    ss << "Cedula: " << this->cedula << endl;
    ss << "Nombre: " << this->nombre << endl;
    ss << "Telefono: " << this->telefono << endl;
    ss << "Fecha de nacimiento: " << *this->fechaNacimiento << endl;
    ss << "Estado: " << this->estado << endl;
    ss << "Horas de entrenamiento: " << this->horasEntrenamiento << endl;
    ss << "Temperatura promedio: " << this->temperaturaPromedio << endl;
    return ss.str();
}

ostream& operator<<(ostream& out, const Ciclista& ciclista_)
{
    out << ciclista_.toString();
    return out;
}