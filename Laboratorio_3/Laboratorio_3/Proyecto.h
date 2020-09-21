#pragma once
#include <vector>
#include "Cmpnte_Proyecto.h"
#include "Fabrica_Proyecto.h"

using namespace std;

class Proyecto
{
public:
	Proyecto();
	~Proyecto();

	std::vector<std::string>* CrearEstructura(Fabrica_Proyecto* fp); //Define la estructura de las actividades, o en otras palabras, el tipo del proyecto.

private:
	vector <Cmpnte_Proyecto*> tareas;
	std::vector<std::string>* estructuraActividades; //Por ahora el tipo de actividad se maneja con string en vez de una clase por separado
};

