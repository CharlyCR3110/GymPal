#pragma once
#include "Fecha.h"

class Pago
{
private:
	Fecha* fecha;
	string mesCancelado;
	double monto;
public:
	Pago(Fecha* fecha_, string mesCancelado_, double monto_);
	Pago(const Pago& pago_);
	virtual ~Pago();
	// setters
	void setFecha(Fecha* fecha_);
	void setMesCancelado(string mesCancelado_);
	void setMonto(double monto_);
	// getters
	Fecha* getFecha();
	const string getMesCancelado() const;
	const double getMonto() const;
	// metodos
	const string toString() const;
	// arhcivos
	const string toStringParaGuardar() const;
	// sobrecarga de operadores
	Pago& operator=(const Pago& pago_);
	friend ostream& operator<<(ostream& out, const Pago& pago_);
};