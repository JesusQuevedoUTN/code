#include "../../Libs/utils.h"


int main()
{
/*
7) Realizá un programa que permita al usuario ingresar el nombre de un archivo de texto. Validar su
existencia. La computadora debe reemplazar, en el mismo archivo, varios espacios seguidos por un
único espacio
*/
    cadena carpeta = "../../.C-file/";
    FILE* archivo;
    escribirArchivo(archivo, carpeta);
}

void escribirArchivo(FILE** archivo,cadena ruta){
    archivo = fopen(ruta,"w");
}