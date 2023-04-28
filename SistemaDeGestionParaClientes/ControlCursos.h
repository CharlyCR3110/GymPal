#pragma once
#include "ListaEnlazada.h"
#include "Curso.h"
#include "Deportista.h"
const int MAX_CURSOS = 3;
class ControlCursos
{
private:
	ListaEnlazada<Curso>* listaCursos;
	ListaEnlazada<Deportista>* listaDeportistas;
	Fecha* fechaActual;
public:
	ControlCursos();
	ControlCursos(ListaEnlazada<Curso>* listaCursos_, ListaEnlazada<Deportista>* listaDeportistas_, Fecha* fechaActual_);
	ControlCursos(const ControlCursos& controlCursos_);
	virtual ~ControlCursos();
	// metodo para registrar un nuevo curso
	void registrarCurso(string codigo_, string nombre_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos_);	//
	// metodo para generar el reporte de un curso en especifico
	string generarReporteCurso(string codigo_);
	// matricular en un grupo especifico
	void matricularEnGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_);
	// mostrar los grupos de un curso para matricular
	string reporteGuiaMatriculaCurso(string codigo_);
};