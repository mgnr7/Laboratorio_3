#pragma once
#include <string>

using namespace std;

class Actividad_Grupo;

class Cmpnte_Proyecto
{
protected:
	
	Cmpnte_Proyecto* padre;
	
	string responsable;
	string nombre;
	//Se asume que el formato es YYYY-MM-DD
	string fecha_plan_ini;
	string fecha_plan_fin;
	string descripcion;

public:

	virtual void setPadre(Cmpnte_Proyecto* p) = 0;
	virtual Cmpnte_Proyecto* getPadre() = 0;

	virtual void eliminar() = 0;

	virtual void setNombre(string n) = 0;
	virtual string getNombre() = 0;

	virtual void setResponsable(string r) = 0;
	virtual string getResponsable() = 0;

	virtual void setDescripcion(string d) = 0;
	virtual string getDescripcion() = 0;

	virtual void setFechaInicio(string f) = 0;
	virtual string getFechaInicio() = 0;

	virtual void setFechaFinal(string f) = 0;
	virtual string getFechaFinal() = 0;

	virtual void eliminarSubActividad(string nombre) = 0;
	virtual void agregar(Cmpnte_Proyecto* actividad) = 0;

	virtual void obtAtributos(vector< pair< string, string > >& vectorValores) = 0;

};
