#include "../../Libs/utils.h"

void mezclarTextos(cadena ruta, cadena primero, cadena segundo);
void escribirArchivo(FILE* final,FILE* archivo1);

int main()
{
/*
3. dar el nombre de 2 archivos, y juntarlos en uno nuevo
*/
    cadena carpeta = "../../.C-file/mezclaejercicio3.txt", ruta1 = "../../.C-file/tabla-del-N.txt", ruta2 = "../../.C-file/textominusMAYUS.txt";
    mezclarTextos(carpeta, ruta1, ruta2);
}

void mezclarTextos(cadena ruta, cadena primero, cadena segundo){
    FILE *final, *archivo1, *archivo2;
    final = fopen(ruta, "w");
    archivo1 = fopen(primero, "r");
    archivo2 = fopen(segundo, "r+");
    
    escribirArchivo(final, archivo1);
    escribirArchivo(final, archivo2);

    fclose(final);
    fclose(archivo1);
    fclose(archivo2);
}

void escribirArchivo(FILE* final,FILE* archivo){
    char x;
    while ((x = fgetc(archivo)) != EOF)
    {
        ;
        fprintf(final, "%c", x);
    }
}
