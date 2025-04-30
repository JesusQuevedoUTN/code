#include "../../Libs/utils.h"

#define MENOR 1
#define MAYOR 10

void escribirTabla (cadena ruta, cadena modo);

int leerTabla();
void escribirTablaN(FILE* archivo, int numero);
void escribirFilaN(int numero, int decenas, FILE* archivo);

void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo);
void cerrarArchivo(FILE* pArch);

int main()
{
/*
1) Realizá un programa que permita al usuario ingresar un número entero N entre 1 y 10. La
computadora deberá guardar en el archivo tabla-del-N.txt la tabla de multiplicar de N. Si el
archivo no existe, crearlo
*/
    cadena ruta = "../../.C-file/tabla-del-N.txt";

    escribirTabla(ruta, "w");
}

void escribirTabla (cadena ruta, cadena modo) {
    FILE* pArchivo;    
    int numero = leerTabla();
    
    abrirArchivo(&pArchivo, ruta, modo);
    escribirTablaN(pArchivo, numero);
    cerrarArchivo(pArchivo);
}

int leerTabla(){
    cadena mensaje;
    sprintf(mensaje, "Ingrese un valor entre %d, y %d", MENOR, MAYOR);
    return leerEnteroEntre(MENOR, MAYOR, mensaje);
}
void escribirTablaN(FILE* archivo, int numero) {
    int decenas = 0;
    while (decenas<100)
    {
        escribirFilaN(numero, decenas, archivo);
        fputs("\n", archivo);
        decenas+=10;
    }        
}
void escribirFilaN(int numero, int decenas, FILE* archivo){
    int posicion;
    for (int i = 1; i <= 10; i++)
    {
        posicion = (decenas+i) * numero;
        fprintf(archivo, "%d ", posicion);
    }
}

void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo) {
    *ppArch = fopen(ruta, modo);
    if (*ppArch != NULL) {
        printf("ARCHIVO ABIERTO EN MODO '%s'\n", modo);
    } else {
        puts("NO SE PUDO ABRIR");
    }
}
void cerrarArchivo(FILE* pArch) {
    int result = fclose(pArch);
    if (result == 0) {
        puts("ARCHIVO CERRADO");
    } else {
        puts("NO SE PUDO CERRAR EL ARCHIVO");
    }
}