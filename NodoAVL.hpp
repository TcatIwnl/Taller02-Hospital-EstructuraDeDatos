#pragma once
#include "Paciente.hpp"

class NodoAVL
{
private:
    Paciente* paciente;
    NodoAVL* izq;
    NodoAVL* der;
    int altura;

public:
    NodoAVL(Paciente* paciente);
    ~NodoAVL();

    Paciente* getPaciente();
    NodoAVL* getIzq();
    NodoAVL* getDer();
    int getAltura();

    void setIzq(NodoAVL* nodo);
    void setDer(NodoAVL* nodo);
    void setAltura(int nuevaAltura);
};
