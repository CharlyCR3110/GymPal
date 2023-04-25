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
    return ss.str();
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

ostream& operator<<(ostream& out, Curso& curso_)
{
    out << curso_.toString();
    return out;
}