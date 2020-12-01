#include "EntidadCompuesta.h"

EntidadCompuesta::EntidadCompuesta()
{
	this->nombre = "";
}

EntidadCompuesta::EntidadCompuesta(string nombre) 
{
	this->nombre = nombre;
}

EntidadCompuesta::~EntidadCompuesta()
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		delete* itr;
	}
	this->propiedades.clear();

	for (auto itr = this->entidades.begin(); itr != this->entidades.end(); itr++) {
		delete* itr;
	}
	this->entidades.clear();

}

void EntidadCompuesta::setNombre(string nombre)
{
	this->nombre = nombre;
}

string EntidadCompuesta::getNombre()
{
	return this->nombre;
}

void EntidadCompuesta::agregarPropiedad(Propiedad* p)
{
	this->propiedades.push_back(p);
}

void EntidadCompuesta::eliminarPropiedad(string nombrePropiedad)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			this->propiedades.erase(itr);
			itr = this->propiedades.end();
		}
	}
}

void EntidadCompuesta::modificarPropiedadNombre(string nombrePropiedad, string nuevoNombre)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setNombre(nuevoNombre);
			itr = this->propiedades.end();
		}
	}
}

void EntidadCompuesta::modificarPropiedadTipo(string nombrePropiedad, string nuevoTipo)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setTipo(nuevoTipo);
			itr = this->propiedades.end();
		}
	}
}

void EntidadCompuesta::modificarPropiedadValor(string nombrePropiedad, string nuevoValor)
{
	for (auto itr = this->propiedades.begin(); itr != this->propiedades.end(); itr++) {
		if ((*itr)->getNombre() == nombrePropiedad)
		{
			(*itr)->setValor(nuevoValor);
			itr = this->propiedades.end();
		}
	}
}

void EntidadCompuesta::agregarEntidad(EntidadAbstracta* entidad)
{
	this->entidades.push_back(entidad);
}

void EntidadCompuesta::eliminarEntidad(string nombre)
{
	for (auto itr = this->entidades.begin(); itr != this->entidades.end(); itr++) {
		if ((*itr)->getNombre() == nombre)
		{
			this->entidades.erase(itr);
			itr = this->entidades.end();
		}
	}
}
