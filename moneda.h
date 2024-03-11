#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ConversorMonetario {
private:
    string nombre;
    float tasaDeCambio;

public:
    ConversorMonetario(string nombreMoneda, float tasaInicial) : nombre(nombreMoneda), tasaDeCambio(tasaInicial) {}

    void cambiarTasaDeCambio(float nuevaTasa) {
        tasaDeCambio = nuevaTasa;
    }

    void cambiarNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    float convertirPesosAMoneda(float cantidadEnPesos) {
        return cantidadEnPesos / tasaDeCambio;
    }

    float convertirMonedaAPesos(float cantidadEnMoneda) {
        return cantidadEnMoneda * tasaDeCambio;
    }

    float obtenerTasaDeCambio() {
        return tasaDeCambio;
    }

    string obtenerNombre() {
        return nombre;
    }
};