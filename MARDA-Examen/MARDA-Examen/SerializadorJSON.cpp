#include "SerializadorJSON.h"

SerializadorJSON::SerializadorJSON()
{
	this->serializacion = "";
}

SerializadorJSON::~SerializadorJSON()
{
}

void SerializadorJSON::inicioObjeto(string nombreObjeto)
{
	this->serializacion = this->serializacion + nombreObjeto + "{ :";
}

void SerializadorJSON::finObjeto()
{
	this->serializacion = this->serializacion + "}";
}

void SerializadorJSON::serializarPropiedad(Propiedad* p)
{
	serializacion = serializacion + '"' + p->getNombre() + '"' + ':' + p->getValor() + ", ";
}

string SerializadorJSON::obtSerializacion()
{
	return this->serializacion;
}