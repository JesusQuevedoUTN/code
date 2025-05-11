#include "../../C.h"

void abrir(FILE** archivo, char* nombreArchivo);
void mostrar(FILE* archivo);
void morse(FILE* archivo);
char morseAChar(char* cadena);



int main()
{
    //ARCHIVOS
    FILE* archivo;
    char* direccion = "../morse.txt";
    
    //FUNCIONES
    abrir(&archivo, direccion);
    mostrar(archivo);
    morse(archivo);

    //FIN
    fclose(archivo);
    return 0;
}

void abrir(FILE** archivo, char* nombreArchivo)
{
    (*archivo) = fopen(nombreArchivo, "r");
    
    if( (*archivo) == NULL )
    {
        printf("Papucho, creo que algo salio maaaal.\n");
    }
    
}

void mostrar(FILE* archivo)
{
    char cadena[5];
    while ( fscanf(archivo, " %[^\n]", cadena) != EOF)
    {
        printf("%s\n", cadena);
    }
    rewind(archivo);
}
void morse(FILE* archivo)
{   
    char codigo[10];
    char texto[50];
    char digito;

    for (size_t i = 0; i < strlen(texto); i++)
    {
        texto[i] = '\0';
    }
    

    while ( fgets(codigo, sizeof(codigo), archivo) != NULL)
    {
        if (strlen(codigo) == 1)
        {
            digito = ' ';
            strncat(texto," ",1);
        }
        else
        {
            digito = morseAChar(codigo);
            strncat(texto,&digito,1);
        }
    }
    printf("\nTraducido: [%s]\n", texto);
}
char morseAChar(char* cadena)
{
    char caracter;
    char* codigo[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };       // S-Z
    int i = 0;
    cadena[strcspn(cadena,"\n")] = '\0';
    while (i<26 && strcmp( codigo[i] , cadena )!=0)
    {
        i++;
    }
    caracter = i+'A';
    return caracter;
}