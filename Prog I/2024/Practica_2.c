#include "Libs/utils.h"

int cuentaCaracteres(cadena mensaje);
int cuentaPalabras(cadena mensaje);
int esLetra(char x);
void cuentaLetras(cadena mensaje);
void mayuscula(cadena mensaje);
void estraerPalabra(cadena mensaje);

    /*
int main()
{
    a) El largo de la cadena, realizando una función llamada CuentaCaracteres
    b) La cantidad de palabras ingresadas ,realizando una función llamada
    CuentaPalabras
    c) La cantidad de letras y números, que posee ese texto ingresado, realizando
    una función CuentaLetras
    d) Convertir la cadena ingresada en Mayúscula ,esa conversión dejarla en otra
    cadena, realizando una función llamada Mayúscula
    e) Extraer la ultima palabra de la cadena ,en una función llamada
    ExtraerPalabra 
    */

    /*
    cadena test = " H0, la est0y  prob4ndo la Cadena Nro 1 uno";
    puts(test);
    cuentaCaracteres(test); //19+20+3espacios = 42
    cuentaPalabras(test);   //9 palabras
    cuentaLetras(test);     //28 letras + 4 numeros
    mayuscula(test);        
    estraerPalabra(test);   //UNO
    
    return 0;
}
    */

int cuentaCaracteres(cadena mensaje){
    int i=0;
    while (mensaje[i] != '\0')
    {
        i++;
    }
    return i;
}

int cuentaPalabras(cadena mensaje){
    int i=0, contador=0;
    while (mensaje[i] != '\0')
    {
        if ( (i == 0 && esLetra(mensaje[i]) ) || (esLetra(mensaje[i]) && mensaje[i-1] == ' ') )
        {
            contador++;
        }
        i++;
    }
    return contador;
}

int esLetra(char x){
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

void cuentaLetras(cadena mensaje){
    int i=0;
    int contadorLetras=0;
    int contadorNumeros=0;
    
    while (mensaje[i] != '\0')
    {
        if (mensaje[i]>='0' && mensaje[i]<='9')
        {
            contadorNumeros++;
        }
        if ( (mensaje[i]>='a' && mensaje[i]<='z') || (mensaje[i]>='A' && mensaje[i]<='Z'))
        {
            contadorLetras++;
        }
        i++;
    }
    printf("La cadena tiene %d letras y %d numeros\n", contadorLetras, contadorNumeros);
}

void mayuscula(cadena mensaje){
    int i=0;
    while (mensaje[i] != '\0')
    {
        if (mensaje[i]>='a' && mensaje[i]<='z')
        {
            mensaje[i] = mensaje[i] - 32;
        }
        
        i++;
    }
    puts(mensaje);
}

void estraerPalabra(cadena mensaje){
    char *token = strtok(mensaje, " ");
    char *ultima;
    cadena extraer;

    while (token != NULL)
    {
        ultima = token;
        token = strtok(NULL, " ");
        strcpy(extraer, ultima);
    }
    puts(extraer);
}