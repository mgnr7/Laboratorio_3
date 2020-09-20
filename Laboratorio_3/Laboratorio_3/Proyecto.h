#pragma once
#include <vector>
#include "Cmpnte_Proyecto.h"

using namespace std;

class Proyecto
{
public:
	Proyecto();
	~Proyecto();
	vector <Cmpnte_Proyecto*> tareas;
};

