#pragma once
#include <string>
#include <iostream>
#include "NodoPaciente.hpp"

class Seccion
{
private:
    NodoPaciente* cabecera;
    string nombre;
public:
    Seccion(string nombre);
    string getNombre();
    void ingresarPaciente(Paciente* p);  
    void mostrarEstado();
    ~Seccion();
};
