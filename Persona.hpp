#pragma once    
#include <string>
using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad);
    string getNombre();
    int getEdad();
    void setNombre(string nombre);
    void setEdad(int edad);

    virtual ~Persona();
};

