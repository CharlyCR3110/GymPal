﻿#pragma once
// luego incluyo las clases necesarias
#include "Gimnasio.h"
#include "Utils.h"
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
	static void menuAdministracionGeneralNombreGimnasio(); // 1.1
	static void menuAdministracionGeneralMontoMensual(); // 1.2
	//
	static int menuControlDeportistas();	// 2
	//submenus de menuControlDeportistas
	static void menuControlDeportistasIngresoNuevoDeportista(); // 2.1
	static void menuControlDeportistasModificarDeportista(); // 2.2
	static void menuControlDeportistasMostrarListadosDeportistas(); // 2.3
	static void menuControlDeportistasMostrarDeportistaEspecifico(); // 2.4
	//
	static int menuControlCursos();	// 3
	// submenus de menuControlCursos
	static void menuControlCursosIngresoNuevoCurso(); // 3.1
	static void menuControlCursosMostrarCursoEspecifico(); // 3.2
	static void menuControlCursosModificarCurso(); // 3.3
	//
	static int menuControlGrupos();	// 4
	// submenus de menuControlGrupos
	static void menuControlGruposIngresoNuevoGrupo(); // 4.1
	static void menuControlGruposModificarGrupo(); // 4.2
	static void menuControlGruposMatricularEnGrupo(); // 4.3
	static void menuControlGruposMostrarGrupoEspecifico(); // 4.4
	static void menuControlGruposMostrarDeportistasPorGrupo(); // 4.5
	static void menuControlGruposCancelarMatriculaEnGrupo(); // 4.6
	//
	static int menuControlPagos();	// 5
	// submenus de menuControlPagos
	static void menuControlPagosIngresoNuevoPago(); // 5.1
	static void menuControlPagosMostrarPagosDeportista(); // 5.2
	//

	//
	static void regresar();
	static void opcionInvalida();	// para cuando salte el default
	static void salir();	// para cuando se quiera salir del programa
	static void mensajeDeBienvenida();

	//menus auxiliares
	static Fecha* menuFecha();

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
	// metodo para validar ingreso de datos de un deportista
	static string ingresarYValidarCedulaDeportista();
	static string ingresarYValidarNombreDeportista();
	static string ingresarYValidarTelefonoDeportista();
	static char ingresarYValidarSexoDeportista();
	static int ingresarYValidarHorasEntrenamientoDeportista();
	static int ingresarYValidarCantidadParticipacionesIronManDeportista();
	static int ingresarYValidarCantidadTriatlonesGanadosDeportista(int cantidadParticipados);
	static int ingresarYValidarTemperaturaPromedio();
	static double ingresarYValidarEstaturaDeportista();
	static double ingresarYValidarPesoDeportista();
	static double ingresarYValidarPorcentajeGrasaCorporalDeportista();
	static double ingresarYValidarPorcentajeMasaMuscularDeportista();
	// metodos para validar ingreso de datos de un curso
	static string ingresarYValidarNombre();
	static string ingresarYValidarDescripcion();
	static string ingresarYValidarNivel();
	static int ingresarYValidarCantidadGrupos();
	static string ingresarYValidarCodigo();
	//
	// metodos para cambiar y validad datos de un curso;
	static void modificarNombreCurso(Curso* curso);
	static void modificarDescripcionCurso(Curso* curso);
	static void modificarNivelCurso(Curso* curso);
	static void modificarCantidadGruposCurso(Curso* curso);
	static void modificarCodigoCurso(Curso* curso);

	 //metodos para validar ingreso de datos de un grupo
	static Instructor* ingresarYValidarInstructor();
	static string ingresarYValidarNombreInstructor();
	static string ingresarYValidarApellidoInstructor();
	static string ingresarYValidarCedulaInstructor();
	static int ingresarYValidarCupoMaximo();
	static int ingresarYValidarSemanasDuracion();
	static char ingresarYValidarDiaDeLaSemana();
	static Hora* ingresarYValidarHoraEntrada();
	static Hora* ingresarYValidarHoraSalida(Hora* horaEntrada);

	//metodos para cambiar y validad datos de un grupo;
	static void modificarNombreInstructor(Grupo* grupo);
	static void modificarCedulaInstructor(Grupo* grupo);
	static void modificarCupoMaximoGrupo(Grupo* grupo);
	static void modificarFechaInicioGrupo(Grupo* grupo);
	static void modificarSemanasDuracionGrupo(Grupo* grupo);
	static void modificarDiaDeLaSemanaGrupo(Grupo* grupo);
	static void modificarHoraEntradaGrupo(Grupo* grupo);
	static void modificarHoraSalidaGrupo(Grupo* grupo);

	//
	static void test();
};