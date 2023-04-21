#include "Curso.h"

Curso::Curso(const Curso& curso_)
{
    this->descripcion = curso_.descripcion;
	this->nivel = curso_.nivel;
	this->cupoMaximo = curso_.cupoMaximo;
	this->fechaInicio = new Fecha(*curso_.fechaInicio);
	this->fechaFin = new Fecha(*curso_.fechaFin);
	this->horario = curso_.horario;
	this->cantidadDeportistas = curso_.cantidadDeportistas;
	this->listaDeportistasInscritos = new ListaEnlazada<Deportista>(*curso_.listaDeportistasInscritos);
}

Curso::Curso(string descripcion_, string nivel_, int cupoMaximo_, Fecha* fechaInicio_, Fecha* fechaFin_, string horario_)
    : descripcion(descripcion_), nivel(nivel_), cupoMaximo(cupoMaximo_), fechaInicio(fechaInicio_), fechaFin(fechaFin_), horario(horario_)
{
    this->cantidadDeportistas = 0;
    this->listaDeportistasInscritos = new ListaEnlazada<Deportista>();
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

const int Curso::getCantidadDeportistas() const
{
    return this->cantidadDeportistas;
}

ListaEnlazada<Deportista>* Curso::getListaDeportistasInscritos()
{
    return this->listaDeportistasInscritos;
}

void Curso::agregarDeportista(Deportista* deportista_)
{
    //verificar que haya cupo disponible
    if (this->tieneCupoDisponible())
    {
		listaDeportistasInscritos->insertar(deportista_);
		this->cantidadDeportistas++;
    }
    else {
        throw CupoMaximoExcedido("No hay cupo disponible para este curso.");
    }
}

void Curso::eliminarDeportista(Deportista* deportista_)
{
    listaDeportistasInscritos->eliminarDato(deportista_);
}

void Curso::mostrarDeportistas()
{
    ListaDeportistaUtils::MostrarDeportistas(listaDeportistasInscritos);
}

bool Curso::tieneCupoDisponible()
{
    return this->cantidadDeportistas < cupoMaximo;
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
        << "Cantidad de deportistas inscritos: " << this->cantidadDeportistas << endl
        << "Lista de clientes inscritos: " << endl
        << ListaDeportistaUtils::MostrarDeportistas(this->listaDeportistasInscritos);
    return ss.str();
}

void Curso::agregarListaDeportistas(ListaEnlazada<Deportista>* listaDeportistas_)
{
    this->listaDeportistasInscritos = listaDeportistas_;
    this->cantidadDeportistas = listaDeportistas_->getCantidad();
}

Curso& Curso::operator=(const Curso& curso_)
{
    this->descripcion = curso_.descripcion;
	this->nivel = curso_.nivel;
	this->cupoMaximo = curso_.cupoMaximo;
	this->fechaInicio = new Fecha(*curso_.fechaInicio);
	this->fechaFin = new Fecha(*curso_.fechaFin);
	this->horario = curso_.horario;
	this->cantidadDeportistas = curso_.cantidadDeportistas;
	this->listaDeportistasInscritos = new ListaEnlazada<Deportista>(*curso_.listaDeportistasInscritos);
	return *this;
}

ostream& operator<<(ostream& out, Curso& curso_)
{
    out << curso_.toString();
    return out;
}