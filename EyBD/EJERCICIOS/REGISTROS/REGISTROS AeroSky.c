#include "../C/Libs/utils.h"

// Definición de la estructura Asiento
typedef struct
{
    int fila;
    char columna;
    int ocupado; // 0 = libre, 1 = ocupado
    char pasajero[50];
} Asiento;
// Definición de la matriz de asientos
#define FILAS 25
#define COLUMNAS 4
Asiento avion[FILAS][COLUMNAS];

#define MIN_FILAS 1
#define MAX_FILAS 25

// Prototipos de funciones
void inicializarAsientos(Asiento avion[][COLUMNAS]);
void pausa(void);
int menu(void);
void reservarAsiento(Asiento avion[][COLUMNAS]);
void cancelarReserva(Asiento avion[][COLUMNAS]);
void mostrarEstado(Asiento avion[][COLUMNAS]);
void consultarReservas(Asiento avion[][COLUMNAS]);

//

void mostrarAsiento(Asiento avion);
void buscarAsiento(int* fila, int* columna);

int main()
{
    int op;
    inicializarAsientos(avion);
    do
    {
        op = menu();
        system("cls");
        switch (op)
        {
        case 1:
            reservarAsiento(avion);
            break;
        case 2:
            cancelarReserva(avion);
            break;
        case 3:
            mostrarEstado(avion);
            break;
        case 4:
            consultarReservas(avion);
            break;
        }
    } while (op < 5);
    return 0;
}

void inicializarAsientos(Asiento avion[][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            avion[i][j].fila = i + 1;
            avion[i][j].columna = 'A' + j;
            avion[i][j].ocupado = 0;
            strcpy(avion[i][j].pasajero, "");
        }
    }
}

int menu(void)
{
    int op;
    do
    {
        system("cls");
        printf("\n\t\t\t MENU DE RESERVAS DEL ESTACIONAMIENTO\n");
        printf("\n 1. Reservar un asiento\n");
        printf(" 2. Cancelar una reserva\n");
        printf(" 3. Mostrar asientos ocupados y libres\n");
        printf(" 4. Consultar reservas por pasajero\n");
        printf(" 5. Salir\n");
        printf(" Ingrese una opcion [1-5]: ");
        scanf("%d", &op);
    } while (op < 1 || op > 5);
    return op;
}
//PIDE NUM Y COL
//LIBRE: PEDIR NOMBRE
//OCUPADO: ERROR, VUELVA A ELEGIR
void reservarAsiento(Asiento avion[][COLUMNAS])
{
    int fila, columna;
    
    do
    {
        buscarAsiento(&fila,&columna);
        
        if (avion[fila][columna].ocupado == 1)
        {
            printf("ERROR. El asiento ya esta ocupado.\n");
            system("pause");
            system("cls");
        }
    } while (avion[fila][columna].ocupado == 1);

    printf("INGRESE SU NOMBRE: ");
    scanf(" %[^\n]", avion[fila][columna].pasajero);
    avion[fila][columna].ocupado = 1;
}
//OCUPADO: SE DESOCUPA
//LIBRE: ERROR, NO HABIA RESERVA AHI
void cancelarReserva(Asiento avion[][COLUMNAS])
{
    int fila    = 0;
    int columna = ' ';
    
    do
    {
        buscarAsiento(&fila, &columna);

        if (avion[fila][columna].ocupado == 0)
        {
            printf("ERROR. El asiento ya esta desocupado.\n");
            system("pause");
            system("cls");
        }

    } while (avion[fila][columna].ocupado==0);
    
    printf("\nReserva eliminada:\n");
    mostrarAsiento(avion[fila][columna]);
    avion[fila][columna].ocupado = 0;
    mostrarAsiento(avion[fila][columna]);
    system("pause");
}
//MOSTRAR SI ESTAN LIBRES O NO, Y NOMBRE
//CANT LIBRES Y OCUPADOS
void mostrarEstado(Asiento avion[][COLUMNAS])
{
    int libres = 50, ocupados =0;

    printf("[%3s][%3s][%-50s]\n", "FIL", "COL","NOMBRE DEL PASAJERO");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            mostrarAsiento(avion[i][j]);
            if (avion[i][j].ocupado == 1)
            {
                libres--;
                ocupados++;
            }
            
        }
        puts("");
    }
    printf("ASIENTOS LIBRES:    %d\n", libres);
    printf("ASIENTOS OCUPADOS:  %d\n", ocupados);
    system("pause");
}
//PEDIR NOMBRE
//MOSTRAR ASIENTOS A SU NOMBRE
void consultarReservas(Asiento avion[][COLUMNAS])
{
    char nombre[50];
    printf("INGRESE EL NOMBRE QUE BUSCA: ");
    scanf(" %[^\n]", nombre);
    int contador = 0;

    for (int fila = 0; fila < FILAS;fila++)
    {
        for (int columna = 0; columna < COLUMNAS; columna++)
        {
            if (strcmp(nombre,avion[fila][columna].pasajero) == 0)
            {
                mostrarAsiento(avion[fila][columna]);
                contador++;
            }
        }
    }
    if (contador == 0)
    {
        printf("No hay nadie con el nombre: %s", nombre);
    }
    system("pause");
}

//
void mostrarAsiento(Asiento avion)
{
    if (avion.ocupado==1)
    {
        printf("[%-3d][%-3c][%-50s]", avion.fila,avion.columna, avion.pasajero);
    }
    else
    {
        printf("[%-3d][%-3c][%-50s]", avion.fila,avion.columna, " ");
    }
    puts("");
}

void buscarAsiento(int* fila, int* columna)
{
    do
        {
            printf("INGRESE LA FILA QUE BUSCA [%d - %d]: ", MIN_FILAS, MAX_FILAS);
            scanf(" %d", fila);
            if (*fila>MAX_FILAS || *fila<MIN_FILAS)
            {
                printf("ERROR. Fuera de rango: [%d - %d]\n", MIN_FILAS, MAX_FILAS);
            }
        } while (*fila>MAX_FILAS || *fila<MIN_FILAS);
        
        do
        {
            printf("INGRESE LA COLUMNA QUE BUSCA [%d - %d]: ", MIN_FILAS, COLUMNAS);
            scanf(" %d", columna);
            if (*columna>COLUMNAS || *columna<MIN_FILAS)
            {
                printf("ERROR. Fuera de rango: [%d - %d]\n", MIN_FILAS, COLUMNAS);
            }
        } while (*columna>COLUMNAS || *columna<MIN_FILAS);        

        (*fila)--;
        (*columna)--;

}