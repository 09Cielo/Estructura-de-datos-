#include "ColaCircular.h"
ColaCircular::ColaCircular() {
    frente = 0;
    fin = -1;
    cantidad = 0;
}
bool ColaCircular::estaLlena() {
    return cantidad == MAX;
}

bool ColaCircular::estaVacia() {
    return cantidad == 0;
}

bool ColaCircular::encolar(string valor) {
    if (estaLlena()) return false;

    fin = (fin + 1) % MAX;
    datos[fin] = valor;
    cantidad++;
    return true;
}

string ColaCircular::desencolar() {
    if (estaVacia()) return "COLA VACÍA";

    string valor = datos[frente];
    frente = (frente + 1) % MAX;
    cantidad--;
    return valor;
}

void ColaCircular::mostrar() {
    if (estaVacia()) {
        cout << "Cola vacía.\n";
        return;
    }

    cout << "Contenido de la cola: ";
    int i = frente;
    for (int cont = 0; cont < cantidad; cont++) {
        cout << "[" << datos[i] << "] ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}
