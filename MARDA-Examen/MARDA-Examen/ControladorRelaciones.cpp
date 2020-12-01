#include "ControladorRelaciones.h"

ControladorRelaciones::ControladorRelaciones()
{
}

ControladorRelaciones::~ControladorRelaciones()
{
}

void ControladorRelaciones::agregarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	//restriccion de las cardinalidades
	if (relacion->getRelacion()->count(llave) < relacion->getCardSegundo() && relacion->contarLlaves(elemento) < relacion->getCardPrimero()) {
		relacion->getRelacion()->insert(std::pair<EntidadAbstracta*, EntidadAbstracta*>(llave, elemento));
		//TO DO: Escribir en la bitacora que se agrego la relacion
	}
	else {
		//TO DO: Escribir en la bitacora que no se pudo agregar la relacion
	}


}

void ControladorRelaciones::eliminarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	bool encontrado = false;
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->first == llave && itr->second == elemento) {
			relacion->getRelacion()->erase(itr);
			encontrado = true;
			break;
		}
	}
	if (encontrado) {
		//TO DO: Escribir en la bitacora que se borro la relacion
	}
	else {
		//TO DO: Escribir en la bitacora que no se encontro la relacion para borrar

	}
}

std::vector<EntidadAbstracta*>* ControladorRelaciones::getElementos(Relacion* relacion, EntidadAbstracta* llave)
{
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->first == llave)
			vector->push_back(itr->second);
	}
	return vector;
}

std::vector<EntidadAbstracta*>* ControladorRelaciones::getLlaves(Relacion* relacion, EntidadAbstracta* elemento)
{
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->second == elemento)
			vector->push_back(itr->first);
	}
	return vector;
}
