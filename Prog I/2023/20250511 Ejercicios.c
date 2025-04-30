#include "Libs/utils.h"

//1. esPar, que devuelva si un número entero dado como parámetro es par o no.
int esPar(int);

//2. obtenerResto, que devuelva el resto del cociente entre dos números enteros dados como parámetros (sin usar el operador %).
int obtenerResto(int, int);

//3. imprimirSimbolo, que imprima por consola n veces un caracter en la misma línea. Tanto n como el caracter se reciben como parámetro.
void imprimirSimbolo (char, int);

//4. esVocal, que devuelva si un caracter dado como parámetro es o no una letra vocal (contemplar mayúsculas y minúsculas).
int esVocal (char);

//5. mostrarSucesion, que imprima por consola la sucesión de números inclusiva entre a y b, dados como parámetros.
void mostrarSucesion (int, int);
int esMayor(int, int);

//6. esMultiplo, que devuelva si un número entero es múltiplo de otro. Ambos son dados como parámetros.
int esMultiplo(int, int);

//7. cantDivisores, que devuelva la cantidad de divisores que posea un número entero dado como parámetro.
int cantDivisores(int);

//8. esPrimo, que devuelva si un número entero dado como parámetro es o no primo.
int esPrimo(int);

//9. mostrarNPrimos, que muestre por la consola, separados por comas, los primeros n números primos. El valor de n se recibe como parámetro.
void mostrarNPrimos(int);

//10. esNumeroPerfecto, que devuelva si un número entero dado como parámetro es o no perfecto.
int esNumeroPerfecto(int);

int main ()
{
    printf("Probar\n\n");

/*  1.
    int a;
    scanf("%d", &a);
    if (esPar(a))
    {
        printf("Es par");
    }   else {printf("No");}
*/

/*  2.
    int a, b, resto;
    scanf("%d %d", &a, &b);
    resto=obtenerResto(a,b);
    printf("Resto: %d", resto);
*/

/*  3.
    char c;
    fflush(stdin);
    scanf("%c", &c);
    fflush(stdin);
    int n;
    scanf("%d", &n);

    imprimirSimbolo(c, n);
*/

/*  4.
char c;
    fflush(stdin);
    scanf("%c", &c);

    if (esVocal(c))
    {
        printf("%c si es una vocal", c);
    }
    else
    {
        printf("Vuelva a jardin porque %c NO es una vocal", c);
    }
*/

/*  5.
int primero, segundo;
    fflush(stdin);
    scanf("%d", &primero);
    fflush(stdin);
    scanf("%d", &segundo);

    mostrarSucesion (primero, segundo);
*/

/*  6.
    int a, b;
    fflush(stdin);
    scanf("%d %d", &a, &b);
    
    if (esMultiplo(a,b)==0)
    {
        printf("\n%d y %d son multiplos", a, b);
    }
    else
    {
        printf("\n%d y %d NO son multiplos", a, b);
    }*/

/*  7.
int a;
fflush(stdin);
scanf("%d", &a);

printf("\n%d tiene: %d divisores", a, cantDivisores(a));
*/

/*  8.
    int a;
    fflush(stdin);
    scanf ("%d", &a);

    if (esPrimo(a)==0)
    {
        printf("\nUgh, es primo");
    }
    else
    {
        printf("\nno no no");
    }*/
    
/*  9.
int a;
scanf("%d", &a);
mostrarNPrimos(a);
*/

/*  10.
int a;
scanf("%d", &a);
if (esNumeroPerfecto(a)==0)
{
    printf("E pefecto, no como ute");
}
else
{
    printf("E como ute, malandro");
}
*/

return 0;
}

int esPar(int n)
{
return (n+1)%2;
}

int obtenerResto(int divisor, int dividendo)
{
 return divisor-(divisor/dividendo)*dividendo;
}

void imprimirSimbolo (char letra, int cont){
    for(int i=0;i<cont;i++){
    printf("%c", letra);
    }
}

int esVocal (char x){
    const char PRIMERA='A';
    const char SEGUNDA='E';
    const char TERCERA='I';
    const char CUARTA= 'O';
    const char QUINTA= 'U';
    
    if(x==PRIMERA || x==PRIMERA+32 || x==SEGUNDA || x==SEGUNDA+32 || x==TERCERA || x==TERCERA+32 || x==CUARTA
    || x==CUARTA+32 || x==QUINTA || x==QUINTA+32)
    {return 1;}
    else
    {return 0;}
}

void mostrarSucesion(int a, int b)
{
    if (esMayor(a, b)<0){
    for(int i=a;i<=b;i++){printf("\n%d", i);}
    }
    else
    {
    for(int i=a;i>=b;i--){printf("\n%d", i);}
    }
}

int esMayor (int a,int b)
{return (a-b);}

int esMultiplo(int a, int b)
{
    if (a%b==0 || b%a==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cantDivisores(int n)
{
    int m=0;
    for (int i = 1; i<=n; i++)
    {
        if (n%i==0)
        {
            m++;
        }
        
    }
    
    return m;
}

int esPrimo(int p)
{
    int o=0;
    for (int i = 2; i<p; i++)
    {if (p%i==0) {o++;}}
    return o;
}

void mostrarNPrimos(int n)
{
    int i=1, o=1;
    while (o<n)
    {
        if (esPrimo(i)==0)
        {
            printf("%d, ", i);
            o++;
        }
    i++;
    }
    
}

int esNumeroPerfecto(int n)
{
    int o=0;
    for (int i=1; i < n; i++)
    {
        if (obtenerResto(n,i)==0)
        {
            o=o+i;
        }
    }
    if (o==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 