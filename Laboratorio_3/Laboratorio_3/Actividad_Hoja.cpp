#include "Actividad_Hoja.h"

Actividad_Hoja::Actividad_Hoja()
{
	responsable = "Jefe";
	nombre = "";
	fecha_plan_ini = "2020-09-18";
	fecha_plan_fin = "2020-09-27";
}

Actividad_Hoja::~Actividad_Hoja()
{
	delete this->padre;
}

void Actividad_Hoja::setPadre(Actividad_Grupo* p)
{
	this->padre = p;
}

Actividad_Grupo* Actividad_Hoja::getPadre()
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