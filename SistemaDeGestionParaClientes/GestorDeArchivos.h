#pragma once
#include "Deportista.h"
#include "Curso.h"
#include "Pago.h"
#include "fstream"
class GestorDeArchivos
{
public:
	GestorDeArchivos() = default;
	virtual ~GestorDeArchivos() = default;

	// metodos para deportistas
	virtual void guardarDeportista(Deportista* deportista_);
};

