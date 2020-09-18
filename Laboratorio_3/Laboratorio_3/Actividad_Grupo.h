#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Grupo : public Cmpnte_Proyecto
{
public:
	Actividad_Grupo();
	virtual ~Actividad_Grupo();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

	void agregar(Cmpnte_Proyecto* actividad);

	void eliminar() override;

	void setNombre(string n) override;
	string getNombre() override;

	void setResponsable(string r) override;
	string getResponsable() override;

	void setDescripcion(string d) override;
	string getDescripcion() override;

	void setFechaInicio(string f) override;
	string getFechaInicio() override;

	void setFechaFinal(string f) override;
	string getFechaFinal() override;

	void eliminarSubActividad(string nombre);

private:

	string responsable;

	string nombre;
	//Se asume que el formato es YYYY-MM-DD
	string fecha_plan_ini;
	string fecha_plan_fin;

	string descripcion;

	vector < Cmpnte_Proyecto* > actividades;

};