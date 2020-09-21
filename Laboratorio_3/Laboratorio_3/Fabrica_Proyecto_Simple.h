#pragma once
#include "Fabrica_Proyecto.h"
class Fabrica_Proyecto_Simple :
    public Fabrica_Proyecto
{

public:
    Fabrica_Proyecto_Simple();
    ~Fabrica_Proyecto_Simple();
    Estructura_Act* CrearEstructura() override;
    Cmpnte_Proyecto* CrearActividad() override;
private:
    Estructura_Act estructura;
};

