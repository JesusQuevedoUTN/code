#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para usar tolower() aunque en este ejemplo no lo utilizo
#define LARGO_CAD 81

int main()
{
    char frase[81] = "Esta es una frase de ejemplo\tinteresante.";
    char *token;
    char delimitadores[LARGO_CAD] = " .\t"; // aqui tenemos 2 delimitadores espacio y punto
    char frase_copia[LARGO_CAD];

    // Copiar la frase original a frase_copia
    // porque frase_copia sera partida en subcadenas por lo que rompe
    // completamente la cadena original al modificarla strtok.
    strcpy(frase_copia, frase);
    // utilizamos el strcpy para copiar una cadena ya que es la unica forma de copiar cadenas
    // o usar car�cter por car�cter desde la fuente (frase) al destino (frase_copia).
    printf("La frase original es: \"%s\"\n\n", frase);
    // aqui para arrancar se coloca la frase_copia esto le da comienzo o inicio de cadena
    // a la funci�n strtok para que comience a buscar tokens desde el principio.
    // es como decirle partimos de esta cadena desde el comienzo
    token = strtok(frase_copia, delimitadores);

    while (token != NULL)
    {
        printf("- Palabra \"%s\"\n", token);
        token = strtok(NULL, delimitadores);
        // En las llamadas subsiguientes a strtok, se pasa NULL como primer argumento.
        // Esto indica a la funci�n que contin�e tokenizando la misma cadena
        // desde la posici�n siguiente al token previamente encontrado.
    }

    return 0;
}

