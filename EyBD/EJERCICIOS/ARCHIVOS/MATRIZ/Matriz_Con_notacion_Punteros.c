#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cuad(x) x*x

void pausa(void);
void cargarMatriz(int **, int, int, int, int);
void mostrarMatriz(int **, int, int);
void Convierte_a_Transpuesta(int **, int, int, int **);

int main()
{
    int fila, columna;
    int CotaSup = 200, CotaInf = 10;
    srand(time(NULL)); // Semilla Aleatoria
    printf("%d\n",cuad(2));
    printf("DEFINAMOS DE CUANTO QUEREMOS LA MATRIZ\n");
    printf("Por lo cual te pediremos las filas y las columnas\n\n");
    printf("Defina la cantidad de filas: ");
    scanf("%d", &fila);
    printf("Defina la cantidad de columnas: ");
    scanf("%d", &columna);

    // Reserva de memoria para la matriz
    int **matriz = (int **)malloc(fila * sizeof(int *));
    int **transpuesta = (int **)malloc(columna * sizeof(int *));

    // Rellenamos los espacios de Memoria
    // segun lo pedido por el usuario para la matriz
    for (int i = 0; i < fila; i++)
    
    //Dada una matriz de 8 x 8 cargadas con valores del 0 al 10, se pide determinar cuantos valores del 0 al 10 existen dentro de la matriz, determinar quien fue el que tuvo mas, y mostrar las posiciones dentro de la matriz en las cuales aparece.
//Se necesita crear una matriz de 5 x 5, que ingresen números múltiplos de 2 que no se repitan en la misma y que una vez llenada, recién ahí finalice su carga, y pueda mostrarla.

    {
        matriz[i] = (int *)malloc(columna * sizeof(int));
    }

    // Rellenamos los espacios de Memoria para la transpuesta
    // La transpuesta tendrá el tamaño de columna x fila
    for (int i = 0; i < columna; i++)
    {
        transpuesta[i] = (int *)malloc(fila * sizeof(int));
    }

    cargarMatriz(matriz, fila, columna, CotaInf, CotaSup);
    // Mostrar la matriz original
    printf("Matriz:\n");
    mostrarMatriz(matriz, fila, columna);

    // Generar y mostrar la matriz transpuesta
    Convierte_a_Transpuesta(matriz, fila, columna, transpuesta);
    printf("\nTranspuesta:\n");
    mostrarMatriz(transpuesta, columna, fila);

    // Liberar la memoria al finalizar
    printf("\n\nEstamos por liberar la memoria Dinamica que generamos\n");
    printf("Se borrara la Matriz Original y la Transpuesta\n");
    pausa();
    printf("Liberamos Matriz Original !!\n");
    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    printf("Liberamos Matriz Transpuesta !!\n");
    for (int i = 0; i < columna; i++)
    {
        free(transpuesta[i]);
    }
    free(transpuesta);

    printf("\n\nMemoria Dinamica Liberada!!!!\n");
    pausa();
    return 0;
}

void cargarMatriz(int **matriz, int fila, int columna, int cotaInf, int cotaSup)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            *(*(matriz + i) + j) = rand() % (cotaSup - cotaInf + 1) + cotaInf;
        }
    }
}

void mostrarMatriz(int **matriz, int fila, int columna)
{
    for (int i = 0; i < fila; i++)
    {   
        for (int j = 0; j < columna; j++)
        {
            printf("%4d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

void Convierte_a_Transpuesta(int **matriz, int fila, int columna, int **transpuesta)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            *(*(transpuesta + j) + i) = *(*(matriz + i) + j);
        }
    }
}

void pausa(void)
{
    printf("\nPresione Enter para continuar...");
    fflush(stdin);
    getchar();
}
