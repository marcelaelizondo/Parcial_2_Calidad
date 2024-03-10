#include <iostream>
using namespace std;
/*
  printResults
     Descripción: Imprime los resultados
     Parámetros :  double pay (pago)
     Salida     : N/A
*/
class Printer {
public:
    static void printResults(double pay) {
        cout << "El pago del empleado es de: " << " $" << pay;
    }
};