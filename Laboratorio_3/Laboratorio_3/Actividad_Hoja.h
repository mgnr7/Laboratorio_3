#pragma once
#include <string>
#include <unordered_map>
using namespace std;

#include "Cmpnte_Proyecto.h"
#include "Actividad_Grupo.h"

class Actividad_Hoja : public Cmpnte_Proyecto
{
public:
	Actividad_Hoja();
	virtual ~Actividad_Hoja();

	void setPadre(Cmpnte_Proyecto* p) override;
	Cmpnte_Proyecto* getPadre() override;

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

	void eliminarSubActividad(string nombre) override;
	void agregar(Cmpnte_Proyecto* actividad) override;

	void obtAtributos(vector< pair< string, string > >& vectorValores) override;

private:
	unordered_map< string, string > atributos;
};
