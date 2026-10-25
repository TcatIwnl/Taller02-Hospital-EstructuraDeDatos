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
    Paciente* buscarNombreNodo(NodoAVL* nodo, const string& nombre);
    NodoAVL* eliminarNodo(NodoAVL* nodo, string id, bool liberarPaciente);
    NodoAVL* obtenerNodoMinimo(NodoAVL* nodo); //el nodo mas a la izquierda y abajo..
    int contarNodos(NodoAVL* nodo);

    void inordenRecursivo(NodoAVL* nodo);
    void preordenRecursivo(NodoAVL* nodo);
    void postordenRecursivo(NodoAVL* nodo);

public:
    ArbolAVL();
    ~ArbolAVL();

    bool estaVacio();
    int alturaArbol();
    int contarPacientes();

    void insertar(Paciente* paciente); 
    Paciente* buscar(string id);
    Paciente* buscarPorNombre(const string& nombre);
    void eliminar(string id);

    int alturaNodo(NodoAVL* nodo);
    int factorBalance(NodoAVL* nodo);
    void actualizarAltura(NodoAVL* nodo);

    //Rotar los nodos
    NodoAVL* rotarDerecha(NodoAVL* nodo);
    NodoAVL* rotarIzquierda(NodoAVL* nodo);
    NodoAVL* rotarIqDer(NodoAVL* nodo);
    NodoAVL* rotarDerIq(NodoAVL* nodo);

    //Recorridos
    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
};
