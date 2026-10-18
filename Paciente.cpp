#include "Paciente.hpp"

Paciente::Paciente(string nombre, int edad, string id, string servicio): Persona(nombre, edad)
{
    this->id = id;
    this->servicio = servicio;
}

Paciente::~Paciente()
{}

string Paciente::getServicio()
{
    return this->servicio;
}
void Paciente::setServicio(string servicio)
{
    this->servicio = servicio;
}
string Paciente::getId()
{
    return this->id;
}
void Paciente::setId(string id)
{
    this->id = id;
}