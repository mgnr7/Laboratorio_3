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
	void modificarRelacion(std::string nombreRelacion, std::string nuevoNombreRelacion);
	void agregarRelacion(std::string nombreRelacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);
	void eliminarRelacion(std::string nombreRelacion, EntidadAbstracta* llave, EntidadAbstracta* elemento);

	//Para las busquedas
	std::vector<EntidadAbstracta*>* getElementos(std::string nombreRelacion, EntidadAbstracta* llave);
	std::vector<EntidadAbstracta*>* getLlaves(std::string nombreRelacion, EntidadAbstracta* elemento);
};

