#include <stdlib.h>// recordar que los corchetes angulares se utilizan para librerias standard
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "../../C.h"// pequeña libreria con cosas utiles
// las doble comillas le indican al preprocesador que la libreria se encuentra 
// en el mismo directorio que el main
// prof Behringer alejandro jorge
// archivo Ejempl02_bin_mejorado.c

typedef struct
{
    int codigo;
    char nombre[20];
    float saldo;
} Cliente;

void ingresarClientes(FILE *archivo);
void mostrarClientes(FILE *archivo);

int main()
{
    FILE *archivoClientes;
    const char *nombreArchivo = "clientes.dat";

    system("cls");

    archivoClientes = fopen(nombreArchivo, "rb+");
    if (archivoClientes == NULL)
    {
        archivoClientes = fopen(nombreArchivo, "wb+");
        if (archivoClientes == NULL)
        {
            printf("\nNo se pudo crear el archivo %s.\n", nombreArchivo);
            return 1;
        }
        printf("\nEl archivo %s ha sido creado.", nombreArchivo);
    }
    else
    {
        printf("\nEl archivo %s ha sido abierto para lectura y escritura.", nombreArchivo);
    }

    system("pause");
    ingresarClientes(archivoClientes);
    system("cls");
    mostrarClientes(archivoClientes);
    puts("**************************************************");
    system("pause");
    fclose(archivoClientes);

    return 0;
}

void ingresarClientes(FILE *archivo)
{
    Cliente cliente;
    int codigo;

    printf("\nIngrese código del cliente [0 para salir]: ");
    while (scanf("%d", &codigo) == 1 && codigo != 0)
    {
        cliente.codigo = codigo;

        printf("Ingrese nombre: ");
        fflush(stdin); 
        // solo si estás en Windows y 
        //usando compilador que lo permite OjO
        // bien podria haber utilizado gets, 
        // pero fue eliminada en la version c11 por insegura, 
        // o sea posible desbordamiento de buffer
        // actualmene tenemos  C89, C99, C11, C17, C23
        // cmo ves a continuacion utilizo fgets
        fgets(cliente.nombre, sizeof(cliente.nombre), stdin);
        cliente.nombre[strcspn(cliente.nombre, "\n")] = 0; // eliminar '\n'
        /*
        les doy un ejemplo
        supone ingreso este texto y le doy enter
        quedara asi por que termine antes del fin de cadena
        {'R','o','d','r','i','g','u','e','z','\n','\0'}
        La función strcspn(cliente.nombre, "\n") 
        devuelve 9 (la posición del \n), 
        y esa posición se reemplaza por '\0'
        entonces mi cadena despues quedara de la suigiente manera
        {'R','o','d','r','i','g','u','e','z','\0'}
        ¡Ahora el string tiene solo "Rodriguez" 
        y sin salto de línea al final!
        se entendio ????
        me olvidaba
        y preguntaran porque dentro de los corchetes 
        porque devuelve el indice donde cambiar la cadena.
        */
        cliente.saldo = 0.0;

        fseek(archivo, 0L, SEEK_END);
        // esto de !=1 es porque el fwrite devuelve 
        //lo que grabo en este caso 1 registro 
        // si fuera 0 seria que no grabo o algo paso, , igualmente el compilador no obliga a una devolucion
        // por lo cual si pones fwrite solo no pasaria nada por que el compilador asume que no te interesa la devolucion

        if (fwrite(&cliente, sizeof(cliente), 1, archivo) != 1)
        {
            printf("Error al escribir en el archivo.\n");
        }
        printf("\nCliente Ingresado Correctamente\n\n");
        printf("\nIngrese código del cliente [0 para salir]: ");
    }
}

void mostrarClientes(FILE *archivo)
{
    Cliente cliente;

    rewind(archivo);
    printf("\n\n\t\t\t Nómina de Clientes\n");
    puts("**************************************************");
    printf("\n%-6s %-25s %10s\n", "Código", "Nombre", "Saldo");

    while (fread(&cliente, sizeof(cliente), 1, archivo))
    {
        printf("%-6d %-25s %10.2f\n", cliente.codigo, cliente.nombre, cliente.saldo);
    }

    printf("\n");
}
