#include "ControladorRelaciones.h"

ControladorRelaciones::ControladorRelaciones()
{
}

ControladorRelaciones::~ControladorRelaciones()
{
}

void ControladorRelaciones::agregarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	//restriccion de las cardinalidades
	if (relacion->getRelacion()->count(llave) < relacion->getCardSegundo() && relacion->contarLlaves(elemento) < relacion->getCardPrimero()) {
		relacion->getRelacion()->insert(std::pair<EntidadAbstracta*, EntidadAbstracta*>(llave, elemento));

		bitacora << "A " << relacion->getNombre() << " se agregó una nueva relación entre " << llave->getNombre()<<" y " << elemento->getNombre()<<"."<<std::endl;
	}
	else {

		bitacora << "No se pudo agregar la relacion entre " << llave->getNombre() << " y " << elemento->getNombre() << "a " << relacion->getNombre() << " por la restricción de cardinalidad." << std::endl;
	}
	bitacora.close();

}

void ControladorRelaciones::eliminarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bool encontrado = false;
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->first == llave && itr->second == elemento) {
			relacion->getRelacion()->erase(itr);
			encontrado = true;
			break;
		}
	}
	if (encontrado) {
		bitacora << "Se eliminó la relación entre " << llave->getNombre() << " y " << elemento->getNombre() << "en " << relacion->getNombre() <<"." << std::endl;
	}
	else {
		bitacora << "No se encontró la relación entre " << llave->getNombre() << " y " << elemento->getNombre() << "en " << relacion->getNombre() << " por lo que no se pudo borrar." << std::endl;
	}
	bitacora.close();
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
