#pragma once
#include "DeportistaInvalidoException.h"
#include "Fecha.h"
#include "FechaInvalidaException.h"

class Deportista
{
protected:
	string cedula;
	string nombre;
	string telefono;
	Fecha* fechaNacimiento;
	char estado; // Activo = 'A', Inactivo = 'I', Con Cuentas Pendientes = 'P'
	// agregar lista de pagos
public:
	Deportista(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr, char estado_ = ' ');
	Deportista(const Deportista& deportista_);	//constructor copia
	~Deportista() = default;
	//setters
	virtual void setCedula(string cedula_);
	virtual void setNombre(string nombre_);
	virtual void setTelefono(string telefono_);
	virtual void setFechaNacimiento(Fecha* fechaNacimiento_);
	virtual void setEstado(char estado);
	//getters
	virtual const string getCedula() const;
	virtual const string getNombre() const;
	virtual const string getTelefono() const;
	virtual Fecha* getFechaNacimiento();
	virtual const char getEstado() const;
	//metodo para poder utilizar el template de buscar por codigo
	const string getCodigo() const; //devuelve la cedula
	//metodos
	virtual const string toString() const = 0;	//MVP - metodo virtual puro
	//sobrecarga de operadores
	Deportista& operator=(const Deportista& deportista_);	// operador de asignacion
	bool operator != (const Deportista& deportista_) const; // operador de desigualdad
	friend ostream& operator<<(ostream& out, Deportista& deportista_);	// operador de salida
};