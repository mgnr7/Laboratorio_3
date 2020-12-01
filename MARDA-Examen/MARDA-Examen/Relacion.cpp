#include "Relacion.h"

int Relacion::contarLlaves(EntidadAbstracta* elemento)
{
	int cantidad = 0;
	for (auto itr = this->relacion->begin(); itr != this->relacion->end(); itr++) {
		if (itr->second == elemento)
			cantidad++;
	}
	return cantidad;
}

Relacion::Relacion(std::string nombreRelacion, unsigned int cardPrimero, unsigned int cardSegundo)
{
	this->nombre = nombreRelacion;
	this->cardPrimero = cardPrimero;
	this->cardSegundo = cardSegundo;
	this->relacion = new Mapa();

}

Relacion::~Relacion()
{
	delete relacion;
}

void Relacion::agregarRelacion(EntidadAbstracta* llave, EntidadAbstracta* elemento)
{
	//restriccion de las cardinalidades
	if (relacion->count(llave) < this->cardSegundo && this->contarLlaves(elemento) < this->cardPrimero) {
		this->relacion->insert(std::pair<EntidadAbstracta*, EntidadAbstracta*>(llave, elemento));
	}
	else {
		std::cerr << "No se pudo agregar la relacion ya que no cumple la restricción de la cardinalidad" << std::endl;
	}
}

void Relacion::eliminarRelacion(EntidadAbstracta* llave, EntidadAbstracta* elemento)
{

	for (auto itr = this->relacion->begin(); itr != this->relacion->end(); itr++) {
		if (itr->first == llave && itr->second == elemento) {
			this->relacion->erase(itr);
			break;
		}
	}
}

std::vector<EntidadAbstracta*>* Relacion::getElementos(EntidadAbstracta* llave)
{
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = this->relacion->begin(); itr != this->relacion->end(); itr++) {
		if (itr->first == llave)
			vector->push_back(itr->second);
	}
	return vector;
}

std::vector<EntidadAbstracta*>* Relacion::getLlaves(EntidadAbstracta* elemento)
{
	std::vector<EntidadAbstracta*>* vector = new std::vector<EntidadAbstracta*>();
	for (auto itr = this->relacion->begin(); itr != this->relacion->end(); itr++) {
		if (itr->second == elemento)
			vector->push_back(itr->first);
	}
	return vector;
}
