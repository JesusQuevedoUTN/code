#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

#define FILAS 2
#define COLUMNAS 3

void matrizTranspuesta(int matriz[FILAS][COLUMNAS]);

int main()
{
    /*
    5) Realizá un programa que permita al usuario ingresar una matriz de enteros de NxM. La
    computadora debe mostrar la matriz transpuesta.
    */
    int matriz[FILAS][COLUMNAS];
    leerMatrizDeEnteros("Ingrese la matriz de NxM", FILAS, COLUMNAS, matriz);
    
    matrizTranspuesta(matriz);

    return 0;
}

void matrizTranspuesta(int matriz[FILAS][COLUMNAS]){
    for (int i = 0; i < COLUMNAS; i++)
    {
        for (int j = 0; j < FILAS; j++)
        {
            printf("%d ", matriz[j][i]);
        }
        puts("");
    }
}