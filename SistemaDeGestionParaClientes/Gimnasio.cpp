#include "Gimnasio.h"

Gimnasio::Gimnasio() :
	nombreDelGimnasio("Gimnasio UNAfitness"),
	montoMensual(20000),
	fechaActual(new Fecha()),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlPagos(),
	gestorDeArchivos()
{
}

Gimnasio::Gimnasio(string nombreDelGimnasio_, double montoMensual_, Fecha* fechaActual_):
	nombreDelGimnasio(nombreDelGimnasio_),
	fechaActual(fechaActual_),
	montoMensual(montoMensual_),
	listaDeportistas(new ListaEnlazada<Deportista>()),
	listaCursos(new ListaEnlazada<Curso>()),
	controlPagos(),
	gestorDeArchivos()
{
}

Gimnasio::~Gimnasio()
{
	if (this->fechaActual != nullptr)
	{
		delete this->fechaActual;
		this->fechaActual = nullptr;
	}

	if (this->listaCursos != nullptr)
	{
		delete this->listaCursos;
		this->listaCursos = nullptr;
	}

	if (this->listaDeportistas != nullptr)
	{
		delete this->listaDeportistas;
		this->listaDeportistas = nullptr;
	}

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
	this->listaDeportistas = new ListaEnlazada<Deportista>(*listaDeportistas_);
}

void Gimnasio::setListaCursos(ListaEnlazada<Curso>* listaCursos_)
{
	this->listaCursos = new ListaEnlazada<Curso>(*listaCursos_);
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

string Gimnasio::registrarPago(string cedula_, int mesesAPagar_)
{
	try
	{
		return this->controlPagos->pagarMeses(cedula_, mesesAPagar_, this->listaDeportistas, this->fechaActual, this->montoMensual);
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
	if (curso == nullptr)
	{
		throw CursoNoEncontradoException();
	}

	if (deportista == nullptr)
	{
		throw DeportistaNoEncontradoException();
	}

	if (deportista->getcantidadDeCursosMatriculados() >= MAX_CURSOS)
	{
		string mensajeError = "Error: El deportista ya alcanzo el maximo de cursos matriculados. Maximo: " + std::to_string(MAX_CURSOS);
		throw CupoMaximoExcedido(mensajeError);
	}
	// si el deportista ya esta matriculado en el curso
	if (curso->estaMatriculado(deportista))
	{
		string mensajeError = "Error: El deportista " + deportista->getNombre() + " ya esta matriculado en el curso " + curso->getCodigo();
		throw DeportistaYaMatriculadoException(mensajeError);
	}
	// si el curso esta lleno
	if (curso->grupoLleno(numeroGrupo_))
	{
		string mensajeError = "Error: El grupo " + std::to_string(numeroGrupo_) + " del curso " + curso->getCodigo() + " esta lleno";
		throw CupoMaximoExcedido(mensajeError);
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
		throw CursoNoEncontradoException();
	}

	if (deportista == nullptr)
	{
		throw DeportistaNoEncontradoException();
	}
	// si el deportista no esta matriculado en el curso
	if (!curso->estaMatriculado(deportista))
	{
		string mensajeError = "Error: El deportista " + deportista->getNombre() + " no esta matriculado en el curso " + curso->getCodigo();
		throw DeportistaYaMatriculadoException(mensajeError);
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
		throw CursoNoEncontradoException();
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
	if (this->listaDeportistas != nullptr)
	{
		if (this->listaDeportistas->estaVacia())
		{
			throw ListaVaciaException();	// si da problemas comentar esta linea y descomentar la de abajo
			//throw runtime_error("No hay deportistas registrados");
		}

		if (!this->listaDeportistas->existeItemConCodigo(cedula_))
		{
			throw ElementoNoEncontradoException<Deportista>();	// si da problemas comentar esta linea y descomentar la de abajo
			//throw runtime_error("No se encontro el deportista");
		}
	}
	else
	{
		throw ListaVaciaException();	// si da problemas comentar esta linea y descomentar la de abajo
		//throw runtime_error("No hay deportistas registrados");
	}

	if (listaDeportistas->buscarPorCodigo(cedula_)->getPagos() == nullptr)
	{
		throw ElementoNoEncontradoException<Pago>();	// si da problemas comentar esta linea y descomentar la de abajo
		//throw runtime_error("El deportista no tiene pagos registrados");
	}


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

void Gimnasio::buscarDeportistasNoPagados()
{
	try
	{
		controlPagos->buscarDeportistasNoPagados(this->listaDeportistas, this->fechaActual);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::guardarCursosYGrupos()
{
	try
	{
		gestorDeArchivos.guardarCursosYGrupos(this->listaCursos);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

void Gimnasio::guardarEnArchivoDeportistasYSusPagos()
{
	try
	{
		gestorDeArchivos.guardarDeportistasYPagos(this->listaDeportistas);
	}
	catch (exception& e)
	{
		throw exception(e.what());
	}
}

const void Gimnasio::guardarParaMatricular() const
{
	string texto = toStringParaGuardarCursoGrupoYCedulaDeLosDeportistasAsociados();
	gestorDeArchivos.guardarCursoGrupoYCedulaDeLosDeportistasAsociados(texto);
}

const string Gimnasio::toStringParaGuardarCursoGrupoYCedulaDeLosDeportistasAsociados() const
{
	stringstream ss;
	Curso* curso = nullptr;
	Grupo* grupo = nullptr;
	Nodo<Curso>* nodoCursoActual = this->listaCursos->getPrimero();
	while (nodoCursoActual != nullptr)
	{
		curso = nodoCursoActual->getDato();
		if (curso != nullptr)
		{
			ss << curso->getCodigo() << ";" << curso->getCantidadDeGruposActuales() << ';';
			Nodo<Grupo>* nodoGrupoActual = curso->getListaGrupos()->getPrimero();
			while (nodoGrupoActual != nullptr)
			{
				grupo = nodoGrupoActual->getDato();
				ss << grupo->getNumeroGrupo() << ";" << grupo->getCantidadDeInscritos() << "-";
				Nodo<Deportista>* deportistaActual = grupo->getDeportistasInscritos()->getPrimero();
				while (deportistaActual != nullptr)
				{
					
					ss << deportistaActual->getDato()->getCedula() << ";";
					deportistaActual = deportistaActual->getSiguiente();
				}
				
				nodoGrupoActual = nodoGrupoActual->getSiguiente();
			}
		}
		ss << '\n';
		nodoCursoActual = nodoCursoActual->getSiguiente();
	}
	return ss.str();
}

const string Gimnasio::toStringParaGuardarDatosDelGimnasio() const
{
	stringstream ss;
	ss << this->nombreDelGimnasio << ';' << this->montoMensual << ';';
	return ss.str();
}

void Gimnasio::prueba()
{
	cout << toStringParaGuardarCursoGrupoYCedulaDeLosDeportistasAsociados();
}
