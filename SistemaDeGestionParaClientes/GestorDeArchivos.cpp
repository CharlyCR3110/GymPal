#include "GestorDeArchivos.h"

GestorDeArchivos::GestorDeArchivos()
{
}

void GestorDeArchivos::guardarDeportista(Deportista* deportista_)
{
	ofstream archivoDeportistas;
	archivoDeportistas.open("../Deportistas.txt"/*, ios::app*/);
	if (archivoDeportistas.is_open())
	{
		archivoDeportistas << deportista_->toStringParaGuardar() << endl;
		archivoDeportistas.close();
	}
	else
	{
		throw new exception("No se pudo abrir el archivo Deportistas.txt");
	}
}

void GestorDeArchivos::guardarDeportistas(ListaEnlazada<Deportista>* listaDeportistas_)
{
    ofstream archivoDeportistas;
    archivoDeportistas.open("../Deportistas.txt");
    if (!archivoDeportistas.is_open())
    {
        throw new exception("No se pudo abrir el archivo Deportistas.txt");
    }
    else
    {
        Nodo<Deportista>* nodoActual = listaDeportistas_->getPrimero();
        while (nodoActual != nullptr)
        {
            archivoDeportistas << nodoActual->getDato()->toStringParaGuardar();
            nodoActual = nodoActual->getSiguiente();
        }
        archivoDeportistas.close();
    }
}


//const string Triatlonista::toStringParaGuardar() const
//{
//ss << this->cedula << ';' << this->nombre << ';' << this->telefono << ';' << this->fechaNacimiento->getDia() << ';' << this->fechaNacimiento->getMes() << ';' << this->fechaNacimiento->getAnio() << ';' << this->horasEntrenamiento << ';' << temperaturaPromedio << ';' << this->cantidadParticipacionesIronMan << ';' << this->cantidadTriatlonesGanados << ';' << this->corredor->getSexo() << ';' << this->corredor->getEstatura() << ';' << this->nadador->getMasaMuscular() << ';' << this->nadador->getPeso() << ';' << this->nadador->getPorcentajeGrasaCorporal() << ';' << this->fechaUltimaActualizacion->getDia() << ';' << this->fechaUltimaActualizacion->getMes() << ';' << this->fechaUltimaActualizacion->getAnio() << '\n';
//    return ss.str();
//}
ListaEnlazada<Deportista>* GestorDeArchivos::cargarDeportistas()
{
    ListaEnlazada<Deportista>* listaDeportistas = new ListaEnlazada<Deportista>();
	ifstream archivoDeportistas;
	archivoDeportistas.open("../Deportistas.txt");
    if (!archivoDeportistas.is_open())
    {
		throw runtime_error("No se pudo abrir el archivo Deportistas.txt");
	}
    else
    {
		string linea;  
        // se leen los datos necesarios para crear un deportista tipo triatlonista o sea, DEportista* deportista = new Triatlonista(...);
        while (getline(archivoDeportistas, linea))
        {
            stringstream ss(linea);
			string cedula, nombre, telefono, fechaNacimientoDia, fechaNacimientoMes, fechaNacimientoAnio, horasEntrenamiento, temperaturaPromedio,cantidadParticipacionesIronMan, cantidadTriatlonesGanados, sexo, estatura, masaMuscular, peso, porcentajeGrasaCorporal, fechaUltimaActualizacionDia, fechaUltimaActualizacionMes, fechaUltimaActualizacionAnio;
			getline(ss, cedula, ';');
			getline(ss, nombre, ';');
			getline(ss, telefono, ';');
			getline(ss, fechaNacimientoDia, ';');
			getline(ss, fechaNacimientoMes, ';');
			getline(ss, fechaNacimientoAnio, ';');
			getline(ss, horasEntrenamiento, ';');
			getline(ss, temperaturaPromedio, ';');
			getline(ss, cantidadParticipacionesIronMan, ';');
			getline(ss, cantidadTriatlonesGanados, ';');
			getline(ss, sexo, ';');
			getline(ss, estatura, ';');
			getline(ss, masaMuscular, ';');
			getline(ss, peso, ';');
			getline(ss, porcentajeGrasaCorporal, ';');
			getline(ss, fechaUltimaActualizacionDia, ';');
			getline(ss, fechaUltimaActualizacionMes, ';');
			getline(ss, fechaUltimaActualizacionAnio, '\n');

			Deportista* deportista = new Triatlonista(cedula, nombre, telefono, new Fecha(stoi(fechaNacimientoDia), stoi(fechaNacimientoMes), stoi(fechaNacimientoAnio)), stoi(horasEntrenamiento), stod(temperaturaPromedio), stoi(cantidadParticipacionesIronMan), stoi(cantidadTriatlonesGanados), sexo[0], stod(estatura), stod(masaMuscular), stod(peso), stod(porcentajeGrasaCorporal), new Fecha(stoi(fechaUltimaActualizacionDia), stoi(fechaUltimaActualizacionMes), stoi(fechaUltimaActualizacionAnio)));
			listaDeportistas->insertar(deportista);
		}
		archivoDeportistas.close();
	}
	return listaDeportistas;
}
