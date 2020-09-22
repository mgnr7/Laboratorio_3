#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#include "Cmpnte_Proyecto.h"

class Actividad_Grupo : public Cmpnte_Proyecto
{
public:
	Actividad_Grupo();
	virtual ~Actividad_Grupo();

	void setPadre(Cmpnte_Proyecto* p) override;
	Cmpnte_Proyecto* getPadre() override;

	void agregar(Cmpnte_Proyecto* actividad) override;

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

	void eliminarSubActividad(string nombre) override;

private:
	unordered_map< string, string > atributos;
	vector < Cmpnte_Proyecto* > actividades;

};