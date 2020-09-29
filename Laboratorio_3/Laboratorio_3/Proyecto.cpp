#include "Proyecto.h"

Proyecto::Proyecto()
{
}

Proyecto::~Proyecto()
{
	tareas.clear();
}

vector<Cmpnte_Proyecto*>::iterator Proyecto::tareas_begin()
{
	return tareas.begin();
}

vector<Cmpnte_Proyecto*>::iterator Proyecto::tareas_end()
{
	return tareas.end();
}

void Proyecto::setRaiz(Cmpnte_Proyecto* raiz)
{
	this->tareaRaiz = raiz;
}

Cmpnte_Proyecto* Proyecto::getRaiz()
{
	return tareaRaiz;
}

void Proyecto::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Proyecto::getNombre()
{
	return this->nombre;
}

