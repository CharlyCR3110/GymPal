#include "Fecha.h"

Fecha::Fecha(int dia_, int mes_, int anio_)
    :dia(dia_), mes(mes_), anio(anio_)
{
}

Fecha::~Fecha()
{
}

void Fecha::setDia(int dia_)
{
    this->dia = dia_;
}

void Fecha::setMes(int mes_)
{
    this->mes = mes_;
}

void Fecha::setAnio(int anio_)
{
    this->anio = anio_;
}

int Fecha::getDia()
{
    return this->dia;
}

int Fecha::getMes()
{
    return this->mes;
}

int Fecha::getAnio()
{
    return this->anio;
}

string Fecha::toString()
{
    stringstream s;
	s << this->dia << "/" << this->mes << "/" << this->anio;
	return s.str();
}
