#include "codigo_12.c"
/*  1. Se debe ingresar un código de factura y mostrarla, se muestra cada producto individual, y se muestra el total a pagar
    2. Ingresar un código de producto y mostrar la cantidad de unidades que se vendieron 
    3. Mostrar cuanta guita se gano, si es tipo C su precio total se suma un 21%    */

int main()
{
    Producto listaDeMercaderia[BUFFER];
    Factura facturasDelDia[BUFFER];
    cadena rutaProducto = "../productos.txt";
    cadena rutaFactura = "../facturas.txt";

    inicializarProductos(listaDeMercaderia);
    inicializarFacturas(facturasDelDia);

    leerProductos(listaDeMercaderia, rutaProducto);
    leerFacturas(facturasDelDia, rutaFactura);

    //ingresarCodigoFactura();
    //ingresarCodigoProducto();
    //plataIngresada();

    mostrarProductos(listaDeMercaderia);
    puts("");
    mostrarFacturas(facturasDelDia);

    return 0;
}