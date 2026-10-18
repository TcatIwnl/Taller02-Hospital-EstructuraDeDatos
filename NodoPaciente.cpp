#include "NodoPaciente.hpp"

NodoPaciente::NodoPaciente(Paciente* p){
    this->paciente = p;
    this->sgte = nullptr;

}

NodoPaciente* NodoPaciente::getSgte(){
    return this->sgte;
}

Paciente* NodoPaciente::getPaciente(){
    return this->paciente;
}

void NodoPaciente::setSgte(NodoPaciente* nuevo){
    this->sgte = nuevo;
}

NodoPaciente::~NodoPaciente(){

}