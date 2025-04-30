#include "../../Libs/utils.h"

void nuevaRuta(cadena base, cadena mensaje);
void ingresarTexto(cadena ruta, cadena mensaje);
void contadores(FILE *archivo);
int contarCaracteres(FILE *archivo);
int contarRenglones(FILE *archivo);
int contarPalabras(FILE *archivo);

int main()
{
/*
5. Realizá un programa que permita al usuario ingresar el nombre de un archivo de texto. La
computadora debe mostrar por consola la siguiente información del archivo:
▪ Cantidad de caracteres ▪ Cantidad de renglones ▪ Cantidad de palabras
*/
    //cadena carpeta = "../../.C-file/";
    cadena carpeta = "../../.C-file/buscar-ej-4.txt";
    FILE* archivo;
    //nuevaRuta(carpeta, "Cual documento esta buscando?");
    abrirArchivo(&archivo, carpeta, "r");
    contadores(archivo);
    cerrarArchivo(archivo, carpeta);
}

void nuevaRuta(cadena base, cadena mensaje){
    ingresarTexto(base, mensaje);
    strcat(base, ".txt");
}
void ingresarTexto(cadena ruta, cadena mensaje){
    cadena texto;
    puts(mensaje);
    gets(texto);
    strcat(ruta, texto);
}
void contadores(FILE *archivo){
    int caracteres = contarCaracteres(archivo);
    int renglones = contarRenglones(archivo);
    int palabras = contarPalabras(archivo);

    printf("Cantidad de caracteres: %d\nCantidad de renglones: %d\nCantidad de palabras: %d\n", caracteres, renglones, palabras);
}

int contarCaracteres(FILE *archivo){
    rewind(archivo);
    int contador = 0;
    char caracterLeido;
    while((caracterLeido=fgetc(archivo)) != EOF){
        contador++;
    }
    return contador;
}
int contarRenglones(FILE *archivo){
    rewind(archivo);
    int contador = 0;
    char cadenaleida[150];

    while(fgets(cadenaleida, sizeof(cadenaleida), archivo) != NULL){
        contador++;
    }
    return contador;
}
int contarPalabras(FILE *archivo){
    rewind(archivo);
    int contador = 0;
    cadena linea;

    while (fgets(linea, sizeof(linea), archivo) != NULL){
        char *token = strtok(linea, " ");
        while (token != NULL) {
            contador++;
            token = strtok(NULL, " ");
        }
    }
    return contador;
}

//cosa rara de la funcion