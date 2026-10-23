
#pragma once
#include "NodoPregunta.hpp"

class ArbolDecision {
private:
    NodoPregunta* raiz;

    // Recorridos auxiliares
    void mostrarPreordenDesde(NodoPregunta* nodo) const;
    void mostrarInordenDesde(NodoPregunta* nodo) const;
    void mostrarPostordenDesde(NodoPregunta* nodo) const;

    // Cuenta los servicios finales del arbol
    int contarHojasDesde(NodoPregunta* nodo) const;

public:
    ArbolDecision();
    ~ArbolDecision();

    // Evitamos copiar objetos que poseen punteros
    ArbolDecision(const ArbolDecision&) = delete;
    ArbolDecision& operator=(const ArbolDecision&) = delete;

    void mostrarPreorden() const;
    void mostrarInorden() const;
    void mostrarPostorden() const;

    int contarServicios() const;
};
