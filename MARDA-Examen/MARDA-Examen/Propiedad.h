#pragma once
#include <string>

using namespace std;

class Propiedad {
private:
	string nombre;
	string tipo;
	string valor;

public:
	Propiedad();
	Propiedad(string nombre, string tipo, string valor);
	~Propiedad();

	void setNombre(string nombre);
	string getNombre();

	void setTipo(string tipo);
	string getTipo();

	void setValor(string valor);
	string getValor();
};