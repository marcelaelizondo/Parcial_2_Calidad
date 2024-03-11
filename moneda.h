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

int main() {
    ConversorMonetario conversor(20.0); // Supongamos que la tasa inicial es de 20 pesos por dólar
    float cantidadEnPesos = 1000.0;
    float cantidadEnDolares = 50.0;
    cout << cantidadEnPesos << " pesos equivalen a " << conversor.convertirPesosADolares(cantidadEnPesos) << " dólares." << std::endl;
    cout << cantidadEnDolares << " dólares equivalen a " << conversor.convertirDolaresAPesos(cantidadEnDolares) << " pesos." << std::endl;

    conversor.cambiarTasaDeCambio(18.5); // Cambiamos la tasa de cambio a 18.5 pesos por dólar
    cout << cantidadEnPesos << " pesos equivalen a " << conversor.convertirPesosADolares(cantidadEnPesos) << " dólares." << std::endl;
    cout << cantidadEnDolares << " dólares equivalen a " << conversor.convertirDolaresAPesos(cantidadEnDolares) << " pesos." << std::endl;

    return 0;
}
