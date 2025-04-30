#include <stdio.h>

void mostrarArchivoConScanf (FILE* archivo);

int main () {
    FILE* archivo = fopen("../frase.txt", "r");

    if (archivo != NULL) {
        mostrarArchivoConScanf(archivo);

        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0;
}

void mostrarArchivoConScanf (FILE* archivo) {
    char cadena[50];
    int i=0;
    while(feof(archivo) == 0) {
        /*
            int fscanf(FILE *archivo, const char *formato, ...);

            La función fscanf funciona igual que scanf en cuanto a parámetros, pero la entrada se
            toma de un archivo (puntero enviado como primer argumento) en lugar del teclado.
        */
        fscanf(archivo, "%s", cadena);
        printf("%s\n", cadena);
    }
}
