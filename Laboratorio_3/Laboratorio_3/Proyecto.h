#pragma once
#include <vector>
#include "Cmpnte_Proyecto.h"
#include "Tipo.h"
#include <string>

using namespace std;

class Proyecto
{
public:
	Proyecto();
	~Proyecto();
	/*Para poder iterar el vector de tareas*/
	vector< Cmpnte_Proyecto* >::iterator tareas_begin();
	vector< Cmpnte_Proyecto* >::iterator tareas_end();

	void setRaiz(Cmpnte_Proyecto* raiz);
	Cmpnte_Proyecto* getRaiz();

	void setNombre(string nombre);
	string getNombre();


private:
	vector <Cmpnte_Proyecto*> tareas;
	Cmpnte_Proyecto* tareaRaiz;
	Tipo* tipoProyecto;
	string nombre;
};

