#include "Fabrica_Proyecto_Complejo.h"

Fabrica_Proyecto_Complejo::Fabrica_Proyecto_Complejo()
{
	estructura.push_back("Proyecto");
	estructura.push_back("Fase");
	estructura.push_back("Tarea");
}

Fabrica_Proyecto_Complejo::~Fabrica_Proyecto_Complejo()
{
	estructura.clear();
}

Estructura_Act* Fabrica_Proyecto_Complejo::CrearEstructura()
{
	return &estructura;
}

Cmpnte_Proyecto* Fabrica_Proyecto_Complejo::CrearActividad()
{
	return nullptr;
}
