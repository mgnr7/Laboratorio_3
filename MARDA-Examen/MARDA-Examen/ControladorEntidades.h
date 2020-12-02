#pragma once
#include<vector>
#include<iostream>
#include<string>
#include "EntidadAbstracta.h"
#include "EntidadSimple.h"
#include "EntidadCompuesta.h"
#include"Relacion.h"
#include <fstream>
class ControladorEntidades
{
private:
	std::ofstream bitacora;
	std::vector<EntidadAbstracta*> vectorEntidades;
	void* getEntidad(std::string nombre);
public:
	ControladorEntidades();
	~ControladorEntidades();
	void crearEntidadSimple(std::string nombreEntidad);
	void crearEntidadCompuesta(std::string nombreEntidad);
	void modificarEntidad(std::string nombreEntidad, std::string nuevoNombreEntidad);
	void agregarPropiedad(std::string nombreEntidad, std::string nombrePropiedad, std::string tipoPropiedad, std::string valorPropiedad);
	void eliminarPropiedad(std::string nombreEntidad, std::string nombrePropiedad);

};

