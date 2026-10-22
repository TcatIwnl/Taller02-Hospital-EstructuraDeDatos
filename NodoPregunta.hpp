#pragma once
#include <string>
using namespace std;

class NodoPregunta {
private:
    string texto; //guarda la pregunta o el servicio final..
    NodoPregunta* hijoSi;
    NodoPregunta* hijoNo;

public:
    NodoPregunta(string texto);
    ~NodoPregunta();
    string getTexto();
    
    NodoPregunta* getHijoSi();
    NodoPregunta* getHijoNo();
    void setHijoSi(NodoPregunta* nodo);
    void setHijoNo(NodoPregunta* nodo); 
    bool esServicioFinal(); //si no tiene hijo significa que llegamos al final
};