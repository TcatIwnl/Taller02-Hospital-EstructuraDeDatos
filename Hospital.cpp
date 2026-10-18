#include "Hospital.hpp"
#include "ColaPacientes.hpp"
#include <iostream>

Hospital::Hospital()
{
    this->cabecera = nullptr;
}

void Hospital::ingresarSeccion(string nombre)
{
    Seccion* nuevaSeccion = new Seccion(nombre);
    NodoSeccion* nuevoNodo = new NodoSeccion(nuevaSeccion);

    if (this->cabecera == nullptr)
    {
        this->cabecera = nuevoNodo;
        return;
    }

    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual->getSgte() != nullptr)
    {
        nodoActual = nodoActual->getSgte();
    }

    nodoActual->setSgte(nuevoNodo);
}

Seccion* Hospital::buscarSeccion(string nombre)
{
    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        if (nodoActual->getSeccion()->getNombre() == nombre)
        {
            return nodoActual->getSeccion();
        }

        nodoActual = nodoActual->getSgte();
    }

    return nullptr;
}

void Hospital::mostrarSecciones(){
    cout << "=== DEPARTAMENTOS/SECCIONES ===" << endl;
    NodoSeccion* nodoActual = this->cabecera;
    int contador = 1;//lo mismo que en la fila de pacientes..

    while (nodoActual != nullptr) {
        cout << contador << ". " << nodoActual->getSeccion()->getNombre() << endl;
        nodoActual = nodoActual->getSgte();
        contador++;
    }

}

void Hospital::atenderPacientes(ColaPacientes& cola, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Paciente* pacienteAtendido = cola.sacarPaciente();

        if (pacienteAtendido == nullptr)
        {
            cout << "No quedan pacientes pendientes." << endl;
            return;
        }

        if (i == 0) cout << "=== ATENDIENDO PACIENTES ===" << endl;

        //Datos del paciente que atendimos recien..
        cout << "ID: " << pacienteAtendido->getId() << endl;
        cout << "Nombre: " << pacienteAtendido->getNombre() << endl;
        cout << "Edad: " << pacienteAtendido->getEdad() << endl;
        cout << "Servicio: " << pacienteAtendido->getServicio() << endl;
        cout << "Paciente enviado a " << pacienteAtendido->getServicio() << ".\n" << endl; 

        Seccion* seccionPaciente = buscarSeccion(
            pacienteAtendido->getServicio()
        );

        if (seccionPaciente != nullptr)
        {
            seccionPaciente->ingresarPaciente(pacienteAtendido);
        }
        else
        {
            cout << "Servicio no encontrado: "
                 << pacienteAtendido->getServicio() << endl;

            delete pacienteAtendido;
        }
    }
}

Hospital::~Hospital()
{
    NodoSeccion* nodoActual = this->cabecera;

    while (nodoActual != nullptr)
    {
        NodoSeccion* siguiente = nodoActual->getSgte();

        delete nodoActual->getSeccion();
        delete nodoActual;

        nodoActual = siguiente;
    }

    this->cabecera = nullptr;
}