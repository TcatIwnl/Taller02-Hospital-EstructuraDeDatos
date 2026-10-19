#include "Paciente.hpp"

Paciente::Paciente(string id,string nombre,int edad,float temperatura,int presion,int dolor,string tipoDolor,int trauma,int sintomas,int cirugia,int dias): Persona(nombre, edad)
{
    this->id = id;
    this->temperatura = temperatura;
    this->presion = presion;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomas = sintomas;
    this->cirugia = cirugia;
    this->dias = dias;
    this->servicioAsignado = "No asignado"; //por defecto
    
}

Paciente::~Paciente()
{}
string Paciente::getServicio(){return this->servicioAsignado;}
void Paciente::setServicio(string servicio){this->servicioAsignado = servicio;}
string Paciente::getId(){return this->id;}
void Paciente::setId(string id){this->id = id;}

float Paciente::getTemperatura() { return this->temperatura; }//getters para el arbol
int Paciente::getPresion() { return this->presion; }
int Paciente::getDolor() { return this->dolor; }
string Paciente::getTipoDolor() { return this->tipoDolor; }
int Paciente::getTrauma() { return this->trauma; }
int Paciente::getSintomas() { return this->sintomas; }
int Paciente::getCirugia() { return this->cirugia; }
int Paciente::getDias() { return this->dias; }