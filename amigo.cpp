#include "Amigo.h"
#include <cstring>

Amigo::Amigo() {
    strcpy_s(nombre, "");
    edad = 0;
    sexo = ' ';
    estado = 'A';
}

Amigo::Amigo(const char nom[], int ed, char sx) {
    strcpy_s(nombre, nom);
    edad = ed;
    sexo = sx;
    estado = 'A';
}

void Amigo::setAmigo(const char nom[], int ed, char sx) {
    strcpy_s(nombre, nom);
    edad = ed;
    sexo = sx;
    estado = 'A';
}

char* Amigo::getNombre() { return nombre; }
int Amigo::getEdad() { return edad; }
char Amigo::getSexo() { return sexo; }
char Amigo::getEstado() { return estado; }

void Amigo::guardarArchivo(ofstream& fsalida) {
    fsalida.write(nombre, sizeof(nombre));
    fsalida.write(reinterpret_cast<char*>(&edad), sizeof(edad));
    fsalida.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
    fsalida.write(reinterpret_cast<char*>(&estado), sizeof(estado));
}

bool Amigo::leerArchivo(ifstream& fentrada) {

    if (!fentrada.read(nombre, sizeof(nombre))) return false;

    fentrada.read(reinterpret_cast<char*>(&edad), sizeof(edad));
    fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
    fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));

    return true;
}

bool Amigo::buscar(ifstream& fentrada, int nroReg) {

    fentrada.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);

    return leerArchivo(fentrada);
}

bool Amigo::eliminar(fstream& fes, int nroReg) {

    fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
    fes.read(reinterpret_cast<char*>(this), sizeof(Amigo));

    if (fes.eof()) return false;

    estado = 'E';

    fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
    fes.write(reinterpret_cast<char*>(this), sizeof(Amigo));

    return true;
}

bool Amigo::modificar(fstream& fes, int nroReg) {

    fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
    fes.write(reinterpret_cast<char*>(this), sizeof(Amigo));

    return true;
}

int Amigo::getTamBytesRegistro() {
    return sizeof(nombre) + sizeof(edad) + sizeof(sexo) + sizeof(estado);
}
