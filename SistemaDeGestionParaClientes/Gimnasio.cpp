#include "Gimnasio.h"

Gimnasio::Gimnasio():
	nombreDelGimnasio("Gimnasio UNAfitness"),
	montoMensual(20000),
	fechaActual(new Fecha()),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlPagos()
{
}

Gimnasio::Gimnasio(string nombreDelGimnasio_, double montoMensual_, Fecha* fechaActual_):
	nombreDelGimnasio(nombreDelGimnasio_),
	fechaActual(fechaActual_),
	montoMensual(montoMensual_),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlPagos()
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
	delete controlPagos;
}

void Gimnasio::setNombreDelGimnasio(string nombreDelGimnasio_)
{
	this->nombreDelGimnasio = nombreDelGimnasio_;
}

void Gimnasio::setMontoMensual(double montoMensual_)
{
	this->montoMensual = montoMensual_;
}

void Gimnasio::setFechaActual(Fecha* fechaActual_)
{
	this->fechaActual = fechaActual_;
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
	Curso* curso = new Curso(codigo_, nombre_, nivel_, descripcion_, cantidadMaximaDeGrupos_);
	try
	{
		listaCursos->insertar(curso);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::registrarDeportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, int horasEntremiento_, double temperaturaPromedio_, int cantidadParticipacionesIronMan_, int cantidadTriatlonesGanados_, char sexo_, double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_)
{
	try
	{
		Deportista* deportista = new Triatlonista(cedula_, nombre_, telefono_, fechaNacimiento_, horasEntremiento_, temperaturaPromedio_, cantidadParticipacionesIronMan_, cantidadTriatlonesGanados_, sexo_, estatura_, masaMuscular_, peso_, porcentajeGrasaCorporal_, fechaActual);
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
		this->controlPagos->pagarMeses(cedula_, mesesAPagar_, this->listaDeportistas, this->fechaActual, this->montoMensual);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::matricularEnGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_)
{
	Curso* curso = nullptr;
	Deportista* deportista = nullptr;
	try
	{
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
		deportista = listaDeportistas->buscarPorCodigo(cedulaDeportista_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
	if (curso == nullptr || deportista == nullptr)
	{
		throw exception("No se encontro el curso o el deportista");
	}

	if (deportista->getcantidadDeCursosMatriculados() >= MAX_CURSOS)
	{
		throw exception("El deportista ya tiene 3 cursos matriculados");
	}
	// si el deportista ya esta matriculado en el curso
	if (curso->estaMatriculado(deportista))
	{
		throw exception("El deportista ya esta matriculado en el curso");
	}
	// si el curso esta lleno
	if (curso->grupoLleno(numeroGrupo_))
	{
		throw exception("El curso esta lleno");
	}

	// hacer la matricula
	try
	{
		curso->matricularEnGrupo(numeroGrupo_, deportista);
		deportista->agregarCurso(curso);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::desmatricularDeGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_)
{
	Curso* curso = nullptr;
	Deportista* deportista = nullptr;
	try
	{
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
		deportista = listaDeportistas->buscarPorCodigo(cedulaDeportista_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
	if (curso == nullptr)
	{
		throw exception("No se encontro el curso");
	}

	if (deportista == nullptr)
	{
		throw exception("No se encontro el deportista");
	}
	// si el deportista no esta matriculado en el curso
	if (!curso->estaMatriculado(deportista))
	{
		throw exception("El deportista no esta matriculado en el curso");
	}
	// hacer la desmatricula
	try
	{
		curso->desmatricularDeGrupo(numeroGrupo_, deportista);
		deportista->eliminarCurso(curso);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::agregarGrupo(string codigoCurso_, Grupo* grupo_)
{
	Curso* curso = nullptr;
	try
	{
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
	if (curso != nullptr)
	{
		curso->agregarGrupo(grupo_);
	}
	else
	{
		throw exception("No se encontro el curso.");
	}
}

const string Gimnasio::generarReporteCursoCod(string codigo_) const
{
	Curso* curso = nullptr;
	try
	{
		curso = listaCursos->buscarPorCodigo(codigo_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
	if (curso != nullptr)
	{
		return curso->generarReporte();
	}
	else
	{
		return "No se encontro el curso";
	}
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
		ss << this->controlPagos->generarReportePagos(cedula_, this->listaDeportistas);
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
	Nodo<Curso>* cursoActual;
	try
	{
		cursoActual = listaCursos->getPrimero();
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	//recorrer la lista y llamar al metodo listadoDeCurso() de cada curso
	stringstream ss;
	ss << "Listado de cursos: " << endl;
	if (cursoActual != nullptr)
	{
		while (cursoActual != nullptr)
		{
			ss << cursoActual->getDato()->listadoDeCurso() << endl;
			cursoActual = cursoActual->getSiguiente();
		}
	}
	else
	{
		throw exception("No hay cursos registrados.");
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

const string Gimnasio::generarReporteDeportistasPorEstado(char estado_) const
{
	if (listaDeportistas->estaVacia())
	{
		throw exception("No hay deportistas registrados.");
	}

	stringstream ss;
	try
	{
		ss << this->listaDeportistas->mostrarPorEstado(estado_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}

	return ss.str();
}

const string Gimnasio::generarReporteDeportistasMatriculadosPorGrupo(string codigoCurso_, int numeroGrupo_) const
{
	stringstream ss;
	Curso* curso = nullptr;
	try
	{
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
	if (curso != nullptr)
	{
		ss << curso->generarReporteDeportistasMatriculadosPorGrupo(numeroGrupo_);
	}
	else
	{
		ss << "No se encontro el curso." << endl;
	}

	return ss.str();
}

const string Gimnasio::generarReporteCursosMatriculados(string cedula_) const
{
	if (listaDeportistas->estaVacia())
	{
		throw "No hay deportistas registrados.";
	}

	if (listaCursos->estaVacia())
	{
		throw "No hay cursos registrados.";
	}

	Deportista* deportista = nullptr;
	try
	{
		deportista = listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}



	stringstream ss;
	ss << "Cursos matriculados por el deportista con cedula " << cedula_ << ":" << endl;
	try {
		ss << deportista->mostrarCursosMatriculados();
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}

	return ss.str();
}

Deportista* Gimnasio::buscarDeportista(string cedula_)
{
	Deportista* deportista = nullptr;
	try
	{
		deportista = this->listaDeportistas->buscarPorCodigo(cedula_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}

	return deportista;
}

Curso* Gimnasio::buscarCurso(string codigo_)
{
	Curso* curso = nullptr;
	try
	{
		curso = this->listaCursos->buscarPorCodigo(codigo_);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
	return curso;
}

bool Gimnasio::existeCursoConCodigo(string codigo_)
{
	return listaCursos->existeItemConCodigo(codigo_);
}

bool Gimnasio::existeDeportistaConCedula(string cedula_)
{
	return listaDeportistas->existeItemConCodigo(cedula_);
}
