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
    if (cantidad <= 0)
    {
        cout << "La cantidad de pacientes a atender debe ser mayor a 0." << endl;
        return;
    }

    if (cola.estaVacia())
    {
        cout << "No quedan pacientes pendientes." << endl;
        return;
    }

    cout << "=== ATENDIENDO PACIENTES ===" << endl;

    for (int i = 0; i < cantidad; i++)
    {
        Paciente* pacienteAtendido = cola.sacarPaciente();
        if (pacienteAtendido == nullptr)
        {
            cout << "No quedan mas pacientes pendientes en la cola." << endl;
            return;
        }

        string rutaDecision = "";
        string servicioAsignado = this->arbolDecision.clasificarPaciente(pacienteAtendido, rutaDecision);
        pacienteAtendido->setServicio(servicioAsignado);

        cout << "ID: " << pacienteAtendido->getId() << endl;
        cout << "Nombre: " << pacienteAtendido->getNombre() << endl;
        cout << "Edad: " << pacienteAtendido->getEdad() << endl;
        cout << "Temperatura: " << pacienteAtendido->getTemperatura() << endl;
        cout << "PresionArterial: " << pacienteAtendido->getPresion() << endl;
        cout << "Dolor: " << pacienteAtendido->getDolor() << endl;
        cout << "TipoDolor: " << pacienteAtendido->getTipoDolor() << endl;
        cout << "Trauma: " << pacienteAtendido->getTrauma() << endl;
        cout << "SintomasNeurologicos: " << pacienteAtendido->getSintomas() << endl;
        cout << "RequiereCirugia: " << pacienteAtendido->getCirugia() << endl;
        cout << "DiasHospitalizacion: " << pacienteAtendido->getDias() << endl;
        cout << "Ruta: " << rutaDecision << endl;
        cout << "Servicio asignado: " << servicioAsignado << endl;

        Seccion* seccionDestino = buscarSeccion(servicioAsignado);
        if (seccionDestino != nullptr)
        {
            seccionDestino->ingresarPaciente(pacienteAtendido);
            cout << "Paciente insertado en el AVL de " << servicioAsignado << ".\n" << endl;
        }
        else
        {
            cout << "Error: Servicio no encontrado (" << servicioAsignado << ")." << endl;
            delete pacienteAtendido;
        }
    }
}

Paciente* Hospital::buscarPacienteEnHospital(const string& criterio, string& departamentoEncontrado)
{
    NodoSeccion* nodoActual = this->cabecera;
    while (nodoActual != nullptr)
    {
        Seccion* sec = nodoActual->getSeccion();
        Paciente* p = sec->buscarPacientePorId(criterio);
        if (p == nullptr)
        {
            p = sec->buscarPacientePorNombre(criterio);
        }
        if (p != nullptr)
        {
            departamentoEncontrado = sec->getNombre();
            return p;
        }
        nodoActual = nodoActual->getSgte();
    }
    departamentoEncontrado = "";
    return nullptr;
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