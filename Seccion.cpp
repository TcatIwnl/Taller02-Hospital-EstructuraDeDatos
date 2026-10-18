#include "Seccion.hpp"

Seccion::Seccion(string nombre){ // al parecer no es necesario incluir el <string>, ya que importamos Seccion.hpp
    this->nombre = nombre;
    this->cabecera = nullptr;
}

string Seccion::getNombre(){return this->nombre;}


void Seccion::mostrarEstado(){
    cout << "=== ESTADO " << this->nombre << " ===" << endl;
    
    if (this->cabecera == nullptr) {
        cout << "No hay pacientes en este departamento." << endl;
        return;
    }
    NodoPaciente* nodoActual = this->cabecera; // o solo cabecera??
    int contador = 0;
    while (nodoActual != nullptr)
    {
        contador++;
        nodoActual = nodoActual->getSgte();
    }
    cout << "Pacientes en el departamento de " << this->nombre << ": " << contador << endl;

    nodoActual = this->cabecera; // Reiniciamos el cursor al inicio
    while (nodoActual != nullptr) {
        Paciente* p = nodoActual->getPaciente();
        cout << "- " << p->getNombre() << " (" << p->getEdad() << ")" << endl;
        nodoActual = nodoActual->getSgte();
    }
    

}

void Seccion::ingresarPaciente(Paciente* p){
    NodoPaciente* nuevoNodo = new NodoPaciente(p);
    
    // Si la lista está vacía, el nuevo nodo es la cabecera
    if (this->cabecera == nullptr) {
        this->cabecera = nuevoNodo;
    } else {
        // Si no está vacía, recorremos hasta el final y lo agregamos
        NodoPaciente* nodoActual = this->cabecera;
        while (nodoActual->getSgte() != nullptr) {
            nodoActual = nodoActual->getSgte();
        }
        nodoActual->setSgte(nuevoNodo);
    }
}

Seccion::~Seccion()
{
    NodoPaciente* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        NodoPaciente* siguiente = nodoActual->getSgte();

        delete nodoActual->getPaciente();
        delete nodoActual;

        nodoActual = siguiente;
    }

    this->cabecera = nullptr;
}