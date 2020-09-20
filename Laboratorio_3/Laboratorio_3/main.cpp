// Laboratorio_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Proyecto.h"
#include "SerializadorAbstracto.h"

void Serializar(Proyecto& p, SerializadorAbstracto& s) 
{
	vector< pair< string, string > > vectorValores;
	vector < Cmpnte_Proyecto* >::iterator tareaIterator;

	tareaIterator = p.tareas.begin();

	s.inicioObjeto((*tareaIterator)->getNombre());

	for (tareaIterator = p.tareas.begin()+1; tareaIterator != p.tareas.end(); tareaIterator++)
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


int main()
{

}

