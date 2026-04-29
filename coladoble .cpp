#include <iostream>
#include "DDQueue.h"

using namespace std;

int main() {
    DDQueue cola;

    for (char c = 'A'; c <= 'Z'; c++) {
        cola.put_back(c);
    }
   
    for (int i = 9; i >= 0; i--) {
        cola.put_front(i + '0');
    }

    cout << "Contenido de la cola (de frente a fondo):" << endl;

    while (!cola.empty()) {
        cout << cola.get_front() << " ";
    }

    cout << "\n\nFin del programa.\n";
    return 0;
}}
