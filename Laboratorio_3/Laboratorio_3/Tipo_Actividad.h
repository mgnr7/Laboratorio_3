#pragma once
#include <string>
#include <iostream>
class Tipo_Actividad
{
public:
	Tipo_Actividad(std::string nombre);
	~Tipo_Actividad();
	void setNombre(std::string nombre);
	std::string getNombre();
	friend std::ostream& operator<<(std::ostream& os, const Tipo_Actividad& ta);

private:
	std::string nombre;
};