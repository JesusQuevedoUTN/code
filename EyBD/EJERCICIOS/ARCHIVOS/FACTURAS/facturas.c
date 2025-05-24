#include "../../C.h"

typedef struct
{
    int codigoDeCliente;
    char nombreDelCliente[30];
    float cuenta; // aquí acumulo el saldo o lo facturado en total a cada cliente
} Cliente;

typedef struct
{
    int codigoDelArticulo;
    char nombreDelArticulo[30];
    float precio;
    int stock;
    float facturado;
} Articulo;

typedef struct
{
    int codigoDeCliente;
    int codigoDelArticulo;
    int cantidad;
    float total;
} Factura;

// UTILS
int menu();
// MENU
void mostrarClientes();
void mostrarArticulos();
void agregarNuevoCliente();
void agregarNuevoArticulo();
void realizarFacturacion();
void productoEstrella();
void mostrarListaAscendente();
void borrar();
// MOLECULA

// ATOMO
void mostrarCliente(Cliente cliente);
void mostrarArticulo(Articulo articulo);

void mostrarFacturas();

#define _RUTA_CLIENTES "../clientes.dat"
#define _RUTA_ARTICULOS "../articulos.dat"
#define _RUTA_FACTURAS "../facturas.dat"

#define _SALIR 8
#define _PRIMERA_OPCION 0

int main()
{
    // INICIAR
    iniciar();
    // MENU
    int opcion = menu();

    while (opcion != _SALIR)
    {
        switch (opcion)
        {
        case 1:
            mostrarClientes();
            system("pause");
            break;
        case 2:
            mostrarArticulos();
            system("pause");
            break;
        case 3:
            agregarNuevoCliente();
            break;
        case 4:
            agregarNuevoArticulo();
            break;
        case 5:
            realizarFacturacion();
            break;
        case 6:
            productoEstrella();
            break;
        case 7:
            mostrarListaAscendente();
            break;
        case 0:
            borrar();
            break;
        }
        system("cls");
        opcion = menu();
    }

    return 0;
}

int menu()
{
    int opcion = 0;
    do
    {
        printf("\t + - - - - - - - - - - + EL CHINARDO + - - - - - - - - - - + \n");
        printf("\t\t[1]\tMostrar clientes.\n");
        printf("\t\t[2]\tMostrar artículos.\n");
        printf("\t\t[3]\tAgregar nuevo cliente.\n");
        printf("\t\t[4]\tAgregar nuevo artículo.\n");
        printf("\t\t[5]\tRealizar una facturación.\n");
        printf("\t\t[6]\tVer producto estrella.\n");
        printf("\t\t[7]\tMostrar listado de clientes ordenado por nombre.\n");
        printf("\t\t[8]\tSalir del sistema.\n");
        printf("\t + - - - - - - - - - - - - +  S.A  + - - - - - - - - - - - + \n\n");
        printf("\t\t\t[0]\t. . . .\n");
        scanf("%d", &opcion);
        clean();
    } while (opcion < _PRIMERA_OPCION || opcion > _SALIR);
    return opcion;
}

void mostrarClientes()
{
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb");
    Cliente cliente;

    printf("\t\t\t Nómina de Clientes\n");
    puts("**************************************************");
    printf("\n%-6s %-25s %10s\n", "Código", "Nombre", "Saldo");

    while (fread(&cliente, sizeof(cliente), 1, archivo))
    {
        mostrarCliente(cliente);
    }
    printf("\n");
    fclose(archivo);
}

void mostrarArticulos()
{
    FILE *archivo = fopen(_RUTA_ARTICULOS, "rb");
    Articulo articulo;

    printf("\t\t\t Nómina de Articulos\n");
    puts("**************************************************");
    printf("\n%-6s %-25s %10s %5s %10s\n", "Código", "Nombre", "Precio", "Stock", "Facturando");

    while (fread(&articulo, sizeof(articulo), 1, archivo))
    {
        mostrarArticulo(articulo);
    }
    printf("\n");
    fclose(archivo);
}

void mostrarFacturas()
{
    FILE *archivo = fopen(_RUTA_FACTURAS, "rb");
    Factura factura;

    while (fread(&factura, sizeof(Factura), 1, archivo))
    {
        printf("%d, %d, %d, %.2f", factura.codigoDeCliente, factura.codigoDelArticulo, factura.cantidad, factura.total);
    }
    printf("\n");
    fclose(archivo);
}

void agregarNuevoCliente()
{
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb+");
    Cliente nuevoCliente;
    int cod = -1;

    printf("Ingrese codigo  del cliente\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);
    fseek(archivo, 0L, SEEK_END);

    while (cod)
    {
        nuevoCliente.codigoDeCliente = cod;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nuevoCliente.nombreDelCliente);

        nuevoCliente.cuenta = 0.0;

        fwrite(&nuevoCliente, sizeof(Cliente), 1, archivo);

        system("cls");
        printf("Ingrese codigo  del cliente\n");
        printf("Pulse [0] para salir: ");
        scanf(" %d", &cod);
    }
    fclose(archivo);
}

void agregarNuevoArticulo()
{
    FILE *archivo = fopen(_RUTA_ARTICULOS, "rb+");
    Articulo nuevoArticulo;
    int cod;

    printf("Ingrese codigo  del artículo\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    while (cod)
    {
        fseek(archivo, 0L, SEEK_END);
        nuevoArticulo.codigoDelArticulo = cod;

        printf("Ingrese nombre del artículo: ");
        fflush(stdin);
        gets(nuevoArticulo.nombreDelArticulo);

        printf("Ingrese precio del artículo: ");
        scanf(" %f", &nuevoArticulo.precio);

        printf("Ingrese Stock: ");
        scanf(" %d", &nuevoArticulo.stock);

        nuevoArticulo.facturado = 0.0;

        fwrite(&nuevoArticulo, sizeof(Articulo), 1, archivo);

        system("cls");
        printf("Ingrese codigo  del artículo\n");
        printf("Pulse [0] para salir: ");
        scanf(" %d", &cod);
    }
    fclose(archivo);
}


/*
perfecto, ya funciona, MENOS, actualizar los clientes y articulos
*/
void realizarFacturacion()
{
    FILE *fClientes = fopen(_RUTA_CLIENTES, "rb+");
    FILE *fArticulos = fopen(_RUTA_ARTICULOS, "rb+");
    FILE *fFacturas = fopen(_RUTA_FACTURAS, "rb+");
    int clienteABuscar, flag = 0;

    Cliente clienteAFacturar;
    Articulo articuloAFacturar;
    Factura nuevaFactura;

    do
    {
        mostrarClientes();
        printf("INGRESE CODIGO DE CLIENTE:");
        scanf(" %d", &clienteABuscar);

        while (fread(&clienteAFacturar, sizeof(Cliente), 1, fClientes) && flag == 0)
        {
            if (clienteAFacturar.codigoDeCliente == clienteABuscar)
            {
                flag = 1;
                fseek(fClientes, -sizeof(Cliente), SEEK_CUR);
            }
        }

        if (flag == 1)
        {
            int articuloABuscar;
            flag = 0;
            do
            {
                mostrarArticulos();
                printf("INGRESE CODIGO DEL ARTICULO:");
                scanf(" %d", &articuloABuscar);

                while (fread(&articuloAFacturar, sizeof(Articulo), 1, fArticulos) && flag == 0)
                {
                    if (articuloAFacturar.codigoDelArticulo == articuloABuscar)
                    {
                        flag = 1;
                        fseek(fArticulos, -sizeof(Articulo), SEEK_CUR);
                    }
                }

                if (flag == 1)
                {
                    int cantidadAComprar;
                    mostrarArticulo(articuloAFacturar);
                    printf("Cuantos %s desea llevar?", articuloAFacturar.nombreDelArticulo);
                    scanf(" %d", &cantidadAComprar);
                    if (cantidadAComprar<=articuloAFacturar.stock)
                    {
                        articuloAFacturar.stock = articuloAFacturar.stock - cantidadAComprar;
                        articuloAFacturar.facturado = articuloAFacturar.facturado + cantidadAComprar * articuloAFacturar.precio;
                        clienteAFacturar.cuenta = clienteAFacturar.cuenta + cantidadAComprar * articuloAFacturar.precio;
                        
                        // Reescribir el artículo en la posición correcta
                        fseek(fArticulos, -sizeof(Articulo), SEEK_CUR);
                        fwrite(&articuloAFacturar, sizeof(Articulo), 1, fArticulos);

                        
                        nuevaFactura.codigoDeCliente = clienteAFacturar.codigoDeCliente;
                        nuevaFactura.codigoDelArticulo = articuloAFacturar.codigoDelArticulo;
                        nuevaFactura.cantidad = cantidadAComprar;
                        nuevaFactura.total = cantidadAComprar * articuloAFacturar.precio;
                        fwrite(&nuevaFactura, sizeof(Factura),1,fFacturas);
                        printf("COMPRA REALIZADA\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("ERROR. No se encontró\n");
                    system("pause");
                }
                rewind(fArticulos);
                system("cls");
                flag = 0;
                
            } while (articuloABuscar);
            
            fseek(fClientes,-sizeof(Cliente),SEEK_CUR);
            fwrite(&clienteAFacturar, sizeof(Cliente), 1, fClientes);
            
            flag = 0;
            rewind(fClientes);
            rewind(fArticulos);
            
        }
        else
        {
            printf("ERROR. no se encontró\n");
            system("pause");
        }
        flag = 0;
        rewind(fClientes);
        rewind(fArticulos);
        system("cls");
    } while (clienteABuscar);

    fclose(fClientes);
    fclose(fArticulos);
    fclose(fFacturas);
}

void productoEstrella()
{
    FILE *archivo =fopen (_RUTA_ARTICULOS,"rb");
    Articulo producto, estrella;
    int mayorCantidadDeVentas = 0;
    while (fread(&producto, sizeof(Articulo),1,archivo))
    {
        if (producto.facturado > mayorCantidadDeVentas)
        {
            estrella = producto;
        }
    }
    printf("Producto estrella: ");
    mostrarArticulo(estrella);
    system("pause");
}

/*
armé esto, pero no sé como decirle, si el nombre es mayor, entonces, ponerlo al final
*/
void mostrarListaAscendente()
{
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb");
    if (!archivo) return;

    int cantidad = 0;
    Cliente *lista = NULL;
    Cliente temporal;

    // Leer todos los clientes
    while (fread(&temporal, sizeof(Cliente), 1, archivo))
    {
        lista = realloc(lista, sizeof(Cliente) * (cantidad + 1));
        lista[cantidad] = temporal;
        cantidad++;
    }

    // Ordenar alfabéticamente por nombre (bubble sort simple)
    for (int i = 0; i < cantidad - 1; i++)
    {
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (strcmp(lista[j].nombreDelCliente, lista[j + 1].nombreDelCliente) > 0)
            {
                Cliente aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    // Mostrar
    for (int i = 0; i < cantidad; i++)
    {
        mostrarCliente(lista[i]);
    }

    fclose(archivo);
    free(lista);
    system("pause");
}

void borrar()
{
    FILE *archivo = NULL;
    int opcion;

    do
    {
        printf("Cual archivo desea borrar?\n");
        printf("0. Salir\t\t1. Clientes\t\t2. Articulos\t\t3. Facturas\n");
        scanf(" %d", &opcion);
        switch (opcion)
        {
        case 1:
            archivo = fopen(_RUTA_CLIENTES, "wb");
            break;
        case 2:
            archivo = fopen(_RUTA_ARTICULOS, "wb");
            break;

        case 3:
            archivo = fopen(_RUTA_FACTURAS, "wb");
            break;
        }
        system("cls");
    } while (opcion != 0);

    fclose(archivo);
}

void mostrarCliente(Cliente cliente)
{
    printf("%-6d %-30s %10.2f\n", cliente.codigoDeCliente, cliente.nombreDelCliente, cliente.cuenta);
}
void mostrarArticulo(Articulo articulo)
{
    printf("%-6d %-30s %3.2f %3d %10.2f\n", articulo.codigoDelArticulo, articulo.nombreDelArticulo, articulo.precio, articulo.stock, articulo.facturado);
}