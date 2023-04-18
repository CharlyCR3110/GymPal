#pragma once
#include "ClienteInvalidoException.h"
#include "DatosBiometricos.h"
#include "DatosBiometricosInvalidosException.h"
#include "Fecha.h"
#include "FechaInvalidaException.h"

class Cliente abstract
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
	//Constructores
	Cliente();
	Cliente(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, string sexo_ = "", char estado = ' ', DatosBiometricos* datosBiometricos_ = nullptr);
	Cliente(const Cliente& cliente_);
	//Destructor
	virtual ~Cliente() = default;
	//Setters
	virtual void setCedula(string cedula_) = 0;
	virtual void setNombre(string nombre_) = 0;
	virtual void setTelefono(string telefono_) = 0;
	virtual void setFechaNacimiento(Fecha* fechaNacimiento_) = 0;
	virtual void setSexo(string sexo_) = 0;
	virtual void setDatosBiometricos(DatosBiometricos* datosBiometricos_) = 0;
	virtual void setEstado(char estado) = 0;
	//Getters
	virtual const string getCedula() const = 0;
	virtual const string getNombre() const = 0;
	virtual const string getTelefono() const = 0;
	virtual Fecha* getFechaNacimiento() = 0;
	virtual const string getSexo() const = 0;
	virtual DatosBiometricos* getDatosBiometricos() = 0;
	virtual const char getEstado() const = 0;
	// Metodos
	virtual const string toString() const = 0;
	// Sobrecarga de operadores
	friend ostream& operator<<(ostream& out, const Cliente& cliente_);
	Cliente& operator=(const Cliente& cliente_);
};