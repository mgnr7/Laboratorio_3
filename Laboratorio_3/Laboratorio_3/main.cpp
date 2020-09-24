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

/*Debe retornar un proyecto*/
void crear_Proyecto() 
{
	bool ejecutar = true;
	int cnt_niveles = 0;

	while (ejecutar) 
	{
		cout << "Digite la cantidad de niveles del proyecto: ";
		cin >> cnt_niveles;
		if (cnt_niveles <= 0) 
		{
			cout << "La cantidad debe ser mayor a 0" << endl;
		}
		else 
		{
			/*Crear tipo con "cnt_niveles" niveles*/
			/*Crear actiidadGrupo para la raiz*/
			
			vector<int> cnt_subAct;
			int input = 0;

			for (int n = 0; n < cnt_niveles; n++) 
			{
				cout << "Digite la cantidad de sub actividades para el nivel " + to_string(n+1) + ": ";
				cin >> input;

				cnt_subAct.push_back(input);

			}

			for (int i = 0; i < cnt_subAct.size(); i++)
			{
				/*Crear las actividades para cada nivel*/
			}

			ejecutar = false;
		}
	}


	

}


int main()
{
	crear_Proyecto();
}

