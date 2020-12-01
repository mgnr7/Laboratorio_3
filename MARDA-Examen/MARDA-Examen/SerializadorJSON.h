#pragma once

#include <string>
#include "Propiedad.h"

using namespace std;
class SerializadorJSON 
{
private:
	string serializacion;

public:
	SerializadorJSON();
	~SerializadorJSON();

	virtual void inicioObjeto(string nombreObjeto);
	virtual void finObjeto();
	virtual void serializarPropiedad(Propiedad* p);
	virtual string obtSerializacion();
};
