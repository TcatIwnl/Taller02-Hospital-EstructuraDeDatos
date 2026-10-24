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
NodoAVL* ArbolAVL::rotarIqDer(NodoAVL* nodo){
    nodo->setIzq(rotarIzquierda(nodo->getIzq()));//primero a la izquierda el hijo
    return rotarDerecha(nodo); //luego lo rotamos a la derecha
}
NodoAVL* ArbolAVL::rotarDerIq(NodoAVL* nodo){
    nodo->setDer(rotarDerecha(nodo->getDer()));
    return rotarIzquierda(nodo);
}

void ArbolAVL::insertar(Paciente* paciente){
    this->raiz = insertarNodo(this->raiz, paciente);
}

NodoAVL* ArbolAVL::insertarNodo(NodoAVL* nodo, Paciente* paciente){
    if (nodo == nullptr) {
        return new NodoAVL(paciente);
    }

    if (paciente->getId() < nodo->getPaciente()->getId()) {
        nodo->setIzq(insertarNodo(nodo->getIzq(), paciente));
    }
    else if (paciente->getId() > nodo->getPaciente()->getId()) {
        nodo->setDer(insertarNodo(nodo->getDer(), paciente));
    }
    else {
        //no lo ingresamos..
        return nodo; 
    }

    actualizarAltura(nodo);
    int balance = factorBalance(nodo);

    if (balance > 1 && paciente->getId() < nodo->getIzq()->getPaciente()->getId())
        return rotarDerecha(nodo);
    
    if (balance < -1 && paciente->getId() > nodo->getDer()->getPaciente()->getId())
        return rotarIzquierda(nodo);

    if (balance > 1 && paciente->getId() > nodo->getIzq()->getPaciente()->getId())
        return rotarIqDer(nodo);
    
    if (balance < -1 && paciente->getId() < nodo->getDer()->getPaciente()->getId())
        return rotarDerIq(nodo);

    return nodo;
}

Paciente* ArbolAVL::buscar(string id){
    return buscarNodo(this->raiz, id);
}

Paciente* ArbolAVL::buscarNodo(NodoAVL* nodo, string id)
{
    if (nodo == nullptr) {
        return nullptr; //No se encontró..
    }
    
    //Búsqueda binaria ultra rapida..
    if (id < nodo->getPaciente()->getId()) {
        return buscarNodo(nodo->getIzq(), id);
    } 
    else if (id > nodo->getPaciente()->getId()) {
        return buscarNodo(nodo->getDer(), id);
    } 
    else {
        return nodo->getPaciente(); //Encontrado
    }
}
