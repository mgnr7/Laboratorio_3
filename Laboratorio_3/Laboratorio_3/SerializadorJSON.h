#pragma once

#include <sstream>
using namespace std;

#include "SerializadorAbstracto.h"
//#include "Valor.h"
class SerializadorJSON : public SerializadorAbstracto
{
public:
	SerializadorJSON();
	~SerializadorJSON();

	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarString(const pair< string, string >& pe) override;
	//virtual void serializarTipoProyecto(const pair< string, Valor* >& pd) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // producto del constructor
};

