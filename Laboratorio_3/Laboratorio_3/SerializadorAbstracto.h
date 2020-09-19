#include <utility>
#include <string>
using namespace std;

//#include "ProyectoSimple.h"
//#include "ProyectoComplejo.h"

class SerializadorAbstracto
{
public:
	SerializadorAbstracto() {};
	~SerializadorAbstracto() {};

	virtual void inicioObjeto(string nombreObjeto) = 0;
	virtual void finObjeto() = 0;
	virtual void serializarString(const pair< string, string >& pe) = 0;
	/*virtual void serializarTipoProyecto(const pair< string, Valor* >& pd) = 0;*/
	virtual string obtSerializacion() = 0;
};