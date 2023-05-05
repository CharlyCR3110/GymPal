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
	Deportista* deportista = nullptr;

	try
	{
		deportista = listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		//throw DeportistaNoEncontradoException();
		throw runtime_error("El deportista no esta registrado");
	}

	if (deportista == nullptr)
	{
		//throw DeportistaNoEncontradoException();
		throw runtime_error("El deportista no esta registrado");
	}

	if (deportista->getPagos() == nullptr)
	{
		throw runtime_error("El deportista no tiene pagos registrados");
	}

	if (deportista->getPagos()->estaVacia())
	{
		throw runtime_error("El deportista no tiene pagos registrados");
		//throw PagosNoRegistradosException().what();	// me esta dando problemas
	}

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

	ListaEnlazada<Pago>* pagosDelDeportista = (deportista->getPagos());

	string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
							 "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

	
	int ultimoMesPagado = 0;
	if (pagosDelDeportista->estaVacia())
	{
		ultimoMesPagado = fechaActual->getMes() - 1;
	}
	else
	{
		ultimoMesPagado = deportista->getPagos()->getUltimo()->getDato()->getFecha()->getMes() - 1;
	}



	stringstream ss;
	ss << "Monto a pagar: " << montoMensual * cantidadMeses_ << endl << endl;
	ss << "Excelente se ha cancelado las siguiente cuotas: " << endl;


	for (int i = 0; i < cantidadMeses_; i++)
	{
		string mes = meses[ultimoMesPagado];
		double monto = montoMensual;

		pagosDelDeportista->insertar(new Pago(fechaActual, mes, monto));
		try {
			cout << "-----------------------------------------------------------" << endl;
			if (deportista->getPagos()->estaVacia())
			{
				cout << "la lista esta vacia" << endl;
			}
			else
			{
				cout << deportista->getPagos()->toString();
			}
			cout << "Se supone que se agrego el pago" << endl;
			cout << "-----------------------------------------------------------" << endl;

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
	ss << "El deportista " << deportista->getNombre() << " ha pagado " << cantidadMeses_ << " meses" << endl;
	ss << "Debe de pagar haste el mes de: " << meses[ultimoMesPagado] << " " << fechaActual->getAnio() << endl;

	cout << "AL FINAL CON LOS PAGOS" << endl;
	cout << deportista->getPagos()->toString();
	return ss.str();
}