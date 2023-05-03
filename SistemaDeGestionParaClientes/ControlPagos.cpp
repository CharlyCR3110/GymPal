#include "ControlPagos.h"

ControlPagos::ControlPagos()
{
}


ControlPagos::~ControlPagos()
{
}

void ControlPagos::registrarPago(string cedula_, string mesCancelado_, double monto_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual)
{
	Deportista* deportista;
	try 
	{
		deportista = listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw DeportistaNoEncontradoException();
	}

	Pago* pago;
	try 
	{
		pago = new Pago(fechaActual, mesCancelado_, monto_);
	}
	catch (exception& e)
	{
		throw PagoInvalidoException();
	}

	try 
	{
		deportista->getPagos()->insertar(pago);
	}
	catch (exception& e)
	{
		throw PagoInvalidoException();
	}

}

string ControlPagos::generarReportePagos(string cedula_, ListaEnlazada<Deportista>* listaDeportistas)
{
	Deportista* deportista;
	try
	{
		deportista = listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw DeportistaNoEncontradoException();
	}

	if (deportista->getPagos()->estaVacia())
		throw PagosNoRegistradosException();

	stringstream ss;
	ss << "Reporte de pagos de " << deportista->getNombre() << endl;
	ss << "Fecha de Pago" << '\t' << "Mes Cancelado" << '\t' << "Monto" << endl;
	ss << deportista->getPagos()->toString();

	return ss.str();
}

void ControlPagos::pagarMeses(string cedula_, int cantidadMeses_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual, double montoMensual)
{
	Deportista* deportista;
	try
	{
		deportista = listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw DeportistaNoEncontradoException();
	}

	string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
							 "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

	// si yo estoy en enero y quiero pagar 3 meses, entonces debo pagar enero, febrero y marzo
	int mesActual = fechaActual->getMes() - 1;

	for (int i = 0; i < cantidadMeses_; i++)
	{
		string mes = meses[mesActual];
		double monto = montoMensual;

		try {
			registrarPago(cedula_, mes, monto, listaDeportistas, fechaActual);
		}
		catch (exception& e)
		{
			throw PagoInvalidoException();
		}

		mesActual++;
		if (mesActual == 11)
			mesActual = 0;
	}
}