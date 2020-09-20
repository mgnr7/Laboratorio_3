#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class Actividad_Grupo;

class Cmpnte_Proyecto
{
protected:
	Actividad_Grupo* padre;
	unordered_map< string, string > atributos;

public:

	virtual void setPadre(Actividad_Grupo* p) = 0;
	virtual Actividad_Grupo* getPadre() = 0;

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

	virtual void obtAtributos(vector< pair< string, string > >& vectorValores) = 0;

};
