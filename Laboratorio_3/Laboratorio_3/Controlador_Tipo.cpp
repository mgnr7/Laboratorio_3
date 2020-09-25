#include "Controlador_Tipo.h"
inline Controlador_Tipo::Controlador_Tipo()
{
}

inline Controlador_Tipo::~Controlador_Tipo()
{
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		delete* itr;
	}
	tiposAlmacenados.clear();
}

Tipo* Controlador_Tipo::buscarTipo(std::string nombre) {
	Tipo* tipo = nullptr;
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombre) {
			tipo = *itr;
			break;
		}
	}
	return tipo;
}

void Controlador_Tipo::crearTipo(std::string nombre) {
	if (buscarTipo(nombre) == nullptr) {
		Tipo* tipo = new Tipo();
		tipo->setNombre(nombre);
		tiposAlmacenados.push_back(tipo);

	}
	else {
		std::cerr << "No se pueden repetir nombres de tipos de proyectos." << std::endl;
	}
}

void Controlador_Tipo::eliminarTipo(std::string nombre) {
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombre) {
			tiposAlmacenados.erase(itr);
			break;
		}
	}
}

void Controlador_Tipo::modificarTipo(std::string nombre) {
	Tipo* tipo = buscarTipo(nombre);
	//Modificar el tipo
}

Tipo* Controlador_Tipo::consultarTipo(std::string nombre) {
	Tipo* tipo = buscarTipo(nombre);
	if (tipo == nullptr) {
		std::cout << "El tipo especificado no existe." << std::endl;
	}
	return tipo;
}