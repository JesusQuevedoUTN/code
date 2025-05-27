#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
#define ARCH_TIEMPOS2 "../tiempos2.dat"
#define ARCH_CORREDORES "../corredores.dat"
#define ARCH_CONFIG "../config.txt"
#define ARCH_TOP "../top10.txt"
#define TOTAL_DE_VUELTAS 10
#define TOP 10

typedef struct
{
    int numcorredor;
    char nombre[15];
    char apellido[15];
    char escuderia[15];
} Corredor;

typedef struct
{
    int numvuelta;
    int numcorredor;
    float tiempo;
} tiempos;
// ++++++++++++++++++++++++++++++++++++
// chequear posibles struct a utilizar
// ++++++++++++++++++++++++++++++++++++
typedef struct
{
    int numcorredor;
    float tiempo;
    char nombre[15];
    char apellido[15];
}tiempoFinal;
/*
typedef struct
{
    int numcorredor;
    float tiempodevuelta;
    float sumatiempo;
    char nombre[15];
    char apellido[15];
}tiempoParcial;
*/

void mostrarVersion(char *aplicacion, char *circuito, char *version);
void MostrarCorredores();
void MostrarTiempos();
void MostrarPromedioTiempoVuelta(); // opcion 3
void Top_10_de_carrera(); // opcion 4
void Menu();
void utf8();
int compararCorredoresPorTiempo(const void *a, const void *b);

int main()
{
    utf8();
    int opcion;
    Menu();
    printf("Ingrese la opcion deseada:\n");
    scanf("%d", &opcion);

    while (opcion != -1)
    {
        system("cls");

        switch (opcion)
        {
        case 1:
            MostrarCorredores();
            system("pause");
            break;

        case 2:
            MostrarTiempos();
            system("pause");
            break;

        case 3: MostrarPromedioTiempoVuelta();
                break;

        case 4: Top_10_de_carrera();
                break;
        }

        system("cls");

        Menu();
        printf("Ingrese la opcion deseada:\n");
        scanf("%d", &opcion);
    }
    printf("\n\nsaliendo del sistema .....!!!\n\n");
    return 0;
}


void MostrarPromedioTiempoVuelta()
{
    FILE *archCorredores = fopen(ARCH_CORREDORES, "rb");

    //EL ARCHIVO NO EXISTE
    if (!archCorredores)
    {
        printf("ERROR. No se pudo abrir el archivo %s...\n", ARCH_CORREDORES);
        system("pause");
    }
    //SI EL ARCHIVO EXISTE...
    else
    {
        Corredor corredorABuscar;
        int codigo;
        int flag = 0;
        printf("INGRESE CODIGO DE CORREDOR:");
        scanf(" %d", &codigo);

        //BUSQUEDA
        while (!flag && fread(&corredorABuscar, sizeof(Corredor), 1, archCorredores))
        {
            //SI ES IGUAL ENTONCES FLAG ENCONTADO
            if (codigo == corredorABuscar.numcorredor)
            {
                flag = 1;
                fseek(archCorredores, -sizeof(Corredor), SEEK_CUR);
            }
        }

        //FUE ENCONTRADO...
        if (flag)
        {
            //CALCULAR PROMEDIO...
            flag = 0;
            FILE *archVueltas = fopen(ARCH_TIEMPOS2, "rb");
            float promedioDeVuelta = 0.0;
            tiempos tiempoABuscar;
            while (!flag && fread(&tiempoABuscar, sizeof(tiempos), 1, archVueltas))
            {
                //SI ES IGUAL ENTONCES SUMAMOS
                if (corredorABuscar.numcorredor == tiempoABuscar.numcorredor && (tiempoABuscar.numvuelta != 0) )
                {
                    promedioDeVuelta = promedioDeVuelta + tiempoABuscar.tiempo;
                }
            }

            //MOSTRAR EN PANTALLA...
            printf("%s %s\n", corredorABuscar.nombre, corredorABuscar.apellido);
            printf("Promedio de vuelta: %.3f\n", promedioDeVuelta/TOTAL_DE_VUELTAS);

            fclose(archVueltas);
        }
        //NO FUE ENCONTRADO...
        else
        {
            printf("ERROR. El corredor que indicó no existe, volviendo al MENU.\n");
        }
        
        //CERRAMOS
        fclose(archCorredores);
        system("pause");
    }
}

void Top_10_de_carrera()
{
    FILE *archTiempo = fopen(ARCH_TIEMPOS2, "rb");
    FILE *archCorredores = fopen(ARCH_CORREDORES, "rb");
    Corredor corredorEnLista;
    tiempos tiempoEnLista;

    tiempoFinal *todosLosCorredores = (tiempoFinal*)malloc(sizeof(tiempoFinal));
    int contador = 0;

    //CONSEGUIR LOS CORREDORES PARA GUARDARLOS EN LA LISTA
    while (fread(&corredorEnLista, sizeof(Corredor), 1, archCorredores))
    {
        strcpy(todosLosCorredores[contador].nombre,corredorEnLista.nombre);
        strcpy(todosLosCorredores[contador].apellido,corredorEnLista.apellido);
        todosLosCorredores[contador].numcorredor = corredorEnLista.numcorredor;
        todosLosCorredores[contador].tiempo = 0.0;

        //TENEMOS AL CORREDOR, SOLO NOS FALTAN SUS TIEMPOS
        while (fread(&tiempoEnLista, sizeof(tiempos), 1, archTiempo))
        {
            if (tiempoEnLista.numcorredor == corredorEnLista.numcorredor && tiempoEnLista.numvuelta != 0)
            {
                todosLosCorredores[contador].tiempo = todosLosCorredores[contador].tiempo + tiempoEnLista.tiempo;
            }
        }
        
        //REBOBINAMOS, SUMAMOS 1 POSICION, Y REACOMODAMOS LA MEMORIA DINAMICA
        rewind(archTiempo);
        contador++;
        todosLosCorredores = (tiempoFinal *)realloc(todosLosCorredores, (contador+1) * sizeof(tiempoFinal));
    }
    
    //ORDENAR LOS ELEMENTOS CON QUICKSORT
    qsort(todosLosCorredores,contador,sizeof(tiempoFinal),compararCorredoresPorTiempo);
 
    //METER LOS ELEMENTOS EN EL ARCHIVO TOP10.TXT
    //Posición - Apellido Nombre (Número) - Tiempo Total - Puntaje
    FILE *archTopDiez = fopen(ARCH_TOP, "w");
    int puntaje[] = { 25 , 18 , 15 , 12, 10, 8, 6, 4, 2, 1 };
    for (int i = 0; i < TOP; i++)
    {
        fprintf(archTopDiez, "%d° | %s %s - (%d) | %.3f | %d pts.\n", i+1, todosLosCorredores[i].apellido, todosLosCorredores[i].nombre, todosLosCorredores[i].numcorredor, todosLosCorredores[i].tiempo, puntaje[i]);
    }
    
    //cerramos archivos y heap
    fclose(archTiempo);
    fclose(archCorredores);
    fclose(archTopDiez);
    free(todosLosCorredores);
    printf("REVISE EL ARCHIVO DE \"top10.txt\" QUE APARECIÓ EN LA CARPETA...\n");
    system("pause");
}

void mostrarVersion(char *aplicacion, char *circuito, char *version)
{

    FILE *archivo = NULL;
    archivo = fopen(ARCH_CONFIG, "r");
    if (archivo == NULL)
    {
        printf("El Archivo %s No pudo Abrirse!!\n", ARCH_CONFIG);
        printf("chequear la ruta donde se esta llamando, o si el archivo existe!!\n");
        printf("habitualmente en VS code , el archivo se encuentra en la carpeta output \n");
    }
    else
    {
        fgets(aplicacion, 15, archivo);
        puts(aplicacion);
        fgets(circuito, 15, archivo);
        puts(circuito);
        fgets(version, 5, archivo);
        puts(version);
    }
}

void Menu()
{
    char aplicacion[15];
    char circuito[15];
    char version[5];

    system("cls");
    mostrarVersion(aplicacion, circuito, version);
    printf("-------------------------------------\n");
    printf("\t\tMENU DE OPCIONES\n");
    printf("1.Mostrar Listado de corredores.\n");
    printf("2.Mostrar el Listado de Tiempos.\n");
    printf("3.Mostrar Promedio de tiempo de vuelta por corredor .\n");
    printf("4.informar Top 10 de carrera .\n");
    printf("Para Salir pulsa << -1 >>.\n");
    printf("-------------------------------------\n");
}

void MostrarCorredores()
{

    Corredor aux;
    FILE *Archivo;
    Archivo = fopen("corredores.dat", "rb");
    if (Archivo != NULL)
    {
        fread(&aux, sizeof(Corredor), 1, Archivo);
        while (!feof(Archivo))
        {

            printf("Numero de Corredor:|%d| Nombre: %s. Apellido: %s. Escuderia: %s\n", aux.numcorredor, aux.nombre, aux.apellido, aux.escuderia);

            fread(&aux, sizeof(Corredor), 1, Archivo);
        }
        fclose(Archivo);
    }

    else
    {
        printf("Error en la apertura del archivo");
    }
}

void MostrarTiempos()
{

    tiempos aux;

    FILE *Archivo;
    Archivo = fopen(ARCH_TIEMPOS2, "rb");
    if (Archivo != NULL)
    {
        fread(&aux, sizeof(tiempos), 1, Archivo);
        while (!feof(Archivo))
        {
            printf("Numero de Vuelta: %d, Numero de Corredor: %d, Tiempo: %.3f\n", aux.numvuelta, aux.numcorredor, aux.tiempo);
            fread(&aux, sizeof(tiempos), 1, Archivo);
        }
        fclose(Archivo);
    }
    else
    {
        printf("Error en la apertura del archivo %s",ARCH_TIEMPOS2);
    }
}

void utf8()
{
    #ifdef _WIN32
    system("chcp 65001 < nul");
    #endif
    system("cls");
}

int compararCorredoresPorTiempo(const void *a, const void *b)
{
    float recA = ((tiempoFinal *)a)->tiempo;
    float recB = ((tiempoFinal *)b)->tiempo;

    // Para orden descendente (mayor recaudación primero)
    if (recA < recB)
        return 1;
    else if (recA > recB)
        return -1;
    else
        return 0;
}