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
public:
	ControlPagos();
	virtual ~ControlPagos();
	// setter
	// metodo para registrar el pago de un deportista
	void registrarPago(string cedula_, string mesCancelado_, double monto_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual);	//cedula = codigo
	// metodo para generar un reporte de pagos de un deportista
	string generarReportePagos(string cedula_, ListaEnlazada<Deportista>* listaDeportistas);
	// metodo para pagar x cantidad de meses
	void pagarMeses(string cedula_, int cantidadMeses_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual, double montoMensual);
	//
	//Verificar pago: un método que recibe como parámetro el número de identificación del cliente y verifica si tiene pagos pendientes o si se encuentra activo en el gimnasio.
};