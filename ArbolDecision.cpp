
#include "ArbolDecision.hpp"
#include <iostream>
using namespace std;
#include <stdexcept>

ArbolDecision::ArbolDecision()
{
    // Primera pregunta del arbol
    raiz = new NodoPregunta("Edad < 14");

    // Preguntas internas
    NodoPregunta* trauma =
        new NodoPregunta("Trauma == 1");

    NodoPregunta* cirugia =
        new NodoPregunta("RequiereCirugia == 1");

    NodoPregunta* neurologia =
        new NodoPregunta("SintomasNeurologicos == 1");

    NodoPregunta* pecho =
        new NodoPregunta("TipoDolor == pecho");

    NodoPregunta* urgencias =
        new NodoPregunta("Temperatura >= 38.5 o Dolor >= 8");

    NodoPregunta* hospitalizacion =
        new NodoPregunta("DiasHospitalizacion >= 2");

    // Pregunta 1: edad
    raiz->setHijoSi(new NodoPregunta("Pediatria"));
    raiz->setHijoNo(trauma);

    // Pregunta 2: trauma
    trauma->setHijoSi(cirugia);
    trauma->setHijoNo(neurologia);

    // Pregunta 3: requiere cirugia
    cirugia->setHijoSi(new NodoPregunta("Cirugia"));
    cirugia->setHijoNo(new NodoPregunta("Traumatologia"));

    // Pregunta 4: sintomas neurologicos
    neurologia->setHijoSi(new NodoPregunta("Neurologia"));
    neurologia->setHijoNo(pecho);

    // Pregunta 5: dolor de pecho
    pecho->setHijoSi(new NodoPregunta("Cardiologia"));
    pecho->setHijoNo(urgencias);

    // Pregunta 6: temperatura o dolor intenso
    urgencias->setHijoSi(new NodoPregunta("Urgencias"));
    urgencias->setHijoNo(hospitalizacion);

    // Pregunta 7: dias de hospitalizacion
    hospitalizacion->setHijoSi(
        new NodoPregunta("Hospitalizacion")
    );

    hospitalizacion->setHijoNo(
        new NodoPregunta("Medicina General")
    );
}

ArbolDecision::~ArbolDecision()
{
    delete raiz;
}

// RECORRIDO PREORDEN
// Nodo -> Si -> No
void ArbolDecision::mostrarPreordenDesde(
    NodoPregunta* nodo) const
{
    if (nodo == nullptr)
        return;

    cout << nodo->getTexto() << endl;

    mostrarPreordenDesde(nodo->getHijoSi());
    mostrarPreordenDesde(nodo->getHijoNo());
}

// RECORRIDO INORDEN
// Si -> Nodo -> No
void ArbolDecision::mostrarInordenDesde(
    NodoPregunta* nodo) const
{
    if (nodo == nullptr)
        return;

    mostrarInordenDesde(nodo->getHijoSi());

    cout << nodo->getTexto() << endl;

    mostrarInordenDesde(nodo->getHijoNo());
}

// RECORRIDO POSTORDEN
// Si -> No -> Nodo
void ArbolDecision::mostrarPostordenDesde(
    NodoPregunta* nodo) const
{
    if (nodo == nullptr)
        return;

    mostrarPostordenDesde(nodo->getHijoSi());
    mostrarPostordenDesde(nodo->getHijoNo());

    cout << nodo->getTexto() << endl;
}

void ArbolDecision::mostrarPreorden() const
{
    mostrarPreordenDesde(raiz);
}

void ArbolDecision::mostrarInorden() const
{
    mostrarInordenDesde(raiz);
}

void ArbolDecision::mostrarPostorden() const
{
    mostrarPostordenDesde(raiz);
}

// CUENTA LAS HOJAS
int ArbolDecision::contarHojasDesde(
    NodoPregunta* nodo) const
{
    if (nodo == nullptr)
        return 0;

    if (nodo->esServicioFinal())
        return 1;

    return contarHojasDesde(nodo->getHijoSi())
         + contarHojasDesde(nodo->getHijoNo());
}

int ArbolDecision::contarServicios() const
{
    return contarHojasDesde(raiz);
}


bool ArbolDecision::evaluarPregunta(
    const string& pregunta, Paciente* paciente) const
{
    if (pregunta == "Edad < 14")
        return paciente->getEdad() < 14;

    if (pregunta == "Trauma == 1")
        return paciente->getTrauma() == 1;

    if (pregunta == "RequiereCirugia == 1")
        return paciente->getCirugia() == 1;

    if (pregunta == "SintomasNeurologicos == 1")
        return paciente->getSintomas() == 1;

    if (pregunta == "TipoDolor == pecho")
        return paciente->getTipoDolor() == "pecho";

    if (pregunta == "Temperatura >= 38.5 o Dolor >= 8")
        return paciente->getTemperatura() >= 38.5f
            || paciente->getDolor() >= 8;

    if (pregunta == "DiasHospitalizacion >= 2")
        return paciente->getDias() >= 2;

    throw logic_error("Pregunta no reconocida: " + pregunta);
}

string ArbolDecision::clasificarPaciente(
    Paciente* paciente, string& ruta) const
{
    ruta.clear();

    if (paciente == nullptr)
        return "";

    NodoPregunta* actual = raiz;

    while (actual != nullptr && !actual->esServicioFinal())
    {
        bool respuesta = evaluarPregunta(
            actual->getTexto(), paciente
        );

        if (!ruta.empty())
            ruta += " -> ";

        ruta += actual->getTexto();
        ruta += respuesta ? " [Si]" : " [No]";

        if (respuesta)
            actual = actual->getHijoSi();
        else
            actual = actual->getHijoNo();
    }

    if (actual == nullptr)
        throw logic_error("Arbol de decision incompleto");

    if (!ruta.empty())
        ruta += " -> ";

    ruta += actual->getTexto();

    return actual->getTexto();
}
