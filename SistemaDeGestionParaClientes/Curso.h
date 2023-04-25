#pragma once
#include "Deportista.h"
#include "Fecha.h"
#include "ListaEnlazada.h"
#include "ListaDeportistaUtils.h"
#include "CupoMaximoExcedido.h"
#include "Grupo.h"

class Curso
{
private:
	string codigo;
	string nombreDelCurso;
	string nivel; // principiante, intermedio, avanzado
	string descripcion;
	int cantidadMaximaDeGrupos;
	int cantidadDeGruposActuales;
	ListaEnlazada<Grupo>* listaGrupos;
public:
	Curso(const Curso& curso_);	//constructor copia
	Curso(string codigo_ = "", string nombreDelCurso_ = "", string nivel_ = "", string descripcion_ = "", int cantidadMaximaDeGrupos = 0);
	~Curso();
	// setters
	void setCodigo(string codigo_);
	void setNombreDelCurso(string nombreDelCurso_);
	void setNivel(string nivel_);
	void setDescripcion(string descripcion_);
	void setCantidadMaximaDeGrupos(int cantidadMaximaDeGrupos_);
	void setCantidadDeGruposActuales(int cantidadDeGruposActuales_);	// no deberia de utilizarse
	void setListaGrupos(ListaEnlazada<Grupo>* listaGrupos_);
	// getters
	const string getCodigo() const;
	const string getNombreDelCurso() const;
	const string getNivel() const;
	const string getDescripcion() const;
	const int getCantidadMaximaDeGrupos() const;
	const int getCantidadDeGruposActuales() const;
	ListaEnlazada<Grupo>* getListaGrupos();
	// metodos
	const string toString() const;
	// sobrecarga de operador para mostrar los datos
	friend ostream& operator<<(ostream &out, Curso &curso_);
	Curso& operator=(const Curso& curso_);	// operador de asignacion
};