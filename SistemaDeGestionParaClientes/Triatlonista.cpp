#include "Triatlonista.h"

Triatlonista::Triatlonista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, char estado, int horasEntrenamiento_, double temperaturaPromedio_, int cantidadParticipacionesIronMan_, int cantidadTriatlonesGanados_, char sexo_, double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_, Fecha* fechaUltimaActualizacion_):
    Ciclista(cedula_, nombre_, telefono_, fechaNacimiento_, estado, horasEntrenamiento_, temperaturaPromedio_),
    cantidadParticipacionesIronMan(cantidadParticipacionesIronMan_),
    cantidadTriatlonesGanados(cantidadTriatlonesGanados_),
    corredor(new Corredor(sexo_, estatura_, fechaUltimaActualizacion_)),
    nadador(new Nadador(masaMuscular_, peso_, porcentajeGrasaCorporal_, fechaUltimaActualizacion_))
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

Triatlonista::Triatlonista(const Triatlonista& triatlonista_) :
    Ciclista(triatlonista_),
    cantidadParticipacionesIronMan(triatlonista_.cantidadParticipacionesIronMan),
    cantidadTriatlonesGanados(triatlonista_.cantidadTriatlonesGanados),
    corredor(new Corredor(*triatlonista_.corredor)),
    nadador(new Nadador(*triatlonista_.nadador))
{
    try
    {
		this->fechaUltimaActualizacion = new Fecha(*triatlonista_.fechaUltimaActualizacion);
	}
    catch (FechaInvalidaException& e)
    {
		throw FechaInvalidaException("Fecha de nacimiento invalida");
	}
}

Triatlonista::~Triatlonista()
{
    delete this->corredor;
	delete this->nadador;
}

void Triatlonista::setCantidadParticipacionesIronMan(int cantidadParticipacionesIronMan_)
{
    this->cantidadParticipacionesIronMan = cantidadParticipacionesIronMan_;
}

void Triatlonista::setCantidadTriatlonesGanados(int cantidadTriatlonesGanados_)
{
    this->cantidadTriatlonesGanados = cantidadTriatlonesGanados_;
}

void Triatlonista::setCorredor(Corredor* corredor_)
{
    if (corredor_ != nullptr)
    {
		this->corredor = corredor_;
	}
}

void Triatlonista::setSexo(char sexo_)
{
    this->corredor->setSexo(sexo_);
}

void Triatlonista::setEstatura(double estatura_)
{
    this->corredor->setEstatura(estatura_);
}

void Triatlonista::actualizarEstatura(double estatura_, Fecha* fechaActualizacion_)
{
    if (fechaActualizacion_ == nullptr)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    if (this->fechaUltimaActualizacion > fechaActualizacion_)
    {
		throw FechaInvalidaException("Fecha de actualizacion invalida");
	}

    try
    {
        this->corredor->actualizarEstatura(estatura_, fechaActualizacion_);
        this->fechaUltimaActualizacion = new Fecha(*fechaActualizacion_);
        //tambien se actualiza la fechaUltimaActualizacion de la clase nadador, esto para que todos los datos biometricos tengan la misma fecha de actualizacion
        this->nadador->setFechaUltimaActualizacion(fechaActualizacion_);
    }
    catch (FechaInvalidaException& e)
    {
		throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

}

void Triatlonista::setNadador(Nadador* nadador_)
{
    if (nadador_ != nullptr)
    {
		this->nadador = nadador_;
	}
}

void Triatlonista::setMasaMuscular(double masaMuscular_)
{
    this->nadador->setMasaMuscular(masaMuscular_);
}

void Triatlonista::actualizarMasaMuscular(double masaMuscular_, Fecha* fechaActualizacion_)
{
    if (fechaActualizacion_ == nullptr)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    if (this->fechaUltimaActualizacion > fechaActualizacion_)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    try
    {
        this->nadador->actualizarMasaMuscular(masaMuscular_, fechaActualizacion_);
        this->fechaUltimaActualizacion = new Fecha(*fechaActualizacion_);
        //tambien se actualiza la fechaUltimaActualizacion de la clase corredor, esto para que todos los datos biometricos tengan la misma fecha de actualizacion
        this->corredor->setFechaUltimaActualizacion(fechaActualizacion_);
    }
    catch (FechaInvalidaException& e)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida. Mensaje desde la clase Triatlonista");
	}
}

void Triatlonista::setPeso(double peso_)
{
    this->nadador->setPeso(peso_);
}

void Triatlonista::actualizarPeso(double peso_, Fecha* fechaActualizacion_)
{
    if (fechaActualizacion_ == nullptr)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    if (this->fechaUltimaActualizacion > fechaActualizacion_)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    try
    {
        this->nadador->actualizarPeso(peso_, fechaActualizacion_);
        this->fechaUltimaActualizacion = new Fecha(*fechaActualizacion_);
        //tambien se actualiza la fechaUltimaActualizacion de la clase corredor, esto para que todos los datos biometricos tengan la misma fecha de actualizacion
        this->corredor->setFechaUltimaActualizacion(fechaActualizacion_);
    }
    catch (FechaInvalidaException& e)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida. Mensaje desde la clase Triatlonista");
    }
}

void Triatlonista::setPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_)
{
    this->nadador->setPorcentajeGrasaCorporal(porcentajeGrasaCorporal_);
}

void Triatlonista::actualizarPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_, Fecha* fechaActualizacion_)
{
    if (fechaActualizacion_ == nullptr)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    if (this->fechaUltimaActualizacion > fechaActualizacion_)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida");
    }

    try
    {
        this->nadador->actualizarPorcentajeGrasaCorporal(porcentajeGrasaCorporal_, fechaActualizacion_);
        this->fechaUltimaActualizacion = new Fecha(*fechaActualizacion_);
        //tambien se actualiza la fechaUltimaActualizacion de la clase corredor, esto para que todos los datos biometricos tengan la misma fecha de actualizacion
        this->corredor->setFechaUltimaActualizacion(fechaActualizacion_);
    }
    catch (FechaInvalidaException& e)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida. Mensaje desde la clase Triatlonista");
    }
}

void Triatlonista::actualizarDatosBiometricos(double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_, Fecha* fechaUltimaActualizacion_)
{
    if (fechaUltimaActualizacion_ == nullptr)
    {
		throw FechaInvalidaException("Fecha de actualizacion invalida");
	}

    if (this->fechaUltimaActualizacion > fechaUltimaActualizacion_)
    {
		throw FechaInvalidaException("Fecha de actualizacion invalida");
	}

    try
    {
        this->corredor->actualizarEstatura(estatura_, fechaUltimaActualizacion_);
        this->nadador->actualizarMasaMuscular(masaMuscular_, fechaUltimaActualizacion_);
        this->nadador->actualizarPeso(peso_, fechaUltimaActualizacion_);
        this->nadador->actualizarPorcentajeGrasaCorporal(porcentajeGrasaCorporal_, fechaUltimaActualizacion_);
        this->fechaUltimaActualizacion = new Fecha(*fechaUltimaActualizacion_);
    }
    catch (FechaInvalidaException& e)
    {
        throw FechaInvalidaException("Fecha de actualizacion invalida. Mensaje desde la clase Triatlonista"); 
    }

}

const int Triatlonista::getCantidadParticipacionesIronMan() const
{
    return this->cantidadParticipacionesIronMan;
}

const int Triatlonista::getCantidadTriatlonesGanados() const
{
    return this->cantidadTriatlonesGanados;
}

Corredor* Triatlonista::getCorredor()
{
    return this->corredor;
}

const char Triatlonista::getSexo() const
{
    return this->corredor->getSexo();
}

const double Triatlonista::getEstatura() const
{
    return this->corredor->getEstatura();
}

Nadador* Triatlonista::getNadador()
{
    return this->nadador;
}

const double Triatlonista::getMasaMuscular() const
{
    return this->nadador->getMasaMuscular();
}

const double Triatlonista::getPeso() const
{
    return this->nadador->getPeso();
}

const double Triatlonista::getPorcentajeGrasaCorporal() const
{
    return this->nadador->getPorcentajeGrasaCorporal();
}

const string Triatlonista::toString() const
{
    stringstream ss;
    ss << Ciclista::toString();
    ss << corredor->toString();
    ss << nadador->toString();
    ss << "Cantidad de participaciones en IronMan: " << this->cantidadParticipacionesIronMan << endl;
    ss << "Cantidad de triatlones ganados: " << this->cantidadTriatlonesGanados << endl;
    return ss.str();
}

ostream& operator<<(ostream& out, const Triatlonista& triatlonista_)
{
    out << triatlonista_.toString();
    return out;
}
