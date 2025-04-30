#include "Libs/utils.h"

    //Constantes
    const char MOTO = 'A';
    const char AUTO = 'B';
    const char CAMION = 'C';
    const char PROFESIONAL = 'D';
    const int FIN = -1;

char validarVehiculo(cadena mensaje);
int aprobado(char tipo, int faltas, int tiempo);

int main()
{
    int datos, aprobados=0, total=0, contador=0, contadorProfesional=0;
    printf("Bienvenido a la sede de licencias de transito\n");

    do
    {
        datos = registrarNumero("Para ingreasar un nuevo dato escriba cualquier numero:\nESCRIBA -1 PARA INDICAR DETENERSE\n");
        if (datos!=FIN)
        {
            // Entrada de datos
            int faltas = registrarMayorA(0, "\nCuantas falta tuvo?\n");
            int tiempo = registrarMayorA(1, "\nCuantos segundos le tomo completar el circuito?\n");
            char categoria = validarVehiculo("\nIndique, que categoria fue?\nA. Pulse 'A' para indicar Moto \nB. Pulse 'B' para indicar Auto\nC. Pulse 'C' para indicar Camion\nD. Pulse 'D' para indicar profesional\n");
            
            // Procesos
            if (aprobado(categoria, faltas, tiempo))
            {
                aprobados++;
            }
            if (categoria==PROFESIONAL)
            {
                total=total+tiempo;
                contadorProfesional++;
            }
            contador++;
            printf("\n");
        }
    } while (datos != FIN);
    
    // Muestra de resultados
    if (contador!=0){
    printf("\nEl total de circuitos aprobados fue:  %d\n", aprobados);
    printf("Minutos promedio PROFESIONAL: %.0f\nSegundos: %d\n", promedio((total/60-total%60),contadorProfesional), total%60);}

    return 0;
}

char validarVehiculo(cadena mensaje)
{
    char coche;
    printf("%s", mensaje);

    do
    {
    fflush(stdin);
    scanf("%c", &coche);
    if (coche!=MOTO && coche!=AUTO && coche!=CAMION && coche!=PROFESIONAL)
    {
        printf("\nERROR. Las letras disponibles solo son A, B, C y D en MAYUSCULAS\nVuelva a Intentarlo\n");
    }
    } while (coche!= MOTO && coche!= AUTO && coche!= CAMION && coche!= PROFESIONAL);
    
    return coche;
}

int aprobado(char tipo, int faltas, int tiempo)
{
    int aprobado=1;
    if (tipo=='A' && faltas<=2 && tiempo <=90)
    {
        aprobado = 0;
    }
    if (tipo=='B' && faltas<=1 || tiempo <=120)
    {
        aprobado = 0;
    }
    if (tipo=='C' || tipo=='D' && faltas<=0)
    {
        aprobado = 0;
    }
    return aprobado;
}