#include <iostream>
#include "vector.h"

using namespace std;

vector::vector(void)
{
    for (int i = 0; i < 10; i++)
        vec[i] = 0;
    n = 0;
}

vector::~vector(void)
{
}

void vector::cargarVector(int vec[], int n)
{
    int nota1, nota2, nota3, mejor;

    for (int i = 0; i < n; i++)
    {
        cout << "Alumno " << i + 1 << endl;
        cout << "Nota 1: "; cin >> nota1;
        cout << "Nota 2: "; cin >> nota2;
        cout << "Nota 3: "; cin >> nota3;

       
        mejor = nota1;
        if (nota2 > mejor) mejor = nota2;
        if (nota3 > mejor) mejor = nota3;

        vec[i] = mejor;
    }
}

void vector::mostrarVector(int vec[], int n)
{
    cout << "\nMejores notas: ";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}

void vector::ordenarVector(int vec[], int n)
{
    int aux;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
