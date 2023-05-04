#pragma once
#include "Deportista.h"
#include "Curso.h"
#include "Pago.h"
#include "fstream"
class GestorDeArchivos
{
public:
	GestorDeArchivos();
	virtual ~GestorDeArchivos() = default;

	// metodos para deportistas
	virtual void guardarDeportista(Deportista* deportista_);
	virtual void guardarDeportistas(ListaEnlazada<Deportista>* listaDeportistas_);
	virtual ListaEnlazada<Deportista>* cargarDeportistas();
};

