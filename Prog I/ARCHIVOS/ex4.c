#include "../../Libs/utils.h"

void mostrarRenglones(cadena base);
void nuevaRuta(cadena base, cadena mensaje);
void ingresarTexto(cadena ruta, cadena mensaje);
void buscarPalabra(FILE *archivo);

int main()
{
/*
4) Realizá un programa que permita al usuario ingresar el nombre de un archivo de texto y una
palabra. La computadora debe mostrar por consola solo los renglones del archivo donde aparece la
palabra, numerados. Considerar al primer renglón del archivo como el número 1.
*/
    cadena carpeta = "../../.C-file/";
    mostrarRenglones(carpeta);
}

void mostrarRenglones(cadena base){
    FILE* archivo;
    nuevaRuta(base, "Cual documento esta buscando?");
    abrirArchivo(&archivo, base, "r");
    
    buscarPalabra(archivo);

    cerrarArchivo(archivo, base);
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

void buscarPalabra(FILE *archivo){
    cadena palabra;
    leerCadena("Que palabra busca?", palabra);
    cadena buffer;

    int numeroRenglon = 1;
    while (fgets(buffer, 150, archivo) != NULL)
    {
        if (strstr(buffer, palabra) != NULL)
        {
            printf("%d: %s\n", numeroRenglon, buffer);
        }
        numeroRenglon++;
    }
}