#include "Fecha.h"

Fecha::Fecha()
{
    std::time_t now = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &now);

    // Asignar los componentes de la fecha a los atributos de la clases
    dia = tm.tm_mday;
    mes = tm.tm_mon + 1;    // +1 porque enero es 0
    anio = tm.tm_year + 1900; // año desde 1900
}

Fecha::Fecha(const Fecha& fecha_)
{
    // no se valida la fecha porque se asume que es valida
    this->dia = fecha_.dia;
	this->mes = fecha_.mes;
	this->anio = fecha_.anio;
}

Fecha::Fecha(int dia_, int mes_, int anio_)
{
    if (!esValida(dia_, mes_, anio_))
    {
		throw FechaInvalidaException("Fecha invalida");
	}
    this->dia = dia_;
    this->mes = mes_;
    this->anio = anio_;
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

const int Fecha::getDia() const
{
    return this->dia;
}

const int Fecha::getMes() const
{
    return this->mes;
}

const int Fecha::getAnio() const
{
    return this->anio;
}

const string Fecha::toString() const
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

Fecha& Fecha::operator=(const Fecha& fecha_)
{
    if (this != &fecha_)
    {
        if (&fecha_ == nullptr)
        {
            throw FechaInvalidaException("La fecha proporcionada es nula");
        }
        this->dia = fecha_.dia;
        this->mes = fecha_.mes;
        this->anio = fecha_.anio;
    }
    return *this;
}

bool operator>(const Fecha& fecha1_, const Fecha& fecha2_)
{
    if (fecha1_.anio > fecha2_.anio)
    {
        return true;
    }
    else if (fecha1_.anio == fecha2_.anio)
    {
        if (fecha1_.mes > fecha2_.mes)
        {
            return true;
        }
        else if (fecha1_.mes == fecha2_.mes)
        {
            if (fecha1_.dia > fecha2_.dia)
            {
                return true;
            }
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const Fecha& fecha_)
{
    out << fecha_.toString();
    return out;
}
