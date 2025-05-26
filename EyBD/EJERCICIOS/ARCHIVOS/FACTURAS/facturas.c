#include "../../C.h"

#define _RUTA_CLIENTES "../clientes.dat"
#define _RUTA_ARTICULOS "../articulos.dat"
#define _RUTA_FACTURAS "../facturas.dat"
#define _SALIR 9

typedef struct
{
    int codigoCliente;
    char nombreCliente[30];
    float cuenta; // aquí acumulo el saldo o lo facturado en total a cada cliente
} Cliente;

typedef struct
{
    int codigoArticulo;
    char nombreDelArticulo[30];
    float precio;
    int stock;
    float facturado;
} Articulo;

typedef struct
{
    int codigoCliente;
    int codigoArticulo;
    int cantidad;
    float total;
} Factura;

// UTILS
void menu();
// MENU
void mostrarClientes();
void mostrarArticulos();
void mostrarFacturas();
void agregarCliente();
void agregarArticulo();
void facturar();
void productoEstrella();
void mostrarListaAscendente();
void borrar();


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
        printf("\t + - - - - - - - - - - + EL CHINARDO + - - - - - - - - - - + \n");
        printf("\t\t[1]\tMostrar clientes.\n");
        printf("\t\t[2]\tMostrar artículos.\n");
        printf("\t\t[3]\tMostrar facturas.\n");
        printf("\t\t[4]\tAgregar nuevo cliente.\n");
        printf("\t\t[5]\tAgregar nuevo artículo.\n");
        printf("\t\t[6]\tRealizar una facturación.\n");
        printf("\t\t[7]\tVer producto estrella.\n");
        printf("\t\t[8]\tMostrar listado de clientes ordenado por nombre.\n");
        printf("\t\t[9]\tSalir del sistema.\n");
        printf("\t + - - - - - - - - - - - - +  S.A  + - - - - - - - - - - - + \n");
        scanf("%d", &opcion);

        system("cls");

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
            mostrarFacturas();
            system("pause");
            break;
        case 4:
            agregarCliente();
            break;
        case 5:
            agregarArticulo();
            break;
        case 6:
            facturar();
            break;
        case 7:
            productoEstrella();
            system("pause");
            break;
        case 8:
            mostrarListaAscendente();
            system("pause");
            break;
        case 0:
            borrar();
            break;
        }
        system("cls");
    } while (opcion != _SALIR);
}

void mostrarClientes()
{
    Cliente cliente;
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb");

    if (!archivo)
    {
        printf("No se pudo abrir el archivo de Clientes.\n");
        system("pause");
    }
    else
    {
        printf("\t\t\t Nómina de Clientes\n");
        puts("**************************************************");
        printf("\n%-6s %-25s %10s\n", "Código", "Nombre", "Saldo");
        while (fread(&cliente, sizeof(cliente), 1, archivo))
            printf("%-6d %-30s %10.2f\n", cliente.codigoCliente, cliente.nombreCliente, cliente.cuenta);
        printf("\n");
        fclose(archivo);
    }
}

void mostrarArticulos()
{
    FILE *archivo = fopen(_RUTA_ARTICULOS, "rb");
    Articulo articulo;

    if (!archivo)
    {
        printf("No se pudo abrir el archivo de Articulos.\n");
        system("pause");
    }
    else
    {
        printf("\t\t\t Nómina de Articulos\n");
        puts("**************************************************");
        printf("\n%-6s %-30s %10s %5s %10s\n", "Código", "Nombre", "Precio", "Stock", "Facturando");

        while (fread(&articulo, sizeof(articulo), 1, archivo))
            printf("%-6d %-30s %10.2f %5d %10.2f\n", articulo.codigoArticulo, articulo.nombreDelArticulo, articulo.precio, articulo.stock, articulo.facturado);
        printf("\n");
        fclose(archivo);
    }
}

void mostrarFacturas()
{
    FILE *archivo = fopen(_RUTA_FACTURAS, "rb");
    Factura factura;

    if (!archivo)
    {
        printf("No se pudo abrir el archivo de Articulos.\n");
        system("pause");
    }
    else
    {
        while (fread(&factura, sizeof(factura), 1, archivo))
            printf("Factura = { Cliente: %d, Articulo: %d, Cantidad: %d, Total: $%.2f }\n", factura.codigoCliente, factura.codigoArticulo, factura.cantidad, factura.total);
        printf("\n");
        fclose(archivo);
    }
}

void agregarCliente()
{
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb+");
    Cliente nuevoCliente;
    int cod = -1;
    int flag;

    /*
    Read+
        if (no se leyó?)
        Write+
        if (no se leyó?)
            ERROR. Algo pasó...
        ELSE
            El archivo fue creado
    ELSE
    Seguir ejercicio
    */

    printf("Ingrese codigo  del cliente\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    while (cod)
    {
        rewind(archivo);
        /*
        no no, el rewind no es relevante, lo entiendo pone el puntero del archivo al inicio, lo que no entiendo, es porque el while pone un feof, ahhhhh pará, creo que acabo de entender
        1. lee
        2. entra al while, que va a correr hasta que sea el final del archivo, flag es 1, asi que es true
        3. con fread entre al while de nuevoCliente con 1 dato, su codigo es igual? entonces existe, flag es 0, o sea false, y esto rompe el while, y encima despues pone while flag, como le llega 0, nisiquiera corre, y vuelve a empezar
        PERO, si NO se repite el código, entonces fread, nuevocliente es el nuevo cliente, y ahora avanza el puntero y vuelta a iniciar, y si llega al final, significa que, no existe, no existe? lo agregamos
        creo que entendí bien
        */
        fread(&nuevoCliente, sizeof(Cliente), 1, archivo);
        flag = 1;

        while (!feof(archivo) && flag) //
        {
            if (cod == nuevoCliente.codigoCliente)
            {
                printf("El código de cliente ya existe.\n");
                pausa();
                flag = 0;
            }
            else
            {
                fread(&nuevoCliente, sizeof(Cliente), 1, archivo);
            }
        }
        if (flag)
        {
            nuevoCliente.codigoCliente = cod;

            fflush(stdin);
            printf("Ingrese nombre: ");
            fgets(nuevoCliente.nombreCliente, sizeof(nuevoCliente.nombreCliente), stdin);

            nuevoCliente.cuenta = 0.0;
            printf("Monto en cuenta: $%2.2f", nuevoCliente.cuenta);

            fseek(archivo, 0L, SEEK_END);
            fwrite(&nuevoCliente, sizeof(Cliente), 1, archivo);
        }

        system("cls");
        printf("Ingrese codigo  del cliente\n");
        printf("Pulse [0] para salir: ");
        scanf(" %d", &cod);
    }
    fclose(archivo);
}

void agregarArticulo()
{
    FILE *archivo = fopen(_RUTA_ARTICULOS, "rb+");
    Articulo nuevoArticulo;
    int cod;
    int flag;

    printf("Ingrese codigo  del artículo\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    while (cod)
    {
        rewind(archivo);
        fread(&nuevoArticulo, sizeof(Cliente), 1, archivo);
        flag = 1;

        while (!feof(archivo) && flag) //
        {
            if (cod == nuevoArticulo.codigoArticulo)
            {
                printf("El código de cliente ya existe.\n");
                pausa();
                flag = 0;
            }
            else
            {
                fread(&nuevoArticulo, sizeof(Cliente), 1, archivo);
            }
        }
        if (flag)
        {
            fseek(archivo, 0L, SEEK_END);
            nuevoArticulo.codigoArticulo = cod;

            printf("Ingrese nombre del artículo: ");
            fflush(stdin);
            gets(nuevoArticulo.nombreDelArticulo);

            printf("Ingrese precio del artículo: ");
            scanf(" %f", &nuevoArticulo.precio);

            printf("Ingrese Stock: ");
            scanf(" %d", &nuevoArticulo.stock);

            nuevoArticulo.facturado = 0.0;

            fwrite(&nuevoArticulo, sizeof(Articulo), 1, archivo);
        }
        system("cls");
        printf("Ingrese codigo  del artículo\n");
        printf("Pulse [0] para salir: ");
        scanf(" %d", &cod);
    }
    fclose(archivo);
}

/*
ok mirá corregi lo que dijiste del flag, pero tengo otro error aún que no noto el porque, pero, cuando hago una facturación, no la lee bien, si me equivoco dice "error", no hay drama, pero, si elijo un 1 articulo, y luego elijo otro que existe, o no, vuelve a elegir el anterior
no sé porque pasa de la nada
*/
void facturar()
{
    FILE *fClientes = fopen(_RUTA_CLIENTES, "rb+");
    FILE *fArticulos = fopen(_RUTA_ARTICULOS, "rb+");
    FILE *fFacturas = fopen(_RUTA_FACTURAS, "ab");
    int clienteABuscar, flag = 1;

    Cliente clienteAFacturar;
    Articulo articuloAFacturar;
    Factura nuevaFactura;

    if (!fClientes || !fArticulos || !fFacturas)
    {
        printf("Error al abrir alguno de los archivos.\n");
        pausa();
    }
    else
    {
        mostrarClientes();
        printf("INGRESE CODIGO DE CLIENTE:");
        scanf(" %d", &clienteABuscar);
        while (clienteABuscar)
        {
            while (flag && fread(&clienteAFacturar, sizeof(Cliente), 1, fClientes))
            {
                if (clienteAFacturar.codigoCliente == clienteABuscar)
                {
                    flag = 0;
                    fseek(fClientes, -sizeof(Cliente), SEEK_CUR);
                }
            }

            if (flag == 0)
            {
                int articuloABuscar;
                do
                {
                    
                    mostrarArticulos();
                    printf("INGRESE CODIGO DEL ARTICULO:");
                    scanf(" %d", &articuloABuscar);
                    flag = 1;

                    while (flag && fread(&articuloAFacturar, sizeof(Articulo), 1, fArticulos))
                    {
                        if (articuloAFacturar.codigoArticulo == articuloABuscar)
                        {
                            flag = 0;
                            fseek(fArticulos, -sizeof(Articulo), SEEK_CUR);
                        }
                    }

                    if (flag == 0)
                    {
                        int cantidadAComprar;
                        printf("Articulo:%s \t cantidad:%d\n",articuloAFacturar.nombreDelArticulo, articuloAFacturar.stock);
                        scanf(" %d", &cantidadAComprar);
                        if (cantidadAComprar <= articuloAFacturar.stock)
                        {
                            articuloAFacturar.stock = articuloAFacturar.stock - cantidadAComprar;
                            articuloAFacturar.facturado = articuloAFacturar.facturado + cantidadAComprar * articuloAFacturar.precio;

                            clienteAFacturar.cuenta = clienteAFacturar.cuenta + cantidadAComprar * articuloAFacturar.precio;

                            fwrite(&articuloAFacturar, sizeof(Articulo), 1, fArticulos);
                            
                            nuevaFactura.codigoCliente = clienteAFacturar.codigoCliente;
                            nuevaFactura.codigoArticulo = articuloAFacturar.codigoArticulo;
                            nuevaFactura.cantidad = cantidadAComprar;
                            nuevaFactura.total = cantidadAComprar * articuloAFacturar.precio;
                            fwrite(&nuevaFactura, sizeof(Factura), 1, fFacturas);
                            printf("COMPRA REALIZADA\n");
                            system("pause");
                        }
                        else
                        {
                            printf("ERROR. No existe tanto producto en Stock");
                            system("pause");
                        }
                    }
                    else
                    {
                        printf("ERROR. No existe ese producto\n");
                        system("pause");
                    }
                    rewind(fArticulos);
                    system("cls");
                } while (articuloABuscar);

                fwrite(&clienteAFacturar, sizeof(Cliente), 1, fClientes);

                rewind(fArticulos);
            }
            else
            {
                printf("ERROR. no existe ese cliente\n");
                system("pause");
            }
            rewind(fClientes);
            system("cls");

            mostrarClientes();
            printf("INGRESE CODIGO DE CLIENTE:");
            scanf(" %d", &clienteABuscar);
            flag = 1;
        } 

        fclose(fClientes);
        fclose(fArticulos);
        fclose(fFacturas);
    }
}

void productoEstrella()
{
    FILE *archivo = fopen(_RUTA_ARTICULOS, "rb");
    Articulo producto, estrella;
    int mayorCantidadDeVentas = 0;
    
    printf("\n=== Estadística de Ventas ===\n");
    while (fread(&producto, sizeof(Articulo), 1, archivo))
    {
        printf("%s: $%.2f\n", producto.nombreDelArticulo, producto.facturado);
        if (producto.facturado > mayorCantidadDeVentas)
        {
            estrella = producto;
        }
    }
    printf("Producto estrella: %s ($%.2f facturado)\n", estrella.nombreDelArticulo, estrella.facturado);
    fclose(archivo);
}

/*
armé esto, pero no sé como decirle, si el nombre es mayor, entonces, ponerlo al final
*/
void mostrarListaAscendente()
{
    FILE *archivo = fopen(_RUTA_CLIENTES, "rb");
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
            if (strcmp(lista[j].nombreCliente, lista[j + 1].nombreCliente) > 0)
            {
                Cliente aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    // Mostrar
    printf("\n%-6s %-25s %10s\n", "Código", "Nombre", "Saldo");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%-6d %-30s %10.2f\n", lista[i].codigoCliente, lista[i].nombreCliente, lista[i].cuenta);
    }

    fclose(archivo);
    free(lista);
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
