#pragma once
// luego incluyo las clases necesarias
#include <iostream>
using namespace std;
class Interfaz
{
public:
	// menus funcionalidades
	static int menuPrincipal();
	// submenus de menuPrincipal
	static int menuAdministracionGeneral();	// 1
	static int menuControlDeportistas();	// 2
	static int menuControlCursos();	// 3
	static int menuControlGrupos();	// 4
	static int menuControlPagos();	// 5
};