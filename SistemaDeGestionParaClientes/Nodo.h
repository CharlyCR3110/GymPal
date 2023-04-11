#pragma once
#include <iostream>
#include <sstream>
using namespace std;

//template
template <class T>
class Nodo
{
private:
	T* dato;
	Nodo<T>* siguiente;
public:
	Nodo(T* dato_);
	~Nodo();
	void setSiguiente(Nodo<T>* siguiente_);
	Nodo<T>* getSiguiente();
	T* getDato();
};

template<class T>
inline Nodo<T>::Nodo(T* dato_)
{
	dato = dato_;
	siguiente = nullptr;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente_)
{
	siguiente = siguiente_;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return this->siguiente;
}

template<class T>
T* Nodo<T>::getDato()
{
	return this->dato;
}