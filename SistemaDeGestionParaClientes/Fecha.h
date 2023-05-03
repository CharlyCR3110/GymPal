#pragma once
#include <iostream>
#include <sstream>
#include <ctime>
#include "FechaInvalidaException.h"
using namespace std;

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha();	//constructor por defecto
	Fecha(const Fecha& fecha_);	//constructor copia
	Fecha(int dia_, int mes_, int anio_);
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
	friend bool operator>(const Fecha& fecha1_, const Fecha& fecha2_);	// operador mayor que
	friend bool operator>=(const Fecha& fecha1_, const Fecha& fecha2_);	// operador mayor o igual que
	friend ostream& operator<<(ostream& out, const Fecha& fecha_);	// operador de salida

};