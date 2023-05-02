#pragma once
// luego incluyo las clases necesarias
#include "Gimnasio.h"
using namespace std;
class Interfaz
{
public:
	static void prueba();

	// Gimnasio
	static Gimnasio* gimnasio;

	// menus funcionalidades
	static int menuPrincipal();
	// submenus de menuPrincipal
	static int menuAdministracionGeneral();	// 1
	// submenus de menuAdministracionGeneral
	static void menuAdministracionGeneralNombreGimnasio(); // 1
	static void menuAdministracionGeneralMontoMensual(); // 2
	//
	static int menuControlDeportistas();	// 2
	//submenus de menuControlDeportistas
	static void menuControlDeportistasIngresoNuevoDeportista(); // 1
	static void menuControlDeportistasModificarDeportista(); // 2
	static void menuControlDeportistasMostrarListadosDeportistas(); // 3
	static void menuControlDeportistasMostrarDeportistaEspecifico(); // 4
	//
	static int menuControlCursos();	// 3
	static int menuControlGrupos();	// 4
	static int menuControlPagos();	// 5


	//menus auxiliares
	static Fecha* menuFecha();
	// 

	// modificar datos
	static void modificarNombreDeportista(Deportista* deportista);
	static void modificarTelefonoDeportista(Deportista* deportista);
	static void modificarFechaNacimientoDeportista(Deportista* deportista);
	static void modificarSexoDeportista(Deportista* deportista);
	//biometricos
	static void modificarEstaturaDeportista(Deportista* deportista, Fecha* fechaActual_);
	static void modificarPesoDeportista(Deportista* deportista, Fecha* fechaActual_);
	static void modificarPorcentajeGrasaCorporalDeportista(Deportista* deportista, Fecha* fechaActual_);
	static void modificarPorcentajeMasaMuscularDeportista(Deportista* deportista, Fecha* fechaActual_);
	//
	static void modificarEstadoDeportista(Deportista* deportista);
	static void modificarHorasEntrenamientoDeportista(Deportista* deportista);
	static void modificarCantidadParticipacionesIronManDeportista(Deportista* deportista);
	static void modificarCantidadTriatlonesGanadosDeportista(Deportista* deportista);
	//

};