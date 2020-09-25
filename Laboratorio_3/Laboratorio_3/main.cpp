// Laboratorio_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Proyecto.h"
#include "SerializadorAbstracto.h"
#include "Cmpnte_Proyecto.h"
#include "Actividad_Hoja.h"
#include "Actividad_Grupo.h"
#include "Tipo.h"

void Serializar(Proyecto& p, SerializadorAbstracto& s) 
{
	vector< pair< string, string > > vectorValores;
	vector < Cmpnte_Proyecto* >::iterator tareaIterator;

	tareaIterator = p.tareas_begin();

	s.inicioObjeto((*tareaIterator)->getNombre());

	for (tareaIterator = p.tareas_begin()+1; tareaIterator != p.tareas_end(); tareaIterator++)
	{
		(*tareaIterator)->obtAtributos(vectorValores);
		
		for (auto v : vectorValores) 
		{
			s.serializarString(v);
		}

		vectorValores.clear();
	}

	cout << s.obtSerializacion() << endl;
}


void crear_proyecto(Tipo* tipo_proyecto) 
{
	bool ejecutar = true;

	while (ejecutar) 
	{
	



	}
}


int main()
{
	
}

