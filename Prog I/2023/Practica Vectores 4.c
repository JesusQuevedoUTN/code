#include "Libs/utils.h"

//15
void listadoDePalabras(cadena oracion[]);
int letraEsIgual(char x, char y);
//16
void vectorMayusculas(char vec[], int x);
int contadorDeLetras(char vec[], int cant);
//17 POR EL PROFE
void cifrarPorDesplazamiento(cadena cad, int nroDesp);
int esLetraMinuscula(char caracter);
int esLetraMayuscula(char caracter);
//18
void mostrarCadaCifradoPosible(cadena cad);
void siguienteLetra(cadena cad);

int main()
{
    /*15) CON CHAT GPT
    Realizá un programa que permita al usuario ingresar una cadena que represente una
    frase/oración. La computadora debe mostrar un listado de todos los pares de palabras
    consecutivas en los cuales la primera palabra termina con la inicial de la segunda.
    cadena ejercicio;
    leerCadena("Ingrese una oracion, le mostraré las cadenas que compartan su letra final, con la final", ejercicio);
    listadoDePalabras(ejercicio);
    */
    /*16) 
    Realizá un programa que permita al usuario ingresar una cadena que represente una
    frase/oración. La computadora debe mostrarla enteramente en mayúsculas.
    cadena ejercicio;
    gets(ejercicio);
    
    vectorMayusculas(ejercicio, strlen(ejercicio));

    mostrarVectorDeCaracteres(ejercicio, strlen(ejercicio));
    */
    /*17) POR EL PROFE 
    Realizá un programa que permita al usuario ingresar una cadena que represente una
    frase/oración y un número entero positivo que indique el desplazamiento. La computadora debe
    cifrar la cadena (solo letras) utilizando el cifrado César y mostrar cómo quedó.
    puts("Ingrese la frase que quiere utilizar el cifrado Cesar:");
    cadena cad;
    int desp = leerEnteroEntre(0, 1000, "Ingrese el desplazamiento (positivo)");
    leerCadena("Ingrese una cadena para cifrar", cad);

    printf("Cadena ingresada: \"%s\"\n", cad);
    cifrarPorDesplazamiento(cad, desp);
    printf("Cadena cifrada: \"%s\"\n", cad);
    */
    /*18) 
    La siguiente cadena ha sido cifrada utilizando el cifrado César: "Bm nmtqkqbw. Pia xwlqlw
    lmakqnziz ti kilmvi.". Se desconoce el desplazamiento. Realizá un programa que permita
    descifrar la cadena, mostrando cada uno de los 25 resultados posibles. ¿Lograrás ver el mensaje
    entre alguno de ellos?
    cadena frase = "Bm nmtqkqbw. Pia xwlqlw lmakqnziz ti kilmvi.";
    mostrarCadaCifradoPosible(frase);
    */
    
    return 0;
}

//15
void listadoDePalabras(cadena oracion[])
{
    char *token = strtok(oracion, " ");
    cadena palabraAnterior;
    strcpy(palabraAnterior, token);
    
    while (token)
    {   
        if ( letraEsIgual(palabraAnterior[strlen(palabraAnterior)-1], token[0]) )
            {
                printf("%s - %s\n", palabraAnterior, token);
            }
        strcpy(palabraAnterior, token);
        token = strtok(NULL, " ");
    }
}
int letraEsIgual(char x, char y)
{
    return x == y;
}
//16
void vectorMayusculas(char vec[], int x)
{
    for (int i = 0; i < x; i++)
    {
        if (vec[i]>=97 && vec[i]<=122)
        {
            vec[i]-=32;
        }
    }
}
//17 DEL PROFE
void cifrarPorDesplazamiento(cadena cad, int nroDesp) {
    const int CANT_LETRAS = 'z' - 'a' + 1; // Son 26 letras posibles
    for (int i = 0; i < strlen(cad); i++) {
        if (esLetraMinuscula(cad[i])) {         
            cad[i] = ((cad[i] - 'a' + nroDesp) % CANT_LETRAS) + 'a';
        }
        if (esLetraMayuscula(cad[i])) {         
            cad[i] = ((cad[i] - 'A' + nroDesp) % CANT_LETRAS) + 'A';
        }
    }
}
int esLetraMinuscula(char caracter) {
   return caracter >= 'a' && caracter <= 'z'; 
}
int esLetraMayuscula(char caracter) {
   return caracter >= 'A' && caracter <= 'Z'; 
}
//18
void mostrarCadaCifradoPosible(cadena cad)
{
    for (int i = 0; i < strlen(cad); i++)
    {
        puts(cad);
        siguienteLetra(cad);
    }
    
}
void siguienteLetra(cadena cad)
{
    for (int i = 0; i < strlen(cad) ; i++)
    {
        if ( (cad[i]>='A' && cad[i]<'Z') || (cad[i]>='a' && cad[i]<'z') )
        {
            cad[i]++;
        }
        if (cad[i]== 'Z' || cad[i]== 'z')
        {
            cad[i] -= 25;
        }
    }
}
