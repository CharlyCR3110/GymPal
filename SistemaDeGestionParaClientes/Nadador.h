#pragma once
#include "Fecha.h"

class Nadador
{
private:
	double masaMuscular;
	double peso;
	double porcentajeGrasaCorporal;
	Fecha* fechaUltimaActualizacion;	// fecha de la ultima actualizacion los datos
public:
	Nadador(double masaMuscular_ = 0.0, double peso_ = 0.0, double porcentajeGrasaCorporal_ = 0.0, Fecha* fechaUltimaActualizacion_ = nullptr);
	Nadador(const Nadador& nadador_);
	~Nadador();
	//Setters
	virtual void setMasaMuscular(double masaMuscular_);
	virtual void actualizarMasaMuscular(double masaMuscular_, Fecha* fechaActualizacion_);
	virtual void setPeso(double peso_);
	virtual void actualizarPeso(double peso_, Fecha* fechaActualizacion_);
	virtual void setPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_);
	virtual void actualizarPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_, Fecha* fechaActualizacion_);
	virtual void setFechaUltimaActualizacion(Fecha* fechaDeRegistro_);
	//Getters
	virtual const double getMasaMuscular() const;
	virtual const double getPeso() const;
	virtual const double getPorcentajeGrasaCorporal() const;
	virtual Fecha* getFechaUltimaActualizacion();
	// Metodos
	virtual const string toString() const;
	// Sobrecarga de operadores
	Nadador& operator=(const Nadador& nadador_);
	friend ostream& operator<<(ostream& out, const Nadador& nadador_);
};

