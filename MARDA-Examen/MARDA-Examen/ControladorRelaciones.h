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
	std::ofstream bitacora;
	Relacion* getRelacion(std::string nombre);
public:
	ControladorRelaciones();
	~ControladorRelaciones();
	void crearRelacion(std::string nombre, unsigned int cardPrimero, unsigned int cardSegundo);
	void eliminarRelacion(std::string nombre);
	void modificarRelacion(std::string nombre);
	void agregarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);
	void eliminarRelacion(Relacion* relacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);

	//Para las busquedas
	std::vector<EntidadAbstracta*>* getElementos(Relacion* relacion, EntidadAbstracta* llave);
	std::vector<EntidadAbstracta*>* getLlaves(Relacion* relacion, EntidadAbstracta* elemento);
};

