#pragma once

#include <sstream>
using namespace std;

//#include "Valor.h"
#include "SerializadorAbstracto.h"

class SerializadorXML : public ConstructorSerializadorAbstracto
{
public:
	SerializadorXML();
	~SerializadorXML();

	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarString(const pair< string, string >& pe) override;
	//virtual void serializarTipoProyecto(const pair< string, Valor* >& pd) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // el producto del Constructor
};


