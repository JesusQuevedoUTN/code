#include <stdio.h>

void mostrarArchivoCaracterACaracter (FILE* archivo);

int main () {
    FILE* archivo= fopen("../frase.txt", "r"); // Abre el archivo en modo texto de solo lectura
    if (archivo != NULL) {
        mostrarArchivoCaracterACaracter(archivo);
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0;
}

void mostrarArchivoCaracterACaracter (FILE* archivo) {
    /*
        int feof(FILE *archivo);

        La función feof() comprueba si se llegó al final del archivo, en cuyo caso retornará
        un valor distinto de cero. Suele usarse como condición para el ciclo de recorrida
        secuencial de un archivo.
    */
    char caracterLeido;
    while(!feof(archivo)) {
        /*
            int fgetc(FILE* archivo);

            La función fgetc() lee y retorna un caracter en formato int, avanzando el
            cursor al siguiente. El parámetro es un puntero a un archivo FILE.
            Si no hay ningún caracter disponible, retorna EOF (-1)
        */
        caracterLeido = fgetc(archivo);
        if (caracterLeido != EOF) {
            printf("%c", caracterLeido);
        } else {
            printf("***FIN DE ARCHIVO***\n");
        }

    }
}