#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "EntidadAbstracta.h"
#include"Relacion.h"
#include <fstream>
class ControladorRelaciones
{
private:
	std::vector<Relacion*> vectorRelaciones;
	ofstream bitacora;
public:
	ControladorRelaciones();
	~ControladorRelaciones();
	void agregarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);
	void eliminarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);

	//Para las busquedas
	std::vector<EntidadAbstracta*>* getElementos(Relacion* relacion, EntidadAbstracta* llave);
	std::vector<EntidadAbstracta*>* getLlaves(Relacion* relacion, EntidadAbstracta* elemento);
};

