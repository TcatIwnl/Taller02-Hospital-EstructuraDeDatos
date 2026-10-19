#pragma once
#include <string>
#include "Persona.hpp"
using namespace std;
class Paciente: public Persona{
private:
    string id, tipoDolor,servicioAsignado;
    int presion = 0, dolor = 0, trauma = 0, sintomas = 0, cirugia = 0, dias = 0;
    float temperatura = 0.0;
public:
    Paciente(string id, string nombre, int edad, float temperatura, int presion, int dolor, string tipoDolor, int trauma, int sintomas, int cirugia, int dias);
    string getServicio();
    void setServicio(string servicio);
    string getId();
    void setId(string id);
    float getTemperatura();
    int getPresion();
    int getDolor();
    string getTipoDolor();
    int getTrauma();
    int getSintomas();
    int getCirugia();
    int getDias();
    ~Paciente();
};
