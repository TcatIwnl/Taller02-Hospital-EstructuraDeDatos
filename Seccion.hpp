#pragma once
#include <string>
#include <iostream>
#include "ArbolAVL.hpp"

using namespace std;

class Seccion
{
private:
    ArbolAVL arbolPacientes;
    string nombre;

public:
    Seccion(string nombre);
    ~Seccion();

    string getNombre();
    void ingresarPaciente(Paciente* p);
    Paciente* buscarPacientePorId(const string& id);
    Paciente* buscarPacientePorNombre(const string& nombre);
    void eliminarPacientePorId(const string& id);
    bool estaVacia();
    int cantidadPacientes();
    int alturaAVL();
    void mostrarEstado();
};