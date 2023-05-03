#include "Interfaz.h"


Gimnasio* Interfaz::gimnasio = new Gimnasio();

void Interfaz::prueba()
{
	cout << gimnasio->generarReporteDeportistas();
	cout << gimnasio->getFechaActual()->toString();
}

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
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuAdministracionGeneralNombreGimnasio()    // sub menu 1 de menu administracion general
{
	string nombreGimnasio;
	cout << "\t<1. Administracion General> <1. Nombre del Gimnasio>" << endl;
	cout << "Digite el nuevo nombre del gimnasio: ";
	cin >> nombreGimnasio;
	gimnasio->setNombreDelGimnasio(nombreGimnasio);
}

void Interfaz::menuAdministracionGeneralMontoMensual()  // sub menu 2 de menu administracion general
{
	double montoMensual;
	cout << "\t<1. Administracion General> <2. Monto Mensual>" << endl;
	cout << "Digite el nuevo monto mensual: ";
	cin >> montoMensual;
	gimnasio->setMontoMensual(montoMensual);
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
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

void Interfaz::menuControlDeportistasIngresoNuevoDeportista()
{
	string cedula, nombre, telefono;
	Fecha* fechaNacimiento;
	char sexo;
	int horasEntrenamiento, cantidadParticipacionesIronMan, cantidadTriatlonesGanados;
	double temperaturaPromedio, estatura, masaMuscular, peso, porcentajeGrasaCorporal;
	cout << "\t<2. Control Deportistas> <1. Ingreso nuevo deportista>" << endl;
	cout << "Datos generales:" << endl;
	cout << "\tDigite la cedula del deportista: ";
	cin >> cedula;
	cout << "\tDigite el nombre del deportista: ";
	cin >> nombre;
	cout << "\tDigite el telefono del deportista: ";
	cin >> telefono;
	cout << "\tDigite la fecha de nacimiento del deportista: " << endl;
	fechaNacimiento = Interfaz::menuFecha();
	cout << "\tDigite el sexo del deportista (f/m): ";
	cin >> sexo;
	cout << "\tDigite la cantidad de horas de entrenamiento del deportista: ";
	cin >> horasEntrenamiento;
	cout << "\tDigite la temperatura promedio del deportista: ";
	cin >> temperaturaPromedio;
	cout << "\tDigite la cantidad de participaciones en IronMan del deportista: ";
	cin >> cantidadParticipacionesIronMan;
	cout << "\tDigite la cantidad de triatlones ganados del deportista: ";
	cin >> cantidadTriatlonesGanados;
	cout << endl << "Datos biom�tricos b�sicos" << endl;
	cout << "\tDigite la estatura del deportista: ";
	cin >> estatura;
	cout << "\tDigite el peso del deportista: ";
	cin >> peso;
	cout << "\tDigite el porcentaje de grasa corporal del deportista: ";
	cin >> porcentajeGrasaCorporal;
	cout << "\tDigite la masa muscular del deportista: ";
	cin >> masaMuscular;

	try
	{
		gimnasio->registrarDeportista(cedula, nombre, telefono, fechaNacimiento, horasEntrenamiento, temperaturaPromedio, cantidadParticipacionesIronMan, cantidadTriatlonesGanados, sexo, estatura, masaMuscular, peso, porcentajeGrasaCorporal);
		cout << "Deportista registrado con exito" << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

void Interfaz::menuControlDeportistasModificarDeportista()
{
	Deportista* deportista = nullptr;
	string cedula;
	int opcion = 1;

	cout << "\t<2. Control Deportistas> <2. Modificacion de deportista>" << endl;
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

	if (deportista == nullptr)
	{
		cerr << "Error: Error inesperado" << endl;
		return;
	}

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
}

void Interfaz::menuControlDeportistasMostrarListadosDeportistas()
{
	int opcion;
	cout << "<2. Control Deportistas> <3. Listado de Deportistas>" << endl;
	cout << "1. Listado general" << endl;
	cout << "2. Listado de deportistas activos" << endl;
	cout << "3. Listado de deportistas inactivos" << endl;
	cout << "4. Listado de deportistas en morosidad" << endl;
	cout << "Digite una opción del menú: ";
	cin >> opcion;

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
}

void Interfaz::menuControlDeportistasMostrarDeportistaEspecifico()
{
	string cedula;
	cout << "<2. Control Deportistas> <3. Listado de Deportistas>" << endl;
	cout << "Digite la cedula del deportista: ";
	cin >> cedula;
	try {
		cout << gimnasio->generarReporteDeportistaCed(cedula);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}

//---------------------//
int Interfaz::menuControlCursos()
{
	int opcion = 0;
	cout << "\t\t3. Control de Cursos" << endl;
	cout << "1. Ingreso nuevo curso" << endl;
	cout << "2. Reporte de curso especifico" << endl;
	cout << "3. Modificacion de -curso especifico" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}
//< 3.Control Cursos> < 1.Ingreso nuevo curso >
//
//Digite el código del curso : _ 101
//Digite el nombre del curso : _Spinning
//Digite el nivel : _Principiantes
//Cantidad de grupos : _4
//Descripción : _Curso destinado a la introducción al …… ect
//
//
//< Digite Enter >

void Interfaz::menuControlCursosIngresoNuevoCurso()
{
	string codigo, nombre, nivel, descripcion;
	int cantidadGrupos;
	cout << "<3. Control Cursos> <1. Ingreso nuevo curso>" << endl;
	Utils::clearInputBuffer();
	codigo = Interfaz::ingresarYValidarCodigo();
	Utils::clearInputBuffer();
	nombre = Interfaz::ingresarYValidarNombre();
	Utils::clearInputBuffer();
	nivel = Interfaz::ingresarYValidarNivel();
	Utils::clearInputBuffer();
	cantidadGrupos = Interfaz::ingresarYValidarCantidadGrupos();
	Utils::clearInputBuffer();
	descripcion = Interfaz::ingresarYValidarDescripcion();
	try {
		gimnasio->registrarCurso(codigo, nombre, nivel, descripcion, cantidadGrupos);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}

void Interfaz::menuControlCursosMostrarCursoEspecifico()
{
	string codigo;
	cout << "<3. Control Cursos> <2. Reporte de curso especifico>" << endl;
	try {
		cout << gimnasio->generarListadoCursos();
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	cout << "Digite el codigo del curso: ";
	cin >> codigo;

	try {
		cout << gimnasio->generarReporteCursoCod(codigo);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}

//< 3.Control Cursos> < 3. Modificación de  curso especifico >
//
//Ingrese  el código del curso especifico : _101
//
//Curso encontrado!!!
//
//Cual dato desea modificar :
//
//1.	Código del curso
//2.	Nombre del curso
//3.	Nivel
//4.	Descripción
//5.	Cantidad de grupos
//
//Ingrese  una opción del menú : _3

void Interfaz::menuControlCursosModificarCurso()
{
	Curso* curso = nullptr;
	string codigo;
	int opcion;
	cout << "<3. Control Cursos> <3. Modificacion de curso especifico>" << endl;
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
	}

	cout << "Cual dato desea modificar: " << endl;
	cout << "1. Codigo del curso" << endl;
	cout << "2. Nombre del curso" << endl;
	cout << "3. Nivel" << endl;
	cout << "4. Descripcion" << endl;
	cout << "5. Cantidad de grupos" << endl;
	cout << "Ingrese una opcion del menu: ";
	cin >> opcion;
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
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

int Interfaz::menuControlPagos()
{
	int opcion = 0;
	cout << "\t\t5. Control de Pagos" << endl;
	cout << "1. Registro de nuevo pago" << endl;
	cout << "2. Reporte de pagos por deportista" << endl;
	cout << "Digite una opcion del menu: ";
	cin >> opcion;
	return opcion;
}

Fecha* Interfaz::menuFecha()
{
	int dia, mes, anio;
	Fecha* fecha = nullptr;
	cout << "Digite el dia: ";
	cin >> dia;
	cout << "Digite el mes: ";
	cin >> mes;
	cout << "Digite el anio: ";
	cin >> anio;
	try
	{
		fecha = new Fecha(dia, mes, anio);

	}
	catch (exception &e)
	{
		throw exception(e.what());
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

		try
		{
		deportista->actualizarPorcentajeGrasaCorporal(porcentajeGrasaCorpolar, fechaActual_);
		esPorcentajeValido = true;
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

		try
		{
		deportista->actualizarMasaMuscular(porcentajeMasaMuscular, fechaActual_);
		esPorcentajeValido = true;
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
	}
}

//string nombre;
//bool esNombreValido = false;
//
//while (!esNombreValido)
//{
//    cout << "Digite el nuevo nombre del deportista: ";
//    getline(cin, nombre);
//
//    if (nombre.empty())
//    {
//        cout << "Error: El nombre del deportista no puede estar vacio." << endl;
//        continue;
//    }
//
//    bool esCadenaValida = true;
//    for (char c : nombre)
//    {
//        if (!isalpha(c) && c != ' ')
//        {
//            esCadenaValida = false;
//            break;
//        }
//    }
//
//    if (!esCadenaValida)
//    {
//        cout << "Error: El nombre del deportista solo puede contener letras y espacios." << endl;
//        continue;
//    }
//
//    deportista->setNombre(nombre);
//    esNombreValido = true;
//}
string Interfaz::ingresarYValidarNombre()
{
	string nombre;
	bool esNombreValido = false;
	while (!esNombreValido)
	{
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
	}
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
	}
}

void Interfaz::modificarCodigoCurso(Curso* curso)
{
	string codigo;
	bool esCodigoValido = false;
	while (!esCodigoValido)
	{
		cout << "Digite el codigo del curso: ";
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
	}
}