#include <stdio.h>
int main()
{
    FILE *pArchivo;
    pArchivo = fopen("../frase.txt", "r");
    /*
        Atención: La ruta es con respecto al ejecutable (.exe) que no
        necesariamente está en la misma carpeta que el código fuente (.c)
    */
    if (pArchivo != NULL) {
        printf("ARCHIVO '%s' ABIERTO CORRECTAMENTE\n");
        // Procesar el archivo...
        fclose(pArchivo); // Cierra el archivo
    }
    else {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
    }
    printf("El puntero al archivo es %p\n", pArchivo); // 0000000 representa NULL
    return 0;
}
