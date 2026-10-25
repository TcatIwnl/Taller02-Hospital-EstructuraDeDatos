#pragma once
#include <string>
#include "NodoSeccion.hpp"
#include "ColaPacientes.hpp"
#include "ArbolDecision.hpp"

using namespace std;

class Hospital
{
private:
    NodoSeccion* cabecera;
    ArbolDecision arbolDecision;

public:
    Hospital();
    ~Hospital();

    void ingresarSeccion(string nombre);
    Seccion* buscarSeccion(string nombre);
    void mostrarSecciones();
    void atenderPacientes(ColaPacientes& cola, int cantidad);
    Paciente* buscarPacienteEnHospital(const string& criterio, string& departamentoEncontrado);
};