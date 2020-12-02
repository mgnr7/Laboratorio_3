#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "EntidadAbstracta.h"

using namespace std;

/*Contiene un vector con los datos que se leen del archivo JSON que representa la Base de Datos*/
class Datos 
{
private:
	vector< EntidadAbstracta* > datos;

public:
	Datos();
	~Datos();

	void leerArchivoYcargarDatos(string nombreArchivo);


};