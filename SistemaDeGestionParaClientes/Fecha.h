#pragma once
#include <iostream>
#include <sstream>
#include "FechaInvalidaException.h"
using namespace std;

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(const Fecha& fecha_);	//constructor copia
	Fecha(int dia_ = 0, int mes_ = 0, int anio_ = 0);
	virtual ~Fecha();
	//setters
	void setDia(int dia_);
	void setMes(int mes_);
	void setAnio(int anio_);
	//getters
	const int getDia() const;
	const int getMes() const;
	const int getAnio() const;
	//metodos
	const string toString() const;
	// excepciones
	//IGNORA SI EL ANIO NO ES VALIDO
	bool esValida(int dia_, int mes_, int anio_);
	//sobrecarga de operadores
	Fecha& operator=(const Fecha& fecha_);	// operador de asignacion
};