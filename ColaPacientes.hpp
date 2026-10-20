#include "NodoCola.hpp"
#include <string>
#pragma once

class ColaPacientes
{
private:
    NodoCola* cabecera;  //el sgte en ser atendido
    NodoCola* final; //el ultimo en ser atendido
public:
    ColaPacientes();
    ~ColaPacientes();

    void ingresar(Paciente* paciente);
    Paciente* sacarPaciente();
    bool estaVacia();
    void mostrarCola();

    Paciente* buscarPaciente(string id);
    bool existePaciente(string id);
};