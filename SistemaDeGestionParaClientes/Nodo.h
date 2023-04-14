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
	Nodo(const T& dato_);
	Nodo(T* dato_);
	~Nodo();
	void setSiguiente(Nodo<T>* siguiente_);
	Nodo<T>* getSiguiente();
	T* getDato();
	//sobrecarga de metodos
	friend ostream& operator<<(ostream& out, Nodo<T>& nodo_);
};

template<class T>
inline Nodo<T>::Nodo(const T& dato_)
{
	dato = new T(dato_);
	siguiente = nullptr;
}

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