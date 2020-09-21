#pragma once
#include "Fabrica_Proyecto.h"
#include <vector>


class Fabrica_Proyecto_Complejo :
    public Fabrica_Proyecto
{

public: 
    Fabrica_Proyecto_Complejo();
    ~Fabrica_Proyecto_Complejo();
    Estructura_Act* CrearEstructura() override;
    Cmpnte_Proyecto* CrearActividad() override;

private: 
    Estructura_Act estructura;
};

