#include "Grupo.h"

Grupo::Grupo(Instructor* instructor_, int cupoMaximo_, Fecha* fechaDeInicio_, int semanasDeDuracion_, char diaDeLaSemana_, Hora* horaDeInicio_, Hora* horaDeFin_) :
	instructor(new Instructor(*instructor_)),
	cupoMaximo(cupoMaximo_),
	fechaDeInicio(new Fecha(*fechaDeInicio_)),
	semanasDeDuracion(semanasDeDuracion_),
	diaDeLaSemana(diaDeLaSemana_),
	horaDeInicio(new Hora(*horaDeInicio_)),
	horaDeFin(new Hora(*horaDeFin_))
{
	deportistasInscritos = new ListaEnlazada<Deportista>();
}

Grupo::Grupo(const Grupo& grupo_):
	instructor(new Instructor(*grupo_.instructor)),
	cupoMaximo(grupo_.cupoMaximo),
	fechaDeInicio(new Fecha(*grupo_.fechaDeInicio)),
	semanasDeDuracion(grupo_.semanasDeDuracion),
	diaDeLaSemana(grupo_.diaDeLaSemana),
	horaDeInicio(new Hora(*grupo_.horaDeInicio)),
	horaDeFin(new Hora(*grupo_.horaDeFin)),
	deportistasInscritos(new ListaEnlazada<Deportista>(*grupo_.deportistasInscritos))
{
}

Grupo::~Grupo()
{
	delete this->instructor;
	delete this->fechaDeInicio;
	delete this->horaDeInicio;
	delete this->horaDeFin;
	delete this->deportistasInscritos;
}

void Grupo::setInstructor(Instructor* instructor_)
{
	this->instructor = instructor_;
}

void Grupo::setCupoMaximo(int cupoMaximo_)
{
	this->cupoMaximo = cupoMaximo_;
}

void Grupo::setFechaDeInicio(Fecha* fechaDeInicio_)
{
	this->fechaDeInicio = fechaDeInicio_;
}

void Grupo::setSemanasDeDuracion(int semanasDeDuracion_)
{
	this->semanasDeDuracion = semanasDeDuracion_;
}

void Grupo::setDiaDeLaSemana(char diaDeLaSemana_)
{
	this->diaDeLaSemana = diaDeLaSemana_;
}

void Grupo::setHoraDeInicio(Hora* horaDeInicio_)
{
	this->horaDeInicio = horaDeInicio_;
}

void Grupo::setHoraDeFin(Hora* horaDeFin_)
{
	this->horaDeFin = horaDeFin_;
}

void Grupo::setDeportistasInscritos(ListaEnlazada<Deportista>* triatlonistasInscritos_)
{
	// eliminar la lista actual
	delete this->deportistasInscritos;
	// crear una nueva lista con los elementos de la lista pasada por parametro
	this->deportistasInscritos = new ListaEnlazada<Deportista>();
	// recorrer la lista pasada por parametro y agregar los elementos a la nueva lista
	Nodo<Deportista>* nodoActual = triatlonistasInscritos_->getPrimero();
	while (nodoActual != nullptr)
	{
		this->deportistasInscritos->insertar(nodoActual->getDato());
		nodoActual = nodoActual->getSiguiente();
	}
}


Instructor* Grupo::getInstructor()
{
	return this->instructor;
}

const int Grupo::getCupoMaximo() const
{
	return this->cupoMaximo;
}

Fecha* Grupo::getFechaDeInicio()
{
	return this->fechaDeInicio;
}

const int Grupo::getSemanasDeDuracion() const
{
	return this->semanasDeDuracion;
}

const char Grupo::getDiaDeLaSemana() const
{
	return this->diaDeLaSemana;
}

Hora* Grupo::getHoraDeInicio()
{
	return this->horaDeInicio;
}

Hora* Grupo::getHoraDeFin()
{
	return this->horaDeFin;
}

ListaEnlazada<Deportista>* Grupo::getDeportistasInscritos()
{
	return this->deportistasInscritos;
}

const string Grupo::toString() const
{
	stringstream ss;
	ss << "Instructor: " << this->instructor->toString() << endl;
	ss << "Cupo maximo: " << this->cupoMaximo << endl;
	ss << "Fecha de inicio: " << this->fechaDeInicio->toString() << endl;
	ss << "Semanas de duracion: " << this->semanasDeDuracion << endl;
	ss << "Dia de la semana: " << this->diaDeLaSemana << endl;
	ss << "Hora de inicio: " << this->horaDeInicio->toString() << endl;
	ss << "Hora de fin: " << this->horaDeFin->toString() << endl;
	return ss.str();
}

const string Grupo::mostrarDeportistasInscritos() const
{
	stringstream ss;
	ss << "Triatlonistas inscritos: " << endl;
	Nodo<Deportista>* nodoActual = this->deportistasInscritos->getPrimero();
	if (nodoActual == nullptr)
	{
		ss << "No hay triatlonistas inscritos" << endl;
		return ss.str();
	}

	while (nodoActual != nullptr)
	{
		ss << *nodoActual->getDato() << endl;
		nodoActual = nodoActual->getSiguiente();
	}
	return ss.str();
}

Grupo& Grupo::operator=(const Grupo& grupo_)
{
	if (this == &grupo_)
	{
		return *this;
	}

	// copiar los valores de los atributos
	if (this->instructor != nullptr)
	{
		delete this->instructor;
	}
	this->instructor = new Instructor(*grupo_.instructor);

	this->cupoMaximo = grupo_.cupoMaximo;
	this->semanasDeDuracion = grupo_.semanasDeDuracion;
	this->diaDeLaSemana = grupo_.diaDeLaSemana;

	if (this->fechaDeInicio != nullptr)
	{
		delete this->fechaDeInicio;
	}
	this->fechaDeInicio = new Fecha(*grupo_.fechaDeInicio);

	if (this->horaDeInicio != nullptr)
	{
		delete this->horaDeInicio;
	}
	this->horaDeInicio = new Hora(*grupo_.horaDeInicio);

	if (this->horaDeFin != nullptr)
	{
		delete this->horaDeFin;
	}
	this->horaDeFin = new Hora(*grupo_.horaDeFin);

	// Copiar la lista de triatlonistas inscritos
	ListaEnlazada<Deportista>* nuevaLista = new ListaEnlazada<Deportista>();
	Nodo<Deportista>* nodoActual = grupo_.deportistasInscritos->getPrimero();
	while (nodoActual != nullptr)
	{
		nuevaLista->insertar(nodoActual->getDato());
		nodoActual = nodoActual->getSiguiente();
	}

	if (this->deportistasInscritos != nullptr)
	{
		Nodo<Deportista>* nodoActual = this->deportistasInscritos->getPrimero();
		while (nodoActual != nullptr)
		{
			delete nodoActual->getDato();
			nodoActual = nodoActual->getSiguiente();
		}
		delete this->deportistasInscritos;
	}
	this->deportistasInscritos = nuevaLista;

	return *this;
}

ostream& operator<<(ostream& out, const Grupo& grupo_)
{
	out << grupo_.toString();
	return out;
}
