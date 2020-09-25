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

vector<Cmpnte_Proyecto*>::iterator Proyecto::tareas_begin()
{
	return tareas.begin();
}

vector<Cmpnte_Proyecto*>::iterator Proyecto::tareas_end()
{
	return tareas.end();
}

