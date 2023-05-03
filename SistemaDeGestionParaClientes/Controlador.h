#pragma once
#include "Interfaz.h"
class Controlador
{
public:
	// main
	void iniciar();
	void controladorPrincipal(int opcion);

	// administracion general
	void controladorAdministracionGenerarl();

	// control deportistas
	void controladorControlDeportistas();

	// control cursos
	void controladorControlCursos();

	// control grupos
	void controladorControlGrupos();

	// control pagos
	void controladorControlPagos();
};

