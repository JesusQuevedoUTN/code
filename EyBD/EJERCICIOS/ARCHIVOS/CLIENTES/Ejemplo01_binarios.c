#include <conio.h>
#include <time.h>
#include "../../C.h" 

typedef struct
{
    int cod_cli;
    char nom_cli[20];
    float saldo;
} regcli;

//
void iniciarArchivo(FILE* (*archivo), char* nombreArchivo);
void linea(int x);
//
void IngresoClientes(FILE *);
void mostrar(FILE *);


int main()
{
    FILE *cli = NULL;
    char *nomarchcli = "../clientes.dat";
    system("cls");
    
    iniciarArchivo(&cli,nomarchcli);
    
    IngresoClientes(cli);
    
    system("cls");
    mostrar(cli);
    
    fclose(cli);
    return (0);
}


void iniciarArchivo(FILE* (*archivo), char* nombreArchivo)
{
    if ( ((*archivo) = fopen(nombreArchivo, "rb+")) == NULL)
    {
        (*archivo) = fopen(nombreArchivo, "wb+");
        printf("El archivo %s ha sido Creado !!!\n", nombreArchivo);
    }else
    {
        printf("El archivo %s ha sido Abierto para lectura y escritura!!\n", nombreArchivo);
    }
    system("pause");
    system("cls");
}
void linea(int x)
{
    int i;
    for (i = 0; i < x-1; i++)
        printf("*");
    printf("\n");
}

void IngresoClientes(FILE *archivo)
{
    regcli nuevoCliente;
    int cod;
    // Inicializar los archivos de Registros
    
    printf("Ingrese codigo  del empleado\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    while (cod)
    {
        fflush(stdin);
        fseek(archivo, 0L, SEEK_END);
        nuevoCliente.cod_cli = cod;
        
        printf("Ingrese nombre: ");
        gets(nuevoCliente.nom_cli);
        nuevoCliente.saldo = 0.0;
        fwrite(&nuevoCliente, sizeof(nuevoCliente), 1, archivo);
        fflush(stdin);
        
        printf("Ingrese codigo  del empleado\n");
        printf("Pulse [0] para salir: ");
        scanf("%d", &cod);
    }
}
void mostrar(FILE *archivo)
{
    regcli cliente;

    fseek(archivo, 0L, SEEK_SET);
    system("cls");

    printf("\t\t\t Nomina de Clientes\n");
    linea(80);
    printf("\nCodigo\tNombre\t\t\t\t\t\tSaldo\n");
    fread(&cliente, sizeof(cliente), 1, archivo);
    while (!feof(archivo))
    {
        printf("\n%3d\t%-20s\t\t\t\t%6.2f", cliente.cod_cli, cliente.nom_cli, cliente.saldo);
        fread(&cliente, sizeof(cliente), 1, archivo);
    }
    printf("\n");
    linea(80);
}