#include "Corredor.h"

Corredor::Corredor(char sexo_, double estatura_, Fecha* fechaUltimaActualizacion_):
	sexo(sexo_),
	estatura(estatura_)
{
	try
	{
		this->fechaUltimaActualizacion = new Fecha(*fechaUltimaActualizacion_);
	}
	catch (FechaInvalidaException& e)
	{
		throw FechaInvalidaException("Fecha de nacimiento invalida");
	}
}

Corredor::Corredor(const Corredor& corredor_) :
	sexo(corredor_.sexo),
	estatura(corredor_.estatura)
{
	try
	{
		this->fechaUltimaActualizacion = new Fecha(*corredor_.fechaUltimaActualizacion);
	}
	catch (FechaInvalidaException& e)
	{
		throw FechaInvalidaException("Fecha de nacimiento invalida");
	}
}

void Corredor::setSexo(char sexo_)
{
	this->sexo = sexo_;
}

void Corredor::setEstatura(double estatura_)
{
	this->estatura = estatura_;
}

void Corredor::actualizarEstatura(double estatura_, Fecha* fechaActualizacion_)
{
	if (*fechaActualizacion_ >= *this->fechaUltimaActualizacion)
	{
		try 
		{
			this->fechaUltimaActualizacion = new Fecha(*fechaActualizacion_);
			this->estatura = estatura_;
		}
		catch (FechaInvalidaException& e)
		{
			throw FechaInvalidaException("Fecha de actualizacion invalida");
		}
	}
	else
	{
		throw FechaInvalidaException("La fecha de actualizacion no puede ser menor a la ultima actualizacion");
	}
}

void Corredor::setFechaUltimaActualizacion(Fecha* fechaUltimaActualizacion_)
{
	try
	{
		this->fechaUltimaActualizacion = new Fecha(*fechaUltimaActualizacion_);
	}
	catch (FechaInvalidaException& e)
	{
		throw FechaInvalidaException("Fecha de actualizacion invalida");
	}
}

const char Corredor::getSexo() const
{
	return this->sexo;
}

const double Corredor::getEstatura() const
{
	return this->estatura;
}

Fecha* Corredor::getFechaUltimaActualizacion()
{
	return this->fechaUltimaActualizacion;
}

const string Corredor::toString() const
{
	stringstream ss;
	ss << "Sexo: " << this->sexo << endl;
	ss << "Estatura: " << this->estatura << endl;
	return ss.str();
}

Corredor& Corredor::operator=(const Corredor& corredor_)
{
	if (this != &corredor_)
	{
		this->sexo = corredor_.sexo;
		this->estatura = corredor_.estatura;
		try
		{
			this->fechaUltimaActualizacion = new Fecha(*corredor_.fechaUltimaActualizacion);
		}
		catch (FechaInvalidaException& e)
		{
			throw FechaInvalidaException("Fecha de nacimiento invalida");
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const Corredor& corredor_)
{
	out << corredor_.toString();
	return out;
}
