#include "SerializadorXML.h"

SerializadorXML::SerializadorXML() : serializacion("")
{
}

SerializadorXML::~SerializadorXML()
{
}

void SerializadorXML::inicioObjeto(string nombreObjeto)
{
	serializacion = serializacion + "< " + nombreObjeto + ' ';
}

void SerializadorXML::finObjeto()
{
	serializacion = serializacion + ">";
}

void SerializadorXML::serializarString(const pair< string, string >& pe)
{
	serializacion = serializacion + pe.first + '=' + '"' + pe.second + '"' + ' ';
}

//void SerializadorXML::serializarTipoProyecto(const pair< string, Valor* >& pd)
//{
//	serializacion = serializacion + pd.first + '=' + '"' + pd.second->toString() + '"' + ' ';
//}

string SerializadorXML::obtSerializacion()
{
	return serializacion;
}