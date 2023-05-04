#include "GestorDeArchivos.h"

GestorDeArchivos::GestorDeArchivos()
{
}

void GestorDeArchivos::guardarDeportista(Deportista* deportista_)
{
	ofstream archivoDeportistas;
	archivoDeportistas.open("../Deportistas.txt"/*, ios::app*/);
	if (archivoDeportistas.is_open())
	{
		archivoDeportistas << deportista_->toStringParaGuardar() << endl;
		archivoDeportistas.close();
	}
	else
	{
		throw new exception("No se pudo abrir el archivo Deportistas.txt");
	}
}

void GestorDeArchivos::guardarDeportistas(ListaEnlazada<Deportista>* listaDeportistas_)
{
    ofstream archivoDeportistas;
    archivoDeportistas.open("../Deportistas.txt");
    if (!archivoDeportistas.is_open())
    {
        throw new exception("No se pudo abrir el archivo Deportistas.txt");
    }
    else
    {
        Nodo<Deportista>* nodoActual = listaDeportistas_->getPrimero();
        while (nodoActual != nullptr)
        {
            archivoDeportistas << nodoActual->getDato()->toStringParaGuardar();
            nodoActual = nodoActual->getSiguiente();
        }
        archivoDeportistas.close();
    }
}