#pragma once
#include <string>
#include <vector>
#include "Tipo_Actividad.h"
#include <iostream>

using namespace std;

class Tipo
{
public:
	Tipo();
	~Tipo();

	void set_Tipo_Sub_Actividad(Tipo* subAct);
	Tipo* tipo_sub_Actividad();

	void setNombre(string n);
	string getNombre();

	void seCantNiveles(int c);
	int getCantNiveles();

	void agregarNivel(string nombreActividad);
	void eliminarNivel();
	Tipo_Actividad* operator[](int i);
	Tipo_Actividad* siguienteActividad(Tipo_Actividad* actividadActual);
	int getTamano();

	void imprimirEstructura();
	friend std::ostream& operator<<(std::ostream& os, const Tipo& tp);



private:
	int cant_Niveles;
	string nombre;
	Tipo* sub_Actividad;
	vector<Tipo_Actividad*> estructura;
};