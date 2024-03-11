#include "Calculos.h"
#include "Printer.h"
#include <vector>
#include <iostream>
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
}