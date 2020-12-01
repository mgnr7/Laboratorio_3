#include "Propiedad.h"

Propiedad::Propiedad()
{
	this->nombre = "";
	this->tipo = "";
	this->valor = "";
}

Propiedad::Propiedad(string nombre, string tipo, string valor)
{
	this->nombre = nombre;
	this->tipo = tipo;
	this->valor = valor;
}

Propiedad::~Propiedad()
{
}

void Propiedad::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Propiedad::getNombre()
{
	return this->nombre;
}

void Propiedad::setTipo(string tipo)
{
	this->tipo = tipo;
}

string Propiedad::getTipo()
{
	return this->tipo;
}

void Propiedad::setValor(string valor)
{
	this->valor = valor;
}

string Propiedad::getValor()
{
	return this->valor;
}
