#include "Libs/utils.h"

/*
10) Una tienda necesita conocer datos sobre su facturación. Para ello necesita
procesar la información que ya posee pre cargada.
*/
#define CANT_PRODUCTOS 14 // NO MODIFICAR
#define CANT_FACTURAS 7 // NO MODIFICAR

/*
De los productos se sabe:
▪ Código ▪ Descripción ▪ Precio unitario
*/
typedef struct 
{
    cadena codigo;
    cadena descripcion;
    double precio;
}Producto;

/*
Cada ítem de una factura está compuesto por:
▪ Código de producto ▪ Cantidad de unidades
*/
typedef struct 
{
    int unidades;
    cadena codigo;
}Item;

/*
Las facturas tienen la siguiente estructura:
▪ Código ▪ Tipo ('A', 'B' o 'C') ▪ Ítems (hasta 10)
*/
typedef struct 
{
    cadena codigo;
    char tipo;
    Item items[CANT_PRODUCTOS];
}Factura;


int main () {

    Producto productos[] = {
        {"RGPFPR","Llave Termica",549.82},
        {"AHIWPJ","Llave De Luz",235.19},
        {"DUGAZE","Alargue 20 Mts",1925.76},
        {"YDDYUF","Cable uni 100m",968.72},
        {"GBSXRH","Tablero 24 Boc.",2736.48},
        {"EGEPQX","Interr. Smart",2033.47},
        {"UEDTDP","Medidor Consumo",2837.59},
        {"JUGYFP","Caño Corrugado",853.98},
        {"VAPFQR","Enchufe Wifi",2104.46},
        {"JUISQK","Zapatilla x6t",1139.89},
        {"NPSWKJ","Panel Led 60x60",2832.10},
        {"QBVSSB","Panel Red. 22cm",818.89},
        {"FICKPW","Lampara Led 5w",780.80},
        {"VTXPBI","Lampara Led 12w",135.00}
    };

    Factura facturas[] = {  
    {   
        "NZAQXY",'B', {
            {2, "UEDTDP"}, {1, "VTXPBI"}, {3, "NPSWKJ"}
        }
    },
    {
        "QUJQYK",'C', {
            {4, "VTXPBI"}, {2, "JUGYFP"}, {1, "EGEPQX"},
            {2, "VAPFQR"}, {5, "DUGAZE"}
        }
    },
    {
        "ILIWRV",'A', {
            {4, "FICKPW"}, {4, "VTXPBI"}
        }
    },
    {
        "TDWENB",'B', {
            {2, "UEDTDP"}, {5, "JUISQK"}, {2, "VAPFQR"},
            {2, "NPSWKJ"}
        }
    },
    {
        "LANDGH",'B', {
            {8, "VTXPBI"}, {6, "AHIWPJ"}, {10, "EGEPQX"},
            {5, "QBVSSB"}, {12, "DUGAZE"}
        }
    },
    {
        "PEBYBU",'A', {
            {3, "JUISQK"}, {3, "DUGAZE"}, {1, "RGPFPR"},
            {1, "NPSWKJ"}, {3, "AHIWPJ"}, {4, "UEDTDP"}
        }
    },
    {
        "YGAFLC",'C', {
            {2, "VTXPBI"}, {5, "YDDYUF"}, {3, "AHIWPJ"}
        }
    }
};

    /* Desarrollar lo pedido... */
    return 0;
}

/*
A) Ingresar un código de factura. Se debe emitir una tabla en la consola que representa el detalle
de los ítems de la misma, de la forma:
| Cantidad | Descripción del producto | Precio unitario | Subtotal |
Debajo de la tabla, mostrar el monto total.
*/

/*
B) Ingresar un código de producto y mostrar la cantidad de unidades que se vendieron.
*/

/*
C) Mostrar el monto total facturado, teniendo en cuenta que las facturas de tipo C tienen un
recargo del 21% a su monto dado por el IVA.
*/