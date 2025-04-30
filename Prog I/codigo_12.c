#include "Libs/utils.h"
#define BUFFER 20
#define CANTIDAD 10
#define IVA 1.21

typedef struct
{
    int unidades;
    cadena codigo;
}Item;
typedef struct
{
    cadena codigo;
    char tipo;
    Item items[CANTIDAD];
}Factura;
typedef struct
{
    cadena codigo;
    cadena descripcion;
    float precioUnitario;
}Producto;

void inicializarProductos(Producto productos[BUFFER]){
    for (int i = 0; i < BUFFER; i++)
    {
        strcpy(productos[i].codigo,"");
        strcpy(productos[i].descripcion,"");
        productos[i].precioUnitario = 0.0;
    }
    
}
void inicializarFacturas(Factura facturas[BUFFER]){
    for (int i = 0; i < BUFFER; i++)
    {
        strcpy(facturas[i].codigo,"");
        facturas[i].tipo = ' ';
    }
}
void mostrarItems(Item items[BUFFER]){
    int i=0;
    while (i<BUFFER && strcmp(items[i].codigo,""))
    {
        printf("Item %d: %s, %d\n", i, items[i].codigo, items[i].unidades);
        i++;
    }
}
void mostrarProductos(Producto productos[BUFFER]){
    int i=0;
    while (i<BUFFER && strcmp(productos[i].codigo,""))
    {
        printf("%d: %s, %s, %f\n", i, productos[i].codigo, productos[i].descripcion, productos[i].precioUnitario);
        i++;
    }
}
void mostrarFacturas(Factura facturas[BUFFER]){
    int i = 0;
    while (i<BUFFER && strcmp(facturas[i].codigo,""))
    {
        printf("%d: %s, %c\n", i+1, facturas[i].codigo, facturas[i].tipo);
        mostrarItems(facturas[i].items);
        i++;
    }
}

void leerProductos(Producto productos[BUFFER], cadena ruta){
    FILE* documento = fopen(ruta, "r");
    int i = 0, largo = sizeof(cadena);
    cadena linea;
    char* token;

    if(documento!=NULL)
    { 
        do
        {
            fgets(linea,largo,documento);
            
            token = strtok(linea,"\t");
            strcpy(productos[i].codigo, token);
                
            token = strtok(NULL, "\t");
            strcpy(productos[i].descripcion, token);

            token = strtok(NULL, "\t\n");
            productos[i].precioUnitario = atof(token);

            i++;
        } while (!feof(documento));   

    fclose(documento);
    }
    else{ printf("NO ABRIO EL ARCHIVO");}
}

void leerItems(Item items[BUFFER], cadena linea){
    linea=linea;
    for (int i = 0; i < BUFFER; i++)
    {
        strcpy(items[i].codigo," ");
        items[i].unidades = 0;
    }
    
}

void leerFacturas(Factura facturas[BUFFER], cadena ruta){
    FILE* documento = fopen(ruta, "r");
    int i = 0;
    int largo = sizeof(cadena);
    cadena linea;
    
    if(documento!=NULL)
    { 
        do
        {
            fgets(linea,largo,documento);
            strcpy(facturas[i].codigo,linea);
            fgets(linea,largo,documento);
            facturas[i].tipo = linea[0];
            fgets(linea,largo,documento);
            leerItems(facturas[i].items,linea);

            i++;
        } while (!feof(documento));   

    fclose(documento);
    }
    else{ printf("NO ABRIO EL ARCHIVO");}
}




