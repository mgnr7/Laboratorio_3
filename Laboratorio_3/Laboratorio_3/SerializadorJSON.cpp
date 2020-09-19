#include "SerializadorJSON.h"

SerializadorJSON::SerializadorJSON() : serializacion("")
{
}


SerializadorJSON::~SerializadorJSON()
{
}

void SerializadorJSON::inicioObjeto(string nombreObjeto)
{
	serializacion = serializacion + nombreObjeto + "{ :";
}

void SerializadorJSON::finObjeto()
{
	serializacion = serializacion + "}";
}

void SerializadorJSON::serializarString(const pair< string, string >& pe)
{
	serializacion = serializacion + '"' + pe.first + '"' + ':' + pe.second + ", ";
}

//void SerializadorJSON::serializarTipoProyecto(const pair< string, Tipo* >& pd)
//{
//	serializacion = serializacion + '"' + pd.first + '"' + ':' + pd.second->toString() + ", ";
//}

string SerializadorJSON::obtSerializacion()
{
	return serializacion;
}