#include "Calculos.h"
#include "Printer.h"
#include "Validacion.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int pedirTipoContrato(){
    int tipo_contrato;
    cout << "Ingrese el tipo de contrato: " << endl;
    cout << "1. Por Horas" << endl;
    cout << "2. Base + Prestaciones" << endl;
    cout << "3. Comisiones" << endl;
    cin >> tipo_contrato;
    return tipo_contrato;
}

//funcion de pide la tarifa por hora
double pedirTarifaPorHora(){
    double tarifaxhora;
    cout << "Ingrese la tarifa por hora: " ;
    cin >> tarifaxhora;
    return tarifaxhora;
}

//funcion qde los ingresos de las horas trabajadas
double pedirHorasTrabajadas(){
    double horas;
    cout << "Ingrese las horas trabajadas: ";
    cin >> horas;
    return horas;
}

//funcion que pide el sueldo base
double pedirSueldoBase(){
    double sueldo_base;
    cout << "Ingrese el sueldo base: " ;
    cin >> sueldo_base;
    return sueldo_base;
}

//funcion que pide prestaciones
double pedirPrestaciones(){
    double prestaciones;
    cout << "Ingrese las prestaciones: " ;
    cin >> prestaciones;
    return prestaciones;
}

//funcion que pide el ingreso de1 las deducciones
double pedirDeducciones(){
    double deducciones;
    cout << "Ingrese las deducciones: " ;
    cin >> deducciones;
    return deducciones;
}

//funcion que pide el porcentaje de comision
double pedirPorcentajeComision(){
    double porcentaje_comision;
    cout << "Ingrese el porcentaje de comision: " ;
    cin >> porcentaje_comision;
    return porcentaje_comision;
}

//funcion que pide unidades vendidas
double pedirUnidadesVendidas(){
    double unidades_vendidas;
    cout << "Ingrese las unidades vendidas: ";
    cin >> unidades_vendidas;
    return unidades_vendidas;
}

//funcion de unidades vendidas
vector<double> pedirPreciosVentas(int unidades_vendidas){
    vector<double> precioAutos;
    for (int i = 0; i < unidades_vendidas; i++){
        double precio;
        cout << "Ingrese el precio de la venta " << i+1 << ": ";
        cin >> precio;
        precioAutos.push_back(precio);
    }
    return precioAutos;
}


int main(int argc, char const *argv[])
{
    int seleccion = 1;
    while(seleccion != 0){
        //Se pregunta si se desea comenzar con la lectura de un archivo
        cout << "Quiere calcular el salario de los empleados?" << endl;
        cout << "1. Si. 0. No. : ";
        cin >> seleccion; cout<<endl;
        if(seleccion == 1){
            string nombreArch;
            //Se pregunta el nombre del archivo
            cout<<"Introduzca el nombre del archivo: "; cin>>nombreArch; cout<<endl;
            if (existeArch(nombreArch)){
                ifstream archivo(nombreArch);
                if (!vacio(archivo)){
                    string linea;
                    int contador = 0;
                    vector<string> Datos;
                    while(!archivo.eof()){
                        getline(archivo, linea);
                        contador++;
                        if (datosValidos(linea, contador, Datos)){

                        }
                    }

                }//else archivo esta vacio
            }//else archivo no existe
        }//si es 0 se apaga
    }
    return 0;


    /*
    int tipo_contrato;
    tipo_contrato = pedirTipoContrato();
    double sueldo=0;
    if (tipo_contrato == 1){ //si el tipo de contrato es 1
        double tarifaxhora;
        double horas;
        tarifaxhora = pedirTarifaPorHora();
        horas = pedirHorasTrabajadas();
        sueldo = Calculos::Metodo1(tarifaxhora, horas);
        Printer::printResults(sueldo);
    }
    else if (tipo_contrato == 2){ //si ingresos de tipo 2
        double sueldo_base;
        sueldo_base = pedirSueldoBase();
        double prestaciones;
        prestaciones = pedirPrestaciones();
        double deducciones;
        deducciones = pedirDeducciones();
        sueldo = Calculos::Metodo2(sueldo_base, prestaciones, deducciones);
        Printer::printResults(sueldo);
    }
    else if (tipo_contrato == 3){ //ingresos de tipo 3
        double porcentaje_comision;
        porcentaje_comision = pedirPorcentajeComision();
        double unidades_vendidas;
        unidades_vendidas = pedirUnidadesVendidas();
        vector<double> precios = pedirPreciosVentas(unidades_vendidas);
        sueldo = Calculos::Metodo3(porcentaje_comision, precios);
        Printer::printResults(sueldo);
    }
    return 0;
    */
}