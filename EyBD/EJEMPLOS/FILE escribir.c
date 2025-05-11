#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define LARGO_CAD 81

void cargar(FILE*);
void mostrar(FILE*);


int main(){
    FILE *archivo;
    char nom[LARGO_CAD] = "pipo.txt";


    if( archivo = fopen(nom, "w+")==NULL ){
        exit(1);
    }
    printf("\nEl archivo %s se ha abierto correctamente!!", nom);

    cargar(archivo);
    rewind(archivo);
    mostrar(archivo);
    fclose(archivo);

    return 0;
}

void cargar(FILE *x)
{
    char cad[LARGO_CAD];
    puts("\n\nPara ingresar datos en cada linea tipear ENTER\n");
    puts("para finalizar el ingreso de datos\nintroduczca una marca especial de fin de archivo\nllamada control + Z y luego pulse ENTER\n");
    while(gets(cad)!= NULL)
    {
        fputs(cad, x);
        fputc('\n', x);
    }
}

void mostrar(FILE *x)
{
    char cad[LARGO_CAD];
    while(fgets(cad,LARGO_CAD,x)!=NULL)
    {
        printf("%s", cad);
    }
}

