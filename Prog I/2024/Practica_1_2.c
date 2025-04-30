#include "../Libs/utils.h"
#define MAX_ALUMNOS 50

typedef struct 
{
    int legajo;
    cadena apellido;
    cadena nombre;
    float nota[5];
}Alumno;

Alumno estudiantes[MAX_ALUMNOS];

const float MINIMO = 1;
const float MAXIMO = 10;

void inicializarAlumnos ();

void registrarAlumnos (int *cant);
void cargarVector (int cant);
void cargarAlumno (Alumno *estudiante);
void leerNotas(float vec[]);

void mostrarAlumnos(int cant);
void ordenarAlumnos(int cant);
void mayoresA();
void buscarMismaInicial();

void mostrar(Alumno est);

int main ()
{
  //a. Una funciC3n que pida al usuario la cantidad de elementos a almacenar
  //b. cargar N alumnos con sus notas, max 5, si no tomC3 rec la nota es 0
  //c. mostrar alumnos mayor a menor por promedio solo en la nota en la posicion 0 y 2 (parciales)
  //d. mostrar cuantos aprobaron nota >= 6 en parciales
  //e. mostrar alumnos con misma inicial del apellido que inicie con lo pedido
  
  
  inicializarAlumnos ();
  int cant;

  registrarAlumnos(&cant);
  mostrarAlumnos(cant);
  return 0;
}

void inicializarAlumnos ()
{
  for (int i = 0; i < MAX_ALUMNOS; i++)
	{
	  estudiantes[i].legajo = -1;
	  strcpy (estudiantes[i].apellido, "");
	  strcpy (estudiantes[i].nombre, "");
	  estudiantes[i].nota[0] = 0;
	  estudiantes[i].nota[1] = 0;
	  estudiantes[i].nota[2] = 0;
	  estudiantes[i].nota[3] = 0;
	  estudiantes[i].nota[4] = 0;
	}
}

void registrarAlumnos (int *cant)
{
  //a.
  *cant = leerEnteroEntre(1,50, "Cuantos elementos desea cargar?");
  //b.
  cargarVector (*cant);
}


void cargarVector (int cant)
{
  for (int i = 0; i < cant; i++)
	{
	  cargarAlumno (&estudiantes[i]);
	}
}

void cargarAlumno (Alumno *estudiante)
{
  estudiante->legajo = leerEnteroEntre(0,1000,"\nIngrese el legajo del alumno");
  leerCadena("Ingrese el apellido del alumno", estudiante->apellido);
  leerCadena("Ingrese el nombre del alumno", estudiante->nombre);
  leerNotas(estudiante->nota);
}

void leerNotas(float vec[]){

    vec[0] = leerFloatEntre(MINIMO, MAXIMO, "Primer parcial");

    if (vec[0] < 6)
    {
        vec[1] = leerEnteroEntre(MINIMO, MAXIMO, "Recuperatorio");
    }
    
    vec[2] = leerEnteroEntre(MINIMO, MAXIMO, "Segundo parcial");

    if (vec[2] < 6)
    {
        vec[3] = leerEnteroEntre(MINIMO, MAXIMO, "Recuperatorio");
    }

    vec[4] = leerEnteroEntre(MINIMO, MAXIMO, "Examen Integral");
}


void mostrarAlumnos (int cant)
{
//  ordenarAlumnos(cant);
  mayoresA();
  buscarMismaInicial();
}


void ordenarAlumnos(int cant){
  float promedio, guardado = 0;
  Alumno auxiliar = {-1,"","", {0.0, 0.0, 0.0, 0.0, 0.0} };
  for (int i = 0; i < cant; i++)
  {
    promedio = ((float)estudiantes[i].nota[0] + (float)estudiantes[i].nota[2])/(float)2;
    if (i==0 || promedio > guardado)
    {
      guardado=promedio;
      estudiantes[i] = auxiliar;

    }
  }
  for (int i = 0; i < cant; i++)
  {
    mostrar(estudiantes[i]);
  }
  
  
}
void mayoresA(){
  int i=0;
  while (estudiantes[i].legajo != -1)
  {
    if (estudiantes[i].nota[0] >= 6 || estudiantes[i].nota[2] >= 6 )
    {
      mostrar(estudiantes[i]);
    }
    i++;
  }
}

void buscarMismaInicial(){
  char letra = leerCaracter("Que letra busca?");
  int i=0;
  while (estudiantes[i].legajo != -1)
  {
    if (estudiantes[i].apellido[0] == letra)
    {
      mostrar(estudiantes[i]);
    }
    i++;
  }
}

void mostrar(Alumno est){
  printf("\n%s %s\nlegajo: %d\n", est.nombre, est.apellido, est.legajo);
  printf("Notas: %.2f, %.2f, %.2f, %.2f, %.2f\n\n", est.nota[0], est.nota[1], est.nota[2], est.nota[3], est.nota[4]);

}