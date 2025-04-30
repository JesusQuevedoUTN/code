#include "./Libs/utils.h"
#define MAX 20

//1. mostrar el archivo de texto
//2. generar un archivo binario que contenga los nombres del empleado y salario solo de VENTAS
//3. generar un informe con los que tienen oficiio EMPLEADO (empleados.txt) y otros con los demas empleados (otro.txt)

typedef struct 
{
    int idEmpleado;
    cadena apellido;
    cadena puesto;
    float salario;
    cadena oficina;
}Empleado;

void inicializarEmpleados(Empleado laburantes[MAX]){
    for (int i = 0; i < MAX; i++)
    {
        laburantes[i].idEmpleado = 0;
        strcpy(laburantes[i].apellido,"");
        strcpy(laburantes[i].puesto,"");
        laburantes[i].salario = 0;
        strcpy(laburantes[i].oficina,"");
    }
}

void cargarEmpleados(FILE* documento, Empleado laburantes[MAX]){
    cadena linea;
    cadena* token;

    while (fgets(linea, sizeof(linea), documento) != NULL) {
        
        token = strtok(linea, ";");
        while (token != NULL && token != '\n') {
            
            token = strtok(NULL, ";");
        
}


void mostrarArchivo(FILE* documento, Empleado laburantes[MAX]) {
    int i = 0;
    
    inicializarEmpleados(laburantes);
    cargarEmpleados(documento, laburantes);
    
    while (laburantes[i].idEmpleado != 0) {
        printf("Id: %d, Oficina: %s, Apellido: %s, Puesto: %s, Salario: %.2f\n", laburantes[i].idEmpleado, laburantes[i].oficina, laburantes[i].apellido, laburantes[i].puesto, laburantes[i].salario);
        i++;
    }
}

void generarArchivoBinario(FILE* documento, char* mostrar, char* ruta) {
    FILE* nuevo;
    cadena linea;
        
    abrirArchivo(&nuevo, ruta, "wb");
    
    while (fgets(linea, sizeof(linea), documento) != NULL) {
        char* token = strtok(linea, ";");
        while (token != NULL) {
            if (strcmp(token, mostrar)) {
                fwrite(linea, sizeof(char), strlen(linea), nuevo); 
            }
            token = strtok(NULL, ";");
        }
    }
    
    cerrarArchivo(nuevo, ruta); 
}

//no llegué a este
void generarInforme(FILE* documento, cadena mostrar, cadena primaria, cadena secundaria){
    FILE* nuevo, otro;
    cadena linea;
        
    abrirArchivo(&nuevo, primaria, "wb");
    
    while (fgets(linea, sizeof(linea), documento) != NULL) {
        char* token = strtok(linea, ";");
        while (token != NULL) {
            if (strcmp(token, mostrar)) {
                fwrite(linea, sizeof(char), strlen(linea), nuevo); 
            }
            else{
                fwrite(linea, sizeof(char), strlen(linea), nuevo); 
            }
            token = strtok(NULL, ";");
        }
    }
    
    cerrarArchivo(nuevo, primaria); 
}
