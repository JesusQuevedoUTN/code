#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/utils.h"

//Pasar un codigo binario y traudirlo a caracter
#define BYTE 8
#define BINARIO 2

//
void leerBinario(char*);
bool textoBinario(char*);
bool esBinario(char);

//
void baseADecimal(int,char*);

int main()
{
    char* numeroATraducir = (char*)malloc(BYTE*sizeof(char));

    leerBinario(numeroATraducir);
    baseADecimal(BINARIO, numeroATraducir);
    puts(numeroATraducir);
    free(numeroATraducir);

    return 0;
}

void leerBinario(char* numero)
{
    do
    {
        leerCadenaEntre(BYTE, BYTE, "Ingrese un valor binario", numero);
    }while(!textoBinario(numero));
}

//PUEDE SER MÁS REUTILIZABLE SI ES QUE A ESTE VALOR LE AGREGO UNA BASE Y QUE SEA ENTRE 0 Y UN NUMERO, HEXA SE COMPLICARIA PERO SE PODRÍA
bool textoBinario(char* cad)
{
    int i=0, longitud = strlen(cad);
    while( i<longitud && esBinario(cad[i])  )
    {
        i++;
    }
    return i==longitud;
}

bool esBinario(char c)
{
    return c == '0' || c== '1';
}

void baseADecimal(int inicial, char* textoTraducido)
{
    int sumatoria = 0;
    int i = strlen(textoTraducido)-1, posicion = 0, mantisa;
    while(i >= 0)
    {
        //FALTA ALGO ACÁ
        mantisa = textoTraducido[i] - '0';
        printf("&d", mantisa);
        sumatoria = sumatoria + (mantisa * potencia(inicial,posicion));
        posicion++;
        i--;
    }
    printf("%d\n", sumatoria);
}

int potencia(int x, int y)
{
    for(int i = 0;i<y;i++)
    {
        x *= x;
    }
    return x;
}
