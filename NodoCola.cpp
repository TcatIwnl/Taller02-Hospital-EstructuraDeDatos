#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente* paciente)
{
    this->paciente = paciente;
    this->sgte = nullptr;
}

NodoCola* NodoCola::getSgte(){return this->sgte;}
void NodoCola::setSgte(NodoCola* sgte){this->sgte = sgte;}
Paciente* NodoCola::getPaciente(){return this->paciente;}

NodoCola::~NodoCola()
{}
