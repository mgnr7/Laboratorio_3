#pragma once
#include <string>
#include "Propiedad.h"
#include <vector>

using namespace std;

class EntidadAbstracta
{
protected:
	string nombre;
	vector< Propiedad* > propiedades;

public:

	virtual void setNombre(string nombre) = 0;
	virtual string getNombre() = 0;
	virtual void agregarPropiedad(Propiedad* p) = 0;
	virtual void eliminarPropiedad(string nombrePropiedad) = 0;
	virtual void modificarPropiedadNombre(string nombrePropiedad, string nuevoNombre) = 0;
	virtual void modificarPropiedadTipo(string nombrePropiedad, string nuevoTipo) = 0;
	virtual void modificarPropiedadValor(string nombrePropiedad, string nuevoValor) = 0;

};