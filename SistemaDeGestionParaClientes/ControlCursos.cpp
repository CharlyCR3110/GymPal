#include "ControlCursos.h"

ControlCursos::ControlCursos()
{
    listaCursos = new ListaEnlazada<Curso>();
    listaDeportistas = new ListaEnlazada<Deportista>();
    fechaActual = new Fecha(25, 4, 202
    );
}

ControlCursos::ControlCursos(ListaEnlazada<Curso>* listaCursos_, ListaEnlazada<Deportista>* listaDeportistas_, Fecha* fechaActual_) :
    listaCursos(listaCursos_),
    listaDeportistas(listaDeportistas_),
    fechaActual(fechaActual_)
{
}

ControlCursos::ControlCursos(const ControlCursos& controlCursos_) :
	listaCursos(controlCursos_.listaCursos),
    listaDeportistas(controlCursos_.listaDeportistas),
    fechaActual(controlCursos_.fechaActual)
{
}

ControlCursos::~ControlCursos()
{
    delete listaCursos;
	delete listaDeportistas;
	delete fechaActual;
}

void ControlCursos::registrarCurso(string codigo_, string nombre_, string nivel_, string descripcion_, int cantidadMaximaDeGrupos_)
{
    Curso* curso = new Curso(codigo_, nombre_, nivel_, descripcion_, cantidadMaximaDeGrupos_);
    try
    {
        listaCursos->insertar(curso);
	}
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }
}

string ControlCursos::generarReporteCurso(string codigo_)
{
    Curso* curso = nullptr;
    try
    {
        curso = listaCursos->buscarPorCodigo(codigo_);
    }
    catch (exception& e)
    {
		throw exception(e.what());
	}

    // si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
    if (curso != nullptr)
    {
        return curso->generarReporte();
    }
    else
    {
        return "No se encontro el curso";
    }
}

void ControlCursos::matricularEnGrupo(string codigoCurso_, int numeroGrupo_, string cedulaDeportista_)
{
        Curso* curso = nullptr;
	    Deportista* deportista = nullptr;
        try
        {
		    curso = listaCursos->buscarPorCodigo(codigoCurso_);
		    deportista = listaDeportistas->buscarPorCodigo(cedulaDeportista_);
	    }
        catch (exception& e)
        {
		    throw exception(e.what());
	    }
	    // si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
        if (curso == nullptr || deportista == nullptr)
        {
		    throw exception("No se encontro el curso o el deportista");   
	    }

        if (deportista->getcantidadDeCursosMatriculados() >= MAX_CURSOS)
        {
			throw exception("El deportista ya tiene 3 cursos matriculados");
		}
        // si el deportista ya esta matriculado en el curso
        if (curso->estaMatriculado(deportista))
        {
            throw exception("El deportista ya esta matriculado en el curso"); 
        }
        // si el curso esta lleno
        if (curso->grupoLleno(numeroGrupo_))
        {
			throw exception("El curso esta lleno");
		}

        // hacer la matricula
        try
        {
            curso->matricularEnGrupo(numeroGrupo_, deportista);
        }
        catch (exception& e)
        {
			throw exception(e.what());
		}
}

string ControlCursos::reporteGuiaMatriculaCurso(string codigo_)
{
    Curso* curso = nullptr;
    try
    {
        curso = listaCursos->buscarPorCodigo(codigo_);
    }
    catch (exception& e)
    {
        throw exception(e.what());
    }

    // si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
    if (curso != nullptr)
    {
        return curso->reporteCursoGuiaMatricula();
    }
    else
    {
        return "No se encontro el curso.";
    }
}

//string ControlCursos::reporteCursosMatriculados(string cedula_)
//{
//    Deportista* deportista = nullptr;
//    try
//    {
//		deportista = listaDeportistas->buscarPorCodigo(cedula_);
//	}
//    catch (exception& e)
//    {
//		throw exception(e.what());
//	}
//	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
//    if (deportista != nullptr)
//    {
//		return deportista->reporteCursosMatriculados(); // TO-DO
//	}
//    else
//    {
//		return "No se encontro el deportista.";
//	}
//}

string ControlCursos::reporteListadoCursos()
{
    Nodo<Curso>* cursoActual;
    try 
    {
        cursoActual = listaCursos->getPrimero();
	}
    catch (exception& e)
    {
        throw exception(e.what());
    }
    //recorrer la lista y llamar al metodo listadoDeCurso() de cada curso
    stringstream ss;
    ss << "Listado de cursos: " << endl;
    if (cursoActual != nullptr)
    {
        while (cursoActual != nullptr)
        {
			ss << cursoActual->getDato()->listadoDeCurso() << endl;
			cursoActual = cursoActual->getSiguiente();
		}
	}
    else
    {
		ss << "No hay cursos registrados." << endl;
	}
 
    return ss.str();
}

const string ControlCursos::generarReporteDeportistasMatriculadosPorGrupo(string codigoCurso_, int numeroGrupo_) const
{
    stringstream ss;
    Curso* curso = nullptr;
    try
    {
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
	}
    catch (exception& e)
    {
		throw exception(e.what());
	}
    // si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
    if (curso != nullptr)
    {
		ss << curso->generarReporteDeportistasMatriculadosPorGrupo(numeroGrupo_);
	}
    else
    {
		ss << "No se encontro el curso." << endl;
	}
    
    return ss.str();
}

void ControlCursos::agregarGrupo(string codigoCurso_, Grupo* grupo_)
{
    Curso* curso = nullptr;
    try
    {
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
	}
    catch (exception& e)
    {
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
    if (curso != nullptr)
    {
		curso->agregarGrupo(grupo_);
	}
    else
    {
		throw exception("No se encontro el curso.");
	}
}

string ControlCursos::reporteGrupo(string codigoCurso_, int numeroGrupo_)
{
    Curso* curso = nullptr;
    try
    {
		curso = listaCursos->buscarPorCodigo(codigoCurso_);
	}
    catch (exception& e)
    {
		throw exception(e.what());
	}
	// si es nullptr probablemente nunca llegue a este punto por el catch, pero por si acaso
    if (curso != nullptr)
    {
		return curso->reporteGrupo(numeroGrupo_);
	}
    else
    {
		return "No se encontro el curso.";
	}
}
