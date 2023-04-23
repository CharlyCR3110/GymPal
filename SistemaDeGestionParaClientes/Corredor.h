#pragma once
#include "Fecha.h"
class Corredor
{
private:
	char sexo; // 'M' o 'F'
	double estatura; // en metros
	Fecha* fechaUltimaActualizacion;	// fecha de la ultima actualizacion de estatura
public:
	Corredor(char sexo_ = ' ', double estatura_ = 0.0, Fecha* fechaUltimaActualizacion_ = nullptr);
	Corredor(const Corredor& corredor_);
	virtual ~Corredor() = default;
	//Setters
	virtual void setSexo(char sexo_);
	virtual void setEstatura(double estatura_);
	virtual void actualizarEstatura(double estatura_, Fecha* fechaActualizacion_);
	virtual void setFechaUltimaActualizacion(Fecha* fechaUltimaActualizacion_);
	//Getters
	virtual const char getSexo() const;
	virtual const double getEstatura() const;
	virtual Fecha* getFechaUltimaActualizacion();
	// Metodos
	virtual const string toString() const;
	// Sobrecarga de operadores
	Corredor& operator=(const Corredor& corredor_);
	friend ostream& operator<<(ostream& out, const Corredor& corredor_);
};

