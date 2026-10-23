#include <iostream>
#include <fstream>
#include <string>
#include "ColaPacientes.hpp"
#include "Seccion.hpp"
#include "Hospital.hpp"
#include <cmath>
using namespace std;

bool textoConContenido(const string& texto)
{
    for (size_t i = 0; i < texto.size(); i++)
    {
        if (texto[i] != ' ' && texto[i] != '\t' && texto[i] != '\r')
            return true;
    }
    return false;
}

bool tipoDolorValido(const string& tipo)
{
    return tipo == "pecho" ||
           tipo == "cabeza" ||
           tipo == "abdomen" ||
           tipo == "extremidad" ||
           tipo == "otro";
}

bool datosClinicosValidos(
    const string& id, const string& nombre, int edad,
    float temperatura, int presion, int dolor,
    const string& tipoDolor, int trauma, int sintomas,
    int cirugia, int dias)
{
    if (!textoConContenido(id) || !textoConContenido(nombre))
        return false;
    if (edad < 0 || edad > 120)
        return false;
    if (!std::isfinite(temperatura) ||
        temperatura < 30.0f ||
        temperatura > 45.0f)
        return false;
    if (presion < 40 || presion > 260)
        return false;
    if (dolor < 0 || dolor > 10)
        return false;
    if (!tipoDolorValido(tipoDolor))
        return false;
    if (trauma != 0 && trauma != 1)
        return false;
    if (sintomas != 0 && sintomas != 1)
        return false;
    if (cirugia != 0 && cirugia != 1)
        return false;
    if (dias < 0)
        return false;

    return true;
}

bool convertirEntero(string texto, int& resultado)
{
    try
    {
        size_t caracteresLeidos = 0;
        int numero = stoi(texto, &caracteresLeidos);

        if (caracteresLeidos != texto.size())
            return false;

        resultado = numero;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool convertirDecimal(string texto, float& resultado)
{
    try
    {
        size_t caracteresLeidos = 0;
        float numero = stof(texto, &caracteresLeidos);

        if (caracteresLeidos != texto.size())
            return false;

        resultado = numero;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    ColaPacientes filaPacientes;
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo.." << endl;
        return 1;
    }
    char linea[500]; //array de caracteres para la linea..
    while(archivo.getline(linea,500)){
        char* puntero = linea; //puntero que recorre la linea..
        char* inicioPalabra = linea; //se queda al principio sin avanzar..

        //las nuevas variables del taller 2
        string id, nombre, tipoDolor;
        int edad = 0, presion = 0, dolor = 0, trauma = 0, sintomas = 0, cirugia = 0, dias = 0;
        float temperatura = 0.0;
        int partes = 0;

        bool lineaValida = true;
        int separadores = 0;
        bool campoConContenido = false;

        for (char* revisar = linea; ; revisar++)
        {
            if (*revisar == ';' || *revisar == '\0')
            {
                if (!campoConContenido)
                    lineaValida = false;

                if (*revisar == '\0')
                    break;

                separadores++;
                campoConContenido = false;
            }
            else if (*revisar != ' ' && *revisar != '\t' && *revisar != '\r')
            {
                campoConContenido = true;
            }
        }

        if (separadores != 10)
            lineaValida = false;

        if (!lineaValida)
        {
            cout << "Linea invalida ignorada: formato incorrecto." << endl;
            continue;
        }

        while (*puntero != '\0') //mientas no sea el final de la linea.. importante las '' es un caracter
        {
            if (*puntero == ';')
            {
                *puntero = '\0'; //asi se corta la palabra

                switch (partes)//solo hacemos mas largo el switch..
                {
                case 0:
                    id = inicioPalabra;
                    break;
                case 1:
                    nombre = inicioPalabra;
                    break;
                case 2:
                    if (!convertirEntero(inicioPalabra, edad))
                        lineaValida = false;
                    break;
                case 3:
                    if (!convertirDecimal(inicioPalabra, temperatura))
                        lineaValida = false;
                    break;
                case 4:
                    if (!convertirEntero(inicioPalabra, presion))
                        lineaValida = false;
                    break;
                case 5:
                    if (!convertirEntero(inicioPalabra, dolor))
                        lineaValida = false;
                    break;
                case 6:
                    tipoDolor = inicioPalabra;
                    break;
                case 7:
                    if (!convertirEntero(inicioPalabra, trauma))
                        lineaValida = false;
                    break;
                case 8:
                    if (!convertirEntero(inicioPalabra, sintomas))
                        lineaValida = false;
                    break;
                case 9:
                    if (!convertirEntero(inicioPalabra, cirugia))
                        lineaValida = false;
                    break;
                default:
                    lineaValida = false;
                    break;
                }

                inicioPalabra = puntero + 1;
                partes++;
            }
            puntero++; //este va letra por letra..
        
            
        }
        if (!convertirEntero(inicioPalabra, dias))
            lineaValida = false;

        if (lineaValida && !datosClinicosValidos(
            id, nombre, edad, temperatura, presion,
            dolor, tipoDolor, trauma, sintomas,
            cirugia, dias))
        {
            lineaValida = false;
        }

        
        if (lineaValida && filaPacientes.existePaciente(id))
        {
            cout << "Paciente duplicado ignorado. ID: "
                << id << endl;
            continue;
        }


        if (lineaValida)
        {
            Paciente* nuevoPaciente = new Paciente(
                id, nombre, edad, temperatura, presion,
                dolor, tipoDolor, trauma, sintomas,
                cirugia, dias
            );

            filaPacientes.ingresar(nuevoPaciente);
        }
        else
        {
            cout << "Linea invalida ignorada: datos incorrectos." << endl;
        }
    }
    archivo.close();

    filaPacientes.mostrarCola();

    Hospital hospital;

    hospital.ingresarSeccion("Urgencias");
    hospital.ingresarSeccion("Medicina General");
    hospital.ingresarSeccion("Cardiologia");
    hospital.ingresarSeccion("Neurologia");
    hospital.ingresarSeccion("Traumatologia");
    hospital.ingresarSeccion("Cirugia");
    hospital.ingresarSeccion("Pediatria");
    hospital.ingresarSeccion("Hospitalizacion");

    //Si quieren despues el menu lo metemos en una clase para que este mas ordenado o no??
    int opcion = 0;

    do
    {
        cout<<"=== HOSPITAL PAMPILLA ==="<<endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout<<""<<endl;
        cout << "Seleccionar opcion: ";

        cin >> opcion; //Leemos la opción..
        cin.ignore();

        switch (opcion)
        {
        case 1:{//si sacas estas llaves explota todo..
            int cantidadP = 0;
            filaPacientes.mostrarCola();//ARREGLAR EL OUTPUT, QUE SE VEA TAL COMO EN EL EJ DEL TALLER
            cout<<""<<endl;
            cout<<"Ingrese la cantidad de pacientes a atender.."<<endl;
            cin >> cantidadP;
            //ocupamos el metodo atenderPacientes..
            hospital.atenderPacientes(filaPacientes,cantidadP);
            break;
        }
        case 2:{
            int opcionSeccion;
            hospital.mostrarSecciones();//ARREGLAR EL FORMATO DEL OUTPUT TAMBIEN..
            cout<<""<<endl;
            cout << "Selecciona una opcion: "<<endl;
            cin >> opcionSeccion;

            string nombreBusqueda = "";
            switch (opcionSeccion) {
                case 1: nombreBusqueda = "Urgencias"; break;
                case 2: nombreBusqueda = "Medicina General"; break;
                case 3: nombreBusqueda = "Cardiologia"; break;
                case 4: nombreBusqueda = "Neurologia"; break;
                case 5: nombreBusqueda = "Traumatologia"; break;
                case 6: nombreBusqueda = "Cirugia"; break;
                case 7: nombreBusqueda = "Pediatria"; break;
                case 8: nombreBusqueda = "Hospitalizacion"; break;
                default: cout << "Opcion no valida." << endl; break;
            }
            //acca tenemos que convertir la opcion a string del nombre de la seccion elegida..
            
            if (nombreBusqueda != "") { 
                Seccion* sec = hospital.buscarSeccion(nombreBusqueda);
                if (sec != nullptr) { 
                    cout << endl;
                    sec->mostrarEstado();
                } else {
                    cout << "Departamento no encontrado." << endl;
                }
            }

            break;
        }
        case 3:{

            break;
        }
            
        case 4:{
            cout<<"Hasta luego pariente :p"<<endl;
            break;
        }
            
        default:
            cout<<"Algo salió mal ;("<<endl;
            break;
        }
    } while (opcion!=4);
    



    return 0;
}
