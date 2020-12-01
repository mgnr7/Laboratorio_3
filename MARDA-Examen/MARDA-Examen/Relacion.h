#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
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
	int contarLlaves(EntidadAbstracta* elemento);

public:

	Relacion(std::string nombreRelacion, unsigned int cardLlave, unsigned int cardValor);
	~Relacion();
	void agregarRelacion(EntidadAbstracta* llave, EntidadAbstracta* elemento);
	void eliminarRelacion(EntidadAbstracta* llave, EntidadAbstracta* elemento);
	std::vector<EntidadAbstracta*>* getElementos(EntidadAbstracta* llave);
	std::vector<EntidadAbstracta*>* getLlaves(EntidadAbstracta* elemento);



};

