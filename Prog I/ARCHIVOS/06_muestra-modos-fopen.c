#include <stdio.h>

typedef char cadena[50];

void probarModo (cadena ruta, cadena modo, cadena contenidoAEscribir);
void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo);
void cerrarArchivo(FILE* pArch, cadena ruta);
void mostrarArchivoCaracterACaracter (FILE* archivo, cadena ruta);
void escribirLineaEnArchivo (FILE* archivo, cadena ruta, cadena contenidoAEscribir);

int main () {
    // Crear un archivo llamado 'prueba-open.txt' y colocarlo en la misma carpeta que este archivo .c
    cadena ruta = "../prueba-open.txt"; 

    // A continuación, se hace prueba cada modo con este archivo (probar de a uno por vez)...
    // probarModo(ruta, "r", "Escrito en C!");
    // probarModo(ruta, "w", "Escrito en C!");
    // probarModo(ruta, "a", "Escrito otra vez en C!");
    // probarModo(ruta, "r+", "Vamos de nuevo, con el +");
    // probarModo(ruta, "w+", "Vamos por 2da vez, con el +");
    // probarModo(ruta, "a+", "Vamos por 3ra vez, con el +");

    // A continuación, se hace prueba cada modo con archivos inexistentes (Se pueden probar todos a la vez)...
     
    //probarModo("../generadosPorC/fake1.txt", "r", "Escrito en C!");
    //probarModo("../generadosPorC/fake2.txt", "w", "Escrito en C!");
    //probarModo("../generadosPorC/fake3.txt", "a", "Escrito otra vez en C!");
    //probarModo("../generadosPorC/fake4.txt", "r+", "Vamos de nuevo, con el +");
    //probarModo("../generadosPorC/fake5.txt", "w+", "Vamos por 2da vez, con el +");
    //probarModo("../generadosPorC/fake6.txt", "a+", "Vamos por 3ra vez, con el +");
    

    return 0;
}

void probarModo (cadena ruta, cadena modo, cadena contenidoAEscribir) {
    FILE* pArchivo;    
    // Se intenta abrir en el modo que corresponda
    abrirArchivo(&pArchivo, ruta, modo);
    // Se intenta mostrar en consola, char a char
    mostrarArchivoCaracterACaracter(pArchivo, ruta);
    // Se intenta escribir un contenido en él
    escribirLineaEnArchivo(pArchivo, ruta, contenidoAEscribir);
    // Se intenta cerrar el archivo
    cerrarArchivo(pArchivo, ruta);
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

void mostrarArchivoCaracterACaracter (FILE* archivo, cadena ruta) {
    printf("***MOSTRANDO '%s'...***\n", ruta);
    char caracterLeido = fgetc(archivo);
    while(caracterLeido != EOF) {
        printf("%c", caracterLeido);
        caracterLeido = fgetc(archivo);
    }
    printf("***FIN DE ARCHIVO***\n");
}

void escribirLineaEnArchivo (FILE* archivo, cadena ruta, cadena contenidoAEscribir) {
    printf("***ESCRIBIENDO '%s' en '%s'...***\n", contenidoAEscribir, ruta);
    int result = fputs(contenidoAEscribir, archivo);
    if (result == EOF) {
        printf("***ERROR AL ESCRIBIR EN '%s'***\n", ruta);
    }
}
