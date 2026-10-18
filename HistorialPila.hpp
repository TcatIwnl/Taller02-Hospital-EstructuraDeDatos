#pragma once
#include "NodoPila.hpp"
#include <iostream>

class HistorialPila
{
private:
    NodoPila* cima; //no necesitamos el sgte
public:
    HistorialPila();
    ~HistorialPila();
    void registrarAtencion(Paciente* p);
    void mostrarHistorial();
    bool estaVacia();
};