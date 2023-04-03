#pragma once
#include "Fecha.h"
class ManejoFechas
{
public:
	static int calcularEdad(Fecha* fechaNacimiento_, Fecha* fechaActual_);
	static int calcularDiferencia(Fecha* fecha1_, Fecha* fecha2_);
	static int fechaEnSegundos(Fecha* fecha_);
};

