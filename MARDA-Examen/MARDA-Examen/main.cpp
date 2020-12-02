#include <iostream>
#include "ControladorEntidades.h"
#include "ControladorRelaciones.h"
#include "ControladorDatos.h"


int main()
{
    ControladorEntidades* cntrEnt = new ControladorEntidades();
    ControladorRelaciones* cntrRel = new ControladorRelaciones();
    ControladorDatos* cntrDatos = new ControladorDatos();

    EntidadSimple* e1 = cntrEnt->crearEntidadSimple("Pedro");
    cntrEnt->modificarEntidad("Pedro", "Pedro Perez");
    cntrEnt->agregarPropiedad("Pedro Perez", "Edad", "int", "30");

    EntidadCompuesta* e2 = cntrEnt->crearEntidadCompuesta("Trabajo");
    cntrRel->crearRelacion("Trabaja en", 0, 1); //relacion N:1 
    cntrRel->agregarRelacion("Trabaja en", e1, e2);




}

