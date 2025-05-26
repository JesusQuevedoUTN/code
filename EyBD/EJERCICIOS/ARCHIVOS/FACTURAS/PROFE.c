#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utiles.h"

#define NOMBRE_CLIENTES "clientes.dat"
#define NOMBRE_ARTICULOS "articulos.dat"
#define NOMBRE_FACTURAS "facturas.dat"

// Estructuras

typedef struct
{
    int cod_cli;
    char nom_cli[30];
    float cuenta; // aquí acumulo el saldo o lo facturado en total a cada cliente
} Cliente;

typedef struct
{
    int cod_art;
    char nom_art[30];
    float precio;
    int stock; // cantidad disponible
    float facturado; // acumulo cuanto vendi en pesos del este articulo
} Articulo;

typedef struct
{
    int cod_cli;
    int cod_art;
    int cantidad;
    float total;
} Factura;

// Prototipos
void menu();
void mostrarClientes();
void mostrarArticulos();
void agregarCliente();
void agregarArticulo(); // agregarArticulo
void facturar();
void estadisticaVentas();
void listarClientesOrdenados();
int compararClientes(const void *, const void *);
void pausa();

int main()
{
    utf8();
    menu();
    return 0;
}

void menu()
{
    int opcion;
    do
    {
        system("cls");
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Mostrar clientes\n");
        printf("2. Mostrar artículos\n");
        printf("3. Agregar cliente\n");
        printf("4. Agregar artículo\n");
        printf("5. Facturar\n");
        printf("6. Estadística de ventas\n");
        printf("7. Listado ordenado de clientes\n");
        printf("0. Salir\n");
        printf("Ingrese opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            mostrarClientes();
            pausa();
            break;
        case 2:
            mostrarArticulos();
             pausa();
            break;
        case 3:
            agregarCliente();
            break;
        case 4:
            agregarArticulo();
            break;
        case 5:
            facturar();
            break;
        case 6:
            estadisticaVentas();
             pausa();
            break;
        case 7:
            listarClientesOrdenados();
             pausa();
            break;
        }
    } while (opcion != 0);
}

void mostrarClientes()
{
    Cliente c;
    FILE *f = fopen(NOMBRE_CLIENTES, "rb");
    if (!f)
    {
        printf("No se pudo abrir el archivo de clientes.\n");
        pausa();
    }
    else
    {
        printf("\n%-5s %-20s %-10s\n", "COD", "NOMBRE", "CUENTA");
        while (fread(&c, sizeof(Cliente), 1, f))
            printf("%-5d %-20s $%-10.2f\n", c.cod_cli, c.nom_cli, c.cuenta);
        fclose(f);
    }
}

void mostrarArticulos()
{
    Articulo a;
    FILE *f = fopen(NOMBRE_ARTICULOS, "rb");
    if (!f)
    {
        printf("No se pudo abrir el archivo de Articulos.\n");
        pausa();
    }
    else
    {
        printf("\n%-5s %-20s %-8s %-6s %-10s\n", "COD", "ARTICULO", "PRECIO", "STOCK", "FACTURADO");
        while (fread(&a, sizeof(Articulo), 1, f))
            printf("%-5d %-20s $%-8.2f %-6d $%-10.2f\n", a.cod_art, a.nom_art, a.precio, a.stock, a.facturado);
        fclose(f);
    }
}

void agregarCliente()
{
    Cliente c;
    int flag;
    FILE *f; // archivo de clientes, puse f por file en todas las rutinas
    int cod; // Variable para almacenar el código del cliente
    int flagApetura=1;
    f = fopen(NOMBRE_CLIENTES, "rb+");
    if (f == NULL)
    {
        f = fopen(NOMBRE_CLIENTES, "wb+");
        if (f == NULL)
        {
            printf("\nNo se pudo crear el archivo %s.\n", NOMBRE_CLIENTES);
            flagApetura=0;
        }
        else
        {
            printf("\nEl archivo %s ha sido creado por primera vez.\n", NOMBRE_CLIENTES);
        }
    }
    else
    {
        printf("\nEl archivo %s ha sido abierto para lectura y escritura.\n\n", NOMBRE_CLIENTES);
    }
    if (flagApetura)
    {
        printf("Ingrese código de Cliente << 0 >> cero para salir:");
        scanf("%d", &cod);
        while (cod)
        {
            rewind(f);
            fread(&c, sizeof(Cliente), 1, f);
            flag = 1;
            while (!feof(f) && flag) // 
            {
                if (cod == c.cod_cli)
                {
                    printf("El código de cliente ya existe.\n");
                    pausa();
                    flag = 0;
                }
                else
                {
                    fread(&c, sizeof(Cliente), 1, f);
                }
            }
            if (flag) 
            {
                c.cod_cli = cod;
                fflush(stdin);
                printf("Ingrese nombre del Cliente: ");
                fgets(c.nom_cli, sizeof(c.nom_cli), stdin);
                c.nom_cli[strcspn(c.nom_cli, "\n")] = '\0';
                fflush(stdin);

                c.cuenta = 0.0;
                printf("Monto en cuenta:%2.2f ", c.cuenta);

                fseek(f, 0L, SEEK_END);
                fwrite(&c, sizeof(Cliente), 1, f);
                printf("\n\nCliente agregado con éxito.\n\n");
                pausa();
            }
            printf("Ingrese código de Cliente << 0 >> cero para salir:");
            scanf("%d", &cod);
        }
        fclose(f);
    }
}

void agregarArticulo()
{
    Articulo a;
    int cod;
    int flag;
    int flagApetura=1;
    FILE *f;
    // puse f por file en todas las rutinas
    
    f = fopen(NOMBRE_ARTICULOS, "rb+");
    if (f == NULL)
    {
        f = fopen(NOMBRE_ARTICULOS, "wb+");
        if (f == NULL)
        {
            printf("\nNo se pudo crear el archivo %s.\n", NOMBRE_ARTICULOS);
            flagApetura=0;
        }
        else
        {
            printf("\nEl archivo %s ha sido creado.\n", NOMBRE_ARTICULOS);
        }
    }
    else
    {
        printf("\nEl archivo %s ha sido abierto para lectura y escritura.\n", NOMBRE_ARTICULOS);
    }
    
    if(flagApetura)
    {
        printf("Ingrese código de Articulo << 0 >> cero para salir:");
        scanf("%d", &cod);
        while (cod)
        {
            rewind(f);
            fread(&a, sizeof(Articulo), 1, f);
            flag = 1; // sirve ests bandera para detectar si el codigo de articulo existe o no
            while (!feof(f) && flag)
            {
                if (cod == a.cod_art)
                {
                    printf("\nEl código ya existe.!!\n");
                    pausa();
                    flag = 0;
                }
                else
                {
                    fread(&a, sizeof(Articulo), 1, f);
                }
            }
            if (flag)
            {
                a.cod_art = cod;
                fflush(stdin);
                printf("Ingrese nombre del artículo: ");
                fgets(a.nom_art, sizeof(a.nom_art), stdin);
                a.nom_art[strcspn(a.nom_art, "\n")] = '\0';
                fflush(stdin);
                printf("Ingrese precio: ");
                scanf("%f", &a.precio);
                printf("Ingrese stock: ");
                scanf("%d", &a.stock);
                fflush(stdin);
                a.facturado = 0.0;
                // guardamos la informacion ingresasa en el archivo
                fseek(f, 0L, SEEK_END);
                fwrite(&a, sizeof(Articulo), 1, f);
                printf("\n\nregistro guardado correctamente !!\n\n");
                pausa();
            }
            printf("Ingrese código de articulo << 0 >> cero para salir:");
            scanf("%d", &cod);
        }
        fclose(f);
    }
    if (flagApetura==0)
        printf("\n\nHubo algun problema en la creacion del archivo:%s\n\n",NOMBRE_ARTICULOS);
}


void facturar()
{
    int cod_cli, cod_art, cantidad, encontrado;
    float total;
    Cliente c;
    Articulo a;
    Factura fct;

    FILE *fc = fopen(NOMBRE_CLIENTES, "rb+"); // Abrimos el archivo de clientes como lectura escritura
    FILE *fa = fopen(NOMBRE_ARTICULOS, "rb+"); // Abrimos el archivo de articulos como lectura escritura
    FILE *ff = fopen(NOMBRE_FACTURAS, "ab"); // apertura en modo agregar

    if (!fc || !fa || !ff)
    {
        printf("Error al abrir alguno de los archivos.\n");
        pausa();
    }
    else
    {
        
        printf("Ingrese Código de cliente << 0 >> para salir: ");
        scanf("%d", &cod_cli); // ingresamos el código del cliente
        while (cod_cli!=0)
        { 
            // Posiciono cliente
            fseek(fc, 0, SEEK_SET); 
            // Posiciono el cursor al inicio del archivo de clientes
            encontrado = 1; // bandera para saber si se encontro el cliente
            while (fread(&c, sizeof(Cliente), 1, fc) && encontrado) // empezamos la busqueda
            {
                printf("encontre--->%d\n",c.cod_cli);
                if (c.cod_cli == cod_cli)
                {
                    encontrado = 0;
                }
            }
            if (encontrado)
            {
                printf("\nCliente no encontrado.\n");
            }
            else
            {
                printf("\nCliente:%s\n",c.nom_cli);
                printf("Ingrese Código de artículo\n << 0 >> para finalizar la carga de articulos: ");
                scanf("%d", &cod_art);
                while (cod_art!=0)
                {
                    // Posiciono artículo y busco si existe
                    fseek(fa, 0, SEEK_SET); // Posiciono el cursor al inicio del archivo de articulos
                    encontrado = 1;
                    while (fread(&a, sizeof(Articulo), 1, fa) && encontrado)
                    {
                        if (a.cod_art == cod_art)
                        {
                            encontrado = 0;
                        }
                    }
                    if (encontrado)
                    {
                        printf("Artículo no encontrado.\n");
                    }
                    else
                    {
                        printf("Articulo:%s \t cantidad:%d\n",a.nom_art, a.stock);
                        printf("Ingrese Cantidad: ");
                        scanf("%d", &cantidad);
                        if (cantidad <= a.stock)
                        {
                            total = cantidad * a.precio;
                            c.cuenta += total;
                            a.stock -= cantidad;
                            a.facturado += total;
                    
                            // Escribir factura
                            fct.cod_cli = cod_cli;
                            fct.cod_art = cod_art;
                            fct.cantidad = cantidad;
                            fct.total = total;
                            fwrite(&fct, sizeof(Factura), 1, ff);
                    
                            
                            // Actualizar artículo
                            fseek(fa, -sizeof(Articulo), SEEK_CUR);
                            fwrite(&a, sizeof(Articulo), 1, fa);
                            
                            printf("\nItem de la Factura grabado exitosamente.\n");
                        }
                        else
                        {
                            printf("\nStock insuficiente. Solo hay %d unidades disponibles.\n", a.stock);
                        }
                    }
                    printf("Ingrese Código de artículo \n << 0 >> para finalizar la carga de articulos: ");
                    scanf("%d", &cod_art);
                }
            }
            // Actualizar cliente
            fseek(fc, -sizeof(Cliente), SEEK_CUR);
            fwrite(&c, sizeof(Cliente), 1, fc);
            printf("Ingrese Código de cliente << 0 >> para salir: ");
            scanf("%d", &cod_cli); // ingresamos el código del cliente
        }
        
    }

    fclose(fc);
    fclose(fa);
    fclose(ff);
    printf("\nsaliendo de la facturacion\n");
    pausa();
}

void estadisticaVentas()
{
    Articulo a, estrella;
    int flag = 1;
    float max;
    FILE *f = fopen(NOMBRE_ARTICULOS, "rb");
    if (!f)
    {
        printf("No se pudo abrir el archivo de %s.\n",NOMBRE_ARTICULOS);
        pausa();
    }
    else
    {
        if (!f)
        {
            printf("\n no hubo ventas para realizar la estadistica\n");
        }
        else
        {
    
            printf("\n=== Estadística de Ventas ===\n");
            while (fread(&a, sizeof(Articulo), 1, f))
            {
                printf("%s: $%.2f\n", a.nom_art, a.facturado);
                if (flag)
                {
                    max = a.facturado;
                    estrella = a;
                    flag = 0;
                }
                if (a.facturado > max)
                {
                    max = a.facturado;
                    estrella = a;
                }
            }
            printf("\nProducto estrella: %s ($%.2f facturado)\n", estrella.nom_art, estrella.facturado);
            pausa();
            fclose(f);
        }
    }
}

int compararClientes(const void *a, const void *b)
{
    Cliente *c1 = (Cliente *)a;
    Cliente *c2 = (Cliente *)b;
    char nombre1[30], nombre2[30];
    strcpy(nombre1, c1->nom_cli);
    strcpy(nombre2, c2->nom_cli);

    // Convertimos a mayúsculas
    for (int i = 0; nombre1[i]; i++)
        nombre1[i] = toupper(nombre1[i]);
    for (int i = 0; nombre2[i]; i++)
        nombre2[i] = toupper(nombre2[i]);
    // return strcmp(c1->nom_cli, c2->nom_cli);
    return strcmp(nombre1, nombre2);

    /*
    Devuelve < 0 si c1 va antes que c2
    devuelve 0 si c1 y c2 son iguales
    0 si c1 va después que c2.
    */
}

void listarClientesOrdenados()
{
    Cliente temp;
    // genero un archivo temporal porque no se cuantos registros utilizo
    Cliente *aux;
    // genero un array auxiliar para almacenar los clientes o sea un simple espacio en memoria
    Cliente *vec = NULL; // vector de clientes de dimension desconociada
    int n = 0;           // n es el numero de clientes

    FILE *f = fopen(NOMBRE_CLIENTES, "rb");
    if(!f)
    {
        printf("\n no se pudo abrir el archivo de clientes\n");
        pausa();
    }
    else
    {
        while (fread(&temp, sizeof(Cliente), 1, f))
        {
            // leo el archivo y voy agregando los clientes a mi vector
            // pide una nueva área de memoria dinámica del tamaño necesario para guardar n + 1 clientes.
            aux = (Cliente *) realloc(vec, (n + 1) * sizeof(Cliente)); 
            // genero el espacio en memoria para el cliente
            // Esa nueva dirección se guarda en aux
            if (aux == NULL)
            {
                printf("Error de memoria.\n");
                pausa();
            }
            // Ahora aux apunta a la nueva área de memoria
            // vec ahora apunta al nuevo bloque de memoria (más grande).
        
            vec = aux;     // actualizo el vector o sea
            vec[n] = temp; // le asigno el valor al cliente
            // Esto copia el contenido del cliente recién leído (temp) 
            // a la posición n del vector vec.
            n++;
            // leo el archivo y voy agregando los clientes a mi vector
            // leo un cliente de archivo

        }
        qsort(vec, n, sizeof(Cliente), compararClientes);
        printf("\nListado ordenado por nombre:\n");
        for (int i = 0; i < n; i++)
        printf("%d %-30s - $%4.2f\n", vec[i].cod_cli, vec[i].nom_cli, vec[i].cuenta);
        pausa();
        free(vec);
        fclose(f);
    }
    
}

void pausa()
{
    printf("\nPresione una tecla para continuar...\n");
    getch();
}