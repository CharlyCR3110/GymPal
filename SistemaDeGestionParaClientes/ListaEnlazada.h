#pragma once
#include "Nodo.h"
#include "ListaEnlazadasException.h"
#include "ElementoNoEncontradoException.h"
#include "ListaVaciaException.h"

template <class T>
class ListaEnlazada
{
private:
	Nodo<T>* primero;
	Nodo<T>* ultimo;
	int cantidad;
public:
	ListaEnlazada(const ListaEnlazada<T>& lista_);	// constructor copia
	ListaEnlazada();
	virtual ~ListaEnlazada();
	//getters
	Nodo<T>* getPrimero();
	Nodo<T>* getUltimo();
	int getCantidad();
	// utils
	const bool estaVacia() const;
	//metodos para insertar y eliminar
	void insertar(T* dato_);	// inserta al final
	void insertarAlInicio(T* dato_);	// inserta al inicio
	void eliminar(int posicion_);	// elimina por posicion
	void eliminarPrimero();	// elimina el primero
	void eliminarUltimo();	// elimina el ultimo
	void eliminarDato(T* dato_);	// elimina el dato
	void eliminarDatoPorCodigo(string codigo_);	// elimina el dato por codigo
	void vaciar();	// elimina todos los datos
	T* buscar(T* dato_);
	//metodos para buscar cositas
	Nodo<T>* buscarNodo(T* dato_);	// busca el nodo que contiene el dato --- poco util
	T* buscarPorCodigo(string codigo_);	// me devuelve el dato que contiene el codigo (o sea un deportista, un curso, etc)
	//metodos para filtrar Deportistas por estado
	ListaEnlazada<T>* filtrarPorEstado(char estado_);	// lo filtro. luego en otro metodo lo muestro con 'X
	//metodos para mostrar lista con base en el estado;
	string mostrarPorEstado(char estado_);	// muestra los datos de la lista filtrada //2.3.2-4
	// mostrar elemento especifico por codigo
	string mostrarPorCodigo(string codigo_);	// muestra los datos de un elemento especifico //2.4
	//metodos para mostrar datos
	const string toString() const;	// muestra los datos	//2.3.1 listado general
	// sobrecarga de operador para mostrar los datos
	template <class U>
	friend ostream& operator <<(ostream& out, ListaEnlazada<U>& lista_);	// operador de salida
	ListaEnlazada<T>& operator=(const ListaEnlazada<T>& lista_);	//operador de asignacion
};

template<class T>
inline ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T>& lista_)
{
	if (&lista_ == nullptr)
	{
		throw ListaEnlazadasExceptions("La lista pasada por parametro es nula");
	}

	this->primero = nullptr;
	this->ultimo = nullptr;
	this->cantidad = 0;
	Nodo<T>* actual = lista_.primero;
	while (actual != nullptr)
	{
		insertar(actual->getDato());
		actual = actual->getSiguiente();
	}
}

template<class T>
inline ListaEnlazada<T>::ListaEnlazada()
{
	this->primero = nullptr;
	this->ultimo = nullptr;
	this->cantidad = 0;
}

template<class T>
inline ListaEnlazada<T>::~ListaEnlazada()
{
	vaciar();
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::getPrimero()
{
	return this->primero;
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::getUltimo()
{
	return this->ultimo;
}

template<class T>
inline int ListaEnlazada<T>::getCantidad()
{
	return this->cantidad;
}

template<class T>
inline const bool ListaEnlazada<T>::estaVacia() const
{

	return this->primero == nullptr;
}

template<class T>
inline void ListaEnlazada<T>::insertar(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	Nodo<T>* nuevo = new Nodo<T>(dato_);
	if (estaVacia())
	{
		this->primero = nuevo;
	}
	else
	{
		this->ultimo->setSiguiente(nuevo);
	}
	this->ultimo = nuevo;
	this->cantidad++;
}

template<class T>
inline void ListaEnlazada<T>::insertarAlInicio(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	Nodo<T>* nuevo = new Nodo<T>(dato_);
	if (estaVacia())
	{
		this->primero = nuevo;
		this->ultimo = nuevo;
	}
	else
	{
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
	this->cantidad++;
}

template<class T>
inline void ListaEnlazada<T>::eliminar(int posicion_)
{
	if (posicion_ <= 0 || posicion_ > this->cantidad)
	{
		throw ListaEnlazadasExceptions("Posicion invalida");
	}
	if (posicion_ == 1)
	{
		eliminarPrimero();
	}
	else if (posicion_ == this->cantidad)
	{
		eliminarUltimo();
	}
	else
	{
		Nodo<T>* actual = this->primero;
		for (int i = 1; i < posicion_ - 1; i++)
		{
			actual = actual->getSiguiente();
		}
		Nodo<T>* eliminar = actual->getSiguiente();
		actual->setSiguiente(eliminar->getSiguiente());
		delete eliminar;
		this->cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarPrimero()
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* eliminar = this->primero;
	this->primero = primero->getSiguiente();
	delete eliminar;
	this->cantidad--;
	if (this->cantidad == 0)
	{
		this->ultimo = nullptr;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarUltimo()
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	} 
	
	if (this->cantidad == 1)
	{
		delete this->primero;
		this->primero = this->ultimo = nullptr;
	}
	else
	{
		Nodo<T>* actual = this->primero;		
		while (actual->getSiguiente() != this->ultimo)
		{
			actual = actual->getSiguiente();
		}
		delete this->ultimo;
		this->ultimo = actual;
		actual->setSiguiente(nullptr);
	}
	this->cantidad--;
}

//to-do si no lo encuentra
template<class T>
inline void ListaEnlazada<T>::eliminarDato(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* actual = this->primero;
	Nodo<T>* anterior = nullptr;

	while (actual != nullptr && actual->getDato() != dato_)
	{
		anterior = actual;
		actual = actual->getSiguiente();
	}

	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}

	if (actual == this->primero)
	{
		eliminarPrimero();
	}
	else if (actual == this->ultimo)
	{
		eliminarUltimo();
	}

	else
	{
		anterior->setSiguiente(actual->getSiguiente());
		delete actual;
		this->cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::eliminarDatoPorCodigo(string codigo_)
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* actual = this->primero;
	Nodo<T>* anterior = nullptr;
	while (actual != nullptr && actual->getDato()->getCodigo() != codigo_)
	{
		anterior = actual;
		actual = actual->getSiguiente();
	}
	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}
	if (actual == this->primero)
	{
		eliminarPrimero();
	}
	else if (actual == this->ultimo)
	{
		eliminarUltimo();
	}
	else
	{
		anterior->setSiguiente(actual->getSiguiente());
		delete actual;
		this->cantidad--;
	}
}

template<class T>
inline void ListaEnlazada<T>::vaciar()
{
	while (!estaVacia())
	{
		eliminarPrimero();
	}
	// aunque el metodo eliminarPrimero reduce el valor de cantidad en cada llamada, lo pongo aca por las dudas
	this->cantidad = 0;
}

template<class T>
inline T* ListaEnlazada<T>::buscar(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}


	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	Nodo<T>* actual = primero;
	while (actual != nullptr) {
		if ((actual->getDato()) == dato_) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}

	if (actual == nullptr)
	{
		throw ElementoNoEncontradoException<T>();
	}
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::buscarNodo(T* dato_)
{
	if (dato_ == nullptr)
	{
		throw ListaEnlazadasExceptions("El dato no puede ser nulo");
	}

	if (estaVacia())
	{
		throw ListaVaciaException();
	}
	Nodo<T>* actual = this->primero;
	while (actual != nullptr && actual->getDato() != dato_)	// recorre la lista hasta encontrar el dato o llegar al final
	{
		actual = actual->getSiguiente();
	}
	if (actual == nullptr)	// si no encontr[o el dato lanza una excepcion
	{
		throw ElementoNoEncontradoException<T>;
	}
	return actual;
}

template<class T>
inline T* ListaEnlazada<T>::buscarPorCodigo(string codigo_)
{
	if (estaVacia()) 
	{
		throw ListaVaciaException();
	}

	Nodo<T>* actual = primero;
	while (actual != nullptr) {
		if ((actual->getDato())->getCodigo() == codigo_) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	// si no lo encuentra lanza una excepcion
	throw ElementoNoEncontradoException<T>();
}

template<class T>
inline ListaEnlazada<T>* ListaEnlazada<T>::filtrarPorEstado(char estado_)
{
	if (estaVacia())
	{
		throw ListaVaciaException();
	}

	ListaEnlazada<T>* filtrada = new ListaEnlazada<T>();
	Nodo<T>* actual = this->primero;
	while (actual != nullptr)
	{
		if ((actual->getDato())->getEstado() == estado_)
		{
			filtrada->insertar(actual->getDato());
		}
		actual = actual->getSiguiente();
	}

	if (filtrada->estaVacia())
	{
		throw ElementoNoEncontradoException<T>();
	}

	return filtrada;
}

template<class T>
inline string ListaEnlazada<T>::mostrarPorEstado(char estado_)
{
	try {
		return filtrarPorEstado(estado_)->toString();
	}
	catch (ElementoNoEncontradoException<T>) {
		throw exception("No se encontraron elementos con ese estado.");	//esto debe debe de ser una excepcion
	}
}

template<class T>
inline string ListaEnlazada<T>::mostrarPorCodigo(string codigo_)
{
	try {
		return buscarPorCodigo(codigo_)->toString();
	}
	catch (ElementoNoEncontradoException<T>) {
		return "No se encontro el elemento con ese codigo.";	//esto debe debe de ser una excepcion
	}
}

template<class T>
inline const string ListaEnlazada<T>::toString() const
{
	if (estaVacia())
	{
		return "Actualmente la lista se encuentra vacia.";
	}
	stringstream ss;
	Nodo<T>* actual = this->primero;
	while (actual != nullptr)
	{
		ss << actual->getDato()->toString() << endl;
		actual = actual->getSiguiente();
	}

	return ss.str();
}

template<class T>
inline ListaEnlazada<T>& ListaEnlazada<T>::operator=(const ListaEnlazada<T>& lista_)
{
	if (this != &lista_)
	{
		this->vaciar();	//el metodo vaciar pone el contador en 0
		Nodo<T>* actual = lista_.getPrimero();
		while (actual != nullptr)
		{
			this->insertar(actual->getDato());
			actual = actual->getSiguiente();
		}
	}
	return *this;
}
