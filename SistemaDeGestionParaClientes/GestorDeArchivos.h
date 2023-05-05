#pragma once
#include "Deportista.h"
#include "Curso.h"
#include "Pago.h"
#include "fstream"
class Gimnasio;
class GestorDeArchivos
{
public:
	GestorDeArchivos();
	virtual ~GestorDeArchivos() = default;

	// deportistas y sus pagos
	virtual void guardarDeportistasYPagos(ListaEnlazada<Deportista>* listaDeportistas_);
	virtual ListaEnlazada<Deportista>* cargarDeportistasYPagos();

	//cursos y grupos
	virtual void guardarCursosYGrupos(ListaEnlazada<Curso>* listaCursos_);
	virtual ListaEnlazada<Curso>* cargarCursosYGrupos();

	// metodo para guardar y leer, el codigo, numero de curso y la cedula de los deportistas asociados
	// luego con esos datos puedo matricular a los deportistas en los grupos correspondientes
	virtual const void guardarCursoGrupoYCedulaDeLosDeportistasAsociados(string texto) const;
	virtual void cargarCursoGrupoYCedulaDeLosDeportistasAsociados(Gimnasio* gimnasio_);	// lee y matricula a los deportistas en los grupos correspondientes
};

