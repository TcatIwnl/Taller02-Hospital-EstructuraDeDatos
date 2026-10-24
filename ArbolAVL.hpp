#pragma once
#include "NodoAVL.hpp"

class ArbolAVL
{
private:
    NodoAVL* raiz;
    //Libera los pacientes y nodos que pertenecen al arbol
    void liberar(NodoAVL* nodo);
    NodoAVL* insertarNodo(NodoAVL* nodo, Paciente* paciente);
    Paciente* buscar(string id);
    void eliminar(string id);
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
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
    NodoAVL* rotarIqDer(NodoAVL* nodo);
    NodoAVL* rotarDerIq(NodoAVL* nodo);
    void insertar(Paciente* paciente); //lo llamamos en el hospital 

    Paciente* buscarNodo(NodoAVL* nodo, string id);
    NodoAVL* eliminarNodo(NodoAVL* nodo, string id);
    NodoAVL* obtenerNodoMinimo(NodoAVL* nodo);
    
    void inordenRecursivo(NodoAVL* nodo);
    void preordenRecursivo(NodoAVL* nodo);
    void postordenRecursivo(NodoAVL* nodo);
};
