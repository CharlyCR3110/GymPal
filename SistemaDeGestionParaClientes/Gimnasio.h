#pragma once
#include "ControlPagos.h"
#include "Triatlonista.h"
#include "ListaEnlazada.h"
#include "Curso.h"
#include "GestorDeArchivos.h"
const int MAX_CURSOS = 3;

class Gimnasio
{
private:
	string nombreDelGimnasio;
	double montoMensual;
	Fecha* fechaActual;
	ListaEnlazada<Deportista>* listaDeportistas;
	ListaEnlazada<Curso>* listaCursos;
	ControlPagos* controlPagos;
	// archivos
	GestorDeArchivos gestorDeArchivos;
public:
	Gimnasio();
	Gimnasio(string nombreDelGimnasio_, double montoMensual_, Fecha* fechaActual_);
	//Gimnasio(const Gimnasio& gimnasio_);
	virtual ~Gimnasio();
	// setters
	void setNombreDelGimnasio(string nombreDelGimnasio_);	//1.2
	void setMontoMensual(double montoMensual_);	//1.1
	void setFechaActual(Fecha* fechaActual_);
	void setControlPagos(ControlPagos* controlPagos_);
	void setListaDeportistas(ListaEnlazada<Deportista>* listaDeportistas_);
	void setListaCursos(ListaEnlazada<Curso>* listaCursos_);
	// getters
	const string getNombreDelGimnasio() const;
	const double getMontoMensual() const;
	Fecha* getFechaActual();
	ControlPagos* getControlPagos();
	ListaEnlazada<Deportista>* getListaDeportistas();
	ListaEnlazada<Curso>* getListaCursos();
	// metodos
	// 1. Metodo de Registro
	void registrarCurso(string codigo_, string nombre_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos_);
	void registrarDeportista(string cedula_, string nombre_, string telefono_, Fecha* fechaNacimiento_, int horasEntremiento_, double temperaturaPromedio_, int cantidadParticipacionesIronMan_, int cantidadTriatlonesGanados_, char sexo_, double estatura_, double masaMuscular_, double peso_, double porcentajeGrasaCorporal_);
	string registrarPago(string cedula_, int mesesAPagar_);
	// 2.Me todos de matricula y desmatricula:
	void matricularEnGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_);
	void desmatricularDeGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_);
	void agregarGrupo(string codigoCurso_, Grupo* grupo_);
	// 3. Metodos para generar reportes:
	// metodos para mostrar cositas especificas
	const string generarReporteCursoCod(string codigo_) const;
	const string generarReporteDeportistaCed(string cedula_) const;
	const string generarReportePagosCed(string cedula_) const;
	// metodos para mostrar cositas en general
	const string generarReporteDeportistas() const;
	const string generarListadoCursos() const;
	//const string generarReportePagos() const;	// puede que no haga falta
	// Reporte deportistas por estado:
	const string generarReporteDeportistasPorEstado(char estado_) const;
	// Reporte deportistas matriculados por grupo
	const string generarReporteDeportistasMatriculadosPorGrupo(string codigoCurso_, int numeroGrupo_) const;
	// muestra los cursos que esta matriculado un deportista
	const string generarReporteCursosMatriculados(string cedula_) const;
	// 4. Metodo para buscar
	Deportista* buscarDeportista(string cedula_);
	Curso* buscarCurso(string codigo_);
	// 5. verificar repetidos
	bool existeCursoConCodigo(string codigo_);
	bool existeDeportistaConCedula(string cedula_);
	//archivos
	void guardarEnArchivoDeportistas();
	void guardarCursosYGrupos();
	void guardarEnArchivoDeportistasYSusPagos();
};

