#include "../../Libs/utils.h"

void existeMAYUS(cadena base, cadena modo);
void validar(FILE** point, cadena base, cadena ruta, cadena copiaruta, cadena modo);
void ingresarTexto(cadena ruta);
void copiasRutas(cadena ruta, cadena base, cadena copiaruta);
int existe(FILE** ppArch, cadena ruta, cadena modo);
void pasarMAYUS(FILE* pArchivo, cadena copiaruta);

int main()
{
/*
2) Realizá un programa que permita al usuario ingresar el nombre de un archivo de texto. Validar su
existencia. La computadora debe abrirlo, pasar su contenido a mayúsculas y copiarlo a otro archivo
con el mismo nombre que el abierto (agregándole la palabra MAYUS al final del nombre).
*/
    cadena carpeta = "../../.C-file/";
    existeMAYUS(carpeta, "r"); 
}

void existeMAYUS(cadena base, cadena modo) {
    FILE* pArchivo;
    cadena ruta, rutacpy;
    validar(&pArchivo, base, ruta, rutacpy, modo); 
    pasarMAYUS(pArchivo, rutacpy);
}
void validar(FILE** point, cadena base, cadena ruta, cadena copiaruta, cadena modo){
    copiasRutas(ruta, base, copiaruta);    
    while (!existe(point, ruta, modo))
    {
        puts("El archivo no tiene una validancia de existencia *sorbe cafecito\n vuelva a intentarlo");
        strcpy(ruta, base);
        copiasRutas(ruta, base, copiaruta);
    }
}
void ingresarTexto(cadena ruta){
    cadena texto;
    gets(texto);
    strcat(ruta, texto);
}
void copiasRutas(cadena ruta, cadena base, cadena copiaruta){
    strcpy(ruta, base);
    ingresarTexto(ruta);
    strcpy(copiaruta, ruta);
    strcat(copiaruta, "MAYUS.txt");
    strcat(ruta, ".txt");
}
int existe(FILE** ppArch, cadena ruta, cadena modo) {
    *ppArch = fopen(ruta, modo);
    return *ppArch != NULL;
}
void pasarMAYUS(FILE* pArchivo, cadena copiaruta) {
    FILE* fMayusc = fopen(copiaruta, "w");
    int caracterLeido;
    while ((caracterLeido = fgetc(pArchivo)) != EOF) {
        // Convertir a mayúsculas y escribir en el nuevo archivo
        fputc(toupper(caracterLeido), fMayusc);
    }
    fclose(pArchivo);
    fclose(fMayusc);
}