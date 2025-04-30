#include "../../Libs/utils.h"

int main () {
    FILE* pArchivo;
    cadena ruta = "../frase.txt";
    //leerCadena("Ingrese ruta hacia el archivo", ruta);
    //printf("%p\n", pArchivo); // Para comprobar el pasaje por referencia...
    abrirArchivo(&pArchivo, ruta, "r");
    //printf("%p\n", pArchivo); // Para comprobar el pasaje por referencia...
    copiarANuevoArchivoEnMayusculas(pArchivo, ruta);    
    return 0;
}

void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo) {
    *ppArch = fopen(ruta, modo);
    if (*ppArch != NULL) {
        printf("***ARCHIVO '%s' ABIERTO CORRECTAMENTE EN MODO '%s'***\n", ruta, modo);
    } else {
        printf("***NO SE PUDO ABRIR EL ARCHIVO '%s' EN MODO '%s'***\n", ruta, modo);
    }
}

void cerrarArchivo(FILE* pArch, cadena ruta) {
    int result = fclose(pArch);
    if (result == 0) {
        printf("***ARCHIVO '%s' CERRADO CORRECTAMENTE***\n", ruta);
    } else {
        printf("***NO SE PUDO CERRAR EL ARCHIVO '%s'***\n", ruta);
    }
}



void copiarANuevoArchivoEnMayusculas (FILE* pArchivoFuente, cadena ruta) {
    cadena aux;
    FILE* pArchivoDestino;
    abrirArchivo(&pArchivoDestino, "../frase-MAYUS.txt", "w");

    while(!feof(pArchivoFuente)) {
        fgets(aux, 50, pArchivoFuente);
        strupr(aux); // Lo pasa a mayusculas (poner el include de string.h)
        fputs(aux, pArchivoDestino);
    }