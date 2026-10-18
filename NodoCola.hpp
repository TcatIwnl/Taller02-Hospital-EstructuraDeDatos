#include "Paciente.hpp"
#pragma once
//esta clase representa a un nodo de la cola de pacientes, que contiene un paciente y un puntero al siguiente nodo
class NodoCola
{
private:
    Paciente* paciente;
    NodoCola* sgte; //guardamos la direccion del siguiente nodo (paciente) de la cola

public:
    NodoCola(Paciente* paciente);
    NodoCola* getSgte();
    void setSgte(NodoCola* sgte);
    Paciente* getPaciente();
    ~NodoCola();
};
