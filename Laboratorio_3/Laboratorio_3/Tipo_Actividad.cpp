#include "Tipo_Actividad.h"

Tipo_Actividad::Tipo_Actividad(std::string nombre)
{
	this->setNombre(nombre);
}

Tipo_Actividad::~Tipo_Actividad()
{
}

inline void Tipo_Actividad::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

inline std::string Tipo_Actividad::getNombre()
{
	return this->nombre;
}

std::ostream& operator<<(std::ostream& os, const Tipo_Actividad& ta)
{
	os << ta.nombre;
	return os;
}
