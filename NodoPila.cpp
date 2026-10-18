#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente* p){
    this->paciente = p;
    this->sgte = nullptr;
}

Paciente* NodoPila::getPaciente() { return this->paciente; }
NodoPila* NodoPila::getSgte() { return this->sgte; }
void NodoPila::setSgte(NodoPila* sgte) { this->sgte = sgte; }

NodoPila::~NodoPila(){
//No eliminamos aca al paciente..
}
