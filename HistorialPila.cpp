#include "HistorialPila.hpp"

HistorialPila::HistorialPila() {
    this->cima = nullptr;
}

bool HistorialPila::estaVacia() {
    return this->cima == nullptr;
}

//FALTA LOGICA DE LIFO Y LO QUE SE MUESTRA EN PANTALLA..