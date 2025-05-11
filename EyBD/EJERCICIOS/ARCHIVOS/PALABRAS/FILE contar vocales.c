#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO_CAD 81

void cargar(FILE*);
void mostrar(FILE*);
void contar(FILE*);
int contarLinea(char*);
void contarVocal(FILE*);
int contarVocalLinea(char*);

//funcion que pueda contar la cantidad de palabras que tengo por renglon

int main(){
    FILE* archivo;
    char nom[LARGO_CAD] = "ejercicio3.txt";

    #ifdef _WIN32
        system("chcp 65001 < nul");
    #endif

    if( (archivo = fopen(nom, "w+")) == NULL ){
        exit(1);
    }
    else
    {
        printf("\nEl archivo %s se ha abierto correctamente!!", nom);
    }
    cargar(archivo);
    rewind(archivo);

    contarVocal(archivo);

    fclose(archivo);
    puts("\n");
    return 0;
}

void cargar(FILE *x)
{
    char cad[LARGO_CAD];
    puts("\n\nPara ingresar datos en cada linea tipear ENTER\n");
    puts("para finalizar el ingreso de datos\nintroduczca una marca especial de fin de archivo\nllamada control + Z y luego pulse ENTER\n");
    while(gets(cad)!= NULL)
    {
        fputs(cad, x);
        fputc('\n', x);
    }
}

void mostrar(FILE *x)
{
    char cad[LARGO_CAD];
    while(fgets(cad,LARGO_CAD,x)!=NULL)
    {
        printf("%s", cad);
    }
}

void copiar(FILE *x, FILE *y)
{
    char cad[LARGO_CAD];
    while(fgets(cad,LARGO_CAD,y)!= NULL)
    {
        fputs(cad, x);
        //fputc('\n', x);
    }
}


void contar(FILE* x)
{
    int contador = 0;
    char cad[LARGO_CAD];

    while(fgets(cad,LARGO_CAD,x)!= NULL)
    {
        contador = contador + contarLinea(cad);
    }
    if(contador==1)
    {
        printf("Hay 1 sola palabra");
    }
    else if(contador>1)
        {
            printf("Hay un total de %d palabras", contador);
        }
        else
        {
            printf ("No hay palabras");
        }
}

int contarLinea(char* cad)
{
    int palabra = 0, i = 0;
    //bool noSeaFinal = cad[i]!='\n';

    while(cad[i]!='\n')
    {
        while(cad[i] == ' ' && cad[i]!='\n')i++;
        palabra = palabra + 1;
        while(cad[i] != ' ' && cad[i]!='\n')i++;
    }
    return palabra;
}


void contarVocal(FILE* x)
{
    int contador = 0;
    char cad[LARGO_CAD];

    while(fgets(cad,LARGO_CAD,x)!= NULL)
    {
        contador = contador + contarVocalLinea(cad);
    }

    if(contador==1)
    {
        printf("Hay 1 sola vocal");
    }
    else if(contador>1)
        {
            printf("Hay un total de %d vocales", contador);
        }
        else
        {
            printf ("No hay vocales");
        }
}
int contarVocalLinea(char* cad)
{
    int contador = 0, i = 0;
    //bool noSeaFinal = cad[i]!='\n';

    while(cad[i]!='\n')
    {
        if(cad[i]=='a' || cad[i]=='e' || cad[i]=='i' || cad[i]=='o' || cad[i]=='u' || cad[i]=='A' || cad[i]=='E' || cad[i]=='I' || cad[i]=='O' || cad[i]=='U')
        {
            contador++;
        }
    }
    return contador;
}
