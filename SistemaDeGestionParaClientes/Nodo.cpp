#include "Nodo.h"

template<class T>
ostream& operator<<(ostream& out, Nodo<T>& nodo_)
{
	out << *nodo_.dato;
	return out;
}
