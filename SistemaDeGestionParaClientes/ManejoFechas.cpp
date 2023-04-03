#include "ManejoFechas.h"

int ManejoFechas::calcularEdad(Fecha* fechaNacimiento_, Fecha* fechaActual_)
{
	int edad = fechaActual_->getAnio() - fechaNacimiento_->getAnio();
	if (fechaNacimiento_->getMes() > fechaActual_->getMes())
	{
		edad--;
	}
	else if (fechaNacimiento_->getMes() == fechaActual_->getMes())
	{
		if (fechaNacimiento_->getDia() > fechaActual_->getDia())
		{
			edad--;
		}
	}
	return edad;
}
/// <summary>
/// Este metodo probablemente deba devolver un entero que represento los dias, con el fin de poder programaar cursos
/// </summary>
/// <param name="fecha1_"></param>
/// <param name="fecha2_"></param>
/// <returns> Devuelve un entero que representa los dias de diferencia entre las dos fechas</returns>
int ManejoFechas::calcularDiferencia(Fecha* fecha1_, Fecha* fecha2_)
{
	int diferenciaEnSegundos = 0;
	diferenciaEnSegundos = fechaEnSegundos(fecha1_) - fechaEnSegundos(fecha2_);
	// se devuelve la conversion de segundos a dias
	return diferenciaEnSegundos / (24 * 60 * 60);	// 24 horas, 60 minutos, 60 segundos
}

int ManejoFechas::fechaEnSegundos(Fecha* fecha_)
{
	int segundos = 0;
	segundos += fecha_->getDia() * 24 * 60 * 60;
	segundos += fecha_->getMes() * 30 * 24 * 60 * 60;
	segundos += fecha_->getAnio() * 365 * 24 * 60 * 60;	// 365 dias, 24 horas, 60 minutos, 60 segundos
	return segundos;
}
