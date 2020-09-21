#pragma once
#include "Proyecto.h"
#include "Cmpnte_Proyecto.h"
#define Estructura_Act std::vector<std::string>

class Fabrica_Proyecto
{

public:
	virtual Estructura_Act* CrearEstructura() = 0;
	virtual Cmpnte_Proyecto* CrearActividad(/*Cmpnte_Proyecto* padre = nullptr*/) = 0;
};

