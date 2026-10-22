#include "NodoPregunta.hpp"

NodoPregunta::NodoPregunta(string texto) {
    this->texto = texto;
    this->hijoSi = nullptr;
    this->hijoNo = nullptr;
}

NodoPregunta::~NodoPregunta() {//asi eliminamos todo el arbol
    if (hijoSi != nullptr) {
        delete hijoSi;
    }
    if (hijoNo != nullptr) {
        delete hijoNo;
    }
}
string NodoPregunta::getTexto() {return this->texto;}
NodoPregunta* NodoPregunta::getHijoSi() {return this->hijoSi;}
NodoPregunta* NodoPregunta::getHijoNo() {return this->hijoNo;}
void NodoPregunta::setHijoSi(NodoPregunta* nodo) {
    this->hijoSi = nodo;
}
void NodoPregunta::setHijoNo(NodoPregunta* nodo) {
    this->hijoNo = nodo;
}
bool NodoPregunta::esServicioFinal() {
    return (this->hijoSi == nullptr && this->hijoNo == nullptr);
}