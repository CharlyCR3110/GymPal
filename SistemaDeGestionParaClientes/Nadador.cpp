#include "Nadador.h"

Nadador::Nadador(double masaMuscular_, double peso_, double porcentajeGrasaCorporal_, Fecha* fechaUltimaActualizacion_) :
    masaMuscular(masaMuscular_),
    peso(peso_),
    porcentajeGrasaCorporal(porcentajeGrasaCorporal_)
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

Nadador::Nadador(const Nadador& nadador_) :
    masaMuscular(nadador_.masaMuscular),
    peso(nadador_.peso),
    porcentajeGrasaCorporal(nadador_.porcentajeGrasaCorporal)
{
    try
    {
		this->fechaUltimaActualizacion = new Fecha(*nadador_.fechaUltimaActualizacion);
	}
    catch (FechaInvalidaException& e)
    {
		throw FechaInvalidaException("Fecha de nacimiento invalida");
	}
}

Nadador::~Nadador()
{
    delete this->fechaUltimaActualizacion;
	this->fechaUltimaActualizacion = nullptr;
}

void Nadador::setMasaMuscular(double masaMuscular_)
{
    this->masaMuscular = masaMuscular_;
}

void Nadador::actualizarMasaMuscular(double masaMuscular_, Fecha* fechaActualizacion_)
{
    if (*fechaActualizacion_ >= *this->fechaUltimaActualizacion)   //aqui pueden haber excepciones TO-DO
    {
        this->masaMuscular = masaMuscular_;
        this->fechaUltimaActualizacion = fechaActualizacion_;
    }
    else {
        throw FechaInvalidaException("La fecha de actualizacion no puede ser menor a la ultima actualizacion");
    }
}

void Nadador::setPeso(double peso_)
{
    this->peso = peso_;
}

void Nadador::actualizarPeso(double peso_, Fecha* fechaActualizacion_)
{
    if (*fechaActualizacion_ >= *this->fechaUltimaActualizacion)
    {
        this->peso = peso_;
        this->fechaUltimaActualizacion = fechaActualizacion_;
    }
    else {
        throw FechaInvalidaException("La fecha de actualizacion no puede ser menor a la ultima actualizacion");
    }
}

void Nadador::setPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_)
{
    this->porcentajeGrasaCorporal = porcentajeGrasaCorporal_;
}

void Nadador::actualizarPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_, Fecha* fechaActualizacion_)
{
    if (*fechaActualizacion_ >= *this->fechaUltimaActualizacion)
    {
        this->porcentajeGrasaCorporal = porcentajeGrasaCorporal_;
        this->fechaUltimaActualizacion = fechaActualizacion_;
    }
    else {
        throw FechaInvalidaException("La fecha de actualizacion no puede ser menor a la ultima actualizacion");
    }
}

void Nadador::setFechaUltimaActualizacion(Fecha* fechaDeRegistro_)
{
    try
    {
		this->fechaUltimaActualizacion = new Fecha(*fechaDeRegistro_);
	}
    catch (FechaInvalidaException& e)
    {
		throw FechaInvalidaException("Fecha de registro invalida");
	}
}

const double Nadador::getMasaMuscular() const
{
    return this->masaMuscular;
}

const double Nadador::getPeso() const
{
    return this->peso;
}

const double Nadador::getPorcentajeGrasaCorporal() const
{
    return this->porcentajeGrasaCorporal;
}

Fecha* Nadador::getFechaUltimaActualizacion()
{
    return this->fechaUltimaActualizacion;
}

const string Nadador::toString() const
{
    stringstream ss;
    ss << "Masa Muscular: " << this->masaMuscular << endl;
    ss << "Peso: " << this->peso << endl;
    ss << "Porcentaje Grasa Corporal: " << this->porcentajeGrasaCorporal << endl;
    return ss.str();
}

Nadador& Nadador::operator=(const Nadador& nadador_)
{
    if (this != &nadador_)
    {
		this->masaMuscular = nadador_.masaMuscular;
		this->peso = nadador_.peso;
		this->porcentajeGrasaCorporal = nadador_.porcentajeGrasaCorporal;
        try
        {
			this->fechaUltimaActualizacion = new Fecha(*nadador_.fechaUltimaActualizacion);
		}
        catch (FechaInvalidaException& e)
        {
			throw FechaInvalidaException("Fecha de nacimiento invalida");
		}
	}
    return *this;
}

ostream& operator<<(ostream& out, const Nadador& nadador_)
{
    out << nadador_.toString();
    return out; 
}
