#include "../Libs/utils.h"

#define MAX 5
cadena zona[] = { "Norte", "Sur", "Este", "Oeste"} ;

 typedef struct {
 int legajo;
 cadena apellido;
 cadena nombre;
 cadena sector;
} Empleado; 

//.1 inicializar
void inicializarEmpleados(Empleado laburante[MAX]);

//2. cargar
void cargarEmpleados(Empleado laburante[MAX]);
int leerDNI(int documentos[]);
int noSeRepite(int dni, int documentos[]);
void leerZona(cadena sector);


//3. ordenar
void ordenarEmpleados(Empleado laburante[MAX]);

//4. mostrar
void mostrarEmpleados(Empleado laburante[MAX]);


int main ()
{
    /*
    a. función que cargar empleados hasta el DNI igual a -1, validar si el empleado si ya fue ingresado o no
    b. ordenamiento de los empleados por orden alfabético
    c. Mostrar los empleados por sector
    */

    Empleado lista[MAX];
    inicializarEmpleados(lista);

    cargarEmpleados(lista);
    ordenarEmpleados(lista);
    mostrarEmpleados(lista);

}

//1.
void inicializarEmpleados(Empleado laburante[MAX]){
    for (int i = 0; i < MAX; i++)
    {
        strcpy(laburante[i].apellido,"");
        strcpy(laburante[i].nombre,"");
        strcpy(laburante[i].sector,"");
        laburante[i].legajo = 0;
    }
}

//2.
void cargarEmpleados(Empleado laburante[MAX]){
    int i = 0, documentos[MAX];
    int dni = 0;
    puts("Bienvenido al sistema de cargas de Mpleados Nonimos.C\n");

    while (dni != -1 && i<MAX)
    {
        dni = leerDNI(documentos);
        
        if (dni != -1 )
        {
            documentos[i] = dni;
            laburante[i].legajo = dni;            
            leerCadena("Ingrese el apellido", laburante[i].apellido);
            leerCadena("Ingrese el nombre", laburante[i].nombre);
            leerZona(laburante[i].sector);
            i++;
        }
    }
}
/*
int leerDNI(int documentos[]){
    int dni = leerEnteroEntre(-1, 100000000, "\nInserte DNI, pulse -1 para finalizar");
    while (dni == 0 || noSeRepite(dni, documentos))
    {
        puts("ERROR. no se puede repetir ni puede ser 0, intente de nuevo");
        dni = leerEnteroEntre(-1, 100000000, "\nInserte DNI, pulse -1 para finalizar");
    }
    return dni;
}*/

//No pude, llevo 1 semana en este código, tuve que usar chat GPT en este
int leerDNI(int documentos[]){
    int dni;
    do {
        dni = leerEnteroEntre(-1, 100000000, "\nInserte DNI, pulse -1 para finalizar");
        
        // Si el usuario decide terminar la carga de empleados, salir del bucle
        if (dni == -1) {
            break;
        }
        
        // Verificar si el DNI es válido (mayor que 0) y no se repite
        if (dni == 0 || !noSeRepite(dni, documentos)) {
            puts("ERROR. El DNI no puede ser 0 o repetido. Intente de nuevo.");
        }
    } while (dni == 0 || !noSeRepite(dni, documentos));
    
    return dni;
}
int noSeRepite(int dni, int documentos[]){
    int i = 0;

    while (documentos[i] != dni && i<MAX)
    {
        i++;
    }
    
    return i == MAX;
}
void leerZona(cadena sector){
    int posicion = leerEnteroEntre(1,4,"A que sector pertenece?\n1. Norte    2. Sur    3. Este    4. Oeste")-1;
    strcpy(sector, zona[posicion]);
}

//3.
void ordenarEmpleados(Empleado laburante[MAX]){
    Empleado auxiliar;
    //llevo 2 días en esta parte del codigo, usé chat GPT
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (strcmp(laburante[j].apellido, laburante[j + 1].apellido) > 0)
            {
                // Intercambiar los elementos si el apellido en la posición j es mayor que el apellido en la posición j + 1
                auxiliar = laburante[j];
                laburante[j] = laburante[j + 1];
                laburante[j + 1] = auxiliar;
            }
        }
    }
}

//4.
void mostrarEmpleados(Empleado laburante[MAX]){
    int posicion = leerEnteroEntre(1,4, "\n\nQue sector desea ver?\n1. Sector Norte        2. Sector Sur        3. Sector Este        4. Sector Oeste")-1;
    int i = 0;
    
    while (i < MAX)
    {
        //correccion de codigo chat GPT en "&& laburante[i].legajo != 0"
        if (!strcmp(laburante[i].sector, zona[posicion]) && laburante[i].legajo != 0)
        {
            printf("\nDNI: %d\n", laburante[i].legajo);
            printf("Apellido: %s\n", laburante[i].apellido);
            printf("Nombre: %s\n", laburante[i].nombre);
            printf("Zona: %s\n", laburante[i].sector);
        }
        i++;
    }
}
