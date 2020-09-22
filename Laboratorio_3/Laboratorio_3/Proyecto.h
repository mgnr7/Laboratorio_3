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
	/*Para poder iterar el vector de tareas*/
	vector< Cmpnte_Proyecto* >::iterator tareas_begin();
	vector< Cmpnte_Proyecto* >::iterator tareas_end();

	vector<string>* CrearEstructura(Fabrica_Proyecto* fp); //Define la estructura de las actividades, o en otras palabras, el tipo del proyecto.

private:
	vector <Cmpnte_Proyecto*> tareas;
	vector<string>* estructuraActividades; //Por ahora el tipo de actividad se maneja con string en vez de una clase por separado
};

