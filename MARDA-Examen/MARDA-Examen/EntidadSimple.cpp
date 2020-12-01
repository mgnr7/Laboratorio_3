#include "EntidadSimple.h"

EntidadSimple::EntidadSimple()
{
	this->nombre = "";
}

EntidadSimple::EntidadSimple(string nombre)
{
	this->nombre = nombre;
}

EntidadSimple::~EntidadSimple()
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		delete* itr;
	}
	this->propiedades.clear();
}

void EntidadSimple::setNombre(string nombre)
{
	this->nombre = nombre;
}

string EntidadSimple::getNombre()
{
	return this->nombre;
}

void EntidadSimple::agregarPropiedad(Propiedad* p)
{
	propiedades.push_back(p);
}

void EntidadSimple::eliminarPropiedad(string nombrePropiedad)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			this->propiedades.erase(itr);
			itr = this->propiedades.end();
		}
	}
}

void EntidadSimple::modificarPropiedadNombre(string nombrePropiedad, string nuevoNombre)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setNombre(nuevoNombre);
			itr = this->propiedades.end();
		}
	}
}

void EntidadSimple::modificarPropiedadTipo(string nombrePropiedad, string nuevoTipo)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setTipo(nuevoTipo);
			itr = this->propiedades.end();
		}
	}
}

void EntidadSimple::modificarPropiedadValor(string nombrePropiedad, string nuevoValor)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setValor(nuevoValor);
			itr = this->propiedades.end();
		}
	}
}
