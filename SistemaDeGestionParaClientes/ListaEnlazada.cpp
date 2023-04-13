#include "ListaEnlazada.h"

template<class T>
ostream& operator<<(ostream& out, ListaEnlazada<T>& lista_)
{
	Nodo<T>* actual = lista_.getPrimero();
	while (actual != nullptr)
	{
		out << *actual->getDato() << endl;
		actual = actual->getSiguiente();
	}
	return out;
}