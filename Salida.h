#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Salida{
public:
    string nombre;
    string numeroNomina;
    string categoria;
    float sueldo;


    Salida(){
        nombre = "";
        numeroNomina = "" ;
        categoria = "";
        sueldo = 0.0;
    }

    Salida(string nom, string numNomina, string cat, float suel){
        nombre = nom;
        numeroNomina = numNomina;
        categoria = cat;
        sueldo = suel;
    }
};

void imprimirNombre(Salida empleado) {
    cout << "Nombre: " << empleado.nombre << "\t | ";
}

void imprimirSueldo(Salida empleado) {
    cout << "Pago: $" << empleado.sueldo << endl;
}

void imprimirNumeroNomina(Salida empleado){
    cout << empleado.numeroNomina << " | ";
}

void imprimirCategoria(Salida empleado){
    cout << "Tipo de Categoria: "<< empleado.categoria << " | ";
}

void imprimirSalida(Salida empleado) {
    imprimirNombre(empleado);
    imprimirNumeroNomina(empleado);
    imprimirCategoria(empleado);
    imprimirSueldo(empleado);
}