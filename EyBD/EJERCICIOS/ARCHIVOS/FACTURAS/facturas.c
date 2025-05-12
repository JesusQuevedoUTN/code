#include "../../C.h"

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
    int stock;
    float facturado;
} Articulo;

typedef struct
{
    int cod_cli;
    int cod_art;
    int cantidad;
    float total;
} Factura;

//UTILS
int menu();
//FUNCION
void mostrarClientes(FILE* archivo);
void mostrarArticulos(FILE* archivo);
void agregarNuevoCliente(FILE* archivo);
void agregarNuevoArticulo(FILE* archivo);void realizarFacturacion(FILE* cliente, FILE* articulo, FILE* factura);
void productoEstrella(FILE* archivo);
void mostrarListaAscendente(FILE* archivo);
//MOLECULA
void mostrarCliente(Cliente cliente);
void mostrarArticulo(Articulo articulo);
//ATOMO
int codigoValido(int cod);
int encontrarCliente(FILE* archivo , int cod);
int encontrarArticulo(FILE* archivo , int cod);


int main()
{
    //INICIAR
    iniciar();
    FILE *clientes = NULL;
    FILE *articulos = NULL;
    FILE *facturas = NULL;
    char *rutaClientes = "../clientes.dat";
    char *rutaArticulos = "../articulos.dat";
    char *rutaFacturas = "../facturas.dat";
    iniciarBinario(&clientes, rutaClientes);
    iniciarBinario(&articulos, rutaArticulos);
    iniciarBinario(&facturas, rutaFacturas);
    pausa();

    //MENU
    int opcion;
    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            mostrarClientes(clientes);
            break;
        case 2:
            mostrarArticulos(articulos);            
            break;
        case 3:
            agregarNuevoCliente(clientes);
            break;
        case 4:
            agregarNuevoArticulo(articulos);
            break;
        case 5:
            realizarFacturacion(clientes,articulos,facturas);
            break;    
        case 6:
            productoEstrella(facturas);
            break;
        case 7:
            mostrarListaAscendente(clientes);
            break;
        }
        pausa();
    }
    while(opcion != 8);

    fclose(clientes);
    fclose(articulos);
    fclose(facturas);

    return 0;
}

int menu()
{
    int opcion = 0;
    do
    {
        printf("\t + - - - - - - - - - - - - - - + EL CHINARDO + - - - - - - - - - - - - - - + \n");
        printf("\t\t[1]\tMostrar clientes.\n");
        printf("\t\t[2]\tMostrar artículos.\n");
        printf("\t\t[3]\tAgregar nuevo cliente.\n");
        printf("\t\t[4]\tAgregar nuevo artículo.\n");
        printf("\t\t[5]\tRealizar una facturación.\n");
        printf("\t\t[6]\tVer producto estrella.\n");
        printf("\t\t[7]\tMostrar listado de clientes ordenado por nombre.\n");
        printf("\t\t[8]\tSalir del sistema.\n");
        printf("\t + - - - - - - - - - - - - - - - - +  S.A  + - - - - - - - - - - - - - - - + \n");
        scanf("%d", &opcion);
        clean();
    } while (opcion<1 || opcion >8);
    return opcion;
}


void mostrarClientes(FILE* archivo)
{
    Cliente cliente;

    rewind(archivo);
    printf("\n\n\t\t\t Nómina de Clientes\n");
    puts("**************************************************");
    printf("\n%-6s %-25s %10s\n", "Código", "Nombre", "Saldo");

    while (fread(&cliente, sizeof(cliente), 1, archivo))
    {
        mostrarCliente(cliente);
    }
    printf("\n");
}
void mostrarArticulos(FILE* archivo)
{
    Articulo articulo;

    rewind(archivo);
    printf("\n\n\t\t\t Nómina de Articulos\n");
    puts("**************************************************");
    printf("\n%-6s %-25s %10s %5s %10s\n", "Código", "Nombre", "Precio", "Stock", "Facturando");

    while (fread(&articulo, sizeof(articulo), 1, archivo))
    {
       mostrarArticulo(articulo);
    }
    printf("\n");
}
void agregarNuevoCliente(FILE* archivo)
{
    Cliente nuevoCliente;
    int cod;
    
    printf("Ingrese codigo  del cliente\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    //PROBLEMA ACÁ, SI SE REPITE NO TIRA ERROR Y NO VUELVE A PEDIR
    while (codigoValido(cod))
    {
        if (!encontrarCliente(archivo, cod))
        {
            fflush(stdin);
            fseek(archivo, 0L, SEEK_END);
            nuevoCliente.cod_cli = cod;
            
            printf("Ingrese nombre: ");
            gets(nuevoCliente.nom_cli);
            nuevoCliente.cuenta = 0.0;
            fwrite(&nuevoCliente, sizeof(nuevoCliente), 1, archivo);
            fflush(stdin);
        }
        
        
        printf("Ingrese codigo  del cliente\n");
        printf("Pulse [0] para salir: ");
        scanf("%d", &cod);
    }
}

void agregarNuevoArticulo(FILE* archivo)
{
    Articulo nuevoArticulo;
    int cod;
    
    printf("Ingrese codigo  del artículo\n");
    printf("Pulse [0] para salir: ");
    scanf(" %d", &cod);

    while (codigoValido(cod) && !encontrarArticulo(archivo, cod))
    {
        fflush(stdin);
        fseek(archivo, 0L, SEEK_END);
        nuevoArticulo.cod_art = cod;
        
        printf("Ingrese nombre: ");
        gets(nuevoArticulo.nom_art);
        
        printf("Ingrese precio del artículo: ");
        scanf(" %f", &nuevoArticulo.precio);

        printf("Ingrese Stock: ");
        scanf(" %d", &nuevoArticulo.stock);

        nuevoArticulo.facturado = 0.0;

        fwrite(&nuevoArticulo, sizeof(nuevoArticulo), 1, archivo);
        fflush(stdin);
        
        printf("Ingrese codigo  del artículo\n");
        printf("Pulse [0] para salir: ");
        scanf("%d", &cod);
    }
}
void realizarFacturacion(FILE* cliente, FILE* articulo, FILE* factura)
{

}
void productoEstrella(FILE* archivo)
{

}
void mostrarListaAscendente(FILE* archivo)
{

}

void mostrarCliente(Cliente cliente)
{
    printf("%-6d %-25s %10.2f\n", cliente.cod_cli, cliente.nom_cli, cliente.cuenta);
}
void mostrarArticulo(Articulo articulo)
{
    printf("%-6d %-25s %3.2f %3d %10.2f\n", articulo.cod_art, articulo.nom_art, articulo.precio, articulo.stock, articulo.facturado);
}

int codigoValido(int cod)
{
    return cod && cod>=0;
}

int encontrarCliente(FILE* archivo , int cod)
{
    Cliente cliente;
    int flag = 0;
    fread(&cliente, sizeof(cliente), 1, archivo);
    while (!feof(archivo) && flag)
    {
        if (cod == cliente.cod_cli)
        {
            flag = 1;
        }
        else
            fread(&cliente, sizeof(cliente), 1, archivo);
    }

    return flag;
}

int encontrarArticulo(FILE* archivo , int cod)
{
    Articulo articulo;
    int flag = 0;
    fread(&articulo, sizeof(articulo), 1, archivo);
    while (!feof(archivo) && flag)
    {
        if (cod == articulo.cod_art)
        {
            flag = 1;
        }
        else
            fread(&articulo, sizeof(articulo), 1, archivo);
    }

    return flag;
}