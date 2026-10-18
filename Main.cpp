#include <iostream>
#include <fstream>
#include <string>
#include "ColaPacientes.hpp"
#include "Seccion.hpp"
#include "Hospital.hpp"
using namespace std;


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

        string nombre;
        string servicio;
        string id;
        int edad = 0;
        int partes = 0;

        while (*puntero != '\0') //mientas no sea el final de la linea.. importante las '' es un caracter
        {
            if (*puntero == ';')
            {
                *puntero = '\0'; //asi se corta la palabra

                switch (partes) //switch porque soy un pro..
                {
                case 0:
                    id = inicioPalabra;
                    break;
                case 1:
                    nombre = inicioPalabra;
                    break;
                case 2:
                    edad = stoi(inicioPalabra);
                    break;
                default:
                    cout<<"Algo salió mal.."<<endl;
                    break;
                }

                inicioPalabra = puntero + 1;
                partes++;
            }
            puntero++; //este va letra por letra..
        
            
        }
        servicio = inicioPalabra; //donde quedo el puntero al final.. ya que no tiene ;

        Paciente* nuevoPaciente = new Paciente(nombre,edad,id,servicio);
        filaPacientes.ingresar(nuevoPaciente);
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
