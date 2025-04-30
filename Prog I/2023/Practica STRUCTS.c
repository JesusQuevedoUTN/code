#include "Libs/utils.h"
/*
3) En un instituto existe la materia "Lengua extranjera", donde los alumnos tienen la posibilidad de
elegir cursar un idioma entre las posibilidades existentes. Realizá un programa que permita
ingresar, por cada alumno (como máximo 10):
▪ Su apellido.
▪ Su edad (Entero entre 14 y 18).
▪ Un caracter que represente la inicial del idioma elegido (validar):
[I]nglés [F]rancés [P]ortugués [A]lemán
Por cada alumno cargado se debe preguntar si se desea seguir ingresando otro, de la forma "¿Desea
ingresar otro alumno? [S/N]".Al finalizar la carga, debe mostrar el porcentaje de alumnos que
eligió cada idioma, junto a su promedio de edad.
*/

#define MAX_ALUMNOS 10
#define CANT_IDIOMAS 4

/*
typedef struct 
{
    cadena apellido;
    int edad;
    char idioma;
}Alumno;

void totalAlumnos();
void cargarAlumnos(Alumno alumnos, int contador);
Alumno leerAlumno(Alumno x, int idiomas[], int edades[]);
char leerIdioma(char x, cadena mensaje);
void porcentaje(int idiomas[CANT_IDIOMAS], int contador);
void promedioIdiomas(int edades[], int idiomas[]);


int main()
{
    puts("Es el momento de registrar a los alumnos de la materia de idioma, preparese para indicar los datos necesarios");
    totalAlumnos();

    return 0;
}

void totalAlumnos(){
    Alumno estudiantes[MAX_ALUMNOS];
    int contador = 0;
    cargarAlumnos(estudiantes, contador);
}
    
void cargarAlumnos(Alumno alumnos, int contador){
    int idiomas[CANT_IDIOMAS], edades[CANT_IDIOMAS];
    inicializarVectorDeEnteros(idiomas, CANT_IDIOMAS);
    inicializarVectorDeEnteros(edades, CANT_IDIOMAS);

    while (contador < MAX_ALUMNOS && confirmaUsuario("Desea ingresar un nuevo alumno?"))
    {
        alumnos[contador] = leerAlumno(alumnos[contador], idiomas, edades);
        contador++;
    }
    porcentaje(idiomas, contador);
    promedioIdiomas(edades,idiomas);
}

Alumno leerAlumno(Alumno x, int idiomas[], int edades[]){
    leerCadena("Apellido:", x.apellido);
    x.edad = leerEnteroEntre(14,18, "Edad:");
    x.idioma = leerIdioma(x.idioma , "Idioma:");
    switch (x.idioma)
    {
    case 'I':
        idiomas[0]++;
        edades+=x.edad;
        break;
    case 'F':
        idiomas[1]++;
        edades+=x.edad;
        break;
    case 'P':
        idiomas[2]++;
        edades+=x.edad;
        break;
    case 'A':
        idiomas[3]++;
        edades+=x.edad;
        break;
    }
    return x;
    }

char leerIdioma(char x, cadena mensaje){
    x = leerCaracter(mensaje);
    while (x!='I' && x!='F' && x!='P' && x!='A')
    {
        puts("Solo puede ser las letras I (Ingles), F (Frances), P (Portugues), A (Aleman), en MAYUSCULAS");
        x = leerCaracter(mensaje);
    }
    return x;
    }

void porcentaje(int idiomas[CANT_IDIOMAS], int contador){
    printf("Ingles: %d\n", (idiomas[0]/contador)*100);
    printf("Frances: %d\n", (idiomas[1]/contador)*100);
    printf("Portugues: %d\n", (idiomas[2]/contador)*100);
    printf("Aleman: %d\n", (idiomas[3]/contador)*100);
}

void promedioIdiomas(int edades[], int idiomas[]){
    printf("Promedio Ingles: %.2f\n", promedio(edades[0],idiomas[0]));
    printf("Promedio Frances: %.2f\n", promedio(edades[1],idiomas[1]));
    printf("Promedio Portugues: %.2f\n", promedio(edades[2],idiomas[2]));
    printf("Promedio Aleman: %.2f\n", promedio(edades[3],idiomas[3]));
}

*/