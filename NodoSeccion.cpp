#include "NodoSeccion.hpp"

NodoSeccion::NodoSeccion(Seccion* seccion)
{
    this->seccion = seccion;
    this->sgte = nullptr;
}

Seccion* NodoSeccion::getSeccion()
{
    return this->seccion;
}

NodoSeccion* NodoSeccion::getSgte()
{
    return this->sgte;
}

void NodoSeccion::setSgte(NodoSeccion* sgte)
{
    this->sgte = sgte;
}

NodoSeccion::~NodoSeccion()
{
}