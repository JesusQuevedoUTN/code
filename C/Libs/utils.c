#include "utils.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c!= EOF);
}


//ENTERO
int LeerEntero(){
    int numero;
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

//FLOAT
float LeerFloat(){
    float numero;
    fflush(stdin);
    scanf(" %f", &numero);
    return numero;
}

//CHAR
char LeerCaracter(){
    char caracter;
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}

//LEER ENTRE...
int LeerEnteroEntre(int valorMin,int valorMax) {
    int valor = LeerEntero();
    while(valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %d y %d.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = LeerEntero();
    }
    return valor;
}

float LeerFloatEntre(float valorMin,float valorMax) {
    float valor = LeerFloat();
    while (valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %.2f y %.f.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = LeerFloat();
    }
    return valor;
}

int esLetra(char letra)
{
    return (letra >= 'a' && letra <='z') || (letra >= 'A' && letra <= 'Z');
}

int esPrimo(int primo)
{
    int i = 2;
    while (primo%i!=0 && i<primo)
    {
        i++;
    }
    return i == primo;
}
int sonIgualesCaracteres(char x, char y)
{
    return x==y;
}

//PROMEDIO
float promedio(int total, int parcial) {
    return (float)total/parcial;
}

//CAMBIAR POSICION
void cambiarPosicionDeEnteros(int *x, int *y)
{
    int aux = *x;
    *x=*y;
    *y=aux;
}

void cambiarPosicionDeCaracteres(char *x, char *y)
{
    char aux = *x;
    *x=*y;
    *y=aux;
}

//ORDENAR VECTOR ASC Y DESC
void ordenarVectorDeEnterosAscendente(int* vec, int cant) {
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j<cant-1; j++)
        {
            if(vec[j]>vec[j+1])
            {
                cambiarPosicionDeEnteros(&vec[j], &vec[j+1]);
            }
        }
    }
}

int contadorDeLetras(char* vec, int cant)
{
    int contador=0;
    for (int i = cant ; i > 0; i--)
        {
            if (vec[i-1] != ' ')
            {
                contador++;
            }
        }
    return contador;
}

//LEER char* S
void leerCadena(char*  mensaje, char*  target) {
    puts(mensaje);
    gets(target);
}