#pragma once
#include <string>
#include "Persona.hpp"
using namespace std;
class Paciente: public Persona{
private:
    string id;
    string servicio;
public:
    Paciente(string nombre, int edad, string id, string servicio);
    string getServicio();
    void setServicio(string servicio);
    string getId();
    void setId(string id);
    ~Paciente();
};
