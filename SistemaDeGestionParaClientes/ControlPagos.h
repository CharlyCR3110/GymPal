#pragma once
#include "Deportista.h"
#include "ListaEnlazada.h"
#include "Pago.h"
#include "ControlPagosInvalidoException.h"
#include "DeportistaNoEncontradoException.h"
#include "PagoInvalidoException.h"
#include "PagosNoRegistradosException.h"

class ControlPagos
{
private:
	double montoMensual;	// esto le debe de pertenecer a Gimnasio, pero por ahora lo dejo aqui
	ListaEnlazada<Deportista>* listaDeportistas;
	Fecha* fechaActual;	//la fecha actual del sistema
public:
	ControlPagos(double montoMensual_ = 0, ListaEnlazada<Deportista>* listaDeportistas_ = nullptr, Fecha* fechaActual_ = nullptr);
	ControlPagos(const ControlPagos& controlPagos_);
	virtual ~ControlPagos();
	// metodo para registrar el pago de un deportista
	void registrarPago(string cedula_, string mesCancelado_, double monto_);	//cedula = codigo
	// metodo para generar un reporte de pagos de un deportista
	string generarReportePagos(string cedula_);
	// metodo para pagar x cantidad de meses
	void pagarMeses(string cedula_, int cantidadMeses_);
};