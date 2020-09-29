#pragma once
#include <utility>
#include <string>
using namespace std;

class SerializadorAbstracto
{
public:
	SerializadorAbstracto() {};
	~SerializadorAbstracto() {};

	virtual void inicioObjeto(string nombreObjeto) = 0;
	virtual void finObjeto() = 0;
	virtual void serializarString(const pair< string, string >& pe) = 0;
	virtual string obtSerializacion() = 0;
};