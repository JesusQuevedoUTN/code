#include "../../C.h"
#define LEN_ALUMNO  15
#define LEN_MATERIA 25

typedef struct 
{
    char nombre[LEN_ALUMNO];
    char apellido[LEN_ALUMNO];    
    char materia[LEN_MATERIA];
    int notaFinal;
}Alumno;

void iniciarArchivo(FILE** archivo, char* ruta);
void mostrarAlumnos(FILE* archivo);
void promedioNotas(FILE* archivo);
void alumnosAprobadosYDesaprobados(FILE* archivo, char* aprobado, char* desaprobado);
int esFinal(FILE* archivo, Alumno* alumno);

int main()
{
    FILE* archivo=NULL;
    char* ruta = "../alumnos.txt";
    char* rutaAprobados = "../alumnosAprobados.txt";
    char* rutaDesaprobados = "../alumnosDesaprobados.txt";
    
    iniciarArchivo(&archivo, ruta);
    mostrarAlumnos(archivo);
    promedioNotas(archivo);

    alumnosAprobadosYDesaprobados(archivo, rutaAprobados, rutaDesaprobados);

    fclose(archivo);
    return 0;
}



void iniciarArchivo(FILE** archivo, char* ruta)
{
    (*archivo) = fopen(ruta,"r+");
    if ( (*archivo)==NULL)
    {
        printf("ERROR. El archivo \"%s\" no está creado\n", ruta);
        (*archivo) = fopen(ruta,"w+");
        system("pause");
    }
    if ((*archivo)==NULL)
    {
        printf("ERROR. Algo salio mal...");
        system("pause");
    }
}

void mostrarAlumnos(FILE* archivo)
{
    Alumno alumno;
    printf("[%-15s][%-15s][%-15s][%-4s]\n", "NOMBRE", "APELLIDO", "MATERIA", "NOTA");
    fflush(stdin);
    while (esFinal(archivo, &alumno))
    {
        printf("[%-15s][%-15s][%-15s][%-4d]\n", alumno.nombre, alumno.apellido, alumno.materia, alumno.notaFinal);
    }    
    rewind(archivo);
    system("pause");
    system("cls");
}

void promedioNotas(FILE* archivo)
{
    Alumno alumno;
    int cantidadAlumnos = 0;
    int sumatoria       = 0;

    while (esFinal(archivo, &alumno))
    {
        sumatoria = sumatoria + alumno.notaFinal;
        cantidadAlumnos++;
    }
    printf("El promedio de los alumnos es de %.3f\n", (double)sumatoria/cantidadAlumnos);
    system("pause");
    rewind(archivo);
}

void alumnosAprobadosYDesaprobados(FILE* archivo, char* aprobado, char* desaprobado)
{
    Alumno alumno;
    FILE* archApro;
    FILE* archDesa;
    iniciarArchivo(&archApro, aprobado);
    iniciarArchivo(&archDesa, desaprobado);

    while ( esFinal(archivo, &alumno) )
    {
        if (alumno.notaFinal>=6)
        {
            fprintf(archApro,"%s,%s,%s,%d\n",alumno.nombre,alumno.apellido,alumno.materia,alumno.notaFinal);
        }
        else
        {
            fprintf(archDesa,"%s,%s,%s,%d\n",alumno.nombre,alumno.apellido,alumno.materia,alumno.notaFinal);
        }
        
    }
    
    fclose(archApro);
    fclose(archDesa);
}


int esFinal(FILE* archivo, Alumno* alumno)
{
    return fscanf(archivo,"%[^,],%[^,],%[^,],%d\n", alumno->nombre ,alumno->apellido,alumno->materia, &alumno->notaFinal) != EOF;
}