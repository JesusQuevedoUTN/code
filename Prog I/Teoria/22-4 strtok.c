#include "../Libs/utils.h"

#define CANT 3

typedef struct 
{
    cadena tipo;
    int cantidad;
    float precio;
}Piezas;

void mostrarPiezas(Piezas objeto[CANT]);

int main()
{
    //leer piezas y decir el promedio de la segunda columna
    FILE *archivo = fopen("../piezas.txt", "r");
    Piezas objeto[CANT];
    cadena dato;
    int i=0;

    if (archivo!=NULL)
    {
        fgets(dato, sizeof(cadena), archivo);
        while (!feof(archivo))
        {
            strtok(dato, ",");

                

            fgets(dato, sizeof(cadena), archivo);
            i++;   
        }

        fclose(archivo);
    }

    mostrarPiezas(objeto);

    return 0;
}

void mostrarPiezas(Piezas objeto[CANT]){
    for (int i = 0; i < CANT; i++)
    {
        printf("%s\n%d\t%f", objeto[i].tipo, objeto[i].cantidad, objeto[i].precio);
    }
    
}
