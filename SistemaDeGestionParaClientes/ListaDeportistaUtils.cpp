#include "ListaDeportistaUtils.h"
//linked list of clients
string ListaDeportistaUtils::MostrarDeportistas(ListaEnlazada<Deportista>* lista)
{
	if (lista->estaVacia())
	{
		return "La lista esta vacia";
	}
	stringstream ss;
	Nodo<Deportista>* actual = lista->getPrimero();
	while (actual != nullptr)
	{
		ss << actual->getDato()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return ss.str();
}

string ListaDeportistaUtils::MostrarDeportistasActivos(ListaEnlazada<Deportista>* lista)	//activos = 'A'
{
	if (lista->estaVacia())
	{
		return "La lista esta vacia";
	}
	bool hayActivos = false;
	stringstream ss;
	ss << "Deportistas activos: " << endl;
	Nodo<Deportista>* actual = lista->getPrimero();
	while (actual != nullptr)
	{
		if (actual->getDato()->getEstado() == 'A')
		{
			ss << actual->getDato()->toString() << endl;
			hayActivos = true;
		}
		actual = actual->getSiguiente();
	}

	if (!hayActivos)
	{
		return "No hay clientes activos";
	}

	return ss.str();
}

string ListaDeportistaUtils::MostrarDeportistasInactivos(ListaEnlazada<Deportista>* lista) //inactivos = 'I'
{
	if (lista->estaVacia())
	{
		return "La lista esta vacia";
	}

	bool hayInactivos = false;
	stringstream ss;
	ss << "Deportistas inactivos: " << endl;
	Nodo<Deportista>* actual = lista->getPrimero();
	while (actual != nullptr)
	{
		if (actual->getDato()->getEstado() == 'I')
		{
			ss << actual->getDato()->toString() << endl;
			hayInactivos = true;
		}
		actual = actual->getSiguiente();
	}

	if (!hayInactivos)
	{
		return "No hay clientes inactivos";
	}

	return ss.str();
}

string ListaDeportistaUtils::mostrarDeportistasConCuentasPendientes(ListaEnlazada<Deportista>* lista) //pendientes = 'P'
{
	if (lista->estaVacia())
	{
		return "La lista esta vacia";
	}

	bool hayPendientes = false;
	stringstream ss;
	ss << "Deportistas con cuentas pendientes: " << endl;
	Nodo<Deportista>* actual = lista->getPrimero();
	while (actual != nullptr)
	{
		if (actual->getDato()->getEstado() == 'P')
		{
			ss << actual->getDato()->toString() << endl;
			hayPendientes = true;
		}
		actual = actual->getSiguiente();
	}

	if (!hayPendientes)
	{
		return "No hay clientes con cuentas pendientes";
	}

	return ss.str();
}

string ListaDeportistaUtils::mostrarSoloNombreDeportistas(ListaEnlazada<Deportista>* lista)
{
	if (lista->estaVacia())
	{
		return "La lista esta vacia";
	}
	int i = 1;
	stringstream ss;
	Nodo<Deportista>* actual = lista->getPrimero();
	while (actual != nullptr)
	{
		ss << i << ". " << actual->getDato()->getNombre() << endl;
		actual = actual->getSiguiente();
		i++;
	}
	return ss.str();
}