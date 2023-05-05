#include "Controlador.h"

void Controlador::iniciar()
{
	int opcion = 0;
	Interfaz::mensajeDeBienvenida();
	do
	{
		Utils::pause();
		Utils::clearScreen();
		opcion = Interfaz::menuPrincipal();
		Utils::clearScreen();
		controladorPrincipal(opcion);
	} while (opcion != 6);
}

void Controlador::controladorPrincipal(int opcion)
{
	switch (opcion)
	{
	case 1:
		// administracion general
		controladorAdministracionGenerarl();
		break;
	case 2:
		// control deportistas
		controladorControlDeportistas();
		break;
	case 3:
		// control cursos
		controladorControlCursos();
		break;
	case 4:
		// control grupos
		controladorControlGrupos();
		break;
	case 5:
		// control pagos
		controladorControlPagos();
		break;
	case 6:
		// salir
		Interfaz::salir();
		break;
	case 1000:
		// test
		Interfaz::test();
		break;
	default:
		Interfaz::opcionInvalida();
		break;
	}
}

void Controlador::controladorAdministracionGenerarl()
{
	int opcion = 0;
	do
	{
		Utils::clearScreen();
		opcion = Interfaz::menuAdministracionGeneral();
		Utils::clearScreen();
		switch (opcion)
		{
		case 1:
			// nombre gimnasio
			Interfaz::menuAdministracionGeneralNombreGimnasio();
			break;
		case 2:
			// monto mensual
			Interfaz::menuAdministracionGeneralMontoMensual();
			break;
		case 3:
			// volver
			Interfaz::regresar();
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 3);
}

void Controlador::controladorControlDeportistas()
{
	int opcion = 0;
	do
	{
		Utils::pause();
		Utils::clearScreen();
		opcion = Interfaz::menuControlDeportistas();
		Utils::clearScreen();
		switch (opcion)
		{
		case 1:
			// ingresar nuevo deportista
			Interfaz::menuControlDeportistasIngresoNuevoDeportista();
			break;
		case 2:
			// modificar deportista
			Interfaz::menuControlDeportistasModificarDeportista();
			break;
		case 3:
			// mostrar listados de deportistas
			Interfaz::menuControlDeportistasMostrarListadosDeportistas();
			break;
		case 4:
			// mostrar deportista especifico
			Interfaz::menuControlDeportistasMostrarDeportistaEspecifico();
			break;
		case 5:
			// volver
			Interfaz::regresar();
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 5);
}

void Controlador::controladorControlCursos()
{
	int opcion = 0;
	do
	{
		Utils::pause();
		Utils::clearScreen();
		opcion = Interfaz::menuControlCursos();
		Utils::clearScreen();
		switch (opcion)
		{
		case 1:
			// ingresar nuevo curso
			Interfaz::menuControlCursosIngresoNuevoCurso();
			break;
		case 2:
			// mostrar curso especifico
			Interfaz::menuControlCursosMostrarCursoEspecifico();
			break;
		case 3:
			// modificar curso
			Interfaz::menuControlCursosModificarCurso();
			break;
		case 4:
			// volver
			Interfaz::regresar();
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 4);
}


//static void menuControlGruposIngresoNuevoGrupo(); // 4.1
//static void menuControlGruposModificarGrupo(); // 4.2
//static void menuControlGruposMatricularEnGrupo(); // 4.3
//static void menuControlGruposMostrarGrupoEspecifico(); // 4.4
//static void menuControlGruposMostrarDeportistasPorGrupo(); // 4.5
//static void menuControlGruposCancelarMatriculaEnGrupo(); // 4.6
void Controlador::controladorControlGrupos()
{
	int opcion = 0;
	do
	{
		Utils::pause();
		Utils::clearScreen();
		opcion = Interfaz::menuControlGrupos();
		Utils::clearScreen();
		switch (opcion)
		{
		case 1:
			// ingresar nuevo grupo
			Interfaz::menuControlGruposIngresoNuevoGrupo();
			break;
		case 2:
			// modificar grupo
			Interfaz::menuControlGruposModificarGrupo();
			break;
		case 3:
			// matricular en grupo
			Interfaz::menuControlGruposMatricularEnGrupo();
			break;
		case 4:
			// mostrar grupo especifico
			Interfaz::menuControlGruposMostrarGrupoEspecifico();
			break;
		case 5:
			// mostrar deportistas por grupo
			Interfaz::menuControlGruposMostrarDeportistasPorGrupo();
			break;
		case 6:
			// cancelar matricula en grupo
			Interfaz::menuControlGruposCancelarMatriculaEnGrupo();
			break;
		case 7:
			// volver
			Interfaz::regresar();
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 7);
}

void Controlador::controladorControlPagos()
{
	int opcion = 0;

	do
	{
		Utils::pause();
		Utils::clearScreen();
		opcion = Interfaz::menuControlPagos();
		Utils::clearScreen();
		switch (opcion)
		{
		case 1:
			// ingresar nuevo pago
			Interfaz::menuControlPagosIngresoNuevoPago();
			break;
		case 2:
			// mostrar pagos por deportista
			Interfaz::menuControlPagosMostrarPagosDeportista();
			break;
		case 3:
			// volver
			Interfaz::regresar();
			break;
		default:
			Interfaz::opcionInvalida();
			break;
		}
	} while (opcion != 3);
}
