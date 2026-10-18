#pragma once
#include "Seccion.hpp"

class NodoSeccion
{
private:
    Seccion* seccion;
    NodoSeccion* sgte;

public:
    NodoSeccion(Seccion* seccion);
    Seccion* getSeccion();
    NodoSeccion* getSgte();
    void setSgte(NodoSeccion* sgte);
    ~NodoSeccion();
};