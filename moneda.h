#include <iostream>

using namespace std;

class ConversorMonetario {
private:
    float tasaDeCambio;

public:
    ConversorMonetario(float tasaInicial) {
        tasaDeCambio = tasaInicial;
    }

    void cambiarTasaDeCambio(float nuevaTasa) {
        tasaDeCambio = nuevaTasa;
    }

    float convertirPesosADolares(float cantidadEnPesos) {
        return cantidadEnPesos / tasaDeCambio;
    }

    float convertirDolaresAPesos(float cantidadEnDolares) {
        return cantidadEnDolares * tasaDeCambio;
    }
};
