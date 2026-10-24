#pragma once
#include "NodoAVL.hpp"

class ArbolAVL
{
private:
    NodoAVL* raiz;
    //Libera los pacientes y nodos que pertenecen al arbol
    void liberar(NodoAVL* nodo);
    NodoAVL* insertarNodo(NodoAVL* nodo, Paciente* paciente);
    Paciente* buscarNodo(NodoAVL* nodo, string id);
    NodoAVL* eliminarNodo(NodoAVL* nodo, string id);
    NodoAVL* obtenerNodoMinimo(NodoAVL* nodo); //el nodo mas a la izquierda y abajo..
    void inordenRecursivo(NodoAVL* nodo);
    void preordenRecursivo(NodoAVL* nodo);
    void postordenRecursivo(NodoAVL* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    bool estaVacio();
    int alturaArbol();
    
    void insertar(Paciente* paciente); 
    Paciente* buscar(string id);
    void eliminar(string id);

    int alturaNodo(NodoAVL* nodo);
    int factorBalance(NodoAVL* nodo);
    void actualizarAltura(NodoAVL* nodo);
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
    NodoAVL* rotarIqDer(NodoAVL* nodo);
    NodoAVL* rotarDerIq(NodoAVL* nodo);

    //Recorridos
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
};
