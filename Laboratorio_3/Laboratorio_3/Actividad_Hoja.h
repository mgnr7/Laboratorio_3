#pragma once
#include <string>
using namespace std;

#include "Cmpnte_Proyecto.h"
#include "Actividad_Grupo.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja();
	virtual ~Actividad_Hoja();

	void setPadre(Actividad_Grupo* p) override;
	Actividad_Grupo* getPadre() override;

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

	void obtAtributos(vector< pair< string, string > >& vectorValores) override;

private:

	string responsable;

	string nombre;
	//Se asume que el formato es YYYY-MM-DD
	string fecha_plan_ini;
	string fecha_plan_fin;

	string descripcion;

};
