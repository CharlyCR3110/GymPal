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
		cout << "Error: " << e.what() << endl;
	}

	return fecha;
}
