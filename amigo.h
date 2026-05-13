.h #ifndef AMIGO_H
#define AMIGO_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Amigo {

private:
    char nombre[30];
    int edad;
    char sexo;
    char estado;

public:

    Amigo();
    Amigo(const char nom[], int ed, char sx);

    void setAmigo(const char nom[], int ed, char sx);

    char* getNombre();
    int getEdad();
    char getSexo();
    char getEstado();

    void guardarArchivo(ofstream& fsalida);
    bool leerArchivo(ifstream& fentrada);

    bool eliminar(fstream& fes, int nroReg);
    bool modificar(fstream& fes, int nroReg);
    bool buscar(ifstream& fentrada, int nroReg);

    int getTamBytesRegistro();
};

#endif
