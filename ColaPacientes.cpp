#include "ColaPacientes.hpp"
#include <iostream>
using namespace std;

ColaPacientes::ColaPacientes()
{
    this->cabecera = nullptr;
    this->final = nullptr;
}

void ColaPacientes::ingresar(Paciente* paciente)
{
    NodoCola* nuevo = new NodoCola(paciente);

    if (cabecera == nullptr)
    {
        cabecera = nuevo;
        final = nuevo;
    }
    else
    {
        final->setSgte(nuevo);
        final = nuevo;
    }
}

bool ColaPacientes::estaVacia()
{
    return cabecera == nullptr;
}

Paciente* ColaPacientes::sacarPaciente()
{
    if (estaVacia())
    {
        return nullptr;
    }

    NodoCola* nodoAux = cabecera;
    Paciente* paciente = nodoAux->getPaciente();

    cabecera = cabecera->getSgte();

    if (cabecera == nullptr)
    {
        final = nullptr;
    }

    delete nodoAux;

    return paciente;
}

ColaPacientes::~ColaPacientes()
{
    while (!estaVacia())
    {
        Paciente* pacienteActual = sacarPaciente();
        delete pacienteActual;  //vamos eliminando mientras vamos sacando de la cola.. 
    }
}

void ColaPacientes::mostrarCola(){ 
    if (estaVacia()) return;
    cout << "=== PACIENTES EN ESPERA ===" << endl;
    NodoCola* nodoActual = cabecera;
    int contador = 1;//para que este como en el ejemplo del taller..

    while(nodoActual != nullptr) {
        Paciente* p = nodoActual->getPaciente(); 
        cout << contador << ". " << p->getId() << " " << p->getNombre() << endl;
        nodoActual = nodoActual->getSgte();
        contador++;
    }
}

