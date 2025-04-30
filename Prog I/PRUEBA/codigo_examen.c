#include "Libs/utils.h"
#define BUFFER 20
typedef char cadena[50];

typedef struct
{
    char chasis[20];
    float cilindrada;
    char tipo[10];
}Motor;

typedef struct
{
    int modelo; //año de adquisicion ultimos 4 digitos
    char patente[10];
    char detalle[20];
    int kmRecorridos;
    Motor motor;
}Auto;

void mostrarAuto(Auto coche){
    printf("Modelo: %d, Patente: %s, Detalle: %s\nKms: %d, Chasis: %s, Cilindro: %.1f, Tipo: %s", coche.modelo, coche.patente, coche.detalle, coche.kmRecorridos,coche.motor.chasis, coche.motor.cilindrada, coche.motor.tipo);
}

//1 cargar los datos del txt y mostrar el valor real
int cargarDatos(Auto coche[BUFFER], cadena ruta){
    FILE* documento = fopen(ruta,"r");
    int i = 0;

    if(documento != NULL)
    {
        do
        {
            fscanf(documento, "%d\t%s\t%s\t%d\t%s\t%f\t%s\n", 
                                                            &(coche[i].modelo),
                                                            coche[i].patente, 
                                                            coche[i].detalle, 
                                                            &(coche[i].kmRecorridos),  
                                                            coche[i].motor.chasis, 
                                                            &(coche[i].motor.cilindrada), 
                                                            coche[i].motor.tipo);
            i++;
        } while (!feof(documento));
    fclose(documento);
    }
    else{ puts("NO ABRIO EL ARCHIVO");}

    return i;
}



//2 buscar la fecha y mostrar el mas viejo
void modeloAntiguo(Auto coche[BUFFER], int cant){
    Auto viejo;
        for(int i = 0 ; i < cant ; i++){
            if( i==0 || (coche[i].modelo%1000)<viejo.modelo ) {
                viejo = coche[i];
            }
        }
     printf("Coche mas viejo: ");
    mostrarAuto(viejo);
}

void mostrarCocheEnLista(Auto coche){
    printf("\n%s\t%s\t%d\t%.1f", coche.patente, coche.detalle, coche.kmRecorridos, coche.motor.cilindrada);
}

//3 mostrar todos los que son iguales a lo pedido
void listarAutos(Auto coche[BUFFER], int cant){
    cadena tipo;
    leerCadena("\n\nIndique que de auto busca", tipo);
    int kilometraje = leerEnteroMayorA(0,"Con cuanto kilometraje maximo?");
    printf("\nPatente\t\tDetalle\t\tKilometraje\tCilindrica");
    for(int i = 0 ; i < cant ; i++){
            if( strcmp(coche[i].motor.tipo , tipo) == 0 && coche[i].kmRecorridos < kilometraje) {
                mostrarCocheEnLista(coche[i]);
            }
        }
}
