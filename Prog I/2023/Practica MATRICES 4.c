#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

#define FILAS 4
#define COLUMNAS 2

void mostrarSumatoriaFilaEnOrden(int mat[FILAS][COLUMNAS]);
int sumarFila(int vec[]);


int main()
{
    /*
    4) Realizá un programa que permita al usuario ingresar una matriz de enteros de NxM. La
    computadora debe mostrar la sumatoria de cada fila, ordenadas de mayor a menor.
    */
    int matriz[FILAS][COLUMNAS];
    leerMatrizDeEnteros("Ingrese la matriz de NxM", FILAS, COLUMNAS, matriz);
    
    mostrarSumatoriaFilaEnOrden(matriz);

    return 0;
}

void mostrarSumatoriaFilaEnOrden(int mat[FILAS][COLUMNAS]){
    int sumatoria[FILAS];
    for (int i = 0; i < FILAS; i++)
    {
        sumatoria[i] = sumarFila(mat[i]);
    }
    ordenarVectorDeEnterosAscendente(sumatoria,FILAS);
    mostrarVectorDeEnteros(sumatoria,FILAS);
}

int sumarFila(int vec[]){
    int a=0; 
    for (int i = 0; i < COLUMNAS; i++)
    {
        a+=vec[i];
    }
    return a;
}