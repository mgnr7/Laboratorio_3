#include "Controlador_Tipo.h"
 Controlador_Tipo::Controlador_Tipo()
{
}

Controlador_Tipo::~Controlador_Tipo()
{
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		delete* itr;
	}
	tiposAlmacenados.clear();
}

Tipo* Controlador_Tipo::buscarTipo(std::string nombreTipo) {
	Tipo* tipo = nullptr;
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombreTipo) {
			tipo = *itr;
			break;
		}
	}
	return tipo;
}

Tipo* Controlador_Tipo::ultimaActividad(std::string nombreTipo)
{
	return nullptr;
}

void Controlador_Tipo::crearTipo(std::string nombreTipo) {
	if (buscarTipo(nombreTipo) == nullptr) {
		Tipo* tipo = new Tipo();
		tipo->setNombre(nombreTipo);
		tiposAlmacenados.push_back(tipo);

	}
	else {
		std::cout << "No se pueden repetir nombres de tipos de proyectos." << std::endl;
	}
}

void Controlador_Tipo::eliminarTipo(std::string nombreTipo) {
	for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); itr++) {
		if ((*itr)->getNombre() == nombreTipo) {
			tiposAlmacenados.erase(itr);
			break;
		}
	}
}

void Controlador_Tipo::modificarTipo(std::string nombreTipo) {
	Tipo* tipo = buscarTipo(nombreTipo);
	//Modificar el tipo
}

void Controlador_Tipo::agregarNivelTipo(std::string nombreTipo, std::string nombreActividadNueva)
{
	Tipo* tipo = buscarTipo(nombreTipo);
	if (tipo != nullptr) {
		//Tipo* subtipo = new Tipo();
		//subtipo->setNombre(nombreActividadNueva);
		//tipo->set_Tipo_Sub_Actividad(subtipo);
		tipo->agregarNivel(nombreActividadNueva);
	}
	else {
		std::cout << "El tipo especificado no existe." << std::endl;
	}
}

void Controlador_Tipo::eliminarNivelTipo(std::string nombreTipo)
{
	Tipo* tipo = buscarTipo(nombreTipo);
	if (tipo != nullptr) {
		tipo->eliminarNivel();
	}

}

void Controlador_Tipo::consultarTipo(std::string nombreTipo) {
	cout << endl;
	Tipo* tipo = buscarTipo(nombreTipo);
	if (tipo != nullptr) {
		tipo->imprimirEstructura();
	}
	else {
		std::cout << "El tipo de proyecto \""<<nombreTipo<< "\" no existe." << std::endl;
	}
}

void Controlador_Tipo::listarTipos()
{
	cout << endl;
	if (tiposAlmacenados.size() > 0) {
		cout << "Actualmente los tipos almacenados son:" << endl;
		for (auto itr = tiposAlmacenados.begin(); itr != tiposAlmacenados.end(); ++itr) {
			cout << **itr << endl;
		}
	}
	else {
		cout << "No hay ningún tipo de proyecto almacenado." << endl;
	}
}

Tipo* Controlador_Tipo::obtenerTipo(std::string nombreTipo)
{
	return buscarTipo(nombreTipo);
}
