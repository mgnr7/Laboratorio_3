#include "Tipo.h"

Tipo::Tipo()
{
	cant_Niveles = 0;
	sub_Actividad = nullptr;
}

Tipo::~Tipo()
{
}

void Tipo::set_Tipo_Sub_Actividad(Tipo* subAct)
{
	sub_Actividad = subAct;
}

Tipo* Tipo::tipo_sub_Actividad()
{
	return sub_Actividad;
}

void Tipo::setNombre(string n)
{
	nombre = n;
}

string Tipo::getNombre()
{
	return nombre;
}

void Tipo::seCantNiveles(int c)
{
	cant_Niveles = c;
}

int Tipo::getCantNiveles()
{
	return cant_Niveles;
}
