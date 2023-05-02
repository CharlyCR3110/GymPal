#include "Interfaz.h"


Gimnasio* Interfaz::gimnasio = new Gimnasio();

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
    cout << endl << "Datos biométricos básicos" << endl;
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

//---------------------//
int Interfaz::menuControlCursos()
{
    int opcion = 0;
    cout << "\t\t3. Control de Cursos" << endl;
    cout << "1. Ingreso nuevo curso" << endl;
    cout << "2. Reporte de curso especifico" << endl;
    cout << "3. Modificacion de curso especifico" << endl;
    cout << "Digite una opcion del menu: ";
    cin >> opcion;
    return opcion;
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
		deportista->actualizarEstatura(estatura, fechaActual_);
		esEstaturaValida = true;
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
		deportista->actualizarPeso(peso, fechaActual_);
		esPesoValido = true;
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        deportista->actualizarPeso(porcentajeGrasaCorpolar, fechaActual_);
        esPorcentajeValido = true;
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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		deportista->actualizarMasaMuscular(porcentajeMasaMuscular, fechaActual_);
        esPorcentajeValido = true;
	}
}