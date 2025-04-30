#include "Libs/utils.h"

void separador();
//6
void invertirVectorDeCaracteres(char vec[], int cant);
//7
void unoALaDerecha(char vec[], int cant);
//8
int esPalindromo(char vec[], int cant);
//9
void mostrarSinRepetir(char vec[], int cant);
//10
void mostrarUnion(char pri[], int pi, char seg[], int segs);
void mostrarInterseccion(char pri[], int pi, char seg[], int segs);
void mostrarDiferencia(char pri[], int pi, char seg[], int segs);
void mostrarDiferenciaSimetrica(char pri[], int pi, char seg[], int segs);
int seRepitio(char letra, char vec[], int cant);

int main()
{
    /*
    6) Realizá un programa que permita al usuario ingresar 9 caracteres. La computadora debe invertir
    el contenido del array de caracteres sin usar un array auxiliar. Luego, mostrarlo.
    
    int x=9;
    char ejercicio[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o'};
    invertirVectorDeCaracteres(ejercicio, x);
    mostrarVectorDeCaracteres(ejercicio, x);
    */

    /*
    7) Realizá un programa que permita al usuario ingresar 9 caracteres. La computadora debe rotar
    un lugar hacia la derecha el contenido del array de caracteres sin usar un array auxiliar. Luego,
    mostrarlo.
    
    int x=9;
    char ejercicio[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unoALaDerecha(ejercicio, x);
    mostrarVectorDeCaracteres(ejercicio, x);
    */
    
    /*
    8) Realizá un programa que permita al usuario ingresar 9 caracteres. La computadora debe indicar
    si la palabra representada es o no un palíndromo.
    
    int x=9;
    char ejercicio[] = {'q', 'q', 'e', 'e', 't', 'e', 'e', 'q', 'q'};
    
    if (esPalindromo(ejercicio,x))
    {
        printf("Es palindromo");
    }
    else
    {
        printf("No es palindromo");
    }
    */

    /*
    9) Realizá un programa que permita al usuario ingresar 9 caracteres. La computadora debe
    mostrarlos sin repetidos.
    
    int x=9;
    char ejercicio[] = {'e', 'q', 'e', 'r', 't', 'q', 'w', 'e', 'e'};
    mostrarSinRepetir(ejercicio, x);
    */

    /*
    10) Realizá un programa que permita al usuario ingresar 2 vectores de caracteres separados, no
    necesariamente de la misma longitud, que representan dos conjuntos (es decir, no puede haber
    valores repetidos en el mismo vector). La computadora debe mostrar:
    A) La unión.
    B) La intersección.
    C) La diferencia.
    D) La diferencia simétrica.
    
    int x= 6, y=6;
    char primera[] = {'B', 'L', 'A', 'N', 'C', 'O'}, segunda[] = {'S', 'A', 'L', 'M', 'O', 'N'};
    mostrarUnion(primera, x, segunda, y); //
    separador();
    mostrarInterseccion(primera, x, segunda, y);
    separador();
    mostrarDiferencia(primera, x, segunda, y);
    separador();
    mostrarDiferenciaSimetrica(primera, x, segunda, y);
    */  

    return 0;
}

//6
void invertirVectorDeCaracteres(char vec[], int cant)
{
    int pos=cant-1;
    for (int i = 0; i < cant/2; i++)
    {
        cambiarPosicionDeCaracteres(&vec[i], &vec[pos]);
        pos--;
    }   
}
//7
void unoALaDerecha(char vec[], int cant)
{
    for (int i = cant-1; i > 0; i--)
    {
        cambiarPosicionDeCaracteres(&vec[i],&vec[i-1]);
    }
}
//8
int esPalindromo(char vec[], int cant)
{
    int final=cant-1, a=1, b=1;
    for (int i = 0; i < cant/2; i++)
    {
        if (vec[i]!=vec[final])
        {
            b++;
        }
        
        final--;
    }
    return a==b;    
}
//9
void mostrarSinRepetir(char vec[], int cant)
{
    int cont=0;
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < i; j++) 
        {
            if (sonIgualesCaracteres(vec[i],vec[j])) 
            {
                cont=1;
            }
            
        }
        if (cont == 0)
        {
            printf("%c ", vec[i]);
        }        
        cont=0;
    }
    
}
//10
void mostrarUnion(char pri[], int pi, char seg[], int segs)
{   
    mostrarSinRepetir(pri, pi);
    for (int i = 0; i < segs; i++)
    {
        if (seRepitio(seg[i],pri,pi))
        {
            printf("%c ", seg[i]);
        }
        
    }
}
void mostrarInterseccion(char pri[], int pi, char seg[], int segs)
{
    for (int i = 0; i < pi; i++)
    {
        for (int j = 0; j < segs; j++)
        {
            if (pri[i]==seg[j] && seRepitio(pri[i], pri, i) && seRepitio(seg[j], seg, j))
            {
            printf("%c ", pri[i]);    
            }
            
        }
    }
}
void mostrarDiferencia(char pri[], int pi, char seg[], int segs)
{
    int cont=0;
    for (int i = 0; i < pi; i++)
    {
        for (int j = 0; j < segs; j++) 
        {
            if ( sonIgualesCaracteres(pri[i],seg[j]) ) 
            {
                cont=1;
            }
            
        }
        if (cont == 0)
        {
            printf("%c ", pri[i]);
        }        
        cont=0;
    }    
}
void mostrarDiferenciaSimetrica(char pri[], int pi, char seg[], int segs)
{
    mostrarDiferencia(pri, pi, seg, segs);
    mostrarDiferencia(seg, segs, pri, pi);
}

int seRepitio(char letra, char vec[], int cant)
{
    int a=1;
    for (int i = 0; i < cant; i++)
    {
        if (letra==vec[i])
        {
            a=0;
        }
    }
    return a;
}

void separador()
{
    printf("\n0 - - - - - - - - - - 0\n");
}