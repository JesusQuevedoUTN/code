#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens



int main()
{
    /*
    1) Realizá un programa que permita al usuario ingresar una matriz de enteros de NxM. La
    computadora debe mostrar el valor máximo:
    A) De cada fila.    B) De cada columna.     C) De la matriz
    */
    int fila = 3, columna=3;
    int matriz[3][3] = { {46 , 61, 6}, { -1, -5, -3}, {-10, -5, 1000000}};
    int maximo;
    
    puts("Maximo de cada fila:");
    for (int i = 0; i < fila; i++) {
        maximo = matriz[i][0];
        for (int j = 1; j < columna; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
        printf("Fila %d: %d\n", i + 1, maximo);
    }
    
    puts("Maximo de cada columna:");
    for (int i = 0; i < columna; i++)
    {
        maximo = matriz[0][i];
        for (int j = 1; j < fila; j++)
        {
            if (matriz[j][i] > maximo)
            {
                maximo = matriz[j][i];
            }
            
        }
        printf("Columna %d: %d\n", i + 1, maximo);
    }
    

    // Calcular el máximo de la matriz
    maximo = matriz[0][0];
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
    }
    printf("Maximo de la matriz: %d\n", maximo);

    return 0;
}