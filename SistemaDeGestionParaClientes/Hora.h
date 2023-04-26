#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Hora
{
private:
	int hora;
	int minuto;
	int segundo;
public:
	Hora(int hora_, int minuto_, int segundo_);
	Hora(const Hora& hora_);
	~Hora() = default;
	//setters
	void setHora(int hora_);
	void setMinuto(int minuto_);
	void setSegundo(int segundo_);
	//getters
	const int getHora() const;
	const int getMinuto() const;
	const int getSegundo() const;
	//metodos
	const string toString() const;
	//sobrecarga
	bool operator==(const Hora& hora);
	friend bool operator>(const Hora& hora1_, const Hora& hora2_);
	friend ostream& operator<<(ostream& out, const Hora& hora_);
};