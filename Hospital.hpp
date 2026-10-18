#pragma once
#include <string>
#include "NodoSeccion.hpp"
#include "ColaPacientes.hpp"

using namespace std;

class Hospital
{
private:
    NodoSeccion* cabecera;

public:
    Hospital();
    void ingresarSeccion(string nombre);
    Seccion* buscarSeccion(string nombre);
    void mostrarSecciones();
    void atenderPacientes(ColaPacientes& cola, int cantidad);
    ~Hospital();
};