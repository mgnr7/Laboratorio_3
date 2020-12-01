#pragma once
#include <unordered_map>
#include <string>
#include "EntidadAbstracta.h"
#include <vector>

class Relacion
{
private:
	typedef std::unordered_multimap<EntidadAbstracta*, EntidadAbstracta*> Mapa;
	std::string nombre;
	int cardPrimero;
	int cardSegundo; //Las cardinalidades actuan como una restriccion al agregar una nueva relacion
	Mapa* relacion;

public:

	Relacion(std::string nombreRelacion, unsigned int cardLlave, unsigned int cardValor);
	~Relacion();
	std::string getNombre();
	Mapa* getRelacion();
	int getCardPrimero();
	int getCardSegundo();

	void setNombre(std::string nombre);
	void setRelacion(Mapa* relacion);
	void setCardPrimero(int cardPrimero);
	void setCardSegundo(int cardSegundo);

	int contarLlaves(EntidadAbstracta* elemento);






};

