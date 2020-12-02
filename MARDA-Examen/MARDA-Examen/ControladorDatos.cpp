#include "ControladorDatos.h"

ControladorDatos::ControladorDatos()
{
}

ControladorDatos::~ControladorDatos()
{
}

void ControladorDatos::agregarEntidad(Datos* data, EntidadAbstracta* entidad)
{
	cout << "Se incluye la entidad de nombre " + entidad->getNombre() << endl;
}

void ControladorDatos::modificarNombreEntidad(Datos* data, string nombreEntidad, string nuevoNombre)
{
	cout << "Se cambia el nombre: " + nombreEntidad + ", por el nombre: " + nuevoNombre << endl;
}

void ControladorDatos::modificarPropiedadTipoEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoTipo)
{
	cout << "Se cambia el tipo de la propiedad de nombre: " + nombrePropiedad + ", por el tipo: " + nuevoTipo << endl;
}

void ControladorDatos::modificarPropiedadValorEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoValor)
{
	cout << "Se cambia el valor de la propiedad de nombre: " + nombrePropiedad + ", por el valor: " + nuevoValor << endl;
}

void ControladorDatos::modificarPropiedadNombreEntidad(Datos* data, string nombreEntidad, string nombrePropiedad, string nuevoNombrePropiedad)
{
	cout << "Se cambia el nombre de la propiedad: " + nombrePropiedad + ", por el nombre: " + nuevoNombrePropiedad << endl;
}

void ControladorDatos::eliminarEntidad(Datos* data, string nombreEntidad)
{
	cout << "Se elimina la entidad de nombre: " + nombreEntidad << endl;
}

EntidadAbstracta* ControladorDatos::busquedaPorNombreEntidad(Datos* data, string nombre)
{
	cout << "Se obtiene la entidad de nombre: " + nombre << endl;
	return nullptr;
}

vector<EntidadAbstracta*> ControladorDatos::busquedaPorTipoPropiedad(Datos* data, string tipo)
{
	cout << "Se obtiene un vector con todas las entidades con propiedades de tipo: " + tipo << endl;
	return vector<EntidadAbstracta*>();
}

vector<EntidadAbstracta*> ControladorDatos::busquedaPorValorPropiedad(Datos* data, string valor)
{
	cout << "Se obtiene un vector con todas las entidades con propiedades de valor: " + valor << endl;
	return vector<EntidadAbstracta*>();
}

vector<EntidadAbstracta*> ControladorDatos::busquedaPorNombrePropiedad(Datos* data, string nombrePr)
{
	cout << "Se obtiene un vector con todas las entidades con propiedades de nombre: " + nombrePr << endl;
	return vector<EntidadAbstracta*>();
}
