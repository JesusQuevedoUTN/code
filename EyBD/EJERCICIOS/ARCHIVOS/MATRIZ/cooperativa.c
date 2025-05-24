#include "../../C.h"

typedef struct
{
    int codidoChofer;
    char nombreChofer[30];
    int kms; // kilometros recorridos
    int recaudacion; // Recaudación
} Registro;

void mostrarArchivoTexto(); // Ver archivo de texto original (texto.txt)
void volcarTextoABinario(); // recordar solo una vez se puede hacer
void mostrarBinarioOrdenadoPorCodigo();
void mostrarBinarioOrdenadoPorApellido();
int menu();

/*

*/

#define REGISTROS_DE_VIAJES "../texto 1.txt"
#define ARCHIVO_CHOFERES "../choferes.dat"
#define PRECIO_POR_KM 100

int main()
{
    iniciar();
    int opcion;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            mostrarArchivoTexto();
            break;
        case 2:
            volcarTextoABinario();
            break;
        case 3:
            mostrarBinarioOrdenadoPorCodigo();
            break;
        case 4:
            mostrarBinarioOrdenadoPorApellido();
            break;
        }
        system("cls");
    } while (opcion != 5);
    return 0;
}

int menu()
{
    int opcion = 0;
    do
    {
        printf("\t + - - - - - - - - - - - - - - + COOPERATIVA + - - - - - - - - - - - - - - + \n");
        printf("\t\t[1]\tVer texto.\n");
        printf("\t\t[2]\tVolcar a binario.\n");
        printf("\t\t[3]\tMostrar ordenado por código.\n");
        printf("\t\t[4]\tMostrar ordenado por nombre.\n");
        printf("\t\t[5]\tSalir del sistema.\n");
        printf("\t + - - - - - - - - - - - - - - - + CHOFERES + - - - - - - - - - - - - - - - + \n");
        scanf("%d", &opcion);
        system("cls");
    } while (opcion < 1 || opcion > 5);
    return opcion;
}

void mostrarArchivoTexto()
{
    FILE *archivo = fopen(REGISTROS_DE_VIAJES, "r");
    Registro r;

    if (!archivo)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        printf("[%-12s][%-30s][%-10s]\n", "Cod. Chofer", "Nombre y Apellido", "Kms");
        while (!feof(archivo))
        {
            fscanf(archivo, "%d,%[^,],%d", &r.codidoChofer, r.nombreChofer, &r.kms);
            printf("[%12d][%-30s][%10d]\n", r.codidoChofer, r.nombreChofer, r.kms);
        }
    }
    fclose(archivo);
    system("pause");
}

// 1. Pasar matriz a binario en este formato
//
// Cod. Chofer   Nombre y Apellido   Total Kms. Recorridos   Recaudación Total
//----------------------------------------------------------------------------------------------------------
// n)            FRANCISCO REAL      1750                    $17500
// CONSIDERAR
// 1. NO CODIGOS REPETIDOS.
// 2. SI REPETIDO SUMAR Y CALCULAR.
// 3. MALLOC ESTRUCTURA ANTES DEL BINARIO.
// 4. EL ARCHIVO SOLO SE PASA UNA VEZ. INDICAR ERROR.
// INICIAR
void volcarTextoABinario()
{
    FILE *choferes = fopen(ARCHIVO_CHOFERES, "rb+");
    FILE *viajes = fopen(REGISTROS_DE_VIAJES, "r");
    int contador = 0;
    Registro *chofer = (Registro*)malloc(sizeof(Registro));

    if (!choferes)
    {
        choferes = fopen(ARCHIVO_CHOFERES, "wb+");
        if (!choferes)
        {
            printf("Se creo un nuevo archivo\n");
        }
    }
    else
        printf("El archivo se abrio correctamente\n");

    while (!feof(viajes))
    {
        //Sacamos el dato del texto
        //Comparar si se repite en el Binario
            //SI: 
                //Sumatoria kilometros
            //NO: 
                //Meter datos
        //Calcular recaudacion

        //contador++;
        //chofer = (Registro*)realloc(chofer, sizeof(Registro)*(contador+1));
        //fscanf(viajes, "%d,%[^,],%d", &chofer[contador].codidoChofer, chofer[contador].nombreChofer, &chofer[contador].kms);
    }
    


    free(chofer);
    fclose(choferes);
    fclose(viajes);
}

void mostrarBinarioOrdenadoPorCodigo()
{
}

void mostrarBinarioOrdenadoPorApellido()
{
}