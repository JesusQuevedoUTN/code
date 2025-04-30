#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

const int fila = 3;

void sumarDiagonal(int mat[fila][fila], int fila);
void sumarDiagonalInversa(int mat[fila][fila], int fila);


int main()
{
    /*
    3) Realizá un programa que permita al usuario ingresar una matriz de enteros de NxN (cuadrada).
    La computadora debe mostrar la suma de los elementos de la diagonal principal y la suma de los
    elementos de la diagonal secundaria.
    */
    int matriz[3][3] = { {2 , 6, 6}, { -1, 5, -3}, {-15, -5, 10}};
    
    sumarDiagonal(matriz, fila);
    sumarDiagonalInversa(matriz, fila);

    return 0;
}

void sumarDiagonal(int mat[fila][fila], int fila)
{
    int suma=0;
    for (int i = 0; i < fila; i++)
    {
        suma += mat[i][i];
    }
    printf("Diag 1: %d\n", suma);
}
void sumarDiagonalInversa(int mat[fila][fila], int fila)
{
    int suma=0;
    for (int i = 0; i < fila; i++)
    {
        suma += mat[i][fila-1-i];
    printf("Diag 2: %d\n", suma);
    }
}