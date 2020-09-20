#include "Actividad_Grupo.h"

Actividad_Grupo::Actividad_Grupo()
{
	atributos(5);
	responsable = "Jefe";
	nombre = "";
	fecha_plan_ini = "2020-09-18";
	fecha_plan_fin = "2020-09-27";
	descripcion = "Descripción genérica";

	atributos["Nombre"] = nombre;
	atributos["Responsable"] = responsable;
	atributos["Fecha Inicio"] = fecha_plan_ini;
	atributos["Fecha Fin"] = fecha_plan_fin;
	atributos["Descripción"] = descripcion;
}

Actividad_Grupo::~Actividad_Grupo()
{
	delete this->padre;
}

void Actividad_Grupo::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

Actividad_Grupo* Actividad_Grupo::getPadre()
{
	return padre;
}

void Actividad_Grupo::agregar(Cmpnte_Proyecto* actividad)
{
	actividades.push_back(actividad);
	actividad->setPadre(this);
}

void Actividad_Grupo::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
}

void Actividad_Grupo::setNombre(string n)
{
	nombre = n;
}

string Actividad_Grupo::getNombre()
{
	return nombre;
}

void Actividad_Grupo::setResponsable(string r)
{
	responsable = r;
}

string Actividad_Grupo::getResponsable()
{
	return responsable;
}


void Actividad_Grupo::setDescripcion(string d)
{
	descripcion = d;
}

string Actividad_Grupo::getDescripcion()
{
	return descripcion;
}

void Actividad_Grupo::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

string Actividad_Grupo::getFechaInicio()
{
	return fecha_plan_ini;
}

void Actividad_Grupo::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

string Actividad_Grupo::getFechaFinal()
{
	return fecha_plan_fin;
}

void Actividad_Grupo::obtAtributos(vector<pair<string, string>>& vectorValores)
{
	vectorValores.resize(atributos.size());

	int j = 0;
	for (auto i : atributos)
	{
		vectorValores[j] = i;
		j++;
	}
}

void Actividad_Grupo::eliminarSubActividad(string nombre)
{
	vector < Cmpnte_Proyecto* >::iterator actIterator;
	for (actIterator = actividades.begin(); actIterator != actividades.end(); actIterator++)
	{
		if ((*actIterator)->getNombre().compare(nombre) == 0)
		{
			actividades.erase(actIterator);
			break;
		}
	}

}