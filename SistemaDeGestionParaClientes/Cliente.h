#pragma once
#include "ClienteInvalidoException.h"
#include "DatosBiometricos.h"
#include "DatosBiometricosInvalidosException.h"
#include "Fecha.h"
#include "FechaInvalidaException.h"

class Cliente
{
private:
	string cedula;
	string nombre;
	string telefono;
	Fecha* fechaNacimiento;
	string sexo;
	char estado; // Activo = 'A', Inactivo = 'I', Con Cuentas Pendientes = 'P'
	DatosBiometricos* datosBiometricos;
public:
	Cliente(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, string sexo_ = "", char estado = ' ', DatosBiometricos* datosBiometricos_ = nullptr);
	//Cliente(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, string sexo_ = "", DatosBiometricos* datosBiometricos_ = nullptr);
	~Cliente();
	//setters
	void setCedula(string cedula_);
	void setNombre(string nombre_);
	void setTelefono(string telefono_);
	void setFechaNacimiento(Fecha* fechaNacimiento_);
	void setSexo(string sexo_);
	void setDatosBiometricos(DatosBiometricos* datosBiometricos_);
	void setEstado(char estado);
	//getters
	const string getCedula() const;
	const string getNombre() const;
	const string getTelefono() const;
	Fecha* getFechaNacimiento();
	const string getSexo() const;
	DatosBiometricos* getDatosBiometricos();
	const char getEstado() const;
	//metodos
	const string toString() const;
	//sobrecarga de operadores
	friend ostream & operator<<(ostream& out, Cliente& cliente_);
};