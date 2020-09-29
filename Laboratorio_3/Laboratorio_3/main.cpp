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
#include "Controlador_Tipo.h"

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


Proyecto* crear_proyecto(Tipo* tipo_proyecto)  //Metodo Fabricante
{
	bool ejecutar = true;
	string respuesta;
	int nivelActual;
		
	Proyecto* proyectoNuevo = new Proyecto();
	cout << "Digite el nombre del nuevo proyecto de tipo " << tipo_proyecto->getNombre() << ":" << endl;
	cin >> respuesta;
	proyectoNuevo->setNombre(respuesta);

	Actividad_Grupo* raizProyecto = new Actividad_Grupo();
	raizProyecto->setTipo((*tipo_proyecto)[0]); // Genera la raiz del proyecto basado en el primer componente de la estructura del tipo (i.e "Proyecto")
	proyectoNuevo->setRaiz(new Actividad_Grupo()); 


	return proyectoNuevo;
}


int main()
{
	Controlador_Tipo controlador;
	vector<Proyecto*> proyectosAlmacenados;

	//Crea el tipo de proyecto simple
	controlador.crearTipo("Simple"); 
	controlador.agregarNivelTipo("Simple", "Proyecto");
	controlador.agregarNivelTipo("Simple", "Tarea");
	//controlador.consultarTipo("Simple");

	//Crea el tipo de proyecto complejo
	controlador.crearTipo("Complejo");
	controlador.agregarNivelTipo("Complejo", "Proyecto");
	controlador.agregarNivelTipo("Complejo", "Fase");
	controlador.agregarNivelTipo("Complejo", "Tarea");
	//controlador.consultarTipo("Complejo");


	// Parte donde interactua con el usuario
	bool ejecutar = true;
	int seleccion;
	string respuesta;
	
	while (ejecutar) { 
		controlador.listarTipos();
		cout << "Escriba el nombre del tipo del proyecto nuevo: ";
		cin >> respuesta;
		Tipo* tipo = controlador.obtenerTipo(respuesta);
		if (tipo != nullptr)
		{
			proyectosAlmacenados.push_back(crear_proyecto(tipo));
			ejecutar = false;
		}
		else {
			cout << "El tipo escrito no existe." << endl;
		}
	
	}
	

}

