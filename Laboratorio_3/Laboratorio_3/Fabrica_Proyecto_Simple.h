#pragma once
#include "Fabrica_Proyecto.h"
class Fabrica_Proyecto_Simple :
    public Fabrica_Proyecto
{

public:
    Proyecto* CrearProyecto() override;
};

