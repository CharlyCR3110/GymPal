#pragma once
// luego incluyo las clases necesarias
#include "Gimnasio.h"
using namespace std;
class Interfaz
{
public:
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

	static int menuControlCursos();	// 3
	static int menuControlGrupos();	// 4
	static int menuControlPagos();	// 5


	//menus auxiliares
	static Fecha* menuFecha();
	// 
	void modificarNombreDeportista(Deportista* deportista);
	void modificarTelefonoDeportista(Deportista* deportista);
	void modificarFechaNacimientoDeportista(Deportista* deportista);
	void modificarSexoDeportista(Deportista* deportista);
	//biometricos
	void modificarEstaturaDeportista(Deportista* deportista, Fecha* fechaActual_);
	void modificarPesoDeportista(Deportista* deportista, Fecha* fechaActual_);
	void modificarPorcentajeGrasaCorporalDeportista(Deportista* deportista, Fecha* fechaActual_);
	void modificarPorcentajeMasaMuscularDeportista(Deportista* deportista, Fecha* fechaActual_);
	//
	void modificarEstadoDeportista(Deportista* deportista);
	void modificarHorasEntrenamientoDeportista(Deportista* deportista);
	void modificarCantidadParticipacionesIronManDeportista(Deportista* deportista);
	void modificarCantidadTriatlonesGanadosDeportista(Deportista* deportista);
};