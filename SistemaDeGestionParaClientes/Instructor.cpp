#include "Instructor.h"

Instructor::Instructor(string nombre_, string apellido_, string id_):
	nombre(nombre_),
	apellido(apellido_),
	id(id_)
{
}

Instructor::Instructor(const Instructor& instructor_):
	nombre(instructor_.nombre),
	apellido(instructor_.apellido),
	id(instructor_.id)
{
}

void Instructor::setNombre(string nombre_)
{
	this->nombre = nombre_;
}

void Instructor::setApellido(string apellido_)
{
	this->apellido = apellido_;
}

void Instructor::setId(string id_)
{
	this->id = id_;
}

const string Instructor::getNombre() const
{
	return this->nombre;
}

const string Instructor::getApellido() const
{
	return this->apellido;
}

const string Instructor::getId() const
{
	return this->id;
}

const string Instructor::toString() const
{
	stringstream ss;
	ss << "ID: " << this->id << endl;
	ss << "Nombre: " << this->nombre << " " << this->apellido <<  endl;
	return ss.str();
}

Instructor& Instructor::operator=(const Instructor& instructor_)
{
	if (this != &instructor_)
	{
		this->nombre = instructor_.nombre;
		this->apellido = instructor_.apellido;
		this->id = instructor_.id;
	}
	return *this;
}

ostream& operator<<(ostream& out, Instructor& instructor_)
{
	out << instructor_.toString();
	return out;
}
