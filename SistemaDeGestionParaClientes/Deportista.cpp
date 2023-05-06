#include "Deportista.h"
#include "Curso.h"

Deportista::Deportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_):
    cedula(cedula_),
	nombre(nombre_),
	telefono(telefono_),
    estado('A'),
    cantidadDeCursosMatriculados(0),
    cantidadDePagos(0)
{
    try {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
	}
    catch (FechaInvalidaException& e) 
    {
		throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }

    this->listaPagos = new ListaEnlazada<Pago>();
    this->listaCursos = new ListaEnlazada<Curso>();
}

Deportista::Deportista(const Deportista& deportista_): 
    cedula(deportista_.cedula),
    nombre(deportista_.nombre),
    telefono(deportista_.telefono),
    estado(deportista_.estado),
    listaPagos(deportista_.listaPagos),
    cantidadDeCursosMatriculados(deportista_.cantidadDeCursosMatriculados),
    listaCursos(deportista_.listaCursos),
    cantidadDePagos(deportista_.cantidadDePagos)
{
    try {
		this->fechaNacimiento = new Fecha(*deportista_.fechaNacimiento);
	}
    catch (FechaInvalidaException& e)
    {
		throw DeportistaInvalidoException("Fecha de nacimiento invalida");
	}
}

Deportista::~Deportista()
{
}

void Deportista::setCedula(string cedula_)
{
    this->cedula = cedula_;
}

void Deportista::setNombre(string nombre_)
{
    this->nombre = nombre_;
}

void Deportista::setTelefono(string telefono_)
{
    this->telefono = telefono_;
}

void Deportista::setFechaNacimiento(Fecha* fechaNacimiento_)
{
    try
    {
        this->fechaNacimiento = new Fecha(*fechaNacimiento_);
    }
    catch (FechaInvalidaException& e)
    {
        throw DeportistaInvalidoException("Fecha de nacimiento invalida");
    }
}

void Deportista::setEstado(char estado)
{
    this->estado = estado;
}

void Deportista::setcantidadDeCursosMatriculados(int cantidadDeCursosMatriculados_)
{
    this->cantidadDeCursosMatriculados = cantidadDeCursosMatriculados_;
}

void Deportista::setCantidadDePagos(int cantidadDePagos_)
{
    this->cantidadDePagos = cantidadDePagos_;
}

void Deportista::actualizarEstado(char estado_)
{
//Nota: el estado solo puede ser cambiando de activo a inactivo, el estado de morosidad debe ser determinado automáticamente por el sistema.
    if (this->estado == 'P')
    {
        throw DeportistaInvalidoException("El estado del deportista no puede ser cambiado a inactivo, ya que se encuentra en morosidad. PAGUE, PAGUE");
    }

    if (toupper(estado_) == 'A' || toupper(estado_) == 'I')
    {
		this->estado = toupper(estado_);
	}
    else
    {
		throw DeportistaInvalidoException("El estado del deportista no puede ser cambiado a ese estado. Solo puede ser cambiado a activo o inactivo");
	}
}

const string Deportista::getCedula() const
{
    return this->cedula;
}

const string Deportista::getNombre() const
{
    return this->nombre;
}

const string Deportista::getTelefono() const
{
    return this->telefono;
}

Fecha* Deportista::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

const char Deportista::getEstado() const
{
    return this->estado;
}

ListaEnlazada<Pago>* Deportista::getPagos()
{
    return this->listaPagos;
}

const int Deportista::getCantidadDePagos() const
{
    return this->cantidadDePagos;
}

const int Deportista::getcantidadDeCursosMatriculados() const
{
    return this->cantidadDeCursosMatriculados;
}

ListaEnlazada<Curso>* Deportista::getListaCursos()
{
    return nullptr;
}

const string Deportista::getCodigo() const
{
    return this->cedula;
}

void Deportista::agregarCurso(Curso* curso_)
{
    this->listaCursos->insertar(curso_);
    this->cantidadDeCursosMatriculados++;
}

void Deportista::eliminarCurso(Curso* curso_)
{
    this->listaCursos->eliminarDato(curso_);
	this->cantidadDeCursosMatriculados--;
}

const string Deportista::mostrarCursosMatriculados() const
{
    if (listaCursos->estaVacia())
    {
        throw exception("El deportista no esta matriculado en ningun curso");   //crear excepcion personalizada
    }
    stringstream ss;
    Nodo<Curso> *nodoActual = listaCursos->getPrimero();
    while (nodoActual != nullptr)
    {
        ss << "(" << nodoActual->getDato()->getCodigo() << ")\t" << nodoActual->getDato()->getNombreDelCurso() << "\tGrupo #";
        //se busca en la lista de grupos el grupo al que pertenece el curso
        Nodo<Grupo>* nodoGrupo = nodoActual->getDato()->getListaGrupos()->getPrimero();
        while (nodoGrupo != nullptr)
        {
            //se busca en la lista de deportistas del grupo el deportista
            Nodo<Deportista>* nodoDeportista = nodoGrupo->getDato()->getDeportistasInscritos()->getPrimero();
            while (nodoDeportista != nullptr)
            {
                if (nodoDeportista->getDato()->getCedula() == this->cedula)
                {
					ss << nodoGrupo->getDato()->getNumeroGrupo() << endl;
					break;
				}
				nodoDeportista = nodoDeportista->getSiguiente();
			}
			nodoGrupo = nodoGrupo->getSiguiente();
		}
		nodoActual = nodoActual->getSiguiente();
	}
    	
    return ss.str();
}

Deportista& Deportista::operator=(const Deportista& deportista_)
{
    if (this != &deportista_)
    {
		this->cedula = deportista_.cedula;
		this->nombre = deportista_.nombre;
		this->telefono = deportista_.telefono;
		this->fechaNacimiento = deportista_.fechaNacimiento;
		this->estado = deportista_.estado;
	}
    return *this;
}

bool Deportista::operator!=(const Deportista& deportista_) const
{
    return this->cedula != deportista_.cedula;  // unicamente depende de la cedula porque lo demas puede coincidir
}

ostream& operator<<(ostream& out, Deportista& deportista_)
{
    out << deportista_.toString();
    return out;
}