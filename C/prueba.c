#include "Libs/utils.h"

typedef struct 
{
    int x;
    int y;
}Punto;


void cargarHasta(Punto**,int*);
void mostrarPuntos(Punto**,int*);
void cargarPunto(Punto**, int*);

void cargarFuncion(Punto**,int*);
void meterPuntos(Punto**,int*);

int main() {
    Punto* funcion = NULL;
    int contador = 0;

    //cargarFuncion(&funcion, &contador);
    //meterPuntos(&funcion, &contador);
    cargarHasta(&funcion, &contador);
    mostrarPuntos(&funcion, &contador);

    free(funcion);
    return 0;
}

void mostrarPuntos(Punto** funcion, int* contador)
{
    printf("Funcion:\n");
    for (int i = 0; i < *contador ; i++)
    {
        printf("Punto %d: (%d,%d)\n", i, funcion[i]->x, funcion[i]->y);
    }
}

void cargarHasta(Punto** funcion, int* contador)
{
    int menu = -1;

    while (menu != 0)
    {
        printf("Desea agregar un nuevo punto a la funcion?");
        printf("[1] SI");
        printf("[0] NO");
        
        menu = LeerEnteroEntre(0,1);
        
        if (menu == 1)
        {
            cargarPunto(&funcion, &contador);
        }
    }
}

void cargarPunto(Punto** funcion, int* contador)
{
    Punto nuevo;
    *contador = *contador+1;
    *funcion = realloc(*funcion, sizeof(Punto)* *contador);
    printf("Insertar valor x del Punto %d:", *contador);
    scanf(" %d", &nuevo.x );
    printf("Insertar valor y de %d:", *contador);
    scanf(" %d", &nuevo.y );
    puts("");
    *funcion[*contador-1] = nuevo;
}

void cargarFuncion(Punto** funcion, int* contador)
{
    puts("Cuantos puntos va a tener la funcion?");
    scanf("%d", contador);
    *funcion = malloc(sizeof(Punto)* *contador);
}
void meterPuntos(Punto** funcion, int* contador)
{
    for (int i = 0; i < *contador ; i++)
    {
        printf("Insertar valor x de %d:", i+1);
        scanf(" %d", &funcion[i]->x );
        printf("Insertar valor y de %d:", i);
        scanf(" %d", &funcion[i]->y );
        puts("");
    }
}

