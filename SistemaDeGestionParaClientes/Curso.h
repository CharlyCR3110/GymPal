#pragma once
#include "ListaClienteUtils.h"	// esto incluye a ListaEnlazada.h
#include "Fecha.h"
#include "CupoMaximoExcedido.h"

class Curso
{
private:
	string descripcion;
	string nivel; //principiante, intermedio, avanzado
	int cupoMaximo;
	int cantidadClientes;
	//fechas y horario del curso
	Fecha* fechaInicio;
	Fecha* fechaFin;
	string horario;
	//lista de clientes inscriptos
	ListaEnlazada<Cliente>* listaClientesInscritos;	
public:
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
	const int getCantidadClientes() const;	// cantidad de clientes inscritos en el curso
	ListaEnlazada<Cliente>* getListaClientesInscritos();
	// metodos
	void agregarCliente(Cliente* cliente);	//agregar reserva
	void eliminarCliente(Cliente* cliente);	//eliminar reserva
	void mostrarClientes();	//mostrar reservas
	bool tieneCupoDisponible();
	const string toString() const;
	//metodo experimental para agregar una lista directamente. | es un set de listaClientesInscritos
	void agregarListaClientes(ListaEnlazada<Cliente>* listaClientes_);
	// sobrecarga de operador para mostrar los datos
	friend ostream& operator<<(ostream &out, Curso &curso_);
};