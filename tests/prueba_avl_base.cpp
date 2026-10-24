#include <iostream>
#include "NodoAVL.hpp"
#include "ArbolAVL.hpp"
using namespace std;

int main()
{
    ArbolAVL arbol;
    int pruebasCorrectas = 0;

    // Prueba 1: arbol vacio.
    if (arbol.estaVacio() && arbol.alturaArbol() == 0)
    {
        cout << "OK: AVL vacio tiene altura 0" << endl;
        pruebasCorrectas++;
    }
    else
    {
        cout << "ERROR: AVL vacio" << endl;
    }

    // Pacientes de prueba. No se incorporan al arbol todavia.
    Paciente p10("010", "Diez", 20, 37.0f, 120, 0, "otro", 0, 0, 0, 0);
    Paciente p20("020", "Veinte", 20, 37.0f, 120, 0, "otro", 0, 0, 0, 0);
    Paciente p30("030", "Treinta", 20, 37.0f, 120, 0, "otro", 0, 0, 0, 0);

    // Prueba 2: rotacion LL (30, 20, 10).
    NodoAVL n30(&p30);
    NodoAVL n20(&p20);
    NodoAVL n10(&p10);

    n30.setIzq(&n20);
    n20.setIzq(&n10);

    arbol.actualizarAltura(&n20);
    arbol.actualizarAltura(&n30);

    bool alturaLLCorrecta = n30.getAltura() == 3;
    bool balanceLLCorrecto = arbol.factorBalance(&n30) == 2;

    NodoAVL* raizLL = arbol.rotarDerecha(&n30);

    if (alturaLLCorrecta && balanceLLCorrecto &&
        raizLL == &n20 &&
        raizLL->getIzq() == &n10 &&
        raizLL->getDer() == &n30 &&
        raizLL->getAltura() == 2 &&
        arbol.factorBalance(raizLL) == 0)
    {
        cout << "OK: rotacion LL (30,20,10) produce raiz 20" << endl;
        pruebasCorrectas++;
    }
    else
    {
        cout << "ERROR: rotacion LL" << endl;
    }

    // Prueba 3: rotacion RR (10, 20, 30).
    NodoAVL a10(&p10);
    NodoAVL a20(&p20);
    NodoAVL a30(&p30);

    a10.setDer(&a20);
    a20.setDer(&a30);

    arbol.actualizarAltura(&a20);
    arbol.actualizarAltura(&a10);

    bool alturaRRCorrecta = a10.getAltura() == 3;
    bool balanceRRCorrecto = arbol.factorBalance(&a10) == -2;

    NodoAVL* raizRR = arbol.rotarIzquierda(&a10);

    if (alturaRRCorrecta && balanceRRCorrecto &&
        raizRR == &a20 &&
        raizRR->getIzq() == &a10 &&
        raizRR->getDer() == &a30 &&
        raizRR->getAltura() == 2 &&
        arbol.factorBalance(raizRR) == 0)
    {
        cout << "OK: rotacion RR (10,20,30) produce raiz 20" << endl;
        pruebasCorrectas++;
    }
    else
    {
        cout << "ERROR: rotacion RR" << endl;
    }

    cout << "Pruebas correctas: " << pruebasCorrectas << "/3" << endl;

    if (pruebasCorrectas != 3)
    {
        return 1;
    }

    return 0;
}
