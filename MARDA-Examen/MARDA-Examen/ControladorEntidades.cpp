#include "ControladorEntidades.h"

void* ControladorEntidades::getEntidad(std::string nombre)
{
	void* resultado;
	for (auto itr = this->vectorEntidades.begin(); itr != this->vectorEntidades.end(); itr++) {
		if ((*itr)->getNombre() == nombre)
			resultado = static_cast<void*>(*itr);
		break;
	}
	return resultado;
}

ControladorEntidades::ControladorEntidades()
{
}

ControladorEntidades::~ControladorEntidades()
{
	this->vectorEntidades.clear();
}

void ControladorEntidades::crearEntidadSimple(std::string nombreEntidad)
{
	this->vectorEntidades.push_back(new EntidadSimple(nombreEntidad));
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se creó la entidad simple " << nombreEntidad << std::endl;
	bitacora.close();
}

void ControladorEntidades::crearEntidadCompuesta(std::string nombreEntidad)
{

	this->vectorEntidades.push_back(new EntidadCompuesta(nombreEntidad));
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se creó la entidad compuesta " << nombreEntidad << std::endl;
	bitacora.close();
}

void ControladorEntidades::modificarEntidad(std::string nombreEntidad, std::string nuevoNombreEntidad)
{
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se modificó el nombre de la entidad  " << nombreEntidad << " a  " << nuevoNombreEntidad << std::endl;
	bitacora.close();
}

void ControladorEntidades::agregarPropiedad(std::string nombreEntidad, std::string nombrePropiedad, std::string tipoPropiedad, std::string valorPropiedad)
{
	
	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se creó la propiedad  " << nombrePropiedad  <<" a la entidad "<< nombreEntidad << std::endl;
	bitacora.close();
}

void ControladorEntidades::eliminarPropiedad(std::string nombreEntidad, std::string nombrePropiedad)
{

	bitacora.open("Bitacora.txt", ios::app | ios::out);
	bitacora << "Se eliminó la propiedad  " << nombrePropiedad << " de la entidad " << nombreEntidad << std::endl;
	bitacora.close();
}
