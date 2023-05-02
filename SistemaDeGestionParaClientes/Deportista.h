#pragma once
#include "DeportistaInvalidoException.h"
#include "Fecha.h"
#include "FechaInvalidaException.h"
#include "ListaEnlazada.h"
#include "Pago.h"
class Curso;

class Deportista
{
protected:
	string cedula;
	string nombre;
	string telefono;
	Fecha* fechaNacimiento;
	char estado; // Activo = 'A', Inactivo = 'I', Con Cuentas Pendientes = 'P'
	// agregar lista de pagos
	ListaEnlazada<Pago>* listaPagos;
	// agregar lista de cursos??
	ListaEnlazada<Curso>* listaCursos;
	int cantidadDeCursosMatriculados;
public:
	Deportista(string cedula_ = "", string nombre_ = "", string telefono_ = "", Fecha* fechaNacimiento_ = nullptr);
	Deportista(const Deportista& deportista_);	//constructor copia
	~Deportista() = default;
	//setters
	virtual void setCedula(string cedula_);
	virtual void setNombre(string nombre_);
	virtual void setTelefono(string telefono_);
	virtual void setFechaNacimiento(Fecha* fechaNacimiento_);
	virtual void setEstado(char estado);
	virtual void setcantidadDeCursosMatriculados(int cantidadDeCursosMatriculados_);
	// pa'l estado y no de wassap
	virtual void actualizarEstado(char estado_);
	// setters que se van pa' abajo
	virtual void setSexo(char sexo_) = 0;
	// Corredor
	virtual void actualizarEstatura(double estatura_, Fecha* fechaActualizacion_) = 0;
	// Nadador
	virtual void actualizarMasaMuscular(double masaMuscular_, Fecha* fechaActualizacion_) = 0;
	virtual void actualizarPorcentajeGrasaCorporal(double porcentajeGrasaCorporal_, Fecha* fechaActualizacion_) = 0;
	virtual void actualizarPeso(double peso_, Fecha* fechaActualizacion_) = 0;
	// Ciclista
	virtual void setHorasEntrenamiento(int horasEntrenamiento_) = 0;
	virtual void setTemperaturaPromedio(double temperaturaPromedio_) = 0;
	// triatlonista
	virtual void setCantidadParticipacionesIronMan(int cantidadParticipacionesIronMan_) = 0;
	virtual void setCantidadTriatlonesGanados(int cantidadTriatlonesGanados_) = 0;
	virtual const int getCantidadParticipacionesIronMan() const = 0;
	//getters
	virtual const string getCedula() const;
	virtual const string getNombre() const;
	virtual const string getTelefono() const;
	virtual Fecha* getFechaNacimiento();
	virtual const char getEstado() const;
	ListaEnlazada<Pago>* getPagos();	// devuelve la lista de pagos
	virtual const int getcantidadDeCursosMatriculados() const;
	virtual ListaEnlazada<Curso>* getListaCursos();	// devuelve la lista de cursos
	//metodo para poder utilizar el template de buscar por codigo
	const string getCodigo() const; //devuelve la cedula
	//metodos
	virtual void agregarCurso(Curso* curso_);
	virtual void eliminarCurso(Curso* curso_);
	virtual const string mostrarCursosMatriculados() const;
	virtual const string toString() const = 0;	//MVP - metodo virtual puro
	virtual const string detalleDeportista() const = 0;	//MVP - metodo virtual puro
	//sobrecarga de operadores
	Deportista& operator=(const Deportista& deportista_);	// operador de asignacion
	bool operator != (const Deportista& deportista_) const; // operador de desigualdad
	friend ostream& operator<<(ostream& out, Deportista& deportista_);	// operador de salida
};