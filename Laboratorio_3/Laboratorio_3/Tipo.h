#pragma once
#include <string>
#include <vector>

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



private:
	int cant_Niveles;
	string nombre;
	Tipo* sub_Actividad;

	vector<string> actvidades;
};