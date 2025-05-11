#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define N 50
#define p printf
#define s scanf

void cargaVector(int[], int);
int* buscarPrimosyCarga(int[], int*);
void mostrarVector(int[], int, char *);
void pausa(void);
bool esPrimo(int);

int main()
{
    int vec1[N], cantprimos = 0;// es la cantidad por la que asignaras dinámicamente memoria para el vector de primos
    int* Vecprimos = NULL; // esto es porque asignare memoria dinamica
    #ifdef _WIN32
        system("chcp 65001 < nul");
    #endif

    srand(time(NULL));
    cargaVector(vec1, N);
    mostrarVector(vec1, N, "El Vector original");
    pausa();

    Vecprimos = buscarPrimosyCarga(vec1, &cantprimos);

    mostrarVector(Vecprimos, cantprimos, "Números Primos");
    p("\nLa cantidad de numeros primos que tiene el vector es %d\n", cantprimos);

    free(Vecprimos);
    // Liberamos la memoria asignada para el vector de primos
    pausa();
}

void cargaVector(int x[], int y)
{
    int i;
    int cs = 100, ci = 1;
    for (i = 0; i < y; i++)
    {
        x[i] = rand() % (cs - ci + 1) + ci;
    }
}

int* buscarPrimosyCarga(int x[], int* numPrimos) {
    int* vec = malloc(sizeof(int));
    int valor;

    for(int i = 0 ; i<N ; i++){
        if(esPrimo(x[i])){
            *numPrimos = *numPrimos + 1;
            vec = (int*)realloc(vec, *numPrimos * sizeof(int));
            vec[*numPrimos - 1] = x[i];
        }
    }
    return vec;
}

bool esPrimo(int num)
{
    //5
    int i = 2;
        while(num%i!=0 && i < num){
            i++;
        }
    return i==num || num == 1;
}

void mostrarVector(int x[], int y, char* msj)
{
    p("%s\n", msj);
    for(int i = 0 ; i<y ; i++)
    {
        p("%4d", x[i]);
    }
}

void pausa(void) {
    printf("\n\nPresione Enter para continuar...\n\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

