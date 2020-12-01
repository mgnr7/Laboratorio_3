#pragma once
#include "EntidadAbstracta.h"

class EntidadSimple : public EntidadAbstracta 
{
public:

	EntidadSimple();
	EntidadSimple(string nombre);
	~EntidadSimple();

	void agregarPropiedad(Propiedad* p) override;
	void eliminarPropiedad(string nombrePropiedad) override;
	void modificarPropiedadNombre(string nombrePropiedad, string nuevoNombre) override;
	void modificarPropiedadTipo(string nombrePropiedad, string nuevoTipo) override;
	void modificarPropiedadValor(string nombrePropiedad, string nuevoValor) override;
};