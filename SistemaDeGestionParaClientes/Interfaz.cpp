#include "Interfaz.h"

using namespace std;
Gimnasio* Interfaz::gimnasio = new Gimnasio();


// *Nota* El clearInputBuffer puede generar la necesidad de tocar dos veces enter para que se ejecute la siguiente instruccion, pero si no se usa, muchas veces se toma una entrada vacia y salta el mensaje "No se puede ingresar un valor vacio"

int Interfaz::menuPrincipal()
{
	int opcion = 0;
	cout << "\t\tMenu Principal" << endl;
	cout << "1. Administracion General" << endl;
	cout << "2. Control de Deportistas" << endl;
	cout << "3. Control de Cursos" << endl;
	cout << "4. Control de Grupos" << endl;
	cout << "5. Control Pagos" << endl;
	cout << "6. Guardar en Archivos y salir" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

//---------------------//
int Interfaz::menuAdministracionGeneral()   // sub menu 1 de menu principal
{
	int opcion = 0;
	cout << "\t\t1. Administracion General" << endl;
	cout << "1. Nombre del Gimnasio" << endl;
	cout << "2. Monto Mensual" << endl;
	cout << "3. Regresar al menu principal" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuAdministracionGeneralNombreGimnasio()    // sub menu 1 de menu administracion general
{
	string nombreGimnasio;
	cout << endl << endl << "\t<1. Administracion General> <1. Nombre del Gimnasio>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el nuevo nombre del gimnasio: ";
	cin >> nombreGimnasio;
	gimnasio->setNombreDelGimnasio(nombreGimnasio);
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuAdministracionGeneralMontoMensual()  // sub menu 2 de menu administracion general
{
	double montoMensual;
	cout << endl << endl << "\t<1. Administracion General> <2. Monto Mensual>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el nuevo monto mensual: ";
	cin >> montoMensual;
	gimnasio->setMontoMensual(montoMensual);
	cout << "-----------------------------------------------------------" << endl;
}
//---------------------//

//---------------------//
int Interfaz::menuControlDeportistas()
{
	int opcion = 0;
	cout << "\t\t2. Control de Deportistas" << endl;
	cout << "1. Ingreso nuevo deportista" << endl;
	cout << "2. Modificacion de deportista" << endl;
	cout << "3. Listado de deportistas" << endl;
	cout << "4. Detalle de deportista especifico" << endl;
	cout << "5. Regresar al menu principal" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

//void Interfaz::menuControlDeportistasIngresoNuevoDeportista()
//{
//	string cedula, nombre, telefono;
//	Fecha* fechaNacimiento;
//	char sexo;
//	int horasEntrenamiento, cantidadParticipacionesIronMan, cantidadTriatlonesGanados;
//	double temperaturaPromedio, estatura, masaMuscular, peso, porcentajeGrasaCorporal;
//	cout << endl << endl << "\t<2. Control Deportistas> <1. Ingreso nuevo deportista>" << endl << endl;
//	cout << "-----------------------------------------------------------" << endl;
//	cout << "Datos generales:" << endl;
//	cout << "\tDigite la cedula del deportista: ";
//	cin >> cedula;
//	cout << "----" << endl;
//	cout << "\tDigite el nombre del deportista: ";
//	cin >> nombre;
//	cout << "----" << endl;
//	cout << "\tDigite el telefono del deportista: ";
//	cin >> telefono;
//	cout << "----" << endl;
//	cout << "\tDigite la fecha de nacimiento del deportista: " << endl;
//	fechaNacimiento = Interfaz::menuFecha();
//	cout << "----" << endl;
//	cout << "\tDigite el sexo del deportista (f/m): ";
//	cin >> sexo;
//	cout << "----" << endl;
//	cout << "\tDigite la cantidad de horas de entrenamiento del deportista: ";
//	cin >> horasEntrenamiento;
//	cout << "----" << endl;
//	cout << "\tDigite la temperatura promedio del deportista: ";
//	cin >> temperaturaPromedio;
//	cout << "----" << endl;
//	cout << "\tDigite la cantidad de participaciones en IronMan del deportista: ";
//	cin >> cantidadParticipacionesIronMan;
//	cout << "----" << endl;
//	cout << "\tDigite la cantidad de triatlones ganados del deportista: ";
//	cin >> cantidadTriatlonesGanados;
//	cout << "----" << endl;
//	cout << endl << "Datos biom�tricos b�sicos" << endl;
//	cout << "\tDigite la estatura del deportista: ";
//	cin >> estatura;
//	cout << "----" << endl;
//	cout << "\tDigite el peso del deportista: ";
//	cin >> peso;
//	cout << "----" << endl;
//	cout << "\tDigite el porcentaje de grasa corporal del deportista: ";
//	cin >> porcentajeGrasaCorporal;
//	cout << "----" << endl;
//	cout << "\tDigite la masa muscular del deportista: ";
//	cin >> masaMuscular;
//	cout << "----" << endl;
//
//	try
//	{
//		gimnasio->registrarDeportista(cedula, nombre, telefono, fechaNacimiento, horasEntrenamiento, temperaturaPromedio, cantidadParticipacionesIronMan, cantidadTriatlonesGanados, sexo, estatura, masaMuscular, peso, porcentajeGrasaCorporal);
//		cout << "Deportista registrado con exito" << endl;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	cout << "-----------------------------------------------------------" << endl;
//}

void Interfaz::menuControlDeportistasIngresoNuevoDeportista()
{
	string cedula, nombre, telefono;
	Fecha* fechaNacimiento;
	char sexo;
	int horasEntrenamiento, cantidadParticipacionesIronMan, cantidadTriatlonesGanados;
	double temperaturaPromedio, estatura, masaMuscular, peso, porcentajeGrasaCorporal;
	cout << endl << endl << "\t<2. Control Deportistas> <1. Ingreso nuevo deportista>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "\tDatos generales:" << endl;
	cedula = Interfaz::ingresarYValidarCedulaDeportista();
	cout << "----" << endl;
	nombre = Interfaz::ingresarYValidarNombreDeportista();
	cout << "----" << endl;
	telefono = Interfaz::ingresarYValidarTelefonoDeportista();
	cout << "----" << endl;
	cout << "\tDigite la fecha de nacimiento del deportista: " << endl;
	fechaNacimiento = Interfaz::menuFecha();
	cout << "----" << endl;
	sexo = Interfaz::ingresarYValidarSexoDeportista();
	cout << "----" << endl;
	horasEntrenamiento = Interfaz::ingresarYValidarHorasEntrenamientoDeportista();
	cout << "----" << endl;
	temperaturaPromedio = Interfaz::ingresarYValidarTemperaturaPromedio();
	cout << "----" << endl;
	cantidadParticipacionesIronMan = Interfaz::ingresarYValidarCantidadParticipacionesIronManDeportista();
	cout << "----" << endl;
	cantidadTriatlonesGanados = Interfaz::ingresarYValidarCantidadTriatlonesGanadosDeportista(cantidadParticipacionesIronMan);
	cout << "----" << endl;
	cout << "\tDatos Biometricos Basicos" << endl;
	estatura = Interfaz::ingresarYValidarEstaturaDeportista();
	cout << "----" << endl;
	peso = Interfaz::ingresarYValidarPesoDeportista();
	cout << "----" << endl;
	porcentajeGrasaCorporal = Interfaz::ingresarYValidarPorcentajeGrasaCorporalDeportista();
	cout << "----" << endl;
	masaMuscular = Interfaz::ingresarYValidarPorcentajeMasaMuscularDeportista();
	cout << "----" << endl;

	try
	{
		gimnasio->registrarDeportista(cedula, nombre, telefono, fechaNacimiento, horasEntrenamiento, temperaturaPromedio, cantidadParticipacionesIronMan, cantidadTriatlonesGanados, sexo, estatura, masaMuscular, peso, porcentajeGrasaCorporal);
		cout << "Deportista registrado con exito" << endl;
	}
	catch (exception& e)
	{
		cout << "Error al registrar el deportista" << endl;
		cout << e.what() << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlDeportistasModificarDeportista()
{
	Deportista* deportista = nullptr;
	string cedula;
	int opcion = 1;

	cout << endl << endl << "\t<2. Control Deportistas> <2. Modificacion de deportista>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "Digite la cedula del deportista: ";
	cin >> cedula;
	try
	{
		deportista = gimnasio->buscarDeportista(cedula);
		cout << "Deportista encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	if (deportista == nullptr)
	{
		cerr << "Error: Error inesperado" << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Que dato desea modificar: " << endl;
	cout << "1. Nombre" << endl;
	cout << "2. Telefono" << endl;
	cout << "3. Fecha de nacimiento" << endl;
	cout << "4. Sexo" << endl;
	cout << "5. Estatura" << endl;
	cout << "6. Peso" << endl;
	cout << "7. Porcentaje de grasa corporal" << endl;
	cout << "8. Porcentaje de masa muscular" << endl;
	cout << "9. Estado" << endl;
	cout << "10. Horas entrenamiento" << endl;
	cout << "11. Cantidad de partidos IronMan" << endl;
	cout << "12. Cantidad de triatlones ganados" << endl;
	cout << "Digite una opcion: ";
	cin >> opcion;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');    // limpiar buffer de entrada
	cout << "-----------------------------------------------------------" << endl;
	switch (opcion)
	{
	case 1:
		modificarNombreDeportista(deportista);
		break;
	case 2:
		modificarTelefonoDeportista(deportista);
		break;
	case 3:
		modificarFechaNacimientoDeportista(deportista);
		break;
	case 4:
		modificarSexoDeportista(deportista);
		break;
	case 5:
		modificarEstaturaDeportista(deportista, gimnasio->getFechaActual());
		break;
	case 6:
		modificarPesoDeportista(deportista, gimnasio->getFechaActual());
		break;
	case 7:
		modificarPorcentajeGrasaCorporalDeportista(deportista, gimnasio->getFechaActual());
		break;
	case 8:
		modificarPorcentajeMasaMuscularDeportista(deportista, gimnasio->getFechaActual());
		break;
	case 9:
		modificarEstadoDeportista(deportista);
		break;
	case 10:
		modificarHorasEntrenamientoDeportista(deportista);
		break;
	case 11:
		modificarCantidadParticipacionesIronManDeportista(deportista);
		break;
	case 12:
		modificarCantidadTriatlonesGanadosDeportista(deportista);
		break;
	default:
		cout << "Opcion invalida" << endl;
		break;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlDeportistasMostrarListadosDeportistas()
{
	int opcion;
	cout << endl << endl << "<2. Control Deportistas> <3. Listado de Deportistas>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "1. Listado general" << endl;
	cout << "2. Listado de deportistas activos" << endl;
	cout << "3. Listado de deportistas inactivos" << endl;
	cout << "4. Listado de deportistas en morosidad" << endl;
	cout << "Digite una opción del menú: ";
	cin >> opcion;
	cout << "-----------------------------------------------------------" << endl;
	switch (opcion) {
	case 1:
		// Código para mostrar el listado de deportistas general
		try {
			cout << gimnasio->generarReporteDeportistas();
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
		break;
	case 2:
		// Código para mostrar el listado de deportistas activos
		try {
			cout << gimnasio->generarReporteDeportistasPorEstado('A');
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
		break;
	case 3:
		// Código para mostrar el listado de deportistas inactivos
		try {
			cout << gimnasio->generarReporteDeportistasPorEstado('I');
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
		break;
	case 4:
		// Código para mostrar el listado de deportistas en morosidad
		try {
			cout << gimnasio->generarReporteDeportistasPorEstado('P');
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
		break;
	default:
		cout << "Opción inválida. Por favor, seleccione una opción del menú." << endl;
		break;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlDeportistasMostrarDeportistaEspecifico()
{
	string cedula;
	cout << endl << endl << "<2. Control Deportistas> <3. Listado de Deportistas>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite la cedula del deportista: ";
	cin >> cedula;
	cout << "-----------------------------------------------------------" << endl;
	try {
		cout << gimnasio->generarReporteDeportistaCed(cedula);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}

//---------------------//
int Interfaz::menuControlCursos()
{
	int opcion = 0;
	cout << "\t\t3. Control de Cursos" << endl;
	cout << "1. Ingreso nuevo curso" << endl;
	cout << "2. Reporte de curso especifico" << endl;
	cout << "3. Modificacion de -curso especifico" << endl;
	cout << "4. Regresar al menu principal" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuControlCursosIngresoNuevoCurso()
{
	string codigo, nombre, nivel, descripcion;
	int cantidadGrupos;
	cout << endl << endl << "<3. Control Cursos> <1. Ingreso nuevo curso>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	codigo = Interfaz::ingresarYValidarCodigo();
	cout << "----" << endl;
	nombre = Interfaz::ingresarYValidarNombre();
	cout << "----" << endl;
	nivel = Interfaz::ingresarYValidarNivel();
	cout << "----" << endl;
	cantidadGrupos = Interfaz::ingresarYValidarCantidadGrupos();
	cout << "----" << endl;
	descripcion = Interfaz::ingresarYValidarDescripcion();
	cout << "----" << endl;
	try {
		gimnasio->registrarCurso(codigo, nombre, nivel, descripcion, cantidadGrupos);
		cout << "Curso registrado exitosamente" << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlCursosMostrarCursoEspecifico()
{
	string codigo;
	cout << endl << endl << "<3. Control Cursos> <2. Reporte de curso especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;

	try {
		cout << gimnasio->generarListadoCursos();
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return;
	}
	cout << "Digite el codigo del curso: ";
	cin >> codigo;
	cout << "-----------------------------------------------------------" << endl;
	try {
		cout << gimnasio->generarReporteCursoCod(codigo);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlCursosModificarCurso()
{
	Curso* curso = nullptr;
	string codigo;
	int opcion;
	cout << endl << endl << "<3. Control Cursos> <3. Modificacion de curso especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Ingrese el codigo del curso especifico: ";
	cin >> codigo;
	try
	{
		curso = gimnasio->buscarCurso(codigo);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Cual dato desea modificar: " << endl;
	cout << "1. Codigo del curso" << endl;
	cout << "2. Nombre del curso" << endl;
	cout << "3. Nivel" << endl;
	cout << "4. Descripcion" << endl;
	cout << "5. Cantidad de grupos" << endl;
	cout << "Ingrese una opcion del menu: ";
	cin >> opcion;
	cout << "-----------------------------------------------------------" << endl;
	switch (opcion)
	{
	case 1:
		Interfaz::modificarCodigoCurso(curso);
		break;
	case 2:
		Interfaz::modificarNombreCurso(curso);
		break;
	case 3:
		Interfaz::modificarNivelCurso(curso);
		break;
	case 4:
		Interfaz::modificarDescripcionCurso(curso);
		break;
	case 5:
		Interfaz::modificarCantidadGruposCurso(curso);
		break;
	default:
		cout << "Opcion invalida. Por favor, seleccione una opcion del menu." << endl;
		break;
	}
	cout << "-----------------------------------------------------------" << endl;
}

int Interfaz::menuControlGrupos()
{
	int opcion = 0;
	cout << "\t\t4. Control de Grupos" << endl;
	cout << "1. Ingreso nuevo grupo" << endl;
	cout << "2. Modificacion de grupo especifico" << endl;
	cout << "3. Matricula en grupo especifico" << endl;
	cout << "4. Reporte de grupo especifico" << endl;
	cout << "5. Reporte deportistas matriculados en grupo" << endl;
	cout << "6. Cancelacion de matricula en grupo" << endl;
	cout << "7. Regresar al menu principal" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuControlGruposIngresoNuevoGrupo()
{
	Curso * curso = nullptr;
	Instructor* instructor = nullptr;
	int cupoMaximo, semanasDuracion = 0;
	Fecha* fechaInicio = nullptr;
	char dia = ' ';
	Hora* horaInicio = nullptr;
	Hora* horaFin = nullptr;
	string codigo = "";
	Grupo* grupo = nullptr;
	int numeroGrupo = 0;
	cout << endl << endl << "<4. Control Grupos> <1. Ingreso nuevo grupo>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		cout << gimnasio->generarListadoCursos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;	// si no hay cursos registrados, no se puede registrar un grupo
	}
	cout << "Digite el codigo del curso: ";
	cin >> codigo;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		curso = gimnasio->buscarCurso(codigo);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	Utils::clearInputBuffer();
	instructor = Interfaz::ingresarYValidarInstructor();
	cout << "----" << endl;
	cupoMaximo = Interfaz::ingresarYValidarCupoMaximo();
	Utils::clearInputBuffer();
	cout << "----" << endl;
	fechaInicio = Interfaz::menuFecha();
	Utils::clearInputBuffer();
	cout << "----" << endl;
	semanasDuracion = Interfaz::ingresarYValidarSemanasDuracion();
	Utils::clearInputBuffer();
	cout << "----" << endl;
	cout << "Horario: " << endl;
	dia = Interfaz::ingresarYValidarDiaDeLaSemana();
	cout << "----" << endl;
	Utils::clearInputBuffer();
	horaInicio = Interfaz::ingresarYValidarHoraEntrada();
	cout << "----" << endl;
	Utils::clearInputBuffer();
	horaFin = Interfaz::ingresarYValidarHoraSalida(horaInicio);
	cout << "----" << endl;

	if (curso->getListaGrupos()->getCantidad() == 0)
	{
		numeroGrupo = 1;
	}
	else
	{
		numeroGrupo = curso->getListaGrupos()->getCantidad() + 1;
	}

	try
	{
		grupo = new Grupo(instructor, cupoMaximo, fechaInicio, semanasDuracion, numeroGrupo, dia, horaInicio, horaFin);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}

	try 
	{
		gimnasio->agregarGrupo(codigo, grupo);
		cout << "Excelente!!! Se ha creado el grupo #" << numeroGrupo << " del curso " << curso->getCodigo() << endl;
	}
	catch (exception& e)
	{
		cout << "Error al crear el grupo" << endl;
		cerr << e.what() << endl;
		return;
	}
	cout << endl << endl << "-------------------------------------------------";
}

void Interfaz::menuControlGruposModificarGrupo()
{
	Curso* curso = nullptr;
	Grupo* grupo = nullptr;
	int opcion = 0;
	string codigo = "";
	cout << endl << endl << "<4. Control Grupo> <2. Modificacion de grupo especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		cout << gimnasio->generarListadoCursos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}

	cout << "Digite el codigo del curso: ";
	cin >> codigo;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		curso = gimnasio->buscarCurso(codigo);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}

	try
	{
		cout << curso->generarListadoDeGrupos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el numero del grupo a modificar: ";
	cin >> opcion;
	cout << "-----------------------------------------------------------" << endl;

	try
	{
		grupo = curso->obtenerGrupo(opcion);
		cout << "Grupo encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}

	cout << "Que desea modificar: " << endl;
	cout << "1. ID del Instructor" << endl;
	cout << "2. Nombre del Instructor" << endl;
	cout << "3. Cupo maximo" << endl;
	cout << "4. Fecha de inicio" << endl;
	cout << "5. Semanas de duracion" << endl;
	cout << "6. Dia de la semana" << endl;
	cout << "7. Hora de inicio" << endl;
	cout << "8. Hora de finalizacion" << endl;
	cout << "Digite una opcion: ";
	cin >> opcion;
	cout << "-----------------------------------------------------------" << endl;
	switch (opcion)
	{
	case 1:
		Interfaz::modificarNombreInstructor(grupo);
		break;
	case 2:
		Interfaz::modificarCedulaInstructor(grupo);
		break;
	case 3:
		Interfaz::modificarCupoMaximoGrupo(grupo);
		break;
	case 4:
		Interfaz::modificarFechaInicioGrupo(grupo);
		break;
	case 5:
		Interfaz::modificarSemanasDuracionGrupo(grupo);
		break;
	case 6:
		Interfaz::modificarDiaDeLaSemanaGrupo(grupo);
		break;
	case 7:
		Interfaz::modificarHoraEntradaGrupo(grupo);
		break;
	case 8:
		Interfaz::modificarHoraSalidaGrupo(grupo);
		break;
	default:
		cout << "Opcion invalida" << endl;
		break;
	}
	cout << endl << endl << "-------------------------------------------------";
}

void Interfaz::menuControlGruposMatricularEnGrupo()
{
	int numeroGrupo;
	string idDeportista;
	string codigoCurso;
	Curso* curso = nullptr;

	cout << endl << endl << "<4. Control Grupo> <3. Matricula en grupo especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el ID del deportista: ";
	cin >> idDeportista;
	cout << "-----------------------------------------------------------" << endl;
	if (gimnasio->existeDeportistaConCedula(idDeportista))
	{
		cout << "Deportista encontrado!!!" << endl;
	}
	else
	{
		cout << "Deportista no encontrado!!!" << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el codigo del curso: ";
	cin >> codigoCurso;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		curso = gimnasio->buscarCurso(codigoCurso);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		cout << curso->generarListadoDeGrupos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el numero de grupo deseado: ";
	cin >> numeroGrupo;
	cout << "-----------------------------------------------------------" << endl;
	if (curso->existeGrupo(numeroGrupo))
	{
		cout << "Grupo encontrado!!!" << endl;
	}
	else
	{
		cout << "Grupo no encontrado!!!" << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		gimnasio->matricularEnGrupo(codigoCurso, numeroGrupo, idDeportista);
		cout << "Haz matriculado al deportista con ID" << idDeportista << " en el grupo " << numeroGrupo << " del curso " << codigoCurso << " el dia " << gimnasio->getFechaActual()->toString() << " exitosamente " << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::menuControlGruposMostrarGrupoEspecifico()
{
	Curso* curso = nullptr;
	int numeroGrupo;
	string codigoCurso;
	Grupo* grupo = nullptr;
	cout << endl << endl << "<4. Control Grupo> <4. Reporte de grupo especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el codigo del curso: ";
	cin >> codigoCurso;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		curso = gimnasio->buscarCurso(codigoCurso);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		cout << curso->generarListadoDeGrupos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el numero de grupo deseado: ";
	cin >> numeroGrupo;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		grupo = curso->obtenerGrupo(numeroGrupo);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "A continuacion se muestra la informacion del grupo #" << numeroGrupo << " del curso " << codigoCurso << ":" << endl;
	cout << grupo->toString() << endl;
	Utils::pause();
	cout << "-----------------------------------------------------------" << endl;

}

void Interfaz::menuControlGruposMostrarDeportistasPorGrupo()
{
	Curso* curso = nullptr;
	int numeroGrupo;
	string codigoCurso;
	Grupo* grupo = nullptr;
	cout << endl << endl << "<5. Control Grupo> <4. Reporte de grupo especifico>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "Digite el codigo del curso: ";
	cin >> codigoCurso;
	cout << "-----------------------------------------------------------" << endl;

	try
	{
		curso = gimnasio->buscarCurso(codigoCurso);
		cout << "Curso encontrado!!!" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return;
	}
	cout << "-----------------------------------------------------------" << endl;

	try
	{
		cout << curso->generarListadoDeGrupos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el numero de grupo deseado: ";
	cin >> numeroGrupo;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		grupo = curso->obtenerGrupo(numeroGrupo);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << " Listado de matriculados en el grupo #" << numeroGrupo << " del grupo " << codigoCurso << ":" << endl;
	cout << grupo->mostrarCedulaYNombreInscritos() << endl;
	cout << "-----------------------------------------------------------" << endl;

}

void Interfaz::menuControlGruposCancelarMatriculaEnGrupo()
{
	int numeroGrupo;
	string codigoCurso;
	string idDeportista;

	cout << endl << endl << "<4. Control Grupo> <6. Cancelacion de matricula en grupo>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el ID del deportista: ";
	cin >> idDeportista;
	cout << "-----------------------------------------------------------" << endl;

	if (gimnasio->existeDeportistaConCedula(idDeportista))
	{
		cout << "Deportista encontrado!!!" << endl;
	}
	else
	{
		cerr << "Error: El deportista no existe" << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;

	cout << "Listado de cursos: " << endl;
	try
	{
		gimnasio->generarListadoCursos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;	// si no hay cursos, no se puede cancelar la matricula
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Digite el codigo del curso: ";
	cin >> codigoCurso;
	cout << "-----------------------------------------------------------" << endl;


	if (gimnasio->existeCursoConCodigo(codigoCurso))
	{
		cout << "Curso encontrado!!!" << endl;
	}
	else
	{
		cout << "El curso no existe" << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;

	try
	{
		cout << gimnasio->buscarCurso(codigoCurso)->generarListadoDeGrupos();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;	// si no hay grupos, no se puede cancelar la matricula
	}
	cout << "-----------------------------------------------------------" << endl;

	cout << "Digite el numero de grupo: ";
	cin >> numeroGrupo;
	cout << "-----------------------------------------------------------" << endl;

	if (gimnasio->buscarCurso(codigoCurso)->existeGrupo(numeroGrupo))
	{
		cout << "Grupo encontrado!!!" << endl;
	}
	else
	{
		cout << "El grupo no existe" << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		gimnasio->desmatricularDeGrupo(codigoCurso, numeroGrupo, idDeportista);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;

}

int Interfaz::menuControlPagos()
{
	int opcion = 0;
	cout << "\t\t5. Control de Pagos" << endl;
	cout << "1. Registro de nuevo pago" << endl;
	cout << "2. Reporte de pagos por deportista" << endl;
	cout << "3. Regresar al menu principal" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuControlPagosIngresoNuevoPago()
{
	string idDeportista;
	int cantidadDeCuotas;
	cout << endl << endl << "<5. Control Pagos> <1. Registro de nuevo pago>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Fecha Actual: " << gimnasio->getFechaActual()->toString() << endl;
	cout << "Digite la cedula del deportista: ";
	cin >> idDeportista;
	cout << "-----------------------------------------------------------" << endl;
	if (gimnasio->existeDeportistaConCedula(idDeportista))
	{
		cout << "Deportista encontrado!!!" << endl;
	}
	else
	{
		cout << "El deportista no existe" << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Cuantas cuotas desea cancelar o pagar: ";
	cin >> cantidadDeCuotas;
	cout << "-----------------------------------------------------------" << endl;
	try
	{
		cout << gimnasio->registrarPago(idDeportista, cantidadDeCuotas);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;

}

void Interfaz::menuControlPagosMostrarPagosDeportista()
{
	string cedula;
	cout << endl << endl << "<5. Control Pagos> <2. Reporte de pagos por deportista>" << endl << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "Digite la cedula del deportista: ";
	cin >> cedula;
	cout << "-----------------------------------------------------------" << endl;

	try
	{
		cout << gimnasio->generarReportePagosCed(cedula);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		Utils::pause();
		return;
	}
	cout << "-----------------------------------------------------------" << endl;
}

void Interfaz::regresar()
{
	cout << "Presione cualquier tecla para regresar al menu principal..." << endl;
	Utils::pause();
	Utils::clearScreen();
}

void Interfaz::opcionInvalida()
{
	cout << "Opcion invalida, presione cualquier tecla para continuar..." << endl;
	Utils::pause();
	Utils::clearScreen();
}

void Interfaz::salir()
{
	try
	{
		gimnasio->guardarParaMatricular();
		cout << "Archivo para matricular guardado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		gimnasio->guardarCursosYGrupos();
		cout << "Archivo cursos y grupos guardado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		gimnasio->guardarEnArchivoDeportistasYSusPagos();
		cout << "Archivo deportistas y sus pagos guardado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	
	Utils::pause();
	Utils::clearScreen();
	cout << "Gracias por usar el sistema" << endl;
	Utils::pause();
	Utils::clearScreen();
	cout << "Eliminando gimnasio...";
	delete gimnasio;
}

void Interfaz::mensajeDeBienvenida()
{
	try
	{
		//gimnasio->setListaDeportistas(GestorDeArchivos().cargarDeportistas());
		gimnasio->setListaDeportistas(GestorDeArchivos().cargarDeportistasYPagos());
		cout << "Archivo deportistas y pagos cargado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		gimnasio->setListaCursos(GestorDeArchivos().cargarCursosYGrupos());
		cout << "Archivo cursos y grupos cargado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	try
	{
		GestorDeArchivos().cargarCursoGrupoYCedulaDeLosDeportistasAsociados(gimnasio);
		cout << "Archivo curso, grupo y cedula de los deportistas asociados cargado exitosamente" << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	Utils::pause();
	Utils::clearScreen();
	cout << "Bienvenido al sistema de gestion de gimnasio" << endl;
	cout << gimnasio->getNombreDelGimnasio() << endl;
	cout << "La fecha del sistema es: " << gimnasio->getFechaActual()->toString() << endl;
}

Fecha* Interfaz::menuFecha()
{
	int dia, mes, anio;
	Fecha* fecha = new Fecha(); // Se crea un objeto Fecha por defecto
	bool esFechaValida = false;

	while (!esFechaValida)
	{
		cout << "Digite la fecha de inicio (dd/mm/aaaa): " << endl;
		cout << "Dia: ";
		if (!(cin >> dia))
		{
			cerr << "Error: El dia debe ser un numero." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		cout << "Mes: ";
		if (!(cin >> mes))
		{
			cerr << "Error: El mes debe ser un numero." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		cout << "Anio: ";
		if (!(cin >> anio))
		{
			cerr << "Error: El anio debe ser un numero." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (fecha->esValida(dia, mes, anio))
		{
			fecha->setDia(dia);
			fecha->setMes(mes);
			fecha->setAnio(anio);
			esFechaValida = true;
		}
		else
		{
			cerr << "Error: La fecha ingresada no es valida." << endl;
			cout << "Por favor, intente de nuevo." << endl;
		}
	}

	return fecha;
}


void Interfaz::modificarNombreDeportista(Deportista* deportista)
{
	string nombre;
	bool esNombreValido = false;

	while (!esNombreValido)
	{
		cout << "Digite el nuevo nombre del deportista: ";
		Utils::clearInputBuffer();
		getline(cin, nombre);

		if (nombre.empty())
		{
			cout << "Error: El nombre del deportista no puede estar vacio." << endl;
			continue;
		}

		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El nombre del deportista solo puede contener letras y espacios." << endl;
			continue;
		}

		deportista->setNombre(nombre);
		cout << "Nombre modificado exitosamente." << endl;
		esNombreValido = true;
	}
}

void Interfaz::modificarTelefonoDeportista(Deportista* deportista)
{
	string telefono;
	bool esTelefonoValido = false;

	while (!esTelefonoValido)
	{
		cout << "Digite el nuevo telefono del deportista: ";
		Utils::clearInputBuffer();
		getline(cin, telefono);

		if (telefono.empty())
		{
			cout << "Error: El telefono del deportista no puede estar vacio." << endl;
			continue;
		}

		bool esCadenaValida = true;
		for (char c : telefono)
		{
			if (!isdigit(c) && c != '-')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El telefono del deportista solo puede contener numeros y guiones." << endl;
			continue;
		}

		deportista->setTelefono(telefono);
		esTelefonoValido = true;
		cout << "Telefono modificado exitosamente." << endl;
	}
}

void Interfaz::modificarFechaNacimientoDeportista(Deportista* deportista)
{
	Fecha* fechaNacimiento = nullptr;
	bool esFechaValida = false;
	while (!esFechaValida)
	{
		cout << "Digite la nueva fecha de nacimiento del deportista: " << endl;
		try
		{
			fechaNacimiento = menuFecha();
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
			continue;
		}

		if (fechaNacimiento == nullptr)
		{
			cout << "Error: La fecha de nacimiento del deportista no puede estar vacia." << endl;
			continue;
		}
		deportista->setFechaNacimiento(fechaNacimiento);
		esFechaValida = true;
		cout << "Fecha de nacimiento modificada exitosamente." << endl;
	}
}

void Interfaz::modificarSexoDeportista(Deportista* deportista)
{
	char sexo;
	bool esSexoValido = false;
	while (!esSexoValido)
	{
		cout << "Digite el nuevo sexo del deportista: ";
		cin >> sexo;
		if (sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f')
		{
			cout << "Error: El sexo del deportista solo puede ser M o F." << endl;
			continue;
		}
		deportista->setSexo(sexo);
		esSexoValido = true;
		cout << "Sexo modificado exitosamente." << endl;
	}
}

void Interfaz::modificarEstaturaDeportista(Deportista* deportista, Fecha* fechaActual_)
{
	double estatura;
	bool esEstaturaValida = false;
	while (!esEstaturaValida)
	{
		cout << "Digite la nueva estatura del deportista: ";
		if (!(cin >> estatura) || estatura <= 0)
		{
			cerr << "Error: La estatura del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		try
		{
			deportista->actualizarEstatura(estatura, fechaActual_);
			esEstaturaValida = true;
			cout << "Estatura modificada exitosamente." << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
}

void Interfaz::modificarPesoDeportista(Deportista* deportista, Fecha* fechaActual_)
{
	float peso;
	bool esPesoValido = false;
	while (!esPesoValido)
	{
		cout << "Digite el nuevo peso del deportista: ";
		if (!(cin >> peso) || peso <= 0)
		{
			cerr << "Error: El peso del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		try
		{
			deportista->actualizarPeso(peso, fechaActual_);
			esPesoValido = true;
			cout << "Peso modificado exitosamente." << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
}

void Interfaz::modificarPorcentajeGrasaCorporalDeportista(Deportista* deportista, Fecha* fechaActual_)
{
	double porcentajeGrasaCorpolar;
	bool esPorcentajeValido = false;
	while (!esPorcentajeValido)
	{
		cout << "Digite el nuevo peso del deportista: ";
		if (!(cin >> porcentajeGrasaCorpolar) || porcentajeGrasaCorpolar <= 0)
		{
			cerr << "Error: El peso del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (porcentajeGrasaCorpolar >= 100)
		{
			cerr << "Error: El porcentaje de grasa corporal del deportista debe ser menor a 100." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		try
		{
			deportista->actualizarPorcentajeGrasaCorporal(porcentajeGrasaCorpolar, fechaActual_);
			esPorcentajeValido = true;
			cout << "Porcentaje de grasa corporal modificado exitosamente." << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
}

void Interfaz::modificarPorcentajeMasaMuscularDeportista(Deportista* deportista, Fecha* fechaActual_)
{
	double porcentajeMasaMuscular;
	bool esPorcentajeValido = false;
	while (!esPorcentajeValido)
	{
		cout << "Digite el nuevo porcentaje de masa muscular del deportista: ";
		if (!(cin >> porcentajeMasaMuscular) || porcentajeMasaMuscular <= 0)
		{
			cerr << "Error: El porcentaje de masa muscular del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (porcentajeMasaMuscular >= 100)
		{
			cerr << "Error: El porcentaje de masa muscular del deportista debe ser menor a 100." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		try
		{
			deportista->actualizarMasaMuscular(porcentajeMasaMuscular, fechaActual_);
			esPorcentajeValido = true;
			cout << "Porcentaje de masa muscular modificado exitosamente." << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
}

void Interfaz::modificarEstadoDeportista(Deportista* deportista)
{
	// el estado del deportista solo puede ser cambiado a activo o inactivo. Si el estado del deportista es P, no se puede cambiar.
	char estado;
	bool esEstadoValido = false;
	while (!esEstadoValido)
	{
		cout << "Digite el nuevo estado del deportista: ";
		cin >> estado;
		if (estado != 'A' && estado != 'I' && estado != 'a' && estado != 'i')
		{
			cout << "Error: El estado del deportista solo se puede actualizar a 'A' o 'I'." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		try {
			deportista->actualizarEstado(estado);
			esEstadoValido = true;
			cout << "Estado modificado exitosamente." << endl;
		}
		catch (exception& e)
		{
			cerr << e.what() << endl;
		}
	}
}

void Interfaz::modificarHorasEntrenamientoDeportista(Deportista* deportista)
{
	int horasEntrenamiento;
	bool esHorasValido = false;
	while (!esHorasValido)
	{
		cout << "Digite las nuevas horas de entrenamiento del deportista: ";
		if (!(cin >> horasEntrenamiento) || horasEntrenamiento <= 0)
		{
			cerr << "Error: Las horas de entrenamiento del deportista deben ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		deportista->setHorasEntrenamiento(horasEntrenamiento);
		esHorasValido = true;
		cout << "Horas de entrenamiento modificadas exitosamente." << endl;
	}
}

void Interfaz::modificarCantidadParticipacionesIronManDeportista(Deportista* deportista)
{
	int cantidadPartidosIronMan;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la nueva cantidad de participaciones en competencias Iron Man: ";
		if (!(cin >> cantidadPartidosIronMan) || cantidadPartidosIronMan < 0)
		{
			cerr << "Error: la cantidad de participaciones en competencias Iron Man debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		deportista->setCantidadParticipacionesIronMan(cantidadPartidosIronMan);
		esCantidadValida = true;
		cout << "Cantidad de participacones Iron Man modificadase exitosamente" << endl;
	}
}

void Interfaz::modificarCantidadTriatlonesGanadosDeportista(Deportista* deportista)
{
	int cantidadTriatlonesGanados;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la nueva cantidad de triatlones ganados: ";
		if (!(cin >> cantidadTriatlonesGanados) || cantidadTriatlonesGanados < 0)
		{
			cerr << "Error: la cantidad de triatlones ganados debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (cantidadTriatlonesGanados > deportista->getCantidadParticipacionesIronMan())
		{
			cerr << "Error: la cantidad de triatlones ganados debe de ser menor a la cantidad de participaciones en triatlones Iron Man" << endl;
			continue;
		}

		deportista->setCantidadTriatlonesGanados(cantidadTriatlonesGanados);
		esCantidadValida = true;
		cout << "Cantidad de triatlones ganados modificada exitosamente." << endl;
	}
}

string Interfaz::ingresarYValidarCedulaDeportista()
{
	Utils::clearInputBuffer();
	string cedula;
	bool esCedulaValida = false;
	while (!esCedulaValida)
	{
		cout << "Digite la cedula del deportista: ";
		getline(cin, cedula);
		if (cedula.empty())
		{
			cerr << "Error: EL ID del deportista no puede estar vacia." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		// verificar que no haya otro deportista con la misma cedula
		if (gimnasio->existeDeportistaConCedula(cedula))
		{
			cerr << "Error: Ya existe un deportista con la cedula " << cedula << "." << endl;
			continue;
		}

		esCedulaValida = true;
	}
	return cedula;
}

string Interfaz::ingresarYValidarNombreDeportista()
{
	string nombre;
	bool esNombreValido = false;

	while (!esNombreValido)
	{
		cout << "Digite el nombre del deportista: ";
		getline(cin, nombre);

		if (nombre.empty())
		{
			cout << "Error: El nombre del deportista no puede estar vacio." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El nombre del deportista solo puede contener letras y espacios." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esNombreValido = true;
	}

	return nombre;
}

string Interfaz::ingresarYValidarTelefonoDeportista()
{
	string telefono;
	bool esTelefonoValido = false;

	while (!esTelefonoValido)
	{
		cout << "Digite el telefono del deportista: ";
		getline(cin, telefono);

		if (telefono.empty())
		{
			cout << "Error: El telefono del deportista no puede estar vacio." << endl;
			continue;
		}

		bool esCadenaValida = true;
		for (char c : telefono)
		{
			if (!isdigit(c) && c != '-')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El telefono del deportista solo puede contener numeros y guiones." << endl;
			continue;
		}

		esTelefonoValido = true;
	}
	return telefono;
}

char Interfaz::ingresarYValidarSexoDeportista()
{
	char sexo;
	bool esSexoValido = false;
	while (!esSexoValido)
	{
		cout << "Digite el sexo del deportista: ";
		cin >> sexo;
		if (sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f')
		{
			cout << "Error: El sexo del deportista solo puede ser M o F." << endl;
			continue;
		}
		esSexoValido = true;
	}
	return sexo;
}

int Interfaz::ingresarYValidarHorasEntrenamientoDeportista()
{
	int horasEntrenamiento;
	bool esHorasValido = false;
	while (!esHorasValido)
	{
		cout << "Digite las horas de entrenamiento del deportista: ";
		if (!(cin >> horasEntrenamiento) || horasEntrenamiento <= 0)
		{
			cerr << "Error: Las horas de entrenamiento del deportista deben ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esHorasValido = true;
	}
	return horasEntrenamiento;
}

int Interfaz::ingresarYValidarCantidadParticipacionesIronManDeportista()
{
	int cantidadPartidosIronMan;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la cantidad de participaciones en competencias Iron Man: ";
		if (!(cin >> cantidadPartidosIronMan) || cantidadPartidosIronMan < 0)
		{
			cerr << "Error: la cantidad de participaciones en competencias Iron Man debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCantidadValida = true;
	}
	return cantidadPartidosIronMan;
}

int Interfaz::ingresarYValidarCantidadTriatlonesGanadosDeportista(int cantidadParticipados)
{
	int cantidadTriatlonesGanados;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la cantidad de triatlones ganados: ";
		if (!(cin >> cantidadTriatlonesGanados) || cantidadTriatlonesGanados < 0)
		{
			cerr << "Error: la cantidad de triatlones ganados debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (cantidadTriatlonesGanados > cantidadParticipados)
		{
			cerr << "Error: la cantidad de triatlones ganados debe de ser menor a la cantidad de participaciones en triatlones Iron Man" << endl;
			continue;
		}

		esCantidadValida = true;
	}
	return cantidadTriatlonesGanados;
}

int Interfaz::ingresarYValidarTemperaturaPromedio()
{
	int temperaturaPromedio;
	bool esTemperaturaValida = false;
	while (!esTemperaturaValida)
	{
		cout << "Digite la temperatura promedio del deportista: ";
		if (!(cin >> temperaturaPromedio) || temperaturaPromedio < 0)
		{
			cerr << "Error: la temperatura promedio del deportista debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		if (temperaturaPromedio > 50)
		{
			cerr << "Error: la temperatura promedio del deportista debe ser menor o igual a 50." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esTemperaturaValida = true;
	}
	return temperaturaPromedio;
}

double Interfaz::ingresarYValidarEstaturaDeportista()
{
	double estatura;
	bool esEstaturaValida = false;
	while (!esEstaturaValida)
	{
		cout << "Digite la estatura del deportista: ";
		if (!(cin >> estatura) || estatura <= 0)
		{
			cerr << "Error: La estatura del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esEstaturaValida = true;
	}
	return estatura;
}

double Interfaz::ingresarYValidarPesoDeportista()
{
	float peso;
	bool esPesoValido = false;
	while (!esPesoValido)
	{
		cout << "Digite el peso del deportista: ";
		if (!(cin >> peso) || peso <= 0)
		{
			cerr << "Error: El peso del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esPesoValido = true;
	}
	return peso;
}

double Interfaz::ingresarYValidarPorcentajeGrasaCorporalDeportista()
{
	double porcentajeGrasaCorpolar;
	bool esPorcentajeValido = false;
	while (!esPorcentajeValido)
	{
		cout << "Digite el porcentaje de grasa corporal: ";
		if (!(cin >> porcentajeGrasaCorpolar) || porcentajeGrasaCorpolar <= 0)
		{
			cerr << "Error: El porcentaje de grasa corpora del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (porcentajeGrasaCorpolar >= 100)
		{
			cerr << "Error: El porcentaje de grasa corporal del deportista debe ser menor a 100." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esPorcentajeValido = true;
	}
	return porcentajeGrasaCorpolar;
}

double Interfaz::ingresarYValidarPorcentajeMasaMuscularDeportista()
{
	double porcentajeMasaMuscular;
	bool esPorcentajeValido = false;
	while (!esPorcentajeValido)
	{
		cout << "Digite el porcentaje de masa muscular del deportista: ";
		if (!(cin >> porcentajeMasaMuscular) || porcentajeMasaMuscular <= 0)
		{
			cerr << "Error: El porcentaje de masa muscular del deportista debe ser un numero mayor a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esPorcentajeValido = true;
	}
	return porcentajeMasaMuscular;
}

string Interfaz::ingresarYValidarNombre()
{
	string nombre;
	bool esNombreValido = false;
	while (!esNombreValido)
	{
		Utils::clearInputBuffer();
		cout << "Digite el nombre del curso: ";
		getline(cin, nombre);

		if (nombre.empty())
		{
			cout << "Error: El nombre del curso no puede estar vacio." << endl;
			continue;
		}
		
		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cerr << "Error: El nombre del curso solo puede contener letras y espacios. Si desea agregar un numero escriba un numero romano" << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esNombreValido = true;
	}
	return nombre;
}

string Interfaz::ingresarYValidarDescripcion()
{
	string descripcion;
	bool esDescripcionValida = false;
	while (!esDescripcionValida)
	{
		cout << "Digite la descripcion del curso: ";
		Utils::clearInputBuffer();
		getline(cin, descripcion);
		if (descripcion.empty())
		{
			cerr << "Error: La descripcion del curso no puede estar vacia." << endl;
			continue;
		}
		bool esCadenaValida = true;
		for (char c : descripcion)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}
		if (!esCadenaValida)
		{
			cerr << "Error: La descripcion del curso solo puede contener letras y espacios. Si desea agregar un numero escriba un numero romano" << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esDescripcionValida = true;
	}
	return descripcion;
}
// principiante, intermedio, avanzado (P, I, A)
string Interfaz::ingresarYValidarNivel()
{
	char nivel;
	bool esNivelValido = false;
	while (!esNivelValido)
	{
		cout << "Digite el nivel del curso (P, I, A): ";
		cin >> nivel;
		nivel = toupper(nivel);
		if (nivel != 'P' && nivel != 'I' && nivel != 'A')
		{
			cerr << "Error: El nivel del curso debe ser P, I o A." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esNivelValido = true;
	}

	if (nivel == 'P')
	{
		return "Principiante";
	}
	else if (nivel == 'I')
	{
		return "Intermedio";
	}
	else
	{
		return "Avanzado";
	}
}

int Interfaz::ingresarYValidarCantidadGrupos()
{
	int cantidadGrupos;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la cantidad de grupos del curso: ";
		if (!(cin >> cantidadGrupos) || cantidadGrupos < 0)
		{
			cerr << "Error: La cantidad de grupos del curso debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCantidadValida = true;
	}
	return cantidadGrupos;
}

string Interfaz::ingresarYValidarCodigo()
{
	//validar que no exista otro curso con el mismo codigo
	string codigo;
	bool esCodigoValido = false;
	while (!esCodigoValido)
	{
		Utils::clearInputBuffer();
		cout << "Digite el codigo del curso: ";
		getline(cin, codigo);
		if (codigo.empty())
		{
			cerr << "Error: El codigo del curso no puede estar vacio." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (gimnasio->existeCursoConCodigo(codigo))
		{
			cerr << "Error: Ya existe un curso con ese codigo." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esCodigoValido = true;
	}

	return codigo;
}

void Interfaz::modificarNombreCurso(Curso* curso)
{
	string nombre;
	bool esNombreValido = false;
	while (!esNombreValido)
	{
		cout << "Digite el nombre del curso: ";
		Utils::clearInputBuffer();
		getline(cin, nombre);

		if (nombre.empty())
		{
			cout << "Error: El nombre del curso no puede estar vacio." << endl;
			continue;
		}

		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cerr << "Error: El nombre del curso solo puede contener letras y espacios. Si desea agregar un numero escriba un numero romano" << endl;
			Utils::clearInputBuffer();
			continue;
		}

		curso->setNombreDelCurso(nombre);
		esNombreValido = true;
		cout << "Nombre del curso modificado exitosamente." << endl;
	}
}

void Interfaz::modificarDescripcionCurso(Curso* curso)
{
	string descripcion;
	bool esDescripcionValida = false;
	while (!esDescripcionValida)
	{
		cout << "Digite la descripcion del curso: ";
		getline(cin, descripcion);
		if (descripcion.empty())
		{
			cerr << "Error: La descripcion del curso no puede estar vacia." << endl;
			continue;
		}
		bool esCadenaValida = true;
		for (char c : descripcion)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}
		if (!esCadenaValida)
		{
			cerr << "Error: La descripcion del curso solo puede contener letras y espacios. Si desea agregar un numero escriba un numero romano" << endl;
			Utils::clearInputBuffer();
			continue;
		}
		curso->setDescripcion(descripcion);
		esDescripcionValida = true;
		cout << "Descripcion del curso modificada exitosamente." << endl;
	}
}

void Interfaz::modificarNivelCurso(Curso* curso)
{
	char nivel;
	bool esNivelValido = false;
	while (!esNivelValido)
	{
		cout << "Digite el nivel del curso (P, I, A): ";
		cin >> nivel;
		nivel = toupper(nivel);
		if (nivel != 'P' && nivel != 'I' && nivel != 'A')
		{
			cerr << "Error: El nivel del curso debe ser P, I o A." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esNivelValido = true;
	}

	switch (nivel)
	{
	case 'P':
		curso->setNivel("Principiante");
		break;
	case 'I':
		curso->setNivel("Intermedio"); 
		break;
	case 'A':
		curso->setNivel("Avanzado");
		break;
	default:
		cerr << "Error: Error inesperado al modificar el nivel del curso." << endl;
		return;
		break;
	}
	cout << "Nivel del curso modificado exitosamente." << endl;
}

void Interfaz::modificarCantidadGruposCurso(Curso* curso)
{
	int cantidadGrupos;
	bool esCantidadValida = false;
	while (!esCantidadValida)
	{
		cout << "Digite la cantidad de grupos del curso: ";
		if (!(cin >> cantidadGrupos) || cantidadGrupos < 0)
		{
			cerr << "Error: La cantidad de grupos del curso debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		curso->setCantidadMaximaDeGrupos(cantidadGrupos);
		esCantidadValida = true;
		cout << "Cantidad de grupos del curso modificada exitosamente." << endl;
	}
}

void Interfaz::modificarCodigoCurso(Curso* curso)
{
	string codigo;
	bool esCodigoValido = false;
	while (!esCodigoValido)
	{
		cout << "Digite el codigo del curso: ";
		Utils::clearInputBuffer();
		getline(cin, codigo);
		if (codigo.empty())
		{
			cerr << "Error: El codigo del curso no puede estar vacio." << endl;
			continue;
		}
		if (gimnasio->existeCursoConCodigo(codigo))
		{
			cerr << "Error: Ya existe un curso con ese codigo." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		curso->setCodigo(codigo);
		esCodigoValido = true;
		cout << "Codigo del curso modificado exitosamente." << endl;
	}
}

Instructor* Interfaz::ingresarYValidarInstructor()
{
	string nombre = ingresarYValidarNombreInstructor();
	string cedula = ingresarYValidarCedulaInstructor();
	string apellido = ingresarYValidarApellidoInstructor();

	return new Instructor(nombre, apellido, cedula);
}

string Interfaz::ingresarYValidarNombreInstructor()
{
	string nombre;
	bool esNombreValido = false;

	while (!esNombreValido)
	{
		cout << "Digite el nombre del instructor: ";
		getline(cin, nombre);

		if (nombre.empty())
		{
			cout << "Error: El nombre del instructor no puede estar vacio." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		bool esCadenaValida = true;
		for (char c : nombre)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El nombre del instructor solo puede contener letras y espacios." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esNombreValido = true;
	}

	return nombre;
}

string Interfaz::ingresarYValidarApellidoInstructor()
{
	string apellido;
	bool esApellidoValido = false;

	while (!esApellidoValido)
	{
		cout << "Digite el apellido del instructor: ";
		getline(cin, apellido);

		if (apellido.empty())
		{
			cout << "Error: El apellido del instructor no puede estar vacio." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		bool esCadenaValida = true;
		for (char c : apellido)
		{
			if (!isalpha(c) && c != ' ')
			{
				esCadenaValida = false;
				break;
			}
		}

		if (!esCadenaValida)
		{
			cout << "Error: El apellido del instructor solo puede contener letras y espacios." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esApellidoValido = true;
	}

	return apellido;
}

string Interfaz::ingresarYValidarCedulaInstructor()
{
	string cedula;
	bool esCedulaValida = false;
	while (!esCedulaValida)
	{
		cout << "Digite el ID del instructor: ";
		getline(cin, cedula);
		if (cedula.empty())
		{
			cerr << "Error: EL ID del instructor no puede estar vacia." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCedulaValida = true;
	}
	return cedula;
}

int Interfaz::ingresarYValidarCupoMaximo()
{
	int cupoMaximo;
	bool esCupoValido = false;
	while (!esCupoValido)
	{
		cout << "Digite el cupo maximo del grupo: ";
		if (!(cin >> cupoMaximo) || cupoMaximo < 0)
		{
			cerr << "Error: El cupo maximo del grupo debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCupoValido = true;
	}
	return cupoMaximo;
}

int Interfaz::ingresarYValidarSemanasDuracion()
{
	int semanasDuracion;
	bool esSemanasValidas = false;
	while (!esSemanasValidas)
	{
		cout << "Digite la cantidad de semanas de duracion del grupo: ";
		if (!(cin >> semanasDuracion) || semanasDuracion < 0)
		{
			cerr << "Error: La cantidad de semanas de duracion del grupo debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esSemanasValidas = true;
	}
	return semanasDuracion;
}

// (l-k-m-j-v-s-d) 
char Interfaz::ingresarYValidarDiaDeLaSemana()
{
	char dia;
	bool esDiaValido = false;
	while (!esDiaValido)
	{
		cout << "Digite el dia de la semana del grupo (l-k-m-j-v-s-d): ";
		if (!(cin >> dia) || (dia != 'l' && dia != 'k' && dia != 'm' && dia != 'j' && dia != 'v' && dia != 's' && dia != 'd'))
		{
			cerr << "Error: El dia de la semana del grupo debe ser una letra entre l-k-m-j-v-s-d." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esDiaValido = true;
	}
	return dia;
}

Hora* Interfaz::ingresarYValidarHoraEntrada()
{
	int hora, minuto, segundo;
	bool esHoraValida = false;
	while (!esHoraValida)
	{
		cout << "Digite la hora de inicio del grupo: ";
		if (!(cin >> hora) || hora < 0 || hora > 23)
		{
			cerr << "Error: La hora de inicio del grupo debe ser un numero entre 0 y 23." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		cout << "Digite el minuto de inicio del grupo: ";
		if (!(cin >> minuto) || minuto < 0 || minuto > 59)
		{
			cerr << "Error: El minuto de inicio del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		cout << "Digite el segundo de inicio del grupo: ";
		if (!(cin >> segundo) || segundo < 0 || segundo > 59)
		{
			cerr << "Error: El segundo de inicio del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		esHoraValida = true;
	}

	return new Hora(hora, minuto, segundo);
}

Hora* Interfaz::ingresarYValidarHoraSalida(Hora* horaEntrada)
{
	int hora, minuto, segundo;
	bool esHoraValida = false;
	Hora* horaSalida = nullptr;
	while (!esHoraValida)
	{
		cout << "Digite la hora de finalizacion del grupo: ";
		if (!(cin >> hora) || hora < 0 || hora > 23)
		{
			cerr << "Error: La hora de finalizacion del grupo debe ser un numero entre 0 y 23." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el minuto de finalizacion del grupo: ";
		if (!(cin >> minuto) || minuto < 0 || minuto > 59)
		{
			cerr << "Error: El minuto de finalizacion del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el segundo de finalizacion del grupo: ";
		if (!(cin >> segundo) || segundo < 0 || segundo > 59)
		{
			cerr << "Error: El segundo de finalizacion del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		horaSalida = new Hora(hora, minuto, segundo);
		if (*horaEntrada > *horaSalida)
		{
			cerr << "Error: La hora de finalizacion del grupo debe ser mayor a la hora de inicio." << endl;
			Utils::clearInputBuffer();
			delete horaSalida;
			horaSalida = nullptr;
			continue;
		}
		esHoraValida = true;
	}
	return horaSalida;
}

void Interfaz::modificarNombreInstructor(Grupo* grupo)
{
	string nombre;
	bool esNombreValido = false;
	while (!esNombreValido)
	{
		cout << "Digite el nombre del instructor: ";
		if (!(cin >> nombre) || nombre.empty())
		{
			cerr << "Error: El nombre del instructor debe tener al menos 1 caracter." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esNombreValido = true;
	}
	grupo->getInstructor()->setNombre(nombre);
	cout << "Nombre del instructor modificado exitosamente." << endl;
}

void Interfaz::modificarCedulaInstructor(Grupo* grupo)
{
	string cedula;
	bool esCedulaValida = false;
	while (!esCedulaValida)
	{
		cout << "Digite el nuevo ID del instructor: ";
		if (!(cin >> cedula) || cedula.empty())
		{
			cerr << "Error: El ID del instructor debe de tener al menos un caracter." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCedulaValida = true;
	}
	grupo->getInstructor()->setId(cedula);
	cout << "ID del instructor modificado exitosamente." << endl;
}

void Interfaz::modificarCupoMaximoGrupo(Grupo* grupo)
{
	int cupoMaximo;
	bool esCupoMaximoValido = false;
	while (!esCupoMaximoValido)
	{
		cout << "Digite el nuevo cupo maximo del grupo: ";
		if (!(cin >> cupoMaximo) || cupoMaximo < 0)
		{
			cerr << "Error: El cupo maximo del grupo debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (cupoMaximo < grupo->getCantidadDeInscritos())
		{
			cerr << "Error: El nuevo cupo maximo del grupo debe ser mayor o igual al cupo actual." << endl;
			cerr << "Cupo actual: " << grupo->getCantidadDeInscritos() << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esCupoMaximoValido = true;
	}
	grupo->setCupoMaximo(cupoMaximo);
	cout << "Cupo maximo del grupo modificado exitosamente." << endl;
}

void Interfaz::modificarFechaInicioGrupo(Grupo* grupo)
{
	Fecha* fechaInicio = menuFecha();
	grupo->setFechaDeInicio(fechaInicio);
	cout << "Fecha de inicio del grupo modificada exitosamente." << endl;
}

void Interfaz::modificarSemanasDuracionGrupo(Grupo* grupo)
{
	int semanasDuracion;
	bool esSemanasDuracionValido = false;
	while (!esSemanasDuracionValido)
	{
		cout << "Digite el nuevo numero de semanas de duracion del grupo: ";
		if (!(cin >> semanasDuracion) || semanasDuracion < 0)
		{
			cerr << "Error: El numero de semanas de duracion del grupo debe ser un numero mayor o igual a 0." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esSemanasDuracionValido = true;
	}
	grupo->setSemanasDeDuracion(semanasDuracion);
	cout << "Numero de semanas de duracion del grupo modificado exitosamente." << endl;
}

void Interfaz::modificarDiaDeLaSemanaGrupo(Grupo* grupo)
{
	char diaDeLaSemana = Interfaz::ingresarYValidarDiaDeLaSemana();
	grupo->setDiaDeLaSemana(diaDeLaSemana);
	cout << "Dia de la semana del grupo modificado exitosamente." << endl;
}

void Interfaz::modificarHoraEntradaGrupo(Grupo* grupo)
{
	// se debe de verificar que la hora de entrada sea menor a la hora de salida, en caso contrario se debe de volver a pedir la hora de entrada
	Hora* horaEntrada = new Hora();
	Hora* horaSalida = grupo->getHoraDeFin();
	int hora, minuto, segundo;
	bool esHoraValida = false;
	while (!esHoraValida)
	{
		cout << "Digite la hora de inicio del grupo: ";
		if (!(cin >> hora) || hora < 0 || hora > 23)
		{
			cerr << "Error: La hora de inicio del grupo debe ser un numero entre 0 y 23." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el minuto de inicio del grupo: ";
		if (!(cin >> minuto) || minuto < 0 || minuto > 59)
		{
			cerr << "Error: El minuto de inicio del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el segundo de inicio del grupo: ";
		if (!(cin >> segundo) || segundo < 0 || segundo > 59)
		{
			cerr << "Error: El segundo de inicio del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		if (*horaEntrada > *horaSalida)
		{
			cerr << "Error: La hora de inicio del grupo debe ser menor a la hora de finalizacion." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esHoraValida = true;
	}
	grupo->setHoraDeInicio(horaEntrada);
	cout << "Hora de inicio del grupo modificada exitosamente." << endl;
}

void Interfaz::modificarHoraSalidaGrupo(Grupo* grupo)
{
	int hora, minuto, segundo;
	Hora* horaEntrada = grupo->getHoraDeInicio();
	Hora* horaSalida = new Hora();
	bool esHoraValida = false;
	while (!esHoraValida)
	{
		cout << "Digite la hora de salida del grupo: ";
		if (!(cin >> hora) || hora < 0 || hora > 23)
		{
			cerr << "Error: La hora de salida del grupo debe ser un numero entre 0 y 23." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el minuto de salida del grupo: ";
		if (!(cin >> minuto) || minuto < 0 || minuto > 59)
		{
			cerr << "Error: El minuto de salida del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		cout << "Digite el segundo de salida del grupo: ";
		if (!(cin >> segundo) || segundo < 0 || segundo > 59)
		{
			cerr << "Error: El segundo de salida del grupo debe ser un numero entre 0 y 59." << endl;
			Utils::clearInputBuffer();
			continue;
		}

		if (*horaEntrada > *horaSalida)
		{
			cerr << "Error: La hora de salida del grupo debe ser mayor a la hora de inicio." << endl;
			Utils::clearInputBuffer();
			continue;
		}
		esHoraValida = true;
	}
	grupo->setHoraDeFin(horaSalida);
	cout << "Hora de salida del grupo modificada exitosamente." << endl;
}

void Interfaz::test()
{
	gimnasio->prueba();
}
