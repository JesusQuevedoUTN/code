#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

#define FILAS 2
#define COLUMNAS 2

void sumarMatrices(int matrizSuma[FILAS][COLUMNAS], int mat1[FILAS][COLUMNAS], int mat2[FILAS][COLUMNAS]);
void sumarVectorDeEnteros(int vectorSuma[COLUMNAS], int vec1[COLUMNAS], int vec2[COLUMNAS]);

int main()
{
    /*
    6) Realizá un programa que permita al usuario ingresar dos matrices de enteros de NxM. La
    computadora debe generar y mostrar la matriz suma
    */
    
    int matrizA[FILAS][COLUMNAS] = { {1,2}, {3,4} };
    int matrizB[FILAS][COLUMNAS] = { {5,6}, {7,8} };
    int matrizC[FILAS][COLUMNAS];
    sumarMatrices(matrizC, matrizA,matrizB);
    mostrarMatrizDeEnteros(FILAS,COLUMNAS,matrizC);
    return 0;
}

void sumarMatrices(int matrizSuma[FILAS][COLUMNAS], int mat1[FILAS][COLUMNAS], int mat2[FILAS][COLUMNAS]){
    for (int i = 0; i < FILAS; i++) {
        sumarVectorDeEnteros(matrizSuma[i],mat1[i],mat2[i]);
    }
}

void sumarVectorDeEnteros(int vectorSuma[COLUMNAS], int vec1[COLUMNAS], int vec2[COLUMNAS]){
    for (int i = 0; i < COLUMNAS; i++) {
            vectorSuma[i] = vec1[i] + vec2[i];
        }
}