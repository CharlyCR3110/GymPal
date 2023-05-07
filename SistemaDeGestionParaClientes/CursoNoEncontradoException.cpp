#include "CursoNoEncontradoException.h"

const char* CursoNoEncontradoException::what() const throw()
{
	return "Error: Curso no encontrado";
}
