#include "ListaEnlazada.h"

template<class T>
ostream& operator<<(ostream& out, ListaEnlazada<T>& lista_)
{
	out << lista_.toString();
	return out;
}