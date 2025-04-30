#include <stdio.h>
int main()
{
//18. Realizá un programa que permita al usuario ingresar 12 valores, de a uno por vez, que representan los sueldos mensuales que percibió un empleado durante un año. Si
//durante la carga de los sueldos mensuales se detecta un valor negativo, esto indica que aún no se ha cobrado el mes en curso, por lo tanto, deben dejar de
//ingresarse datos. La computadora debe mostrar el sueldo anual percibido (total o parcial).
/*const int MESES=12;
const int ALTO=0;
int mes=1;
float sumatoria=0, sueldo;
printf("Ingrese su triste sueldo mensual, ponga un numero negativo\nSalario mes %d:\n", mes);
fflush(stdin);
scanf("%f", &sueldo);
sumatoria=sumatoria+sueldo;

if (sueldo<ALTO)
{
    printf("Inicie bien su anio");
}
else
{
    do
    {
        sumatoria=sumatoria+sueldo;
        mes++;
        printf("Salario mes %d:\n", mes);
        fflush(stdin);
        scanf("%f", &sueldo);
    } while (sueldo>=ALTO && mes<MESES);
    printf("El total es de: %.2f$", sumatoria);
}*/



//19. Realizá un programa que permita al usuario ingresar dos números enteros que representen el ancho y el alto de una matriz de cruces. La computadora debe
//mostrar dicha matriz.
/*int ancho, largo;
printf("Ingrese el largo de la matriz\n");
fflush(stdin);
scanf("%d", &largo);
printf("Ingrese el ancho de la matriz\n");
fflush(stdin);
scanf("%d", &ancho);

if (ancho>0 && largo>0)
{
    for (int i = 0; i < largo; i++)
    {
        for (int i = 0; i < ancho; i++)
        {
            printf("x ");
        }
        printf("\n");
    }
}
else
{
    printf("Solo una tarea y la haces mal?");
}*/


//20. Realizá un programa que permita al usuario ingresar un número de minutos. La computadora debe mostrar un cronómetro con el formato "mm:ss" desde "00:00" hasta un
//segundo antes del minuto ingresado
    /*const int CICLO = 60;
    int numero, minutos=0, segundos=0;
    printf("Inserte un minuto\n");
    fflush(stdin);
    scanf("%d", &numero);

    if (numero>0)
    {
        while (minutos<numero)
        {
            printf("%d:%d\n", minutos, segundos);
            segundos++;
                if (segundos==CICLO)
                {
                    segundos=0;
                    minutos++;
                }
        }
        printf("%d:%d\n", minutos, segundos);
    }
    else
    {
        printf("Imbecil");
    }*/
    
    
    return 0;
}

