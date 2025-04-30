#include <stdio.h>

#define MAX_CANT_ALUMNOS 20
typedef char cadena[50];

typedef struct {
    int codCarrera;
    int legajo;
    cadena apellido;
    cadena nombre;
} Alumno;

int leerAlumnos (FILE* archivo, Alumno alumnosLeidos[]);
void cerrarArchivo(FILE* pArch, cadena ruta);
int leerAlumnos (FILE* archivo, Alumno alumnosLeidos[]);
void mostrarAlumnos (Alumno alumnosLeidos[], int cant);
void escribirAlumnos (Alumno alumnosLeidos[], int cant);

int main () {
    cadena ruta = "../data-alumnos/alumnos-2.txt"; 
    FILE* archivo = fopen(ruta, "r");
    Alumno alumnosLeidos[MAX_CANT_ALUMNOS];

    if (archivo != NULL) {
        int cantRealDeAlumnos = leerAlumnos(archivo, alumnosLeidos);
        cerrarArchivo(archivo, ruta);

        mostrarAlumnos(alumnosLeidos, cantRealDeAlumnos);
        escribirAlumnos(alumnosLeidos, cantRealDeAlumnos);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

    return 0;
}

void cerrarArchivo(FILE* pArch, cadena ruta) {
    int result = fclose(pArch);
    if (result == NULL) {
        printf("***ARCHIVO '%s' CERRADO CORRECTAMENTE***\n", ruta);
    } else {
        printf("***NO SE PUDO CERRAR EL ARCHIVO '%s'***\n", ruta);
    }
}

int leerAlumnos (FILE* archivo, Alumno alumnosLeidos[]) {
    int i = 0;
    while(i < MAX_CANT_ALUMNOS && !feof(archivo)) {
        Alumno a;
        fscanf(archivo, "%d,%d,%s,%s\n", &(a.codCarrera), &(a.legajo), a.apellido, a.nombre);
        alumnosLeidos[i] = a;
        i++;
    }
    return i; // Devuelve la cant real de alumnos leidos
}

void mostrarAlumnos (Alumno alumnosLeidos[], int cant) {
    for (int i = 0; i < cant; i++) {
        Alumno a = alumnosLeidos[i];
        printf("%d) %d - %d - %s\n", (i+1), a.codCarrera, a.legajo, a.apellido, a.nombre);
    }
}


void escribirAlumnos (Alumno alumnosLeidos[], int cant) {
    cadena ruta = "../generadosPorC/copia.txt";
    FILE* pArch = fopen(ruta, "w");
    for (int i = 0; i < cant; i++) {
        Alumno a = alumnosLeidos[i];
        fprintf(pArch, "%d) %d - %d - %s \n", (i+1), a.codCarrera, a.legajo, a.apellido, a.nombre);
    }
    cerrarArchivo(pArch, ruta);
}
