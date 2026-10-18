#include "Paciente.hpp"

class NodoPaciente //representa al paciente en la lista enlazada general del sistema
{
private:
    Paciente* paciente;
    NodoPaciente* sgte = nullptr;
public:
    NodoPaciente(Paciente* p);
    Paciente* getPaciente();
    void setSgte(NodoPaciente* nuevo);
    NodoPaciente* getSgte();
    ~NodoPaciente();
};
