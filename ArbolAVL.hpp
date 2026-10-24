#pragma once
#include "NodoAVL.hpp"

class ArbolAVL
{
private:
    NodoAVL* raiz;

    // Libera los pacientes y nodos que pertenecen al arbol.
    void liberar(NodoAVL* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    bool estaVacio();
    int alturaArbol();

    int alturaNodo(NodoAVL* nodo);
    int factorBalance(NodoAVL* nodo);
    void actualizarAltura(NodoAVL* nodo);

    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
};
