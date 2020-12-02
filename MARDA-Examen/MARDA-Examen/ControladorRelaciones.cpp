#include "ControladorRelaciones.h"

Relacion* ControladorRelaciones::getRelacion(std::string nombre)
{
	Relacion* resultado;
	for (auto itr = this->vectorRelaciones.begin(); itr != this->vectorRelaciones.end(); itr++) {
		if ((*itr)->getNombre() == nombre)
			resultado = *itr;
		break;
	}
	return resultado;
}

ControladorRelaciones::ControladorRelaciones()
{
}

ControladorRelaciones::~ControladorRelaciones()
{
	vectorRelaciones.clear();
}

void ControladorRelaciones::crearRelacion(std::string nombre, unsigned int cardPrimero, unsigned int cardSegundo)
{
	this->vectorRelaciones.push_back(new Relacion(nombre, cardPrimero, cardSegundo));
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se cre� la relaci�n " << nombre << std::endl;
	bitacora.close();
}

void ControladorRelaciones::eliminarRelacion(std::string nombre)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	for (auto itr = this->vectorRelaciones.begin(); itr != this->vectorRelaciones.end(); itr++) {
		if ((*itr)->getNombre() == nombre)
			vectorRelaciones.erase(itr);
		delete((*itr));
		bitacora << "Se elimin� la relaci�n " << nombre << std::endl;
		bitacora.close();
	}
}


void ControladorRelaciones::agregarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	//restriccion de las cardinalidades
	if (relacion->getRelacion()->count(llave) < relacion->getCardSegundo() && relacion->contarLlaves(elemento) < relacion->getCardPrimero()) {
		relacion->getRelacion()->insert(std::pair<EntidadAbstracta*, EntidadAbstracta*>(llave, elemento));

		bitacora << "A " << relacion->getNombre() << " se agreg� una nueva relaci�n entre " << llave->getNombre()<<" y " << elemento->getNombre()<<"."<<std::endl;
	}
	else {

		bitacora << "No se pudo agregar la relacion entre " << llave->getNombre() << " y " << elemento->getNombre() << "a " << relacion->getNombre() << " por la restricci�n de cardinalidad." << std::endl;
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
		bitacora << "Se elimin� la relaci�n entre " << llave->getNombre() << " y " << elemento->getNombre() << "en " << relacion->getNombre() <<"." << std::endl;
	}
	else {
		bitacora << "No se encontr� la relaci�n entre " << llave->getNombre() << " y " << elemento->getNombre() << "en " << relacion->getNombre() << " por lo que no se pudo borrar." << std::endl;
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
