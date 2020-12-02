#include "ControladorRelaciones.h"

Relacion* ControladorRelaciones::getRelacion(std::string nombre)
{
	Relacion* resultado = nullptr;
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
	//cardinalidad 0 = infinito
	this->vectorRelaciones.push_back(new Relacion(nombre, cardPrimero, cardSegundo));
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se creó la relación " << nombre << std::endl;
	bitacora.close();
}

void ControladorRelaciones::eliminarRelacion(std::string nombre)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	for (auto itr = this->vectorRelaciones.begin(); itr != this->vectorRelaciones.end(); itr++) {
		if ((*itr)->getNombre() == nombre)
			vectorRelaciones.erase(itr);
		delete((*itr));
		bitacora << "Se eliminó la relación " << nombre << std::endl;
		bitacora.close();
	}
}

void ControladorRelaciones::modificarRelacion(std::string nombreRelacion, std::string nuevoNombreRelacion)
{
	Relacion* relacion = this->getRelacion(nombreRelacion);
	relacion->setNombre(nuevoNombreRelacion);
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se modificó el nombre de la relación " << nombreRelacion << " por " << nuevoNombreRelacion << std::endl;
	bitacora.close();

}


void ControladorRelaciones::agregarRelacion(std::string nombreRelacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	Relacion* relacion = this->getRelacion(nombreRelacion);
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	//restriccion de las cardinalidades
	if ((relacion->getRelacion()->count(llave) < relacion->getCardSegundo() || relacion->getCardSegundo() == 0) && relacion->contarLlaves(elemento) < relacion->getCardPrimero() || relacion->getCardPrimero() == 0) {
		relacion->getRelacion()->insert(std::pair<EntidadAbstracta*, EntidadAbstracta*>(llave, elemento));

		bitacora << "A " << relacion->getNombre() << " se agregó una nueva relación entre " << llave->getNombre()<<" y " << elemento->getNombre()<<"."<<std::endl;
	}
	else {

		bitacora << "No se pudo agregar la relacion entre " << llave->getNombre() << " y " << elemento->getNombre() << "a " << relacion->getNombre() << " por la restricción de cardinalidad." << std::endl;
	}
	bitacora.close();

}

void ControladorRelaciones::eliminarRelacion(std::string nombreRelacion, EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	Relacion* relacion = this->getRelacion(nombreRelacion);
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

std::vector<EntidadAbstracta*>* ControladorRelaciones::getElementos(std::string nombreRelacion, EntidadAbstracta* llave)
{
	Relacion* relacion = this->getRelacion(nombreRelacion);
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->first == llave)
			vector->push_back(itr->second);
	}
	return vector;
}

std::vector<EntidadAbstracta*>* ControladorRelaciones::getLlaves(std::string nombreRelacion, EntidadAbstracta* elemento)
{
	Relacion* relacion = this->getRelacion(nombreRelacion);
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = relacion->getRelacion()->begin(); itr != relacion->getRelacion()->end(); itr++) {
		if (itr->second == elemento)
			vector->push_back(itr->first);
	}
	return vector;
}
