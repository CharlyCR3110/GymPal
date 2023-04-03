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

bool Fecha::esValida(int dia_, int mes_, int anio_)
{
    if (mes_ < 1 || mes_ > 12)
    {
        return false;
    }

    // lista con la cantidad de dias que tiene cada mes
    int diasPorMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int numDias = diasPorMes[mes_ - 1];

    if (mes_ == 2 && (anio_ % 400 == 0 || (anio_ % 4 == 0 && anio_ % 100 != 0)))
    {
        numDias++;
	}

    if (dia_ < 1 || dia_ > numDias)
    {
        return false;
    }
    return true;
}
