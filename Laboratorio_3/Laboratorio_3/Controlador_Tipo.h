#pragma once
#include "Tipo.h"
#include <vector>
#include <string>
#include <iostream>
#include "Cmpnte_Proyecto.h"
//Representa el controlador que gestiona los tipos de proyectos
class Controlador_Tipo{
public:
	Controlador_Tipo();
	~Controlador_Tipo();
	void crearTipo(std::string nombreTipo);//el nombre es el identificador del tipo para el usuario
	void eliminarTipo(std::string nombreTipo);
	void modificarTipo(std::string nombreTipo);
	void agregarNivelTipo(std::string nombreTipo, std::string nombreActividadNueva);//agrega una actividad al final de la estructura del tipo
	void eliminarNivelTipo(std::string nombreTipo);//elimina la ultima actividad de la estructura del tipo

	void consultarTipo(std::string nombreTipo);
	void listarTipos();//Despliega todos los tipos de proyectos que esten almacenados en le controlador



private:
	Tipo* buscarTipo(std::string nombre);
	Tipo* ultimaActividad(std::string nombreTipo);
	std::vector<Tipo*> tiposAlmacenados; // Guarda las raices de los tipos de proyectos
};

