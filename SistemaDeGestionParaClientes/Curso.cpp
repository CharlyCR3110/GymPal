#include "Curso.h"

Curso::Curso(const Curso& curso_)
{
    this->descripcion = curso_.descripcion;
	this->nivel = curso_.nivel;
	this->cupoMaximo = curso_.cupoMaximo;
	this->fechaInicio = new Fecha(*curso_.fechaInicio);
	this->fechaFin = new Fecha(*curso_.fechaFin);
	this->horario = curso_.horario;
	this->cantidadClientes = curso_.cantidadClientes;
	this->listaClientesInscritos = new ListaEnlazada<Cliente>(*curso_.listaClientesInscritos);
}

Curso::Curso(string descripcion_, string nivel_, int cupoMaximo_, Fecha* fechaInicio_, Fecha* fechaFin_, string horario_)
    : descripcion(descripcion_), nivel(nivel_), cupoMaximo(cupoMaximo_), fechaInicio(fechaInicio_), fechaFin(fechaFin_), horario(horario_)
{
    this->cantidadClientes = 0;
    this->listaClientesInscritos = new ListaEnlazada<Cliente>();
}

Curso::~Curso()
{
}

void Curso::setDescripcion(string descripcion_)
{
    this->descripcion = descripcion_;
}

void Curso::setNivel(string nivel_)
{
    this->nivel = nivel_;
}

void Curso::setCupoMaximo(int cupoMaximo_)
{
    this->cupoMaximo = cupoMaximo_;
}

void Curso::setFechaInicio(Fecha* fechaInicio_)
{
    this->fechaInicio = fechaInicio_;
}

void Curso::setFechaFin(Fecha* fechaFin_)
{
    this->fechaFin = fechaFin_;
}

void Curso::setHorario(string horario_)
{
    this->horario = horario_;
}

const string Curso::getDescripcion() const
{
    return this->descripcion;
}

const string Curso::getNivel() const
{
    return this->nivel;
}

const int Curso::getCupoMaximo() const
{
    return this->cupoMaximo;
}

Fecha* Curso::getFechaInicio()
{
    return this->fechaInicio;
}

Fecha* Curso::getFechaFin()
{
    return this->fechaFin;
}

const string Curso::getHorario() const
{
    return this->horario;
}

const int Curso::getCantidadClientes() const
{
    return this->cantidadClientes;
}

ListaEnlazada<Cliente>* Curso::getListaClientesInscritos()
{
    return this->listaClientesInscritos;
}

void Curso::agregarCliente(Cliente* cliente_)
{
    //verificar que haya cupo disponible
    if (this->tieneCupoDisponible())
    {
		listaClientesInscritos->insertar(cliente_);
		this->cantidadClientes++;
    }
    else {
        throw CupoMaximoExcedido("No hay cupo disponible para este curso.");
    }
}

void Curso::eliminarCliente(Cliente* cliente_)
{
    listaClientesInscritos->eliminarDato(cliente_);
}

void Curso::mostrarClientes()
{
    ListaClienteUtils::MostrarClientes(listaClientesInscritos);
}

bool Curso::tieneCupoDisponible()
{
    return this->cantidadClientes < cupoMaximo;
}

const string Curso::toString() const
{
    stringstream ss;
    ss << "Descripcion del curso: " << this->descripcion << endl
        << "Nivel: " << this->nivel << endl
        << "Cupo maximo: " << this->cupoMaximo << endl
        << "Fecha inicio: " << this->fechaInicio->toString() << endl
        << "Fecha fin: " << this->fechaFin->toString() << endl
        << "Horario: " << this->horario << endl
        << "Cantidad de clientes inscritos: " << this->cantidadClientes << endl
        << "Lista de clientes inscritos: " << endl
        << ListaClienteUtils::MostrarClientes(this->listaClientesInscritos);
    return ss.str();
}

void Curso::agregarListaClientes(ListaEnlazada<Cliente>* listaClientes_)
{
    this->listaClientesInscritos = listaClientes_;
    this->cantidadClientes = listaClientes_->getCantidad();
}

ostream& operator<<(ostream& out, Curso& curso_)
{
    out << curso_.toString();
    return out;
}