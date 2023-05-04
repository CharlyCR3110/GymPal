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
		throw runtime_error("No se pudo abrir el archivo Deportistas.txt");
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

void GestorDeArchivos::guardarGrupo(Grupo* grupo_)
{
	ofstream archivoGrupos;
	archivoGrupos.open("../Grupos.txt", ios::app);
	if (archivoGrupos.is_open())
	{
		archivoGrupos << grupo_->toStringParaGuardar() << endl;
		archivoGrupos.close();
	}
	else
	{
		throw runtime_error("No se pudo abrir el archivo Grupos.txt");
	}
}

void GestorDeArchivos::guardarGrupos(ListaEnlazada<Grupo>* listaGrupos_)
{
	ofstream archivoGrupos;
	archivoGrupos.open("../Grupos.txt");
	if (!archivoGrupos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo Grupos.txt");
	}
	else
	{
		Nodo<Grupo>* nodoActual = listaGrupos_->getPrimero();
		while (nodoActual != nullptr)
		{
			archivoGrupos << nodoActual->getDato()->toStringParaGuardar();
			nodoActual = nodoActual->getSiguiente();
		}
		archivoGrupos.close();
	}
}

void GestorDeArchivos::guardarGrupos(ListaEnlazada<Grupo>* listaGrupos_, string nombreArchivo_)
{
	ofstream archivoGrupos;
	archivoGrupos.open(nombreArchivo_.c_str());
	if (!archivoGrupos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo Grupos.txt");
	}
	else
	{
		Nodo<Grupo>* nodoActual = listaGrupos_->getPrimero();
		while (nodoActual != nullptr)
		{
			archivoGrupos << nodoActual->getDato()->toStringParaGuardar();
			nodoActual = nodoActual->getSiguiente();
		}
		archivoGrupos.close();
	}
}

void GestorDeArchivos::guardarCursos(ListaEnlazada<Curso>* listaCursos_)
{
    ofstream archivoCursos;
    archivoCursos.open(".. /cursos.txt");
    if (!archivoCursos.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo Cursos.txt");
    }
    else
    {
        Nodo<Curso>* nodoActual = listaCursos_->getPrimero();
        while (nodoActual != nullptr)
        {
            archivoCursos << nodoActual->getDato()->toStringParaGuardar();

            // Obtener la lista de grupos del curso actual
            ListaEnlazada<Grupo>* listaGrupos = nodoActual->getDato()->getListaGrupos();

            // Guardar los grupos del curso actual en un archivo con un nombre que identifique el curso
            string nombreArchivoGrupos = "Grupos_" + nodoActual->getDato()->getNombreDelCurso() + ".txt";
            guardarGrupos(listaGrupos, nombreArchivoGrupos);

            nodoActual = nodoActual->getSiguiente();
        }
        archivoCursos.close();
    }
}

ListaEnlazada<Curso>* GestorDeArchivos::cargarCursos()
{
	ListaEnlazada<Curso>* listaCursos = new ListaEnlazada<Curso>();
	ifstream archivoCursos;
	archivoCursos.open(".. /cursos.txt");
	if (!archivoCursos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo Cursos.txt");
	}
	else
	{
		string linea;
		while (getline(archivoCursos, linea))
		{
			// Crear un objeto Curso con los datos obtenidos
			Curso* curso = new Curso();
			//string codigo_ = "", string nombreDelCurso_ = "", string nivel_ = "", string descripcion_ = "", int cantidadMaximaDeGrupos = 0
			string codigo, nombreDelCurso, nivel, descripcion, cantidadMaximaDeGrupos;
			stringstream ss(linea);
			getline(ss, codigo, ';');
			getline(ss, nombreDelCurso, ';');
			getline(ss, nivel, ';');
			getline(ss, descripcion, ';');
			getline(ss, cantidadMaximaDeGrupos, '|');
			curso->setCodigo(codigo);
			curso->setNombreDelCurso(nombreDelCurso);
			curso->setNivel(nivel);
			curso->setDescripcion(descripcion);
			curso->setCantidadMaximaDeGrupos(stoi(cantidadMaximaDeGrupos));
			// Crear una lista de Grupos para el curso actual
			ListaEnlazada<Grupo>* listaGrupos = new ListaEnlazada<Grupo>();

			// Leer cada línea adicional del archivo y crear un objeto Grupo para cada conjunto de datos
			while (getline(archivoCursos, linea))
			{
				string nombreInstructor, apellidoInstructor, idInstructor, cupoMaximo, diaDeInicio, mesDeInicio, anioDeInicio, semanasDeDuracion, numeroGrupo, diaDeLaSemana, horaDeInicio, minutoDeInicio, segundoDeInicio, horaDeFin, minutoDeFin, segundoDeFin;
				stringstream ss(linea);
				getline(ss, nombreInstructor, ';');
				getline(ss, apellidoInstructor, ';');
				getline(ss, idInstructor, ';');
				getline(ss, cupoMaximo, ';');
				getline(ss, diaDeInicio, ';');
				getline(ss, mesDeInicio, ';');
				getline(ss, anioDeInicio, ';');
				getline(ss, semanasDeDuracion, ';');
				getline(ss, numeroGrupo, ';');
				getline(ss, diaDeLaSemana, ';');
				getline(ss, horaDeInicio, ';');
				getline(ss, minutoDeInicio, ';');
				getline(ss, segundoDeInicio, ';');
				getline(ss, horaDeFin, ';');
				getline(ss, minutoDeFin, ';');
				getline(ss, segundoDeFin, '\n');

				// Crear un objeto Fecha con los datos obtenidos
				Fecha* fechaDeInicio = new Fecha(stoi(diaDeInicio), stoi(mesDeInicio), stoi(anioDeInicio));
				// Crear un objeto Hora con los datos obtenidos
				Hora* horaDeInicioHora = new Hora(stoi(horaDeInicio), stoi(minutoDeInicio), stoi(segundoDeInicio));
				// Crear un objeto Hora con los datos obtenidos
				Hora* horaDeFinHora = new Hora(stoi(horaDeFin), stoi(minutoDeFin), stoi(segundoDeFin));
				// Crear un objeto Instructor con los datos obtenidos
				Instructor* instructor = new Instructor(nombreInstructor, apellidoInstructor, idInstructor);
				// Crear un objeto Grupo con los datos obtenidos
				Grupo* grupo = new Grupo(instructor, stoi(cupoMaximo), fechaDeInicio, stoi(semanasDeDuracion), stoi(numeroGrupo), diaDeLaSemana[0], horaDeInicioHora, horaDeFinHora);

				// Agregar el objeto Grupo a la lista de Grupos
				listaGrupos->insertar(grupo);
			}

			// Agregar la lista de Grupos al objeto Curso
			curso->setListaGrupos(listaGrupos);

			// Agregar el objeto Curso a la lista de cursos
			listaCursos->insertar(curso);
		}
		archivoCursos.close();
	}
	return listaCursos;
}

void GestorDeArchivos::guardarCursosYGrupos(ListaEnlazada<Curso>* listaCursos_)
{
	ofstream archivoCursos;
	archivoCursos.open("../Cursos.txt");

	if (!archivoCursos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo Cursos.txt");
	}
	else
	{
		// se recorre la lista de cursos
		Nodo<Curso>* nodoActual = listaCursos_->getPrimero();
		while (nodoActual != nullptr)
		{
			Curso* cursoActual = nodoActual->getDato();
			// al final se agrega un delimitador para reconocer que lo siguiente son sus grupos
			archivoCursos << cursoActual->toStringParaGuardar() << '|';
			// Obtener la lista de grupos del curso actual
			ListaEnlazada<Grupo>* listaGrupos = cursoActual->getListaGrupos();
			while (listaGrupos->getPrimero() != nullptr)
			{
				// se obtiene el primer grupo de la lista
				Grupo* grupoActual = listaGrupos->getPrimero()->getDato();
				// se agrega el grupo al archivo
				archivoCursos << grupoActual->toStringParaGuardar();
				// se elimina el grupo de la lista
				listaGrupos->eliminar(1);
				archivoCursos << '|';	// delimitador para separar los grupos
			}
			archivoCursos << '\n';	// salto de linea para separar los cursos
			nodoActual = nodoActual->getSiguiente();
		}
	}
	archivoCursos.close();
}

ListaEnlazada<Curso>* GestorDeArchivos::cargarCursosYGrupos()
{
	ListaEnlazada<Curso>* listaCursos = new ListaEnlazada<Curso>();
	ifstream archivoCursos;
	archivoCursos.open("../Cursos.txt");
	if (!archivoCursos.is_open())
	{ 
		throw runtime_error("No se pudo abrir el archivo Cursos.txt");
	}
	else
	{
		string linea;
		while (getline(archivoCursos, linea))
		{
			//    ss << this->codigo << ';' << this->nombreDelCurso << ';' << this->nivel << ';' << this->descripcion << ';' << this->cantidadMaximaDeGrupos << ';' << this->cantidadDeGruposActuales;
			stringstream ss(linea);
			string codigo, nombreDelCurso, nivel, descripcion, cantidadMaximaDeGrupos, cantidadGruposActuales;
			getline(ss, codigo, ';');
			getline(ss, nombreDelCurso, ';');
			getline(ss, nivel, ';');
			getline(ss, descripcion, ';');
			getline(ss, cantidadMaximaDeGrupos, ';');
			getline(ss, cantidadGruposActuales, '|');
			Curso* cursoActual = new Curso(codigo, nombreDelCurso, nivel, descripcion, stoi(cantidadMaximaDeGrupos));
			cout << cursoActual->toString() << "actuales" << cantidadGruposActuales <<endl;
			ListaEnlazada<Grupo>* listaGrupos = new ListaEnlazada<Grupo>();
			for (int i = 0; i < stoi(cantidadGruposActuales); i++)
			{

				string lineaGrupo;
				getline(ss, lineaGrupo, '|');
				stringstream ssGrupo(lineaGrupo);


				string nombreInstructor, apellidoInstructor, idInstructor, cupoMaximo, diaDeInicio, mesDeInicio, anioDeInicio, semanasDeDuracion, numeroGrupo, diaDeLaSemana, horaDeInicio, minutoDeInicio, segundoDeInicio, horaDeFin, minutoDeFin, segundoDeFin;
				int valorDiaDeInicio, valorMesDeInicio, valorAnioDeInicio, valorHoraDeInicio, valorMinutoDeInicio, valorSegundoDeInicio, valorHoraDeFin, valorMinutoDeFin, valorSegundoDeFin;
				getline(ssGrupo, nombreInstructor, ';');
				getline(ssGrupo, apellidoInstructor, ';');
				getline(ssGrupo, idInstructor, ';');
				getline(ssGrupo, cupoMaximo, ';');
				getline(ssGrupo, diaDeInicio, ';');
				getline(ssGrupo, mesDeInicio, ';');
				getline(ssGrupo, anioDeInicio, ';');
				getline(ssGrupo, semanasDeDuracion, ';');
				getline(ssGrupo, numeroGrupo, ';');
				getline(ssGrupo, diaDeLaSemana, ';');
				getline(ssGrupo, horaDeInicio, ';');
				getline(ssGrupo, minutoDeInicio, ';');
				getline(ssGrupo, segundoDeInicio, ';');
				getline(ssGrupo, horaDeFin, ';');
				getline(ssGrupo, minutoDeFin, ';');
				getline(ssGrupo, segundoDeFin, '\n');

				try
				{
					valorDiaDeInicio = stoi(diaDeInicio);
				}
				catch (const std::exception& e)
				{
					cout << "Nombre del instructor: " << nombreInstructor << ", ID: " << idInstructor << " cupo" << cupoMaximo << endl;
					throw runtime_error("El dia de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero: " + diaDeInicio);
				}

				try
				{
					valorMesDeInicio = stoi(mesDeInicio);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("El mes de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}

				try
				{
					valorMesDeInicio = stoi(mesDeInicio);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("El anio de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}

				try
				{
					valorHoraDeInicio = stoi(horaDeInicio);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("la hora de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}


				try
				{
					valorMinutoDeInicio = stoi(minutoDeInicio);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("el segundo de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}


				try
				{
					valorSegundoDeInicio = stoi(segundoDeInicio);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("el segundo de inicio del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}

				// fin
				try
				{
					valorHoraDeFin = stoi(horaDeFin);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("la hora de fin del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}


				try
				{
					valorMinutoDeFin = stoi(minutoDeFin);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("el minuto de fin del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}


				try
				{
					valorSegundoDeFin = stoi(segundoDeFin);
				}
				catch (const std::exception& e)
				{
					throw runtime_error("el segundo de fin del grupo " + numeroGrupo + " del curso " + codigo + " no es un numero");
				}

				// Crear un objeto Fecha con los datos obtenidos
				Fecha* fechaDeInicio = new Fecha(valorDiaDeInicio, valorMesDeInicio, valorMesDeInicio);
				// Crear un objeto Hora con los datos obtenidos
				Hora* horaDeInicioHora = new Hora(valorHoraDeInicio, valorMinutoDeInicio, valorSegundoDeInicio);
				Hora* horaDeFinHora = new Hora(valorHoraDeFin, valorMinutoDeFin, valorSegundoDeFin);
				// Crear un objeto Instructor con los datos obtenidos
				Instructor* instructor = new Instructor(nombreInstructor, apellidoInstructor, idInstructor);
				// Crear un objeto Grupo con los datos obtenidos
				Grupo* grupoActual = new Grupo(instructor, stoi(cupoMaximo), fechaDeInicio, stoi(semanasDeDuracion), stoi(numeroGrupo), diaDeLaSemana[0], horaDeInicioHora, horaDeFinHora);
				// Agregar el grupo a la lista de grupos
				cursoActual->agregarGrupo(grupoActual);
			}
			//// Agregar la lista de grupos al curso
			//cursoActual->setListaGrupos(listaGrupos);
			// Agregar el curso a la lista de cursos
			listaCursos->insertar(cursoActual);
		}
	}
	archivoCursos.close();
	return listaCursos;
}
