#include "Hora.h"

Hora::Hora(int hora_, int minuto_, int segundo_):
    hora(hora_),
	minuto(minuto_),
	segundo(segundo_)
{
}

Hora::Hora(const Hora& hora_):
    hora(hora_.hora),
    minuto(hora_.minuto),
    segundo(hora_.segundo)
{
}

void Hora::setHora(int hora_)
{
    this->hora = hora_;
}

void Hora::setMinuto(int minuto_)
{
    this->minuto = minuto_;
}

void Hora::setSegundo(int segundo_)
{
    this->segundo = segundo_;
}

const int Hora::getHora() const
{
    return this->hora;
}

const int Hora::getMinuto() const
{
    return this->minuto;
}

const int Hora::getSegundo() const
{
    return this->segundo;
}

const string Hora::toString() const
{
    stringstream ss;
    ss << this->hora << ":" << this->minuto << ":" << this->segundo;
    return ss.str();
}

bool Hora::operator==(const Hora& hora)
{
    if(this->hora == hora.hora && this->minuto == hora.minuto && this->segundo == hora.segundo)
    {
		return true;
	}
}

bool operator>(const Hora& hora1_, const Hora& hora2_)
{
    int hora1EnSegundos = hora1_.hora * 3600 + hora1_.minuto * 60 + hora1_.segundo;
    int hora2EnSegundos = hora2_.hora * 3600 + hora2_.minuto * 60 + hora2_.segundo;

    return hora1EnSegundos > hora2EnSegundos;
}

ostream& operator<<(ostream& out, const Hora& hora_)
{
    out << hora_.toString();
    return out;
}