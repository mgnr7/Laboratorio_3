#include "Actividad_Hoja.h"

Actividad_Hoja::Actividad_Hoja() : atributos(5)
{
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

Actividad_Hoja::~Actividad_Hoja()
{
	delete this->padre;
}

void Actividad_Hoja::setPadre(Cmpnte_Proyecto* p)
{
	this->padre = p;
}

Cmpnte_Proyecto* Actividad_Hoja::getPadre()
{
	return padre;
}

void Actividad_Hoja::eliminar()
{
	if (padre != NULL)
	{
		padre->eliminarSubActividad(nombre);
	}
}

void Actividad_Hoja::setNombre(string n)
{
	nombre = n;
}

string Actividad_Hoja::getNombre()
{
	return nombre;
}

void Actividad_Hoja::setResponsable(string r)
{
	responsable = r;
}

string Actividad_Hoja::getResponsable()
{
	return responsable;
}

void Actividad_Hoja::setDescripcion(string d)
{
	descripcion = d;
}

string Actividad_Hoja::getDescripcion()
{
	return descripcion;
}

void Actividad_Hoja::setFechaInicio(string f)
{
	fecha_plan_ini = f;
}

string Actividad_Hoja::getFechaInicio()
{
	return fecha_plan_ini;
}

void Actividad_Hoja::setFechaFinal(string f)
{
	fecha_plan_fin = f;
}

string Actividad_Hoja::getFechaFinal()
{
	return fecha_plan_fin;
}

void Actividad_Hoja::eliminarSubActividad(string nombre)
{
}

void Actividad_Hoja::agregar(Cmpnte_Proyecto* actividad)
{
}

void Actividad_Hoja::obtAtributos(vector<pair<string, string>>& vectorValores)
{
	vectorValores.resize(atributos.size());

	int j = 0;
	for (auto i : atributos)
	{
		vectorValores[j] = i;
		j++;
	}
}
