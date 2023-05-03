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

string ControlPagos::pagarMeses(string cedula_, int cantidadMeses_, ListaEnlazada<Deportista>* listaDeportistas, Fecha* fechaActual_, double montoMensual)
{
	Fecha* fechaActual = new Fecha(fechaActual_->getDia(), fechaActual_->getMes(), fechaActual_->getAnio());	// copia de la fecha actual para no modificarla
	Deportista* deportista = nullptr;
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


	int ultimoMesPagado = deportista->getPagos()->getUltimo()->getDato()->getFecha()->getMes() - 1;

	stringstream ss;
	ss << "Excelente se ha cancelado las siguiente cuotas: " << endl;


	for (int i = 0; i < cantidadMeses_; i++)
	{
		string mes = meses[ultimoMesPagado];
		double monto = montoMensual;

		try {
			registrarPago(cedula_, mes, monto, listaDeportistas, fechaActual);
			ss << "-" << mes << " " << fechaActual->getAnio() << endl;
		}
		catch (exception& e)
		{
			throw PagoInvalidoException();
		}

		ultimoMesPagado++;
		if (ultimoMesPagado == 12)
		{
			ultimoMesPagado = 0;
			fechaActual->setAnio(fechaActual->getAnio() + 1);
		}
	}
	delete fechaActual;
	return ss.str();
}