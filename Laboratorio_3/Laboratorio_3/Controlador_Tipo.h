#pragma once
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
	void crearTipo(std::string nombre);
	void eliminarTipo(std::string nombre);
	void modificarTipo(std::string nombre);
	void agregarActividad(std::string nombreTipo, std::string nombreActividadNueva);//agrega una actividad a la secuencia
	void eliminarActividad(std::string nombreTipo, std::string nombreActividad);//elimina una activdad de la secuencia

	Tipo* consultarTipo(std::string nombre);


private:
	Tipo* buscarTipo(std::string nombre);
	std::vector<Tipo*> tiposAlmacenados;
};

