#pragma once
#include "EntidadAbstracta.h"

class EntidadCompuesta : public EntidadAbstracta
{
private:
	vector<EntidadAbstracta* > entidades;

public:

	EntidadCompuesta();
	EntidadCompuesta(string nombre);
	~EntidadCompuesta();

	void setNombre(string nombre) override;
	string getNombre() override;
	void agregarPropiedad(Propiedad* p) override;
	void eliminarPropiedad(string nombrePropiedad) override;
	void modificarPropiedadNombre(string nombrePropiedad, string nuevoNombre) override;
	void modificarPropiedadTipo(string nombrePropiedad, string nuevoTipo) override;
	void modificarPropiedadValor(string nombrePropiedad, string nuevoValor) override;

	void agregarEntidad(EntidadAbstracta* entidad);
	void eliminarEntidad(string nombre);
};