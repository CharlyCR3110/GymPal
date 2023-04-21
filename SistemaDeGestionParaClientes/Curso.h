#pragma once
#include "Deportista.h"
#include "Fecha.h"
#include "ListaEnlazada.h"
#include "ListaDeportistaUtils.h"
#include "CupoMaximoExcedido.h"

class Curso
{
private:
	string descripcion;
	string nivel; //principiante, intermedio, avanzado
	int cupoMaximo;
	int cantidadDeportistas;
	//fechas y horario del curso
	Fecha* fechaInicio;
	Fecha* fechaFin;
	string horario;
	//lista de clientes inscriptos
	ListaEnlazada<Deportista>* listaDeportistasInscritos;	
public:
	Curso(const Curso& curso_);	//constructor copia
	Curso(string descripcion_ = "", string nivel_ = "", int cupoMaximo_ = 0, Fecha* fechaInicio_ = new Fecha(), Fecha* fechaFin_ = new Fecha(), string horario_ = "");
	~Curso();
	// setters
	void setDescripcion(string descripcion_);
	void setNivel(string nivel_);
	void setCupoMaximo(int cupoMaximo_);
	void setFechaInicio(Fecha* fechaInicio_);
	void setFechaFin(Fecha* fechaFin_);
	void setHorario(string horario_);
	// getters
	const string getDescripcion() const;
	const string getNivel() const;
	const int getCupoMaximo() const;
	Fecha* getFechaInicio();
	Fecha* getFechaFin();
	const string getHorario() const;
	const int getCantidadDeportistas() const;	// cantidad de clientes inscritos en el curso
	ListaEnlazada<Deportista>* getListaDeportistasInscritos();
	// metodos
	void agregarDeportista(Deportista* deportista_);	//agregar reserva
	void eliminarDeportista(Deportista* deportista_);	//eliminar reserva
	void mostrarDeportistas();	//mostrar reservas
	bool tieneCupoDisponible();
	const string toString() const;
	//metodo experimental para agregar una lista directamente. | es un set de listaDeportistasInscritos
	void agregarListaDeportistas(ListaEnlazada<Deportista>* listaDeportistas_);
	// sobrecarga de operador para mostrar los datos
	friend ostream& operator<<(ostream &out, Curso &curso_);
	Curso& operator=(const Curso& curso_);	// operador de asignacion
};