#include "Calculos.h"
#include "Printer.h"
#include "Validacion.h"
#include "Salida.h"
#include "moneda.h"
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
        // Crear vector de conversores
        vector<ConversorMonetario> conversores;
        conversores.push_back(ConversorMonetario("Dolar USD", 16.81)); // Tasa de cambio para el dolar (ejemplo)
        conversores.push_back(ConversorMonetario("Dolar CAD", 12.47)); // Tasa de cambio para el dolar (ejemplo)
        conversores.push_back(ConversorMonetario("Euro", 18.39)); // Tasa de cambio para el dolar (ejemplo)

        //Se pregunta si se desea comenzar con la lectura de un archivo
        cout << "Quiere calcular el salario de los empleados?" << endl;
        cout << "1. Si. 0. No. : ";
        cin >> seleccion; cout<<endl;
        if(seleccion == 1){
            ConversorMonetario nuevaMoneda("Peso mexicano", 1.0);
            // Mostrar la moneda actual
            cout << "La moneda actual es " << nuevaMoneda.obtenerNombre()<<endl;

            // Preguntar si se desea cambiar la moneda
            char cambiarMoneda;
            cout << "¿Desea cambiar la moneda? (s/n): ";
            cin >> cambiarMoneda;

            if (cambiarMoneda == 's' || cambiarMoneda == 'S') {
                cout << "Otras monedas disponibles:" << endl;
                for (int i = 0; i < conversores.size(); ++i) {
                    cout << i + 1 << ". " << conversores[i].obtenerNombre() << endl;
                }
                string moneda;
                cout << "Ingrese el nombre de la moneda que quiera usar, en caso de querer usar otra, ingrese 'Otra': ";
                cin.ignore(256, '\n');
                getline(cin,moneda);

                bool monedaExiste = false;

                // Verificar si la moneda seleccionada existe en el vector de conversores
                for (int i = 0; i < conversores.size(); ++i) {
                    if (conversores[i].obtenerNombre() == moneda) {
                        monedaExiste = true;
                        nuevaMoneda = conversores[i];
                        break;
                    }
                }

                // Si el usuario selecciona 'Otra', se solicita la tasa de cambio
                if (!monedaExiste && moneda != "Otra") {
                    cout << "Moneda no encontrada." << endl;
                    return 0;
                }

                if (moneda == "Otra") {
                    string nuevoNombre;
                    float nuevaTasa;
                    cout << "Ingrese el nombre de la moneda: ";
                    cin >> nuevoNombre;
                    cout << "Ingrese la tasa de cambio para la moneda " << nuevoNombre << ": ";
                    cin >> nuevaTasa;
                    nuevaMoneda = ConversorMonetario(nuevoNombre, nuevaTasa);
                }
            }

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
                        if (Datos.empty()){
                            break;
                        }
                        vector<float> preciosUni = result.second;
                        float sueldo;
                        string categoria = Datos[0];
                        switch(categoria[0]){
                            case '1':{
                                float tarifas = stof(Datos[3]);
                                int horas = stoi(Datos[4]);
                                sueldo = nuevaMoneda.convertirPesosAMoneda(Calculos::Metodo1(tarifas, horas));
                            } break;

                            case '2':{
                                float base = stof(Datos[3]);
                                float prestaciones = stof(Datos[4]);
                                float deducciones = stof(Datos[5]);
                                sueldo = nuevaMoneda.convertirPesosAMoneda(Calculos::Metodo2(base, prestaciones, deducciones));
                            }break;

                            case '3':{
                                float porcentaje = stof(Datos[3]);
                                sueldo = nuevaMoneda.convertirPesosAMoneda(Calculos::Metodo3(porcentaje, preciosUni));
                            } break;

                        }
                        string nombre = Datos[1];
                        string nomina = Datos[2];
                        Salida empleado(nombre, nomina,categoria,sueldo);
                        imprimirSalida(empleado);
                    }
                }else cout<<"El archivo se encuentra vacio"<<endl;
            }else {
                cout << "El archivo no existe o tiene un error de ortografia." << endl;
                cout << "Por favor, intente de nuevo." << endl << endl;
            }
        }
    }
    return 0;
}
