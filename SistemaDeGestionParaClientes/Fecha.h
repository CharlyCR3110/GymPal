#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int dia_ = 0, int mes_ = 0, int anio_ = 0);
	virtual ~Fecha();
	//setters
	void setDia(int dia_);
	void setMes(int mes_);
	void setAnio(int anio_);
	//getters
	int getDia();
	int getMes();
	int getAnio();
	//metodos
	string toString();
};

