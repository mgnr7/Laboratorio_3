#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Propiedad.h"
#include "EntidadAbstracta.h"
#include "Datos.h"

using namespace std;
/*Controlador con todas las operaciones y busquedas para la base de datos*/
class ControladorDatos 
{

public:
	ControladorDatos();
	~ControladorDatos();

	//Operaciones
	void agregarEntidad(Datos* data, EntidadAbstracta* entidad);
	void modificarNombreEntidad(Datos* data, string nombreEntidad, string nuevoNombre);
	void modificarPropiedadTipoEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoTipo);
	void modificarPropiedadValorEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoValor);
	void modificarPropiedadNombreEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoNombrePropiedad);
	void eliminarEntidad(Datos* data, string nombreEntidad);
	//Busquedas
	EntidadAbstracta* busquedaPorNombreEntidad(Datos* data, string nombre);
	vector< EntidadAbstracta* > busquedaPorTipoPropiedad(Datos* data, string tipo);
	vector< EntidadAbstracta* > busquedaPorValorPropiedad(Datos* data, string valor);
	vector< EntidadAbstracta* > busquedaPorNombrePropiedad(Datos* data, string nombrePr);


};