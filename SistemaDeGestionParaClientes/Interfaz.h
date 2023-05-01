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
	static int menuControlCursos();	// 3
	static int menuControlGrupos();	// 4
	static int menuControlPagos();	// 5


	//menus globales
	static Fecha* menuFecha();
};