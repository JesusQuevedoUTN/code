#include "../Libs/utils.h"

#define MAX 100
  cadena zona[] = { "Norte", "Sur", "Este", "Oeste" };

 typedef struct {
 int legajo;
 cadena apellido;
 cadena nombre;
 cadena sector;
} Empleado; 


void mostrarEmpleados(Empleado listado[], int cant);

int main ()
{
/*
a. función que cargar empleados hasta el DNI igual a -1, validar si el empleado si ya fue ingresado o no
b. ordenamiento de los empleados por orden alfabético
c. Mostrar los empleados por sector
*/
    int cantidadRealDeEmpleados = 0;
    Empleado listado[MAX];
    int documento[MAX];

//    inicializarDocumento(documento);

//    leerEmpleados(listado, &cantidadRealDeEmpleados);
    //ordenarEmpleado(listado, cantidadRealDeEmpleados);
//    mostrarEmpleados(listado, cantidadRealDeEmpleados);
  
  return 0;
}




void mostrarEmpleados(Empleado listado[], int cant){
  int posicion = leerEnteroEntre(1,4, "\n\nQue sector desea ver?\n1. Sector Norte        2. Sector Sur        3. Sector Este        4. Sector Oeste");
  posicion--;

  for (int i = 0; i < cant; i++)
  {
    if (strcmp(listado[i].sector, zona[posicion]) == 0)
    {
      printf("\nDNI: %d\n", listado[i].legajo);
      printf("Apellido: %s\n", listado[i].apellido);
      printf("Nombre: %s\n", listado[i].nombre);
      printf("Zona: %s", listado[i].sector);
    }  
  }
}