#pragma once
#include "Nodo.h"
#include "ListaEnlazadasException.h"
#include "ElementoNoEncontradoException.h"

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
	~ListaEnlazada();
	//getters
	Nodo<T>* getPrimero();
	Nodo<T>* getUltimo();
	int getCantidad();
	//metodos
	bool estaVacia();
	Nodo<T>* buscarNodo(T* dato_);	// busca el nodo que contiene el dato
	void insertar(T* dato_);	// inserta al final
	void insertarAlInicio(T* dato_);	// inserta al inicio
	void eliminar(int posicion_);	// elimina por posicion
	void eliminarPrimero();	// elimina el primero
	void eliminarUltimo();	// elimina el ultimo
	void eliminarDato(T* dato_);	// elimina el dato
	void vaciar();	// elimina todos los datos
	T* buscar(T* dato_);
	//metodos para buscar cositas
	T* buscarPorCodigo(string codigo_);
	
	// sobrecarga de operador para mostrar los datos
	template <class U>
	friend ostream& operator <<(ostream& out, ListaEnlazada<U>& lista_);	// operador de salida
	ListaEnlazada<T>& operator=(const ListaEnlazada<T>& lista_);	//operador de asignacion
};

template<class T>
inline ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T>& lista_)
{
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
inline bool ListaEnlazada<T>::estaVacia()
{
	return this->primero == nullptr;
}

template<class T>
inline Nodo<T>* ListaEnlazada<T>::buscarNodo(T* dato_)
{
	if (estaVacia())
	{
		throw ListaEnlazadasExceptions("Lista vacia");
	}
	Nodo<T>* actual = this->primero;
	while (actual != nullptr && actual->getDato() != dato_)	// recorre la lista hasta encontrar el dato o llegar al final
	{
		actual = actual->getSiguiente();
	}
	if (actual == nullptr)	// si no encontr[o el dato lanza una excepcion
	{
		throw ListaEnlazadasExceptions("Dato no encontrado");
	}
	return actual;
}

template<class T>
inline void ListaEnlazada<T>::insertar(T* dato_)
{
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
		throw exception("Posicion invalida");
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
	if (this->cantidad == 0)
	{
		throw exception("Lista vacia");
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
	if (this->cantidad == 0)
	{
		throw exception("Lista vacia");
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
	if (this->cantidad == 0)
	{
		throw ListaEnlazadasExceptions("Lista vacia");
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
		throw ListaEnlazadasExceptions("Dato no encontrado");
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
	Nodo<T>* actual = primero;
	while (actual != nullptr) {
		if ((actual->getDato()) == dato_) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return nullptr;
}

template<class T>
inline T* ListaEnlazada<T>::buscarPorCodigo(string codigo_)
{
	if (estaVacia()) 
	{
		throw ListaEnlazadasExceptions("Lista vacia");
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
