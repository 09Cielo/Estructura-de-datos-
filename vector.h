#pragma once
class vector
{
private:
    int vec[10], n;

public:
    vector(void);      
    ~vector(void);     

    void cargarVector(int vec[], int n);  
    void mostrarVector(int vec[], int n); 
    void ordenarVector(int vec[], int n); 
};
