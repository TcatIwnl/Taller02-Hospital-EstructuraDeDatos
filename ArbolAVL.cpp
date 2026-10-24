#include "ArbolAVL.hpp"

ArbolAVL::ArbolAVL()
{
    this->raiz = nullptr;
}

ArbolAVL::~ArbolAVL()
{
    liberar(this->raiz);
    this->raiz = nullptr;
}

void ArbolAVL::liberar(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    liberar(nodo->getIzq());
    liberar(nodo->getDer());

    delete nodo->getPaciente();
    delete nodo;
}

bool ArbolAVL::estaVacio()
{
    return this->raiz == nullptr;
}

int ArbolAVL::alturaArbol()
{
    return alturaNodo(this->raiz);
}

int ArbolAVL::alturaNodo(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    return nodo->getAltura();
}

int ArbolAVL::factorBalance(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    int alturaIzquierda = alturaNodo(nodo->getIzq());
    int alturaDerecha = alturaNodo(nodo->getDer());

    return alturaIzquierda - alturaDerecha;
}

void ArbolAVL::actualizarAltura(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    int alturaIzquierda = alturaNodo(nodo->getIzq());
    int alturaDerecha = alturaNodo(nodo->getDer());

    if (alturaIzquierda > alturaDerecha)
    {
        nodo->setAltura(alturaIzquierda + 1);
    }
    else
    {
        nodo->setAltura(alturaDerecha + 1);
    }
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (nodo->getIzq() == nullptr)
    {
        return nodo;
    }

    NodoAVL* nuevaRaiz = nodo->getIzq();
    NodoAVL* subarbolTemporal = nuevaRaiz->getDer();

    // El hijo izquierdo pasa a ser la nueva raiz.
    nuevaRaiz->setDer(nodo);
    nodo->setIzq(subarbolTemporal);

    // Primero actualizamos el nodo que bajo.
    actualizarAltura(nodo);
    actualizarAltura(nuevaRaiz);

    return nuevaRaiz;
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }

    if (nodo->getDer() == nullptr)
    {
        return nodo;
    }

    NodoAVL* nuevaRaiz = nodo->getDer();
    NodoAVL* subarbolTemporal = nuevaRaiz->getIzq();

    // El hijo derecho pasa a ser la nueva raiz.
    nuevaRaiz->setIzq(nodo);
    nodo->setDer(subarbolTemporal);

    // Primero actualizamos el nodo que bajo.
    actualizarAltura(nodo);
    actualizarAltura(nuevaRaiz);

    return nuevaRaiz;
}
