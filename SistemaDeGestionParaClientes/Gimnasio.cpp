#include "Gimnasio.h"

//control pagos constructor => double montoMensual_ = 0, ListaEnlazada<Deportista>* listaDeportistas_ = nullptr, Fecha* fechaActual_ = nullptr
Gimnasio::Gimnasio():
	nombreDelGimnasio("Gimnasio UNAfitness"),
	montoMensual(20000),
	fechaActual(new Fecha()),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlCursos(new ControlCursos(listaCursos, listaDeportistas, fechaActual)),
	controlPagos(new ControlPagos(montoMensual,listaDeportistas, fechaActual))
{
}

Gimnasio::Gimnasio(string nombreDelGimnasio_, double montoMensual_, Fecha* fechaActual_):
	nombreDelGimnasio(nombreDelGimnasio_),
	fechaActual(fechaActual_),
	montoMensual(montoMensual_),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlCursos(new ControlCursos(listaCursos, listaDeportistas, fechaActual_)),
	controlPagos(new ControlPagos(montoMensual_, listaDeportistas, fechaActual_))
{
}

//Gimnasio::Gimnasio(const Gimnasio& gimnasio_)
//{
//}

Gimnasio::~Gimnasio()
{
	delete fechaActual;
	delete listaDeportistas;
	delete listaCursos;
	delete controlCursos;
	delete controlPagos;
}

void Gimnasio::setNombreDelGimnasio(string nombreDelGimnasio_)
{
	this->nombreDelGimnasio = nombreDelGimnasio_;
}

void Gimnasio::setMontoMensual(double montoMensual_)
{
	try
	{
		this->controlPagos->setMontoMensual(montoMensual_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	this->montoMensual = montoMensual_;
}

void Gimnasio::setFechaActual(Fecha* fechaActual_)
{
	this->fechaActual = fechaActual_;
}

void Gimnasio::setControlCursos(ControlCursos* controlCursos_)
{
	this->controlCursos = controlCursos_;
}

void Gimnasio::setControlPagos(ControlPagos* controlPagos_)
{
	this->controlPagos = controlPagos_;
}

void Gimnasio::setListaDeportistas(ListaEnlazada<Deportista>* listaDeportistas_)
{
	this->listaDeportistas = listaDeportistas_;
}

void Gimnasio::setListaCursos(ListaEnlazada<Curso>* listaCursos_)
{
	this->listaCursos = listaCursos_;
}

const string Gimnasio::getNombreDelGimnasio() const
{
	return this->nombreDelGimnasio;
}

const double Gimnasio::getMontoMensual() const
{
	return this->montoMensual;
}

Fecha* Gimnasio::getFechaActual()
{
	return this->fechaActual;
}

ControlCursos* Gimnasio::getControlCursos()
{
	return this->controlCursos;
}

ControlPagos* Gimnasio::getControlPagos()
{
	return this->controlPagos;
}

ListaEnlazada<Deportista>* Gimnasio::getListaDeportistas()
{
	return this->listaDeportistas;
}

ListaEnlazada<Curso>* Gimnasio::getListaCursos()
{
	return this->listaCursos;
}

//string codigo_, string nombre_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos_
void Gimnasio::registrarCurso(string codigo_, string nombre_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos_)
{
	try
	{
		controlCursos->registrarCurso(codigo_, nombre_, nivel_, descripcion_, cantidadMaximaDeGrupos_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::registrarDeportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, char estado_, int horasEntremiento_, double temperaturaPromedio_, int cantidadParticipacionesIronMan_, int cantidadTriatlonesGanados_, char sexo_, double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_)
{
	try
	{
		Deportista* deportista = new Triatlonista(cedula_, nombre_, telefono_, fechaNacimiento_, estado_, horasEntremiento_, temperaturaPromedio_, cantidadParticipacionesIronMan_, cantidadTriatlonesGanados_, sexo_, estatura_, masaMuscular_, peso_, porcentajeGrasaCorporal_, fechaActual);
		listaDeportistas->insertar(deportista);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::registrarPago(string cedula_, int mesesAPagar_)
{
	try
	{
		this->controlPagos->pagarMeses(cedula_, mesesAPagar_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::matricularEnGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_)
{
	try
	{
		this->controlCursos->matricularEnGrupo(codigoCurso_, numeroGrupo_, cedulaDeportista_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::desmatricularDeGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_)
{
	try
	{
		this->controlCursos->desmatricularDeGrupo(codigoCurso_, numeroGrupo_, cedulaDeportista_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::agregarGrupo(string codigoCurso_, Grupo* grupo_)
{
	try
	{
		this->controlCursos->agregarGrupo(codigoCurso_, grupo_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

const string Gimnasio::generarReporteCursoCod(string codigo_) const
{
	stringstream ss;
	try
	{
		ss << this->controlCursos->generarReporteCurso(codigo_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

const string Gimnasio::generarReporteDeportistaCed(string cedula_) const
{
	Deportista* deportista = nullptr;
	stringstream ss;
	try
	{
		deportista = this->listaDeportistas->buscarPorCodigo(cedula_);
		ss << deportista->detalleDeportista();
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

const string Gimnasio::generarReportePagosCed(string cedula_) const
{
	stringstream ss;
	try
	{
		ss << this->controlPagos->generarReportePagos(cedula_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

const string Gimnasio::generarReporteDeportistas() const
{
	stringstream ss;
	try
	{
		ss << this->listaDeportistas->toString();
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

const string Gimnasio::generarListadoCursos() const
{
	stringstream ss;
	try
	{
		ss << this->controlCursos->reporteListadoCursos();
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

//const string Gimnasio::generarReportePagos() const
//{
//	stringstream ss;
//	try
//	{
//		ss << this->controlPagos->;
//	}
//	catch (exception& e)
//	{
//		throw exception(e.what());
//	}
//	return ss.str();
//}

const string Gimnasio::generarReporteDeportistasMatriculadosPorGrupo(string codigoCurso_, int numeroGrupo_) const
{
	stringstream ss;
	try
	{
		ss << this->controlCursos->generarReporteDeportistasMatriculadosPorGrupo(codigoCurso_, numeroGrupo_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return ss.str();
}

const string Gimnasio::generarReporteCursosMatriculados(string cedula_) const
{
	try
	{
		return this->controlCursos->reporteCursosMatriculados(cedula_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}
