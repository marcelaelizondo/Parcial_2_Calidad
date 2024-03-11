#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Salida{
public:
    string nombre;
    int numeroNomina;
    string categoria;
    float sueldo;


    Salida(){
        nombre = "";
        categoria = "";
        numeroNomina = 0 ;
        sueldo = 0.0;
    }
};

void imprimirNombre(Salida empleado) {
    cout << "Nombre: " << empleado.nombre << "\t | ";
}

void imprimirSueldo(Salida empleado) {
    cout << "Pago: $" << empleado.sueldo << endl;
}

void imprimirNumeroNomina(Salida empleado){
    cout << "Nómina: ";
    if(empleado.numeroNomina > 0){
        cout << "#" << empleado.numeroNomina << " | ";
    }else{
        cout << "Numero no válido | ";
    }
}

void imprimirCategoria(Salida empleado){
    cout << "Tipo de Categoría: ";
    if(empleado.categoria != "1" && empleado.categoria != "2" && empleado.categoria != "3"){
        cout << "No válida | ";
    }else{
        cout << empleado.categoria << " | ";
    }
}

void imprimirSalida(Salida empleado) {
    imprimirNombre(empleado);
    imprimirNumeroNomina(empleado);
    imprimirCategoria(empleado);
    imprimirSueldo(empleado);
}