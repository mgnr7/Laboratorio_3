#include "Fabrica_Proyecto_Simple.h"

Fabrica_Proyecto_Simple::Fabrica_Proyecto_Simple()
{
	estructura.push_back("Proyecto");
	estructura.push_back("Tarea");
}

Fabrica_Proyecto_Simple::~Fabrica_Proyecto_Simple()
{
	estructura.clear();
}

Estructura_Act* Fabrica_Proyecto_Simple::CrearEstructura()
{
	return &estructura;
}

Cmpnte_Proyecto* Fabrica_Proyecto_Simple::CrearActividad()
{
	return nullptr;
}
