#include "Libs/utils.h"

/*
int tieneVocales(cadena texto, int x);
int esVocal(char letra);
*/

//14
void promedioPalabrasVector(char vec[], float *prom);

int main()
{
    /*11)
    Realizá un programa que permita al usuario ingresar una cadena. La computadora debe mostrar
    las dos subcadenas formadas por las posiciones pares e impares, respectivamente, de la cadena
    ingresada.
    cadena ejercicio  = "COhmaergiazCaerldo";
    cadena par, impar;
    int longitud = strlen(ejercicio);
    
    for (int i = 0 ; i < longitud ; i++)
    {
        if ( i % 2 != 0 )
        {
            par[i/2]=ejercicio[i];
        }
        else
        {
            impar[i/2]=ejercicio[i];
        }
    }
    puts("Impar");
    mostrarVectorDeCaracteres(impar, longitud/2);
    puts("Par");
    mostrarVectorDeCaracteres(par, longitud/2);
    */
    /*12)
    Realizá un programa que permita al usuario ingresar una cadena. La computadora debe mostrar
    las cantidades de cada vocal (cuántas 'A', cuántas 'E', …).
    cadena palabra;
    gets(palabra);
    int x = strlen(palabra), contadores[5];
    char vocal[] = {'A','E','I','O','U'};
    inicializarVectorDeEnteros(contadores, 5);

    for (int i = 0; i < x; i++)
    {
        if (palabra[i]=='a' || palabra[i]=='A')
        {
            contadores[0]++;
        }
        
        if (palabra[i]=='e' || palabra[i]=='E')
        {
            contadores[1]++;
        }
        if (palabra[i]=='i' || palabra[i]=='I')
        {
            contadores[2]++;
        }
        if (palabra[i]=='o' || palabra[i]=='O')
        {
            contadores[3]++;
        }
        if (palabra[i]=='u' || palabra[i]=='U')
        {
            contadores[4]++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("La vocal %c aparecio: %d\n", vocal[i], contadores[i]);
    }
    */ 
    /*13)
    Realizá un programa que permita al usuario ingresar una cadena que represente una
    frase/oración. La computadora debe mostrar la cantidad total de palabras.
    cadena oracion;
    gets(oracion);
    int x = strlen(oracion), contador; 
    
    contador = contadorDePalabras(oracion, x);
    
    printf("En total hay %d palabra/s", contador);
    */
    /*14) 
    Realizá un programa que permita al usuario ingresar una cadena que represente una
    frase/oración. La computadora debe mostrar la longitud promedio de caracteres que tienen las
    palabras.
    oracion ejercicio;
    float promedio;

    gets(ejercicio);
    
    promedioPalabrasVector(ejercicio, &promedio);

    printf("El promedio total de letras por palabras: %.2f", promedio);
    */
    return 0;
}
/*
int tieneVocales(cadena texto, int x)
{
    int i=0;
    while (i<x && texto[i] != 'a' && texto[i] != 'A' && texto[i] != 'e' && texto[i] != 'E' && texto[i] != 'i' && texto[i] != 'I' && texto[i] != 'o' && texto[i] != 'O' && texto[i] != 'a' && texto[i] != 'U')
    {
        i++;
    }    
    return i!=x;
}
int esVocal(char letra)
{
    int i=0, o=0;
    if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'a' || letra == 'U' )
    {
        i=1;
    }
    return i;
}
*/
//14
void promedioPalabrasVector(char vec[], float *prom)
{
    int contador = 0, leng =strlen(vec), palabras = contadorDePalabras(vec, leng);
    for (int i = 0; i < leng ; i++)
    {
        if ((vec[i]>65 && vec[i]<90) || (vec[i]>97 && vec[i]<122) )
        {
            contador++;
        }
    }

    *prom = contador *1.0 / palabras;
}