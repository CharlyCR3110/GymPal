#pragma once
#include "Deportista.h"
#include "ListaEnlazada.h"
#include "Pago.h"
#include "ControlPagosInvalidoException.h"
#include "DeportistaNoEncontradoException.h"
#include "PagoInvalidoException.h"
#include "PagosNoRegistradosException.h"
#include "ListaVaciaException.h"

class ControlPagos
{
public:
	ControlPagos();
	~ControlPagos();
	// setter
	// metodo para registrar el pago de un deportista
	void registrarPago(string cedula_, string mesCancelado_, double monto_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual);	//cedula = codigo
	// metodo para generar un reporte de pagos de un deportista
	string generarReportePagos(string cedula_, ListaEnlazada<Deportista>* listaDeportistas);
	// metodo para pagar x cantidad de meses
	string pagarMeses(string cedula_, int cantidadMeses_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual, double montoMensual);
	// metodo para buscar a los deportistas que no han pagado y cambiar su estado a 'P' de pendiente
	void buscarDeportistasNoPagados(ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual);
};