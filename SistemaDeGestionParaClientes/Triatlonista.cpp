#include "Triatlonista.h"

Triatlonista::Triatlonista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, int horasEntrenamiento_, double temperaturaPromedio_, int cantidadParticipacionesIronMan_, int cantidadTriatlonesGanados_, char sexo_, double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_, Fecha* fechaUltimaActualizacion_):
    Ciclista(cedula_, nombre_, telefono_, fechaNacimiento_, horasEntrenamiento_, temperaturaPromedio_),
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
    ss << "-----------------------------------------------------------" << endl;
    ss << Ciclista::toString();
    ss << corredor->toString();
    ss << nadador->toString();
    ss << "Cantidad de participaciones en IronMan: " << this->cantidadParticipacionesIronMan << endl;
    ss << "Cantidad de triatlones ganados: " << this->cantidadTriatlonesGanados << endl;
    ss << "-----------------------------------------------------------" << endl;
    return ss.str();
}

const string Triatlonista::detalleDeportista() const
{
    stringstream ss;
    ss << "Datos generales:" << endl;
    ss << '\t' << "Cedula: " << this->cedula << endl;
    ss << '\t' << "Nombre: " << this->nombre << endl;
    ss << '\t' << "Estado: " << this->estado << endl;
    ss << '\t' << "Telefono: " << this->telefono << endl;
    ss << '\t' << "Fecha de nacimiento: " << this->fechaNacimiento->toString() << endl;
    ss << '\t' << "Sexo: " << this->corredor->getSexo() << endl;
    ss << '\t' << "Horas de entrenamiento diarias: " << this->horasEntrenamiento << endl;
    ss << '\t' << "Cantidad de participaciones en IronMan: " << this->cantidadParticipacionesIronMan << endl;
    ss << '\t' << "Cantidad de triatlones ganados: " << this->cantidadTriatlonesGanados << endl;

    ss << "Datos biometricos:" << endl;
    ss << '\t' << "Estatura: " << this->corredor->getEstatura() << endl;
    ss << '\t' << "Peso: " << this->nadador->getPeso() << endl;
    ss << '\t' << "Porcentaje de grasa corporal: " << this->nadador->getPorcentajeGrasaCorporal() << "%" << endl;
    ss << '\t' << "Masa muscular: " << this->nadador->getMasaMuscular() << "%" << endl;
    
    ss << "Grupos matriculados:" << endl; //TO-DO
    try
    {
        ss << mostrarCursosMatriculados() << endl;
    }
    catch (exception& e)
    {
		ss << e.what() << endl;
	}

    return ss.str();
}

const string Triatlonista::toStringParaGuardar() const
{
    stringstream ss;
    ss << this->cedula << ';' << this->nombre << ';' << this->telefono << ';' << this->fechaNacimiento->getDia() << ';' << this->fechaNacimiento->getMes() << ';' << this->fechaNacimiento->getAnio() << ';' << this->horasEntrenamiento << ';' << this->temperaturaPromedio << ';' << this->cantidadParticipacionesIronMan << ';' << this->cantidadTriatlonesGanados << ';' << this->corredor->getSexo() << ';' << this->corredor->getEstatura() << ';' << this->nadador->getMasaMuscular() << ';' << this->nadador->getPeso() << ';' << this->nadador->getPorcentajeGrasaCorporal() << ';' << this->fechaUltimaActualizacion->getDia() << ';' << this->fechaUltimaActualizacion->getMes() << ';' << this->fechaUltimaActualizacion->getAnio() << '\n';
    return ss.str();
}

const string Triatlonista::toStringParaGuardarConPagos() const
{
    stringstream ss;
    ss << this->cedula << ';' << this->nombre << ';' << this->telefono << ';' << this->estado << ';' << this->fechaNacimiento->getDia() << ';' << this->fechaNacimiento->getMes() << ';' << this->fechaNacimiento->getAnio() << ';' << this->horasEntrenamiento << ';' << this->temperaturaPromedio << ';' << this->cantidadParticipacionesIronMan << ';' << this->cantidadTriatlonesGanados << ';' << this->corredor->getSexo() << ';' << this->corredor->getEstatura() << ';' << this->nadador->getMasaMuscular() << ';' << this->nadador->getPeso() << ';' << this->nadador->getPorcentajeGrasaCorporal() << ';' << this->fechaUltimaActualizacion->getDia() << ';' << this->fechaUltimaActualizacion->getMes() << ';' << this->fechaUltimaActualizacion->getAnio() << ';' << this->cantidadDePagos;
    return ss.str();
}

ostream& operator<<(ostream& out, const Triatlonista& triatlonista_)
{
    out << triatlonista_.toString();
    return out;
}
