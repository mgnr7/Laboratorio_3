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
#include "Tipo_Actividad.h"
#include <queue>

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
	queue<Cmpnte_Proyecto*> colaArbol;
	bool ejecutar = true;
	string respuesta;
	int respuesta_int;
		
	Proyecto* proyectoNuevo = new Proyecto();
	cout << "Digite el nombre del nuevo proyecto de tipo " << tipo_proyecto->getNombre() << ":" << endl;
	cin >> respuesta;
	proyectoNuevo->setNombre(respuesta);

	//Primero le pide al usuario los detalles de la raiz del proyecto
	Actividad_Grupo* raizProyecto = new Actividad_Grupo();
	raizProyecto->setTipo((*tipo_proyecto)[0]); // Genera la raiz del proyecto basado en el primer componente de la estructura del tipo (i.e "Proyecto")
	cout << "Escriba un nombre para la actividad raiz: ";
	cin >> respuesta;
	raizProyecto->setNombre(respuesta);
	cout << "Escriba una descripción para la actividad raiz: ";
	cin >> respuesta;
	raizProyecto->setDescripcion(respuesta);
	proyectoNuevo->setRaiz(raizProyecto);

	colaArbol.push(raizProyecto);

	//Ahora el usuario pobla los siguientes niveles del arbol
	while (!colaArbol.empty()) {
		Cmpnte_Proyecto* componenteActual = colaArbol.front();
		Tipo_Actividad* tipoActividadActual = componenteActual->getTipo();
		Tipo_Actividad* tipoActividadSiguiente = tipo_proyecto->siguienteActividad(tipoActividadActual);
		Cmpnte_Proyecto* nuevoComponente;
		colaArbol.pop();

		cout << "¿Cuantas actividades de tipo '" << (tipo_proyecto->siguienteActividad(tipoActividadActual))->getNombre() << "' quiere crear para la actividad llamada '" << componenteActual->getNombre() << "'?:";
		cin >> respuesta;
		int contador = stoi(respuesta);
		for (int i = 0; i < contador; i++) {
			
			if (tipo_proyecto->siguienteActividad(tipoActividadSiguiente) != nullptr) { //Es para saber si la nueva actividad es una hoja o no
				nuevoComponente = new Actividad_Grupo();
				colaArbol.push(nuevoComponente);
			}
			else {
				nuevoComponente = new Actividad_Hoja();
			}
			nuevoComponente->setTipo(tipoActividadSiguiente);
			nuevoComponente->setPadre(componenteActual);

			cout << "Escriba un nombre para la nueva actividad de tipo '" << (tipo_proyecto->siguienteActividad(tipoActividadActual))->getNombre() << "':";
			cin >> respuesta;
			nuevoComponente->setNombre(respuesta);

			cout << "Escriba una descripción para la nueva actividad de tipo '" << (tipo_proyecto->siguienteActividad(tipoActividadActual))->getNombre() << "':";
			cin >> respuesta;
			nuevoComponente->setDescripcion(respuesta);

		}
	}


	//cout << proyectoNuevo->getRaiz()->getNombre();

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

