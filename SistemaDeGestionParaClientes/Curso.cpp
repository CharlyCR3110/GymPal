#include "Curso.h"

Curso::Curso(const Curso& curso_) :
    codigo(curso_.codigo), 
    nombreDelCurso(curso_.nombreDelCurso), 
    nivel(curso_.nivel), 
    descripcion(curso_.descripcion), 
    cantidadMaximaDeGrupos(curso_.cantidadMaximaDeGrupos), 
    cantidadDeGruposActuales(curso_.cantidadDeGruposActuales)
{
    if (curso_.listaGrupos != nullptr)
    {
        this->listaGrupos = new ListaEnlazada<Grupo>;
        Nodo<Grupo>* nodoActual = curso_.listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
			this->listaGrupos->insertar(nodoActual->getDato());
			nodoActual = nodoActual->getSiguiente();
		}
    } 
    else
    {
        this->listaGrupos = nullptr;
    }
}

Curso::Curso(string codigo_, string nombreDelCurso_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos):
    codigo(codigo_),
    nombreDelCurso(nombreDelCurso_),
    nivel(nivel_),
    descripcion(descripcion_),
    cantidadMaximaDeGrupos(cantidadMaximaDeGrupos),
    cantidadDeGruposActuales(0),    // se inicializa en 0
    listaGrupos(new ListaEnlazada<Grupo>)   // se crea una lista vacia
{
}

Curso::~Curso()
{
    if (this->listaGrupos != nullptr)
    {
		delete this->listaGrupos;
	}
}

void Curso::setCodigo(string codigo_)
{
    this->codigo = codigo_;
}

void Curso::setNombreDelCurso(string nombreDelCurso_)
{
    this->nombreDelCurso = nombreDelCurso_;
}

void Curso::setNivel(string nivel_)
{
    this->nivel = nivel_;
}

void Curso::setDescripcion(string descripcion_)
{
    this->descripcion = descripcion_;
}

void Curso::setCantidadMaximaDeGrupos(int cantidadMaximaDeGrupos_)
{
    this->cantidadMaximaDeGrupos = cantidadMaximaDeGrupos_;
}

void Curso::setCantidadDeGruposActuales(int cantidadDeGruposActuales_)
{
    this->cantidadDeGruposActuales = cantidadDeGruposActuales_;
}

void Curso::setListaGrupos(ListaEnlazada<Grupo>* listaGrupos_)
{
    if (listaGrupos_ != nullptr)
    {
        if (this->listaGrupos == nullptr)
        { 
            this->listaGrupos = new ListaEnlazada<Grupo>;
        }
        else
        {
            this->listaGrupos->vaciar();
        }
        Nodo<Grupo>* nodoActual = listaGrupos_->getPrimero();
        while (nodoActual != nullptr)
        {
			this->listaGrupos->insertar(nodoActual->getDato());
			nodoActual = nodoActual->getSiguiente();
		}
    }
    else
    {
        delete this->listaGrupos;
        this->listaGrupos = nullptr;
    }
}

const string Curso::getCodigo() const
{
    return this->codigo;
}

const string Curso::getNombreDelCurso() const
{
    return this->nombreDelCurso;
}


const string Curso::getDescripcion() const
{
    return this->descripcion;
}

const int Curso::getCantidadMaximaDeGrupos() const
{
    return this->cantidadMaximaDeGrupos;
}

const int Curso::getCantidadDeGruposActuales() const
{
    return this->cantidadDeGruposActuales;
}

ListaEnlazada<Grupo>* Curso::getListaGrupos()
{
    return this->listaGrupos;
}

const string Curso::toString() const
{
    stringstream ss;
    ss << "Codigo: " << this->codigo << endl;
    ss << "Nombre del curso: " << this->nombreDelCurso << endl;
    ss << "Nivel: " << this->nivel << endl;
    ss << "Descripcion: " << this->descripcion << endl;
    ss << "Cantidad maxima de grupos: " << this->cantidadMaximaDeGrupos << endl;
    ss << "Cantidad de grupos actuales: " << this->cantidadDeGruposActuales << endl;
    ss << "Lista de grupos: " << endl;
    //ss << *this->listaGrupos << endl; // esto me da errores (desconozco el motivo)

    if (this->listaGrupos != nullptr)
    {
        Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
            ss << *nodoActual->getDato() << endl;
            nodoActual = nodoActual->getSiguiente();
        }
    }
    else
    {
		ss << "No hay grupos" << endl;
    }
    return ss.str();
}

const string Curso::generarReporte() const
{
    stringstream ss;
    ss << "Codigo: " << this->codigo << endl;
    ss << "Nombre del curso: " << this->nombreDelCurso << endl;
    ss << "Nivel: " << this->nivel << endl;
    ss << "Cantidad maxima de grupos: " << this->cantidadMaximaDeGrupos << endl;
    ss << "Detalle de grupos abiertos para el curso: " << endl;
    if (!this->listaGrupos->estaVacia())
    {
        ss << "Grupo" << "\t" << "Cupo" << "\t" << "Cantidad" << endl;
        Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
            ss << nodoActual->getDato()->getNumeroGrupo() << '\t' << nodoActual->getDato()->generarReporte() << endl;
            nodoActual = nodoActual->getSiguiente();
        }
    }
    else
    {
		ss << "No hay grupos" << endl;
    }

    return ss.str();
}

const string Curso::reporteCursoGuiaMatricula() const
{
    stringstream ss;
    ss << "Grupo" << '\t' << "Dia" << '\t' << "    Horario" << '\t'  << "  Cupo" << '\t' << "Cantidad" << endl;
    // mostrar los grupos usando el metodo reporteGrupoGuiaMatricula de la clase Grupo
    if (!this->listaGrupos->estaVacia())
    {
		Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
			ss << nodoActual->getDato()->reporteGrupoGuiaMatricula() << endl;
			nodoActual = nodoActual->getSiguiente();
		}
	}
    else
    {
        ss << "Actualmente no hay grupos disponibles" << endl;
    }

    return ss.str();
}

const string Curso::listadoDeCurso() const
{
    return this->codigo + "  " + this->nombreDelCurso + '\n';
}

const string Curso::generarReporteDeportistasMatriculadosPorGrupo(int numeroGrupo) const
{
    // muestra los deportistas matriculados en un grupo
    stringstream ss;
    ss << "Grupo: " << numeroGrupo << endl;
    if (!this->listaGrupos->estaVacia())
    {
        Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
            if (nodoActual->getDato()->getNumeroGrupo() == numeroGrupo)
            {
                ss << nodoActual->getDato()->mostrarCedulaYNombreInscritos();
				break;
            }
        }
    }
    return ss.str();
}

bool Curso::hayGrupos()
{
    return this->cantidadDeGruposActuales > 0;
}

bool Curso::estaLleno()
{
    // un Curso esta lleno si todos sus grupos estan llenos
    if (!this->listaGrupos->estaVacia())
    {
		Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
            if (!nodoActual->getDato()->estaLleno())
            {
				return false;
			}
			nodoActual = nodoActual->getSiguiente();
		}
		return true;
	}
    else
    {
		return false;
	}
}

bool Curso::grupoLleno(int numeroGrupo)
{
    // un grupo esta lleno si su cantidad de deportistas matriculados es igual a su cupo
    if (!this->listaGrupos->estaVacia())
    {
		Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
        while (nodoActual != nullptr)
        {
            if (nodoActual->getDato()->getNumeroGrupo() == numeroGrupo)
            {
				return nodoActual->getDato()->estaLleno();
			}
			nodoActual = nodoActual->getSiguiente();
		}
		return false;
	}
    else
    {
		return false;
	}
}

void Curso::agregarGrupo(Grupo* grupo_)
{
    if (this->cantidadDeGruposActuales < this->cantidadMaximaDeGrupos)
    {
        this->listaGrupos->insertar(grupo_);
	    this->cantidadDeGruposActuales++;
	}
    else
    {
		throw exception("No se pueden agregar mas grupos");
    }
}

void Curso::eliminarGrupo(Grupo* grupo_)
{
    if (!hayGrupos())
    {
		throw exception("No hay grupos en el curso");
	}

    try {
        this->listaGrupos->eliminarDato(grupo_);
        this->cantidadDeGruposActuales--;
    }
    catch (ListaEnlazadasExceptions& e) {
        cerr << "Error desde Curso::eliminarGrupo: " << e.what() << endl;
	}
}

bool Curso::estaMatriculado(Deportista* deportista_)
{
    if (!hayGrupos())
    {
        throw exception("No hay grupos en el curso Curso::estaMatriculado");
    }
    if (deportista_ == nullptr)
    {
        throw exception("El deportista es nulo desde Curso::estaMatriculado");
    }
    Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
    while (nodoActual != nullptr)
    {
		if (nodoActual->getDato()->estaInscrito(deportista_))
		{
			return true;
		}
		nodoActual = nodoActual->getSiguiente();
    }

    return false;
}

void Curso::matricularEnGrupo(int numeroGrupo, Deportista* deportista)
{
    if (!hayGrupos())
    {
		throw exception("No hay grupos en el curso");
	}
	Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
    while (nodoActual != nullptr)
    {
        // el numero de grupo es conforme a la posicion en la lista
        if (nodoActual->getDato()->getNumeroGrupo() == numeroGrupo)
        {
			nodoActual->getDato()->agregarDeportista(deportista);
            deportista->setcantidadDeCursosMatriculados(deportista->getcantidadDeCursosMatriculados() + 1);
			return;
		}
		nodoActual = nodoActual->getSiguiente();
	}
	throw exception("No se encontro el grupo");
}

Grupo* Curso::obtenerGrupo(int numeroGrupo)
{
    if (!hayGrupos())
    {
        throw exception("No hay grupos en el curso");   // hacer excepcion
    }

    Nodo<Grupo>* nodoActual = this->listaGrupos->getPrimero();
    while (nodoActual != nullptr)
    {
        if (nodoActual->getDato()->getNumeroGrupo() == numeroGrupo)
        {
            return nodoActual->getDato();
        }
        nodoActual = nodoActual->getSiguiente();
    }
    throw exception("No se encontro el grupo");
}

Curso& Curso::operator=(const Curso& curso_)
{
    if (this != &curso_)
    {
		this->codigo = curso_.codigo;
		this->nombreDelCurso = curso_.nombreDelCurso;
		this->nivel = curso_.nivel;
		this->descripcion = curso_.descripcion;
		this->cantidadMaximaDeGrupos = curso_.cantidadMaximaDeGrupos;
		this->cantidadDeGruposActuales = curso_.cantidadDeGruposActuales;

        if (curso_.listaGrupos != nullptr)
        {
            if (this->listaGrupos == nullptr)
            {
				this->listaGrupos = new ListaEnlazada<Grupo>;
			}
            else
            {
				this->listaGrupos->vaciar();
			}
			Nodo<Grupo>* nodoActual = curso_.listaGrupos->getPrimero();
            while (nodoActual != nullptr)
            {
			    this->listaGrupos->insertar(nodoActual->getDato());
			    nodoActual = nodoActual->getSiguiente();
		    }
		}
        else
        {
			delete this->listaGrupos;
			this->listaGrupos = nullptr;
		}
	}
    return *this;
}

const string Curso::getNivel() const
{
    return this->nivel;
}

ostream& operator<<(ostream& out, const Curso& curso_)
{
    out << curso_.toString();
    return out;
}