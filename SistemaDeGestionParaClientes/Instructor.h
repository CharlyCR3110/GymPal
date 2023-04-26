#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Instructor
{
private:
	string nombre;
	string apellido;
	string id;
public:
	Instructor(string nombre_ = "", string apellido_ = "", string id_ = "");
	Instructor(const Instructor& instructor_);	//constructor copia
	~Instructor() = default;
	// setters
	void setNombre(string nombre_);
	void setApellido(string apellido_);
	void setId(string id_);
	// getters
	const string getNombre() const;
	const string getApellido() const;
	const string getId() const;
	// metodos
	const string toString() const;
	// sobrecarga de operador para mostrar los datos
	friend ostream& operator<<(ostream &out, Instructor &instructor_);
	Instructor& operator=(const Instructor& instructor_);	// operador de asignacion
};

