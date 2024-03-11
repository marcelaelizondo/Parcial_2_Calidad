#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class Calculos
{
public:
    static float Metodo1(float tarifa, int horas)
    {
        float sueldo = tarifa * horas;
        return sueldo;
    }
    static float Metodo2(float base, float prestaciones, float deducciones)
    {
        float sueldo = base - deducciones + prestaciones;
        return sueldo;
    }

    static float Metodo3(float porcentajeComision, vector<float> &precioCarros)
    {
        float suma=0;
        float sueldo;
        porcentajeComision = porcentajeComision / 100;
        for (int i = 0; i < precioCarros.size(); i++)
        {
            suma += precioCarros[i];
        }
        sueldo = suma * porcentajeComision;
        return sueldo;
    }
};
