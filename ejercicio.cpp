#include "Calculos.h"
#include "Printer.h"
#include "Validacion.h"
#include "Salida.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


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
                        auto result = datosValidos(linea, contador);
                        vector<string> Datos = result.first;
                        vector<float> preciosUni = result.second;
                        float sueldo;
                        string categoria = Datos[0];
                        string nombre = Datos[1];
                        string nomina = Datos[2];
                        switch(categoria[0]){
                            case '1':{
                                string tarifas = Datos[3];
                                string horas = Datos[4];
                                sueldo = Calculos::Metodo1(stof(tarifas), stoi(horas));
                            } break;

                            case '2':{
                                float base = stof(Datos[3]);
                                float prestaciones = stof(Datos[4]);
                                float deducciones = stof(Datos[5]);
                                sueldo = Calculos::Metodo2(base, prestaciones, deducciones);
                            }break;

                            case '3':{
                                float porcentaje = stof(Datos[4]);
                                sueldo = Calculos::Metodo3(porcentaje, preciosUni);
                            }break;

                        }
                        Salida empleado(nombre, stoi(nomina),categoria,sueldo);
                        imprimirSalida(empleado);
                    }
                }else cout<<"El archivo se encuentra vacio"<<endl;
            }else {
                cout << "El archivo no existe o tiene un error de ortografia." << endl;
                cout << "Por favor, intente de nuevo." << endl << endl;
            }
        }//si es 0 se apaga
    }
    return 0;
}