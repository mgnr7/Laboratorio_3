#include "Tipo.h"

Tipo::Tipo()
{
	cant_Niveles = 0;
	sub_Actividad = nullptr;
}

Tipo::~Tipo()
{
	estructura.clear();
	delete sub_Actividad;
}

void Tipo::set_Tipo_Sub_Actividad(Tipo* subAct)
{
	sub_Actividad = subAct;
}

Tipo* Tipo::tipo_sub_Actividad()
{
	return sub_Actividad;
}

void Tipo::setNombre(string n)
{
	nombre = n;
}

string Tipo::getNombre()
{
	return nombre;
}

void Tipo::seCantNiveles(int c)
{
	cant_Niveles = c;
}

int Tipo::getCantNiveles()
{
	return cant_Niveles;
}

void Tipo::agregarNivel(string nombreActividad)
{
	estructura.push_back(new Tipo_Actividad(nombreActividad));
	//imprimirEstructura();
}

void Tipo::eliminarNivel()
{
	if (estructura.size() > 0) {
		estructura.pop_back();
	//imprimirEstructura();
	}
	else {
		std::cout << "La estructura de este tipo no tiene niveles para borrar." << endl;
	}
}

Tipo_Actividad* Tipo::operator[](int i)
{
	if (i < estructura.size()) {
		return estructura[i];
	}
	else {
		return nullptr;
	}

}

void Tipo::imprimirEstructura()
{
	cout << "Estructura del tipo de proyecto " << this->getNombre() << ":" << endl;
	if (estructura.size() > 0) {
		for (auto itr = estructura.begin(); itr != estructura.end(); ++itr) {
			if (itr != estructura.begin()) {
				cout << "-->";
			}
			cout << **itr;
		}
		cout << endl;
	}
	else {
		cout << "El tipo de proyecto " << this->getNombre() << " no tiene estructura." << endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Tipo& tp)
{
	os << tp.nombre;
	return os;
}
