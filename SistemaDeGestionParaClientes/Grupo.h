#pragma once
#include "Fecha.h"
#include "Hora.h"
#include "Instructor.h"
#include "Triatlonista.h"
#include "ListaEnlazada.h"
class Grupo
{
private:
	Instructor* instructor;
	int cupoMaximo;
	Fecha* fechaDeInicio;
	int semanasDeDuracion;
	//horario
	char diaDeLaSemana; //Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo (L, K, M, J, V, S, D)
	Hora* horaDeInicio;
	Hora* horaDeFin;
	ListaEnlazada<Deportista>* deportistasInscritos;
public:
	Grupo(Instructor* instructor_, int cupoMaximo_, Fecha* fechaDeInicio_, int semanasDeDuracion_, char diaDeLaSemana_, Hora* horaDeInicio_, Hora* horaDeFin_);
	Grupo (const Grupo& grupo_);
	~Grupo();
	//setters
	void setInstructor(Instructor* instructor_);
	void setCupoMaximo(int cupoMaximo_);
	void setFechaDeInicio(Fecha* fechaDeInicio_);
	void setSemanasDeDuracion(int semanasDeDuracion_);
	void setDiaDeLaSemana(char diaDeLaSemana_);
	void setHoraDeInicio(Hora* horaDeInicio_);
	void setHoraDeFin(Hora* horaDeFin_);
	void setDeportistasInscritos(ListaEnlazada<Deportista>* triatlonistasInscritos_);
	//getters
	Instructor* getInstructor();
	const int getCupoMaximo() const;
	Fecha* getFechaDeInicio();
	const int getSemanasDeDuracion() const;
	const char getDiaDeLaSemana() const;
	Hora* getHoraDeInicio();
	Hora* getHoraDeFin();
	ListaEnlazada<Deportista>* getDeportistasInscritos();
	//metodos
	const string toString() const;	
	const string mostrarDeportistasInscritos() const;
	//sobrecarga
	Grupo& operator=(const Grupo& grupo_);
	friend ostream& operator<<(ostream& out, const Grupo& grupo_);
};
