#pragma once
#include "ListaEnlazada.h"
#include "Deportista.h"
//linked list of clients
class ListaDeportistaUtils
{
public:
	static string MostrarDeportistas(ListaEnlazada<Deportista>* lista);
	static string MostrarDeportistasActivos(ListaEnlazada<Deportista>* lista);
	static string MostrarDeportistasInactivos(ListaEnlazada<Deportista>* lista);
	static string mostrarDeportistasConCuentasPendientes(ListaEnlazada<Deportista>* lista);
	static string mostrarSoloNombreDeportistas(ListaEnlazada<Deportista>* lista);	//temp method	
};