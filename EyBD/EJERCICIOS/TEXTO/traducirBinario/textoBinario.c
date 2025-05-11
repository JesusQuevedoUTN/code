#include "../../C.h"

#define BYTE 8

//
void read(FILE** archivo, char* direccion);
void mostrar(FILE* archivo);
void mostrarBinarioATexto(FILE* archivo);

//
int baseADecimal(char* numero, int base);

int main()
{
    FILE* archivo;
    char* direccion = "../textoEnBinario.txt";

    read(&archivo, direccion);
    mostrar(archivo);
    mostrarBinarioATexto(archivo);

    fclose(archivo);
    return 0;
}


void read(FILE** archivo, char* direccion)
{
    *archivo = fopen(direccion, "r");
    if (*archivo==NULL)
    {
        printf("ERROR. NO FUNCIONO");
    }
}
void mostrar(FILE* archivo)
{
    char* cadena = (char*)malloc(BYTE*sizeof(char));
    printf("[ARCHIVO BINARIO]\n");
    while ( fscanf(archivo, " %[^\n]", cadena) != EOF)
    {
        printf("%s\n", cadena);
    }

    rewind(archivo);
    free(cadena);
    system("pause");
    system("cls");
}
void mostrarBinarioATexto(FILE* archivo)
{
    char* cadena = (char*)malloc(BYTE*sizeof(char));
    char c;
    
    printf("TEXTO TRADUCIDO: ");
    while ( fscanf(archivo, " %[^\n]", cadena) != EOF)
    {
        c = baseADecimal(cadena,2);
        printf("%c", c);
    }
    printf("\n");
    
    free(cadena);
    system("pause");
}

//
int baseADecimal(char* numero, int base)
{
    int sumatoria =     0;
    int digito;
    char c;
    int len = strlen(numero);

    for (int i = 0; i < len ; i++)
    {
        c = toupper(numero[(len-1)-i]);
        
        if (isdigit(c))
        {
            digito = c -'0';
        }
        else
        {
            digito = c - 'A' + 10;
        }
        
        sumatoria = sumatoria + digito * pow(base,i);
    }

    return sumatoria;
}