#pragma once
#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class ColaCircular {
private:
    string datos[MAX];
    int frente;
    int fin;
    int cantidad;

public:
    ColaCircular();
    bool estaLlena();
    bool estaVacia();
    bool encolar(string valor);
    string desencolar();
    void mostrar();
};
