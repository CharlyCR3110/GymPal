#include "DatosBiometricos.h"

DatosBiometricos::DatosBiometricos(float estatura_, float peso_, float porcentajeGrasaCorporal_, float porcentajeMasaMuscular_, Fecha* fechaMedicion_)
{
	if (estatura_ < 0)
	{
		throw DatosBiometricosInvalidosException("Estatura", "La estatura no puede ser negativa");
	}

	if (peso_ < 0)
	{
		throw DatosBiometricosInvalidosException("Peso", "El peso no puede ser negativo");
	}

	if (porcentajeGrasaCorporal_ < 0 || porcentajeGrasaCorporal_ > 100)
	{
		throw DatosBiometricosInvalidosException("Porcentaje de grasa corporal", "El porcentaje de grasa corporal debe estar entre 0 y 100");
	}

	if (porcentajeMasaMuscular_ < 0 || porcentajeMasaMuscular_ > 100)
	{
		throw DatosBiometricosInvalidosException("Porcentaje de masa muscular", "El porcentaje de masa muscular debe estar entre 0 y 100");
	}

	if (!fechaMedicion_->esValida(fechaMedicion_->getDia(), fechaMedicion_->getMes(), fechaMedicion_->getAnio()))
	{
		throw DatosBiometricosInvalidosException("Fecha de medicion", "La fecha de medicion no es valida");
	}

	estatura = estatura_;
	peso = peso_;
	porcentajeGrasaCorporal = porcentajeGrasaCorporal_;
	porcentajeMasaMuscular = porcentajeMasaMuscular_;
	fechaMedicion = fechaMedicion_;
}

DatosBiometricos::~DatosBiometricos()
{
}

void DatosBiometricos::setEstatura(float estatura_)
{
	this->estatura = estatura_;
}

void DatosBiometricos::setPeso(float peso_)
{
	this->peso = peso_;
}

void DatosBiometricos::setPorcentajeGrasaCorporal(float porcentajeGrasaCorporal_)
{
	this->porcentajeGrasaCorporal = porcentajeGrasaCorporal_;
}

void DatosBiometricos::setPorcentajeMasaMuscular(float porcentajeMasaMuscular_)
{
	this->porcentajeMasaMuscular = porcentajeMasaMuscular_;
}

void DatosBiometricos::setFechaMedicion(Fecha* fechaMedicion_)
{
	this->fechaMedicion = fechaMedicion_;
}

const float DatosBiometricos::getEstatura() const
{
	return this->estatura;
}

const float DatosBiometricos::getPeso() const
{
	return this->peso;
}

const float DatosBiometricos::getPorcentajeGrasaCorporal() const
{
	return this->porcentajeGrasaCorporal;
}

const float DatosBiometricos::getPorcentajeMasaMuscular() const
{
	return this->porcentajeMasaMuscular;
}

Fecha* DatosBiometricos::getFechaMedicion()
{
	return this->fechaMedicion;
}

string DatosBiometricos::toString()
{
	stringstream ss;
	ss << "--- Datos biometricos ---" << endl;
	ss << "Estatura: " << estatura << endl;
	ss << "Peso: " << peso << endl;
	ss << "Porcentaje de grasa corporal: " << porcentajeGrasaCorporal << endl;
	ss << "Porcentaje de masa muscular: " << porcentajeMasaMuscular << endl;
	ss << "Fecha de medicion: " << fechaMedicion->toString() << endl;
	return ss.str();
}