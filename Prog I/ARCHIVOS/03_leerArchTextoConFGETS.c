#include <stdio.h>

void mostrarArchivoLineaPorLinea (FILE* pArchivo);

int main () {
    FILE* archivo = fopen("../frase.txt", "r");

    if (archivo != NULL) {
        mostrarArchivoLineaPorLinea(archivo);

        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0;
}

void mostrarArchivoLineaPorLinea (FILE* pArchivo) {
    const int CANT_CHARS_POR_RENGLON = 30; // Probar cambiando a 5
    char cadenaDestino[CANT_CHARS_POR_RENGLON];
    while(!feof(pArchivo)) {
        /*
            char *fgets(char *cadena, int n, FILE *pArchivo);

            La función fgets() lee una cadena y la coloca como valor en el puntero
            a cadena enviado como primer parámetro. El segundo parámetro indica la
            cantidad de caracteres leídos. La función leerá hasta n-1 caracteres o
            hasta detectar un retorno de línea (también leído).
            Retorna el mismo puntero enviado como primer parámetro o NULL en caso de
            detectar el fin del archivo o un error.
        */
        char* result = fgets(cadenaDestino, CANT_CHARS_POR_RENGLON, pArchivo);
        if (result != NULL) {
            printf("Leido: %s", cadenaDestino);
        } else {
            printf("***FIN DE ARCHIVO O ERROR***\n");
        }
    }
}
