#include <stdlib.h>// recordar que los corchetes angulares se utilizan para librerias standard
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "utiles.h"// pequeña librería con cosas útiles

// las doble comillas le indican al preprocesador que la librería se encuentra
// en el mismo directorio que el main

typedef struct
{
int codigo;
char nombre[20];
float saldo;
}Cliente;

//MENU
int menu();
//EJERCICIO
void ingresarClientes(FILE**);
void mostrarClientes(FILE*);
//USO


int main(){

    char* nombreArchivo = "clientes.dat";
    FILE* archivo = fopen(nombreArchivo, "rb+");

    inicializarArchivo(archivo, nombreArchivo);

    int op;

    do {
        op = menu();
        system("cls");
        switch (op) {
            case 1:
                ingresarClientes(&archivo);
                break;
            case 2:
                mostrarClientes(archivo);
                system("pause");
                break;
        }
        system("cls");
    } while (op != 0);


    fclose(archivo);
    return 0;
}


int menu() {
    int op;
    do {
        printf("\n\t\t\t MENU DE OPCIONES\n");
        printf("\n\t\t - Salir                    <0>\n");
        printf("\n\t\t - Agregar Clientes         <1>\n");
        printf("\n\t\t - Mostrar Clientes         <2>\n");
        printf("\n\t\t   Ingrese Opcion [0-2]:  ");
        scanf("%d", &op);
    } while (op < 0 || op > 2);
    return op;
}

void ingresarClientes(FILE** archivo)
{
    Cliente cliente;
    int codigo = -1;

    do
    {
        system("cls");

        printf("\n\t\t\t Ingrese codigo de cliente\n");
        printf("\n\t\t            Salir           <0>\n\n");

        scanf("%d", &codigo);
        if(codigo!=0)
        {
            cliente.codigo = codigo;
            cliente.saldo = 0.0;
            printf("\nIngrese el nombre del cliente.\n");
            fflush(stdin);
            fgets(cliente.nombre,0L,stdin);
            fwrite(&cliente, sizeof(cliente), 1, archivo);
        }
    }while(codigo!=0);
}

void mostrarClientes(FILE* archivo)
{
    char* cadena;
    rewind(archivo);
    int i = 0;
    /*while()
    {
        fread(cadena,SEEK_END,0L,archivo);
    }*/
}

//


