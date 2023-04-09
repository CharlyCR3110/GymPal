#pragma once
#include "ListaEnlazada.h"
#include "Cliente.h"

//linked list of clients
class ListaClienteUtils
{
public:
	static string MostrarClientes(ListaEnlazada<Cliente>* lista);
	static string MostrarClientesActivos(ListaEnlazada<Cliente>* lista);
	static string MostrarClientesInactivos(ListaEnlazada<Cliente>* lista);
	static string mostrarClientesConCuentasPendientes(ListaEnlazada<Cliente>* lista);
	static string mostrarSoloNombreClientes(ListaEnlazada<Cliente>* lista);	//temp method	
};