#include "Libs/utils.h"

typedef struct 
{
    char nombreAplicacion[15];
    char nombreCircuito[15];
    float version;
}Programa;

typedef struct 
{
    int numero;
    char nombre[15];
    char apellido[15];
    char escuderia[15];
}Corredor;

typedef struct 
{
    int numeroDeVuelta;
    int numeroDeCorredor;
    float temporizador;
}Tiempo;

void menu(Programa app){
    printf(
        "%s ------------------------\n----------------------------------------\n----------%s----------\n----------------------------------------\n----------------------------------------\n------------------------------------%.2f\n\n",
        app.nombreAplicacion, app.nombreCircuito, app.version
    );
    if(0==0){
        system("cls");
    }
}

void mostrarCorredor(Corredor competidor){
    printf("Numero de corredor: |%d|, Nombre: %s. Apellido: %s. Escuderia: %s\n\n", competidor.numero, competidor.nombre, competidor.apellido, competidor.escuderia);
}

void mostrarTiempo(Tiempo cronometro){
    printf("Numero de vuelta: %d, Numero de corredor: %d, Tiempo: %.3f\n\n", cronometro.numeroDeVuelta, cronometro.numeroDeCorredor, cronometro.temporizador);
}