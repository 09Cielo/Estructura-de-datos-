#pragma once
#include <iostream>
using namespace std;

typedef char DATA_TYPE;

struct nodo {
    DATA_TYPE data;
    nodo* next;
    nodo* prev;
};
class Nodo {
public:
    DATA_TYPE data;
    Nodo* next;
    Nodo* prev;
};

class DDqueue {
    private:
        Nodo* cabeza;  // Apunta al primer nodo
        Nodo* cola;    // Apunta al último nodo
        int items;     // Cantidad de elementos

    public:
        DDQueue();
        ~DDQueue();

        void put_back(DATA_TYPE valor);

        void put_front(DATA_TYPE valor);

        DATA_TYPE get_front();

        DATA_TYPE get_back();


        bool empty() const;

        void mostrar() const;
    };
