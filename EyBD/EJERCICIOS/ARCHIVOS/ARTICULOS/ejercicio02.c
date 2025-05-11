#include "../../C.h"

#define MAX_ARTICULOS 10
#define MAX_CLIENTES 20

//
void inicializarDatos(FILE *archClientes, FILE *archArticulos);
void ingresarVentas(FILE *archClientes, FILE *archArticulos);
//
void cargarArchivo(FILE **archClientes, char *nombreArchivo);
void cerrarArchivos(FILE **archClientes, FILE **archArticulos);
void mostrarSaldo(FILE *archClientes);

typedef struct
{
    int codigo;
    char nombre[20];
    float saldo;
} Cliente;

typedef struct
{
    int codigo;
    char nombre[20];
    float precio;
    int stock;
    float facturado;
} Articulo;

/*
PAUTAS
La búsqueda de clientes y artículos se
debe hacer recorriendo los archivos con
fread() y utilizando rewind() cuando sea necesario.
• Para actualizar registros en archivos binarios,
se debe usar fseek() para
retroceder al lugar correcto antes de escribir
con fwrite().
• Se debe evitar ingresar cantidades inválidas
(negativas o superiores al stock
disponible).
• Mostrar mensajes claros para el usuario en
caso de errores.
*/
int main()
{
    FILE *cli, *art;
    char *nomarchcli = "../clientes.dat";
    char *nomarchart = "../articulos.dat";

    // cargar los archivos
    // buscar con fread y rewind
    // fseek para buscar en binario antes de fwrite
    // corroborar que sea válido, mostrar errorres
    cargarArchivo(&cli, nomarchcli);
    cargarArchivo(&art, nomarchart);
    inicializarDatos(cli, art);

    ingresarVentas(cli, art);

    mostrarSaldo(cli);

    cerrarArchivos(&cli, &art);

    return 0;
}

void cargarArchivo(FILE **archClientes, char *nombreArchivo)
{
    (*archClientes) = fopen(nombreArchivo, "rb+");
    if ((*archClientes) == NULL)
    {
        (*archClientes) = fopen(nombreArchivo, "wb+");
        if ((*archClientes) == NULL)
        {
            printf("\nNo se pudo crear el archivo %s.\n", nombreArchivo);
        }
        printf("\nEl archivo %s ha sido creado.", nombreArchivo);
    }
    else
    {
        printf("\nEl archivo %s ha sido abierto para lectura y escritura.", nombreArchivo);
    }
}
void cerrarArchivos(FILE **archClientes, FILE **archArticulos)
{
    fclose(*archClientes);
    fclose(*archArticulos);
}
void inicializarDatos(FILE *archClientes, FILE *archArticulos)
{
    Cliente clientes[MAX_CLIENTES] = {
        {1, "Lopez", 0},
        {2, "Rodriguez", 0},
        {3, "Garcia", 0},
        {4, "Martinez", 0},
        {5, "Perez", 0}};
    Articulo articulos[MAX_ARTICULOS] = {
        {100, "Coca Cola", 2000, 10, 0},
        {101, "Agua Tonica", 3500, 20, 0},
        {102, "Naranja Fanta", 3600, 15, 0},
        {103, "Sprite", 2800, 8, 0},
        {104, "Pomelo", 2500, 12, 0},
        {105, "Mandarina", 1500, 25, 0}};

    fwrite(clientes, sizeof(Cliente), MAX_CLIENTES, archClientes);
    fwrite(articulos, sizeof(Articulo), MAX_ARTICULOS, archClientes);
    rewind(archArticulos);
    rewind(archClientes);
}

/*
o Validar si el artículo existe y hay
suficiente stock.
o Actualizar el saldo del cliente, el stock
del artículo y el total facturado.
o Mostrar al final el saldo actualizado de
todos los clientes.

Ejemplo de salida esperada
Ingrese código de cliente [0 para finalizar]: 2
Cliente encontrado: Rodriguez
Ingrese código de artículo [0 para terminar venta]: 100
Artículo: Coca Cola - Precio: 2000.00 - Stock: 10
Ingrese cantidad a comprar: 3
Venta registrada: $6000.00
Ingrese código de artículo [0 para terminar venta]: 0
Ingrese código de cliente [0 para finalizar]: 0

Código Nombre Saldo
2 Rodriguez 6000.00
...
*/
void ingresarVentas(FILE *archClientes, FILE *archArticulos)
{
    Cliente comprador;
    Articulo producto;
    // cod cliente
    printf("Ingrese codigo de cliente: ");
    scanf(" %d", comprador.codigo);
    // existe? sigue : ERROR :
    // 0? SALIR
    printf("Ingrese que desea comprar: ");
    scanf(" %d", producto.codigo);
    // existe? se muestra : ERROR
    // hay stock? se compra : ERROR
    // 0? PARAR : otro producto
    // cod cliente
    
}

void mostrarSaldo(FILE *archClientes)
{
    // es cero? no mostrar
}
