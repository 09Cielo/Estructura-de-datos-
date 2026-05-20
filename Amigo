#include "ABAmigo.h"

ABAmigo::ABAmigo(string nomArch) {

    nomArchivo = nomArch;
}

void ABAmigo::introducirDatos(Amigo& newReg) {

    char nombre[30];
    char fecha[15];
    char sexo;

    cin.ignore();

    cout << "\nNombre: ";
    cin.getline(nombre, 30);

    cout << "Fecha de nacimiento (dd/mm/yyyy): ";
    cin.getline(fecha, 15);

    cout << "Sexo (M/F): ";
    cin >> sexo;

    newReg.setAmigo(nombre, fecha, sexo);
}

void ABAmigo::mostrarRegistro(int nroReg) {

    cout << endl
        << nroReg << ". "
        << amig.getNombre() << " | "
        << amig.getFechaNacimiento() << " | "
        << amig.getSexo() << " | "
        << amig.getEstado();
}

void ABAmigo::adicionarNuevo() {

    ofstream fsalida(nomArchivo, ios::app | ios::binary);

    introducirDatos(amig);

    amig.guardarArchivo(fsalida);

    fsalida.close();
}

void ABAmigo::listar() {

    ifstream fentrada(nomArchivo, ios::binary);

    int contador = 0;

    while (amig.leerArchivo(fentrada)) {

        contador++;

        if (amig.getEstado() == 'A') {

            mostrarRegistro(contador);
        }
    }

    fentrada.close();
}

int ABAmigo::buscarReg() {

    int nroReg;

    cout << "\nNumero de registro: ";
    cin >> nroReg;

    ifstream fentrada(nomArchivo, ios::binary);

    if (amig.buscar(fentrada, nroReg)) {

        mostrarRegistro(nroReg);
    }
    else {

        cout << "\nRegistro no existe";

        nroReg = -1;
    }

    fentrada.close();

    return nroReg;
}

void ABAmigo::eliminarReg() {

    int nroReg = buscarReg();

    if (nroReg > 0) {

        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);

        if (amig.eliminar(fes, nroReg)) {

            cout << "\nRegistro eliminado";
        }
        else {

            cout << "\nNo se pudo eliminar";
        }

        fes.close();
    }
}

void ABAmigo::modificarReg() {

    int nroReg = buscarReg();

    if (nroReg > 0) {

        introducirDatos(amig);

        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);

        amig.modificar(fes, nroReg);

        fes.close();

        cout << "\nRegistro modificado";
    }
}
