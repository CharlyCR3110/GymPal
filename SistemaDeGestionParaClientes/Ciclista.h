#pragma once
#include "Deportista.h"
class Ciclista :
    public Deportista
{
protected:
	int horasEntrenamiento;
	double temperaturaPromedio;
public:
	Ciclista(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, int horasEntrenamiento_ = 0, double temperaturaPromedio_ = 0.0);
	Ciclista(const Ciclista& ciclista_);
	virtual ~Ciclista() = default;
	//Setters
	virtual void setHorasEntrenamiento(int horasEntrenamiento_);
	virtual void setTemperaturaPromedio(double temperaturaPromedio_);
	//Getters
	virtual const int getHorasEntrenamiento() const;
	virtual const double getTemperaturaPromedio() const;
	// Metodos
	virtual const string toString() const override;
	virtual const string detalleDeportista() const = 0;
	// Sobrecarga de operadores
	friend ostream& operator<<(ostream& out, const Ciclista& ciclista_);	// operador de salida
};