#pragma once
#include "Paciente.hpp"

class NodoPila
{
private:
    Paciente* paciente;
    NodoPila* sgte;    
public:
    NodoPila(Paciente* p);
    Paciente* getPaciente();
    NodoPila* getSgte();
    void setSgte(NodoPila* sgte);
    ~NodoPila();
};