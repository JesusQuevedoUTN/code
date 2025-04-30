#include "Libs/utils.h"

//1
void invertirVectorDeEnteros(int vec[], int cant);

void separador();

//2
int sumatoria(int vec[], int cant);
void promedioVector(int vec[], int cant);
void mayorAlPromedio(int vec[], float prom, int cant);
//3
void vectorMultiplos(int vec[], int cant);
//4
void maximoValorDelVector(int vec[], int cant);
void aumentarTotal(int num, int maximo, int* total);
void nuevoMax(int vec, int num, int* maximo, int* total);
//5
void sumatoriaParesVector(int vec[], int cant);

int main()
{
    /*
    1) Realizá un programa que permita al usuario ingresar 6 números enteros. La computadora debe
    mostrar cada elemento leído en un solo renglón. Luego, mostrar lo mismo, pero de forma invertida.

    int ejercicio[6];
    leerVectorDeEnteros("Ingrese un valor: ", ejercicio, 6);
    mostrarVectorDeEnteros(ejercicio, 6);

    invertirVectorDeEnteros(ejercicio, 6);
    separador();
    mostrarVectorDeEnteros(ejercicio, 6);
    */

    /*
    2) Realizá un programa que permita al usuario ingresar 8 números enteros. La computadora debe
    mostrar el promedio de los mismos y cuáles fueron los valores ingresados que lo superaron.
    
    int x=8;
    int ejercicio[]={1, 1, 1, 1, 1, 1, 21, 8};
    //leerVectorDeEnteros("Ingrese un valor: ", ejercicio, x);
    promedioVector(ejercicio, x);
    */

    /*
    3) Realizá un programa que permita al usuario ingresar 7 números enteros. La computadora debe
    mostrar aquellos que sean múltiplos del último número ingresado.

    int x=7;
    int ejercicio[]={5, 10, 25, 30, 15, 20, 5};
    //leerVectorDeEnteros("Ingrese un valor: ", ejercicio, x);
    vectorMultiplos(ejercicio, x);
    */
    
    /*
    4) Realizá un programa que permita al usuario ingresar 9 números enteros. La computadora debe
    mostrar el valor máximo y la cantidad de veces que se ingresó tal valor.

    int x=9;
    int ejercicio[]={35, 35, 35, 35, 35, 5, 5, 5, 30};
    maximoValorDelVector(ejercicio, x);
    */
    

    /*
    5) Realizá un programa que permita al usuario ingresar 8 números enteros. La computadora debe
    mostrar la suma de los números ingresados en las posiciones pares.
    
       int x=8;
    int ejercicio[]={2, 1, 2, -15, 2, 0, 2, -7423};
    sumatoriaParesVector(ejercicio, x);
    */

    return 0;
}


//1
void invertirVectorDeEnteros(int vec[], int cant)
{
    int pos=cant-1;
    for (int i = 0; i < cant/2; i++)
    {
        cambiarPosicionDeEnteros(&vec[i], &vec[pos]);
        pos--;
    }
    
}

void separador()
{
    printf("\n0 - - - - - - - - - - 0\n");
}
//2
int sumatoria(int vec[], int cant)
{
    int a=0;
    for (int i = 0; i < cant; i++)
    {
        a += vec[i];
    }
    return a;
}
void promedioVector(int vec[], int cant)
{
    int suma=0;
    float prom;
    suma = sumatoria(vec, cant);
    prom = promedio(suma, cant);
    printf("Sumatoria: %d\nPromedio: %.1f\n\n", suma, prom);
    mayorAlPromedio(vec, prom, cant);
}
void mayorAlPromedio(int vec[], float prom, int cant){
    for (int i = 0; i < cant; i++)
    {
        if (vec[i] >= prom)
        {
            printf("%d", vec[i]);
        }
        
    }
}
//3
void vectorMultiplos(int vec[], int cant)
{
    int mult = cant-1;
    printf("Los numeros multiplos de %d son: ", vec[mult]);
    for (int i = 0; i < cant-1; i++)
    {
        if (vec[i]%vec[mult]==0)
        {
            printf("%d ", vec[i]);
        }
    }  
}
//4
void maximoValorDelVector(int vec[], int cant)
{
    int contador=0, total=0;
    int maximo=0;
    while (contador<cant)
    {
        nuevoMax(vec[contador], contador, &maximo, &total);
        aumentarTotal(vec[contador], maximo, &total);
    contador++;
    }
    printf("El valor maximo es: %d\nSalio: %d veces", maximo, total);
}
void aumentarTotal(int num, int maximo, int *total)
{
    if (num==maximo)
            {
                *total=*total+1;
            }
    }
void nuevoMax(int vec, int num, int* maximo, int* total)
{
    if (num == 0 || vec > *maximo)
            {
                *total=0;
                *maximo=vec;
            }
}
//5
void sumatoriaParesVector(int vec[], int cant)
{
    int sum=0, i=0;
    while (i<cant)
    {
        sum+=vec[i];
        i+=2;
    }
    printf("La sumatoria de los pares es: %d", sum);    
}