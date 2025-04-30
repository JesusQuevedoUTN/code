#include "Libs/utils.h"

typedef struct
{
    int unidades;
    cadena codigo;
}Item;

typedef struct
{
    cadena codigo;
    char tipo;
    Item items[10];
}Factura;

typedef struct
{
    cadena codigo;
    cadena descripcion;
    float precioUnitario;
}Producto;
