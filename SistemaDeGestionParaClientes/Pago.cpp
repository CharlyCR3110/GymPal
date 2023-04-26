#include "Pago.h"

Pago::Pago(Fecha* fecha_, string mesCancelado_, double monto_)
{
	if (fecha_ == nullptr)
	{
		throw invalid_argument("La fecha no puede ser nula. Desde pago.");	// cambiar por una excepcion propia
	}

	this->fecha = fecha_;
	this->mesCancelado = mesCancelado_;
	this->monto = monto_;
}

Pago::Pago(const Pago& pago_)
{
	if (&pago_ == nullptr)
	{
		throw invalid_argument("El pago no puede ser nulo. Desde pago.");	// cambiar por una excepcion propia
	}

	this->fecha = pago_.fecha;
	this->mesCancelado = pago_.mesCancelado;
	this->monto = pago_.monto;
}

Pago::~Pago()
{
	delete fecha;
	fecha = nullptr;
}

void Pago::setFecha(Fecha* fecha_)
{
	this->fecha = fecha_;
}

void Pago::setMesCancelado(string mesCancelado_)
{
	this->mesCancelado = mesCancelado_;
}

void Pago::setMonto(double monto_)
{
	this->monto = monto_;
}

Fecha* Pago::getFecha()
{
	return this->fecha;
}

const string Pago::getMesCancelado() const
{
	return this->mesCancelado;
}

const double Pago::getMonto() const
{
	return this->monto;
}

const string Pago::toString() const
{
	stringstream ss;
	ss << fecha->toString() << "\t" << mesCancelado << "\t" << monto;
	return ss.str();
}

Pago& Pago::operator=(const Pago& pago_)
{
	if (this != &pago_)
	{
		this->fecha = pago_.fecha;
		this->mesCancelado = pago_.mesCancelado;
		this->monto = pago_.monto;
	}

	return *this;
}

ostream& operator<<(ostream& out, const Pago& pago_)
{
	out << pago_.toString();
	return out;
}