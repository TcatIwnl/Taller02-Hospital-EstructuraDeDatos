#include <iostream>
#include <string>
#include "ArbolDecision.hpp"
using namespace std;

struct Caso {
    string descripcion;
    int edad;
    float temperatura;
    int dolor;
    string tipoDolor;
    int trauma;
    int sintomas;
    int cirugia;
    int dias;
    string esperado;
};

int main()
{
    const Caso casos[] = {
        {"Edad 13",                     13, 37.0f, 3, "otro",      0, 0, 0, 0, "Pediatria"},
        {"Edad 14 exactos",             14, 37.0f, 3, "otro",      0, 0, 0, 0, "Medicina General"},
        {"Trauma con cirugia",           30, 37.0f, 3, "otro",      1, 0, 1, 0, "Cirugia"},
        {"Trauma sin cirugia",           30, 37.0f, 3, "otro",      1, 0, 0, 0, "Traumatologia"},
        {"Sintomas neurologicos",        30, 37.0f, 3, "cabeza",    0, 1, 0, 0, "Neurologia"},
        {"Dolor de pecho",               30, 37.0f, 3, "pecho",     0, 0, 0, 0, "Cardiologia"},
        {"Temperatura 38.5 exactos",     30, 38.5f, 3, "otro",      0, 0, 0, 0, "Urgencias"},
        {"Dolor 8 exactos",              30, 37.0f, 8, "otro",      0, 0, 0, 0, "Urgencias"},
        {"Hospitalizacion 2 dias",      30, 37.0f, 3, "otro",      0, 0, 0, 2, "Hospitalizacion"},
        {"Menor con trauma",             12, 37.0f, 3, "otro",      1, 0, 1, 0, "Pediatria"},
        {"Trauma y sintomas neuro",      30, 37.0f, 3, "otro",      1, 1, 0, 0, "Traumatologia"},
        {"Pecho y fiebre",               30, 39.0f, 3, "pecho",     0, 0, 0, 0, "Cardiologia"},
        {"Bajo umbral de urgencias",     30, 38.49f,7, "otro",      0, 0, 0, 0, "Medicina General"},
        {"Fiebre y hospitalizacion",     30, 39.0f, 3, "otro",      0, 0, 0, 3, "Urgencias"}
    };

    ArbolDecision arbol;
    const int total = sizeof(casos) / sizeof(casos[0]);
    int correctos = 0;

    if (arbol.contarServicios() != 8) {
        cerr << "ERROR: el arbol no contiene ocho hojas\n";
        return 1;
    }

    for (int i = 0; i < total; i++) {
        const Caso& caso = casos[i];
        Paciente paciente(to_string(100 + i), caso.descripcion, caso.edad,
                          caso.temperatura, 120, caso.dolor, caso.tipoDolor,
                          caso.trauma, caso.sintomas, caso.cirugia, caso.dias);
        string ruta;
        string obtenido = arbol.clasificarPaciente(&paciente, ruta);
        bool correcto = (obtenido == caso.esperado &&
                         !ruta.empty() &&
                         ruta.size() >= obtenido.size() &&
                         ruta.substr(ruta.size() - obtenido.size()) == obtenido);
        cout << (correcto ? "OK   " : "ERROR") << " Caso " << i+1
             << " - " << caso.descripcion << ": " << obtenido
             << " (esperado: " << caso.esperado << ")\n";
        if (!correcto) cout << "  Ruta: " << ruta << '\n';
        if (correcto) correctos++;
    }

    string ruta = "valor anterior";
    bool nuloCorrecto = arbol.clasificarPaciente(nullptr, ruta).empty() && ruta.empty();
    cout << (nuloCorrecto ? "OK   " : "ERROR") << " Paciente nulo\n";

    // Los destructores se ejecutan al finalizar cada iteracion.
    for (int i = 0; i < 100; ++i) {
        ArbolDecision arbolTemporal;
        if (arbolTemporal.contarServicios() != 8) return 1;
    }

    cout << "\nResultado: " << correctos << "/" << total
         << " clasificaciones; paciente nulo: " << (nuloCorrecto ? "OK" : "ERROR")
         << "; construccion/destruccion: 100 ciclos\n";
    return (correctos == total && nuloCorrecto) ? 0 : 1;
}
