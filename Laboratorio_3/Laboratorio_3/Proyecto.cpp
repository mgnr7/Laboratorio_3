#include "Proyecto.h"

Proyecto::Proyecto()
{
	estructuraActividades = nullptr;
}

Proyecto::~Proyecto()
{
	tareas.clear();
	delete estructuraActividades;
}

std::vector<std::string>* Proyecto::CrearEstructura(Fabrica_Proyecto* fp)
{
	estructuraActividades = fp->CrearEstructura();
	//Cmpnte_Proyecto* raiz = fp->CrearActividad();
}
