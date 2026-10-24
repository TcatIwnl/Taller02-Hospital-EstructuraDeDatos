#include "NodoAVL.hpp"

NodoAVL::NodoAVL(Paciente* paciente)
{
    this->paciente = paciente;
    this->izq = nullptr;
    this->der = nullptr;
    this->altura = 1;
}

NodoAVL::~NodoAVL()
{
    // El ArbolAVL se encarga de eliminar nodos y pacientes.
}

Paciente* NodoAVL::getPaciente()
{
    return this->paciente;
}

NodoAVL* NodoAVL::getIzq()
{
    return this->izq;
}

NodoAVL* NodoAVL::getDer()
{
    return this->der;
}

int NodoAVL::getAltura()
{
    return this->altura;
}

void NodoAVL::setIzq(NodoAVL* nodo)
{
    this->izq = nodo;
}

void NodoAVL::setDer(NodoAVL* nodo)
{
    this->der = nodo;
}

void NodoAVL::setAltura(int nuevaAltura)
{
    this->altura = nuevaAltura;
}
