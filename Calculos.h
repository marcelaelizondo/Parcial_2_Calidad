
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class Calculos
{
public:
    static double Metodo1(double tarifa, int horas)
    {
        double sueldo = tarifa * horas;
        return sueldo;
    }
    static double Metodo2(double base, double prestaciones, double deducciones)
    {
        double sueldo = base - deducciones + prestaciones;
        return sueldo;
    }

    static double Metodo3(double porcentajeComision, vector<double> &precioCarros)
    {
        double suma;
        double sueldo;
        porcentajeComision = porcentajeComision / 100;
        for (int i = 0; i < precioCarros.size(); i++)
        {
            suma += precioCarros[i];
        }
        sueldo = suma * porcentajeComision;
        return sueldo;
    }
};