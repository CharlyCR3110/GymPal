#include "ControlPagos.h"

ControlPagos::ControlPagos(double montoMensual_, ListaEnlazada<Deportista>* listaDeportistas_, Fecha* fechaActual_)
{
	if (montoMensual_ < 0)
		throw ControlPagosInvalidoException("Monto mensual invalido");	//ControlPagosInvalidoException

	this->montoMensual = montoMensual_;

	if (listaDeportistas_ == nullptr)
	{
		this->listaDeportistas = new ListaEnlazada<Deportista>();
	}
	else
	{
		this->listaDeportistas = listaDeportistas_;
	}
	
	if (fechaActual_ == nullptr)
	{
		this->fechaActual = new Fecha();
	}
	else
	{
		this->fechaActual = fechaActual_;
	}


}

ControlPagos::ControlPagos(const ControlPagos& controlPagos_):
	montoMensual(controlPagos_.montoMensual),
	listaDeportistas(controlPagos_.listaDeportistas),
	fechaActual(controlPagos_.fechaActual)
{
}

ControlPagos::~ControlPagos()
{
}

void ControlPagos::registrarPago(string cedula_, string mesCancelado_, double monto_)
{
	Deportista* deportista;
	try 
	{
		deportista = this->listaDeportistas->buscarPorCodigo(cedula_);
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

string ControlPagos::generarReportePagos(string cedula_)
{
	Deportista* deportista;
	try
	{
		deportista = this->listaDeportistas->buscarPorCodigo(cedula_);
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

void ControlPagos::pagarMeses(string cedula_, int cantidadMeses_)
{
	Deportista* deportista;
	try
	{
		deportista = this->listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw DeportistaNoEncontradoException();
	}

	string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
							 "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

	// si yo estoy en enero y quiero pagar 3 meses, entonces debo pagar enero, febrero y marzo
	int mesActual = this->fechaActual->getMes() - 1;

	for (int i = 0; i < cantidadMeses_; i++)
	{
		string mes = meses[mesActual];
		double monto = this->montoMensual;

		try {
			this->registrarPago(cedula_, mes, monto);
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
