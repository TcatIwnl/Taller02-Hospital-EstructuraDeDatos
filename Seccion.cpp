#include "Seccion.hpp"

Seccion::Seccion(string nombre)
{
    this->nombre = nombre;
}

Seccion::~Seccion()
{
    // El destructor de ArbolAVL libera sus nodos y pacientes automaticamente
}

string Seccion::getNombre()
{
    return this->nombre;
}

void Seccion::ingresarPaciente(Paciente* p)
{
    this->arbolPacientes.insertar(p);
}

Paciente* Seccion::buscarPacientePorId(const string& id)
{
    return this->arbolPacientes.buscar(id);
}

Paciente* Seccion::buscarPacientePorNombre(const string& nombre)
{
    return this->arbolPacientes.buscarPorNombre(nombre);
}

void Seccion::eliminarPacientePorId(const string& id)
{
    this->arbolPacientes.eliminar(id);
}

bool Seccion::estaVacia()
{
    return this->arbolPacientes.estaVacio();
}

int Seccion::cantidadPacientes()
{
    return this->arbolPacientes.contarPacientes();
}

int Seccion::alturaAVL()
{
    return this->arbolPacientes.alturaArbol();
}

void Seccion::mostrarEstado()
{
    cout << "=== ESTADO " << this->nombre << " ===" << endl;

    if (this->arbolPacientes.estaVacio())
    {
        cout << "Sin pacientes" << endl;
        return;
    }

    cout << "Pacientes en " << this->nombre << ": " << cantidadPacientes()
         << " (Altura AVL: " << alturaAVL() << ")" << endl;

    cout << "\n-- Recorrido Inorden (con altura y factor de balance) --" << endl;
    this->arbolPacientes.mostrarInorden();

    cout << "\n-- Recorrido Preorden --" << endl;
    this->arbolPacientes.mostrarPreorden();

    cout << "\n-- Recorrido Postorden --" << endl;
    this->arbolPacientes.mostrarPostorden();
}