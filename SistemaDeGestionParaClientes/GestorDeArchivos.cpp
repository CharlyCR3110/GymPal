#include "GestorDeArchivos.h"

GestorDeArchivos::GestorDeArchivos()
{
}

// deportistas y pagos
void GestorDeArchivos::guardarDeportistasYPagos(ListaEnlazada<Deportista>* listaDeportistas_)
{
	ofstream archivoDeportistasYPagos;
	archivoDeportistasYPagos.open("../DeportistasConPagos.txt");
	if (!archivoDeportistasYPagos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo Deportistas.txt");
	}
	else
	{
		Nodo<Deportista>* nodoActual = listaDeportistas_->getPrimero();
		while (nodoActual != nullptr)
		{
			archivoDeportistasYPagos << nodoActual->getDato()->toStringParaGuardarConPagos() << '|';	// delimitador para separar los pagos
			Nodo<Pago>* nodoActualPago = nodoActual->getDato()->getPagos()->getPrimero();
			while (nodoActualPago != nullptr)
			{
				archivoDeportistasYPagos << nodoActualPago->getDato()->toStringParaGuardar() << '|';	// delimitador para separar los pagos
				nodoActualPago = nodoActualPago->getSiguiente();
			}
			archivoDeportistasYPagos << '\n';	// delimitador para separar los deportistas
			nodoActual = nodoActual->getSiguiente();
		}
		archivoDeportistasYPagos.close();
	}
}

ListaEnlazada<Deportista>* GestorDeArchivos::cargarDeportistasYPagos()
{
	ListaEnlazada<Deportista>* listaDeportistas = new ListaEnlazada<Deportista>();
	ifstream archivoDeportistasYPagos;
	archivoDeportistasYPagos.open("../DeportistasConPagos.txt");
	if (!archivoDeportistasYPagos.is_open())
	{
		throw runtime_error("No se pudo abrir el archivo DeportistasConPagos.txt");
	}
	else
	{
		string linea;
		while (getline(archivoDeportistasYPagos, linea))
		{
			stringstream ss(linea);
			string cedula, nombre, telefono, fechaNacimientoDia, fechaNacimientoMes, fechaNacimientoAnio, horasEntrenamiento, temperaturaPromedio, cantidadParticipacionesIronMan, cantidadTriatlonesGanados, sexo, estatura, masaMuscular, peso, porcentajeGrasaCorporal, fechaUltimaActualizacionDia, fechaUltimaActualizacionMes, fechaUltimaActualizacionAnio, cantidadDePagos;
			int valorCantidadDePagos;
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
			getline(ss, fechaUltimaActualizacionAnio, ';');
			getline(ss, cantidadDePagos, '|');
			Deportista* deportista = new Triatlonista(cedula, nombre, telefono, new Fecha(stoi(fechaNacimientoDia), stoi(fechaNacimientoMes), stoi(fechaNacimientoAnio)), stoi(horasEntrenamiento), stod(temperaturaPromedio), stoi(cantidadParticipacionesIronMan), stoi(cantidadTriatlonesGanados), sexo[0], stod(estatura), stod(masaMuscular), stod(peso), stod(porcentajeGrasaCorporal), new Fecha(stoi(fechaUltimaActualizacionDia), stoi(fechaUltimaActualizacionMes), stoi(fechaUltimaActualizacionAnio)));

			valorCantidadDePagos = stoi(cantidadDePagos);
			// while para cargar los pagos, cada pago esta separado por un |, cuando se encuentre un '\n' es porque es otro deportista
			for (int i = 0; i < valorCantidadDePagos; i++)
			{
				string lineaPago;
				getline(ss, lineaPago, '|');
				stringstream ssPago(lineaPago);
				string fechaPagoDia, fechaPagoMes, fechaPagoAnio, mesCancelado, monto;
				getline(ssPago, fechaPagoDia, ';');
				getline(ssPago, fechaPagoMes, ';');
				getline(ssPago, fechaPagoAnio, ';');
				getline(ssPago, mesCancelado, ';');
				getline(ssPago, monto, '|');
				Pago* pago = new Pago(new Fecha(stoi(fechaPagoDia), stoi(fechaPagoMes), stoi(fechaPagoAnio)), mesCancelado, stod(monto));
				deportista->getPagos()->insertar(pago);
			}
			listaDeportistas->insertar(deportista);
		}
	}
	archivoDeportistasYPagos.close();
	return listaDeportistas;
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

// recibe el texto que va a tener el archivo
const void GestorDeArchivos::guardarCursoGrupoYCedulaDeLosDeportistasAsociados(string texto) const
{
	ofstream archivoCursosParaMatricula;
	archivoCursosParaMatricula.open("../ArchivoParaMatricular.txt");
	if (archivoCursosParaMatricula.fail())
	{
		throw runtime_error("No se pudo abrir el archivo para matricular");
	}
	archivoCursosParaMatricula << texto;
	archivoCursosParaMatricula.close();
}

#include "Gimnasio.h"
void GestorDeArchivos::cargarCursoGrupoYCedulaDeLosDeportistasAsociados(Gimnasio* gimnasio_)
{
//
	ifstream archivoCursosParaMatricula;
	archivoCursosParaMatricula.open("../ArchivoParaMatricular.txt");
	if (archivoCursosParaMatricula.fail())
	{
		throw runtime_error("No se pudo abrir el archivo para matricular");
	}

	string linea;
	string codigoCurso;
	string cantidadDeGrupos;
	string numeroGrupo;
	string cantidadDeInscritos;
	string cedulaDeportista;
	stringstream ss;
	// recorre el archivo, cada linea tiene un curso y sus grupos con los deportistas inscritos
	while (getline(archivoCursosParaMatricula, linea))
	{
		ss << linea;
		// obtiene el codigo del curso
		getline(ss, codigoCurso, ';');
		// obtiene la cantidad de grupos del curso
		getline(ss, cantidadDeGrupos, ';');
		// recorre la cantidad de grupos del curso
		for (int i = 0; i < stoi(cantidadDeGrupos); i++)
		{
			// obtiene el numero del grupo
			getline(ss, numeroGrupo, ';');
			// obtiene la cantidad de inscritos del grupo
			getline(ss, cantidadDeInscritos, '-');
			// recorre la cantidad de inscritos del grupo
			for (int j = 0; j < stoi(cantidadDeInscritos); j++)
			{
				// obtiene la cedula del deportista
				getline(ss, cedulaDeportista, ';');
				// busca el deportista en el gimnasio
				gimnasio_->matricularEnGrupo(codigoCurso, stoi(numeroGrupo), cedulaDeportista);
			}
		}
		ss.clear();
	}
}
