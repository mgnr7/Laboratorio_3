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

std::string Relacion::getNombre()
{
	return this->nombre;
}

Relacion::Mapa* Relacion::getRelacion()
{
	return this->relacion;
}

int Relacion::getCardPrimero()
{
	return this->cardPrimero;
}

int Relacion::getCardSegundo()
{
	return this->cardSegundo;
}

void Relacion::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

void Relacion::setRelacion(Mapa* relacion)
{
	this->relacion = relacion;
}

void Relacion::setCardPrimero(int cardPrimero)
{
	this->cardPrimero = cardPrimero;
}

void Relacion::setCardSegundo(int cardSegundo)
{
	this->cardSegundo = cardSegundo;
}


