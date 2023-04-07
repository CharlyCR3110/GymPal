#pragma once
#include "Fecha.h"
#include "DatosBiometricosInvalidosException.h"

class DatosBiometricos
{
private:
	float estatura;
	float peso;
	float porcentajeGrasaCorporal;
	float porcentajeMasaMuscular;
	Fecha* fechaMedicion;
public:
	DatosBiometricos(float estatura_ = 0, float peso_ = 0, float porcentajeGrasaCorporal_ = 0, float porcentajeMasaMuscular_ = 0, Fecha* fechaMedicion_ = new Fecha());
	~DatosBiometricos();
	//setters
	void setEstatura(float estatura_);
	void setPeso(float peso_);
	void setPorcentajeGrasaCorporal(float porcentajeGrasaCorporal_);
	void setPorcentajeMasaMuscular(float porcentajeMasaMuscular_);
	void setFechaMedicion(Fecha* fechaMedicion_);
	//getters
	const float getEstatura() const;
	const float getPeso() const;
	const float getPorcentajeGrasaCorporal() const;
	const float getPorcentajeMasaMuscular() const;
	const Fecha* getFechaMedicion() const;
	//metodos
	string toString();
};