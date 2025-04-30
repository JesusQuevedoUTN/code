#include "Libs/utils.h"
#include "Practica_2.c"

#define MAXIMO 2

void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo);
void leerTextoArchivo(FILE *pointArchivo, cadena ruta);
void contadorPalabras(FILE *pointArchivo);
void cerrarArchivo(FILE* pArch, cadena ruta);

int main()
{
    /*
    Se ingresa un texto de varias líneas  desde teclado y se guarda en un archivo de texto.
    Luego se muestra la cantidad de palabras que tiene cada línea
    */

    FILE *documento;
    cadena ruta = "../cantPalabras.txt";

    abrirArchivo(&documento, ruta, "w");

    leerTextoArchivo(documento, ruta);
    
    contadorPalabras(documento);

    cerrarArchivo(documento, ruta); 

    return 0;
}

void abrirArchivo(FILE **pointDocumento, cadena ruta, cadena modo) {
    *pointDocumento = fopen(ruta, modo);
    
    if (*pointDocumento != NULL) {
        printf("ARCHIVO ABIERTO CORRECTAMENTE\nMODO: '%s'\n", modo);
    } else {
        printf("NO SE PUDO ABRIR EL ARCHIVO '%s'\nMODO: '%s'\n", ruta, modo);
    }
}

void leerTextoArchivo(FILE *pointArchivo, cadena ruta){
    cadena leida;

    printf("Ingrese linea por linea el texto que desea ingresar en el archivo %s\nMAXIMO %d lineas\n\n", ruta, MAXIMO);
    
    for (int i = 0; i < MAXIMO; i++)
    {
        fflush(stdin);
        gets(leida);
        fprintf(pointArchivo,"%s\n",leida);
    }
}

void contadorPalabras(FILE *pointArchivo){
    int contador = 0;
    cadena leida;
    
    cadena prueba1 = "esta cadena funciona"; // debe retornar 3
    cadena prueba2 = "   esta caden4 tam bien"; // debe retornar 4
    printf("cadena1: %d palabras\ncadena2: %d palabras\n", cuentaPalabras(prueba1),cuentaPalabras(prueba2)); //retorna 3 y 4

    fgets(leida, sizeof(leida), pointArchivo);

    while (feof(pointArchivo)) 
    {
        contador =+ cuentaPalabras(leida);
        fgets(leida, sizeof(leida), pointArchivo);
    }

    printf("\nEn total hay %d palabras\n", contador);
}

void cerrarArchivo(FILE *pointDocumento, cadena ruta) {
    int result = fclose(pointDocumento);
    if (result == 0) {
        puts("ARCHIVO CERRADO CORRECTAMENTE");
    } else {
        printf("NO SE PUDO CERRAR EL ARCHIVO '%s'", ruta);
    }
}


/*
void copiarANuevoArchivoEnMayusculas (FILE* pArchivoFuente, cadena ruta) {
    cadena aux;
    FILE* pArchivoDestino;
    abrirArchivo(&pArchivoDestino, "../frase-MAYUS.txt", "w");

    while(!feof(pArchivoFuente)) {
        fgets(aux, 50, pArchivoFuente);
        strupr(aux); // Lo pasa a mayusculas (poner el include de string.h)
        fputs(aux, pArchivoDestino);
    }
    
}
*/