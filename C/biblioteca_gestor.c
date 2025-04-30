/*
  Materia : Estructura y base de datos
  Autor   : Alberto Martín Capurro
  Fecha   : 24 - 04 - 2025

  Gestión de Biblioteca
  Descripción:
  * Crea una estructura llamada Autor con los campos nombre y apellido
    (cadenas de caracteres).

  * Crea una estructura llamada Libro con los campos título
    (cadena de caracteres), anioPublicacion (entero) y un campo autor
    de tipo Autor.

  * Escribe un programa que implemente un menú CRUD (Crear, Leer, Actualizar, Eliminar)
    para gestionar una lista de libros.
    Utiliza memoria dinámica para almacenar la lista de libros.

  * Desarrollar un menú interactivo el menú debe permitir:
    * Agregar un nuevo libro.
    * Mostrar la lista de libros.
    * Modificar la información de un libro existente. (si no me tendrá que
      avisar que no existe).
    * Eliminar un libro de la lista.

  * No olvides liberar la memoria dinámica al finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRO_TITULO_LEN      30
#define AUTOR_NOMBRE_LEN      26
#define AUTOR_APELLIDO_LEN AUTOR_NOMBRE_LEN

#define INDICE_POR_DEFECTO    -1
#define INDICE_MINIMO         1
#define ANIO_MINIMO           1900
#define ANIO_MAXIMO           2025
#define ANIO_POR_DEFECTO      ANIO_MINIMO

#define NOMBRE_POR_DEFECTO    "<sin nombre>"
#define APELLIDO_POR_DEFECTO  "<sin apellido>"
#define TITULO_POR_DEFECTO    "<sin titulo>"


typedef struct st_autor
{
  char  nombre   [AUTOR_NOMBRE_LEN];
  char  apellido [AUTOR_APELLIDO_LEN];
} t_autor;

typedef struct st_libro
{
  char      titulo   [LIBRO_TITULO_LEN];
  int       anio_publicacion;
  t_autor   autor;
} t_libro;

void pausa()
{
  printf("Pulsa ENTER para continuar.\n");
  while(getchar()!='\n');
}

enum {OPCION_SALIR,
      OPCION_ADD_LIBRO,
      OPCION_MOSTRAR_LIBROS,
      OPCION_ACTUALIZAR_LIBRO,
      OPCION_BORRAR_LIBRO};

#define OPCION_DEFAULT -1
#define OPCION_MIN      0
#define OPCION_MAX      4


void crear_libro      (t_libro **libro_ref);
void cargar_libro     (t_libro  *libro_ref);
void leer_cadena      (char *buffer, int buffer_len);

void libro_agregar    (t_libro **libro_lista, int *len);
void libros_mostrar   (t_libro  *libro_lista, int *len);
void libro_modificar  (t_libro  *libro_lista, int *len);
void libro_eliminar   (t_libro **libro_lista, int *len);


int menu(void)
{
  int opcion = OPCION_DEFAULT;
  do
  {
    printf("------------------ BIBLIOTECARIO INSPT ------------------\n");
    printf("  [1] Agregar un nuevo libro.\n");
    printf("  [2] Mostrar la lista de libros. \n");
    printf("  [3] Modificar la informacion de un libro existente. \n");
    printf("  [4] Eliminar libro de la lista. \n");
    printf("\n");
    printf("  [0] Salir. \n");
    printf("---------------------------------------------------------\n");
    printf("Seleccion? ");
    scanf(" %d", &opcion);
    while(getchar()!='\n'){};
    //printf("Leido %d\n", opcion);
  }
  while(opcion < OPCION_MIN || opcion > OPCION_MAX);

  return opcion;
}

void crear_libro(t_libro **libro_ref)
{
  //t_libro *libro_ptr = (t_libro*) malloc(sizeof(t_libro));
  *libro_ref = (t_libro*) malloc(sizeof(t_libro));
  //(*libro_ref)->anio_publicacion = rand()%(0+25+1)+2000;
  (*libro_ref)->anio_publicacion =        ANIO_POR_DEFECTO;
  strcpy( (*libro_ref)->autor.nombre,     NOMBRE_POR_DEFECTO);
  strcpy( (*libro_ref)->autor.apellido,   APELLIDO_POR_DEFECTO);
  strcpy( (*libro_ref)->titulo,           TITULO_POR_DEFECTO);
  cargar_libro(*libro_ref);
}

//leer_cadena(libro_ref->autor.nombre, AUTOR_NOMBRE_LEN);
void leer_cadena(char *buffer, int buffer_len)
{
  char c;
  int  char_count = 0;
  while( (c = getchar())!= '\n' && char_count < buffer_len - 1)
  {
    buffer[char_count++] = c;
  }
  buffer[char_count] = '\0';
  if(c != '\n')
    while(getchar()!='\n'){};
}

void cargar_libro(t_libro *libro_ref)
{
  char titulo[LIBRO_TITULO_LEN] = "";
  do
  {
    printf("Ingresar nuevo titulo libro: %s\n", libro_ref->titulo);
    leer_cadena(titulo, LIBRO_TITULO_LEN);
  }
  while( !strcmp(titulo, "") );

  int anio = ANIO_POR_DEFECTO;
  do
  {
    printf("Ingresar anio de libro: %d\n", libro_ref->anio_publicacion);
    scanf(" %d", &anio);
    while(getchar()!='\n');
    if(ANIO_MINIMO > anio || ANIO_MAXIMO < anio)
    {
      printf("Anyo fuera de rango [%4d - %4d]\n", ANIO_MINIMO, ANIO_MAXIMO );
    }
  }
  while( ANIO_MINIMO > anio || ANIO_MAXIMO < anio);

  char autor_nombre[AUTOR_NOMBRE_LEN] = "";
  do
  {
    printf("Ingresar nombre autor: %s\n", libro_ref->autor.nombre);
    leer_cadena(autor_nombre, AUTOR_NOMBRE_LEN);
  }
  while( !strcmp(autor_nombre, "") );

  char autor_apellido[AUTOR_APELLIDO_LEN] = "";
  do
  {
    printf("Ingresar apellido autor: %s\n", libro_ref->autor.apellido);
    leer_cadena(autor_apellido, AUTOR_APELLIDO_LEN);
  }
  while( !strcmp(autor_apellido, "") );

  libro_ref->anio_publicacion = anio;
  strcpy(libro_ref->titulo         , titulo);
  strcpy(libro_ref->autor.nombre   , autor_nombre);
  strcpy(libro_ref->autor.apellido , autor_apellido);

}

void libro_agregar(t_libro **libro_lista, int *len)
{
  printf("\nAGREGA\n");
  //printf(" len %d\n", *len);
  //construir libro
  //t_libro *libro_ptr = (t_libro*) malloc(sizeof(t_libro));
  //libro_ptr->anio_publicacion = rand()%(0+25+1)+2000;
  //strcpy( libro_ptr->autor.nombre,    "nombre");
  //strcpy( libro_ptr->autor.apellido,  "apellido");
  //strcpy( libro_ptr->titulo,          "el titulo");

  t_libro *libro_ptr = NULL;

  crear_libro(&libro_ptr);

  t_libro *libro_temp = realloc( *libro_lista, sizeof(t_libro) * (*len + 1));
  if(libro_temp == NULL)
  {
    printf("Error de asignacion de memoria\n");
    exit(-2);
  }
  *libro_lista = libro_temp;

  (*libro_lista)[*len] = *libro_ptr;

  free(libro_ptr);
  (*len)++;
}

void libros_mostrar (t_libro *libro_lista, int *len)
{
  printf("MUESTRA\n");

  if(*len == 0)
  {
    printf("-------- La lista esta vacia ---------\n");
  }
  else
  {
    printf("[%s]-[%-20s]-[%-5s]-[%-25s]-[%-25s]\n","Ind","Titulo","Anyo","Nombre","Apellido");
    for(int i =0; i< *len; i++)
    {
      printf("[%3d]-[%-20s]-[%5d]-[%-25s]-[%-25s]\n",
             i+1,
             libro_lista[i].titulo,
             libro_lista[i].anio_publicacion,
             libro_lista[i].autor.nombre,
             libro_lista[i].autor.apellido);
    }
    printf("\n");
  }
  pausa();
}

void libro_modificar(t_libro *libro_lista, int *len)
{
  printf("MODIFICA\n");
  if( *len > 0 )
  {

    int indice = INDICE_POR_DEFECTO;
    do
    {
      printf("Ingresar indice de libro: ");
      scanf(" %d", &indice);
      while(getchar()!='\n');
      indice -= 1;
      if(indice >= (*len) || indice < 0)
      {
        printf("Indice fuera de rango [%2d - %2d]\n", INDICE_MINIMO, *len );
      }
    }
    while( ((*len - 1) < indice) || (indice < 0));

    char titulo[LIBRO_TITULO_LEN] = "";
    do
    {
      printf("Ingresar nuevo titulo libro: %s\n", libro_lista[indice].titulo);
      leer_cadena(titulo, LIBRO_TITULO_LEN);
    }
    while( !strcmp(titulo, "") );

    int anio = ANIO_POR_DEFECTO;
    do
    {
      printf("Ingresar anio de libro: %d\n", libro_lista[indice].anio_publicacion);
      scanf(" %d", &anio);
      while(getchar()!='\n');
      if(ANIO_MINIMO > anio || ANIO_MAXIMO < anio)
      {
        printf("Anyo fuera de rango [%4d - %4d]\n", ANIO_MINIMO, ANIO_MAXIMO );
      }
    }
    while( ANIO_MINIMO > anio || ANIO_MAXIMO < anio);

    char autor_nombre[AUTOR_NOMBRE_LEN] = "";
    do
    {
      printf("Ingresar nombre autor: %s\n", libro_lista[indice].autor.nombre);
      leer_cadena(autor_nombre, AUTOR_NOMBRE_LEN);
    }
    while( !strcmp(autor_nombre, "") );

    char autor_apellido[AUTOR_APELLIDO_LEN] = "";
    do
    {
      printf("Ingresar apellido autor: %s\n", libro_lista[indice].autor.apellido);
      leer_cadena(autor_apellido, AUTOR_APELLIDO_LEN);
    }
    while( !strcmp(autor_apellido, "") );

    if( (*len) > 0 && (*len) > indice)
    {
      libro_lista[indice].anio_publicacion      = anio;
      strcpy(libro_lista[indice].titulo         , titulo);
      strcpy(libro_lista[indice].autor.nombre   , autor_nombre);
      strcpy(libro_lista[indice].autor.apellido , autor_apellido);
    }
  }
  else
  {
    printf("La lista esta vacia\n");
  }
}

void libro_eliminar (t_libro **libro_lista, int *len)
{
  if (*len > 0)
  {

    int indice = INDICE_POR_DEFECTO;
    do
    {
      printf("Ingresar indice de libro: ");
      scanf(" %d", &indice);
      while(getchar()!='\n');
      indice -= 1;
      if(indice >= (*len) || indice < 0)
      {
        printf("Indice fuera de rango [%2d - %2d]\n", INDICE_MINIMO, *len );
      }
    }
    while( ((*len - 1) < indice) || (indice < 0));

    // mueve todos los elementos hacia la izquierda a partir del eleminado si los hay
    // luego hacer realloc
    if( (*len) > 0 && (*len) > indice)
    {
      printf("ELIMINA\n");
      for(int i = indice; i < (*len - 1); i++)
      {
        (*libro_lista)[i] = (*libro_lista)[i+1];
      }

      t_libro *libro_temp = realloc( *libro_lista, sizeof(t_libro) * (*len - 1));
      if(libro_temp == NULL)
      {
        printf("Error de asignacion de memoria\n");
        exit(-1);
      }
      *libro_lista = libro_temp;

      //*libro_lista = realloc( *libro_lista, sizeof(t_libro) * (*len - 1));
      (*len)--;
      //printf("len     %d\n", *len);
      //printf("indice  %d\n", indice);
    }

  }
  else
  {
    printf("\nNo se puede eliminar, lista vacia\n");
  }

}

int main()
{
  t_libro *libro_lista  = NULL;
  int     libro_len     = 0;

  int opcion = -1;
  do
  {
    opcion = menu();
    printf("\nProcesando opcion: %d\n", opcion);

    // * Agregar un nuevo libro.
    // * Mostrar la lista de libros.
    // * Modificar la información de un libro existente. (si no me tendrá que
    //   avisar que no existe).
    // * Eliminar un libro de la lista.

    switch(opcion)
    {
      case OPCION_SALIR:
        break;
      case OPCION_ADD_LIBRO:
        libro_agregar(&libro_lista, &libro_len);
        break;
      case OPCION_MOSTRAR_LIBROS:
        libros_mostrar(libro_lista, &libro_len);
        break;
      case OPCION_ACTUALIZAR_LIBRO:
        libro_modificar(libro_lista, &libro_len);
        break;
      case OPCION_BORRAR_LIBRO:
        libro_eliminar(&libro_lista, &libro_len);
        break;
      default:
        printf("NO DEBERIAS ESTAR AQUI");
    }

  }
  while(opcion != OPCION_SALIR);

  if(libro_lista != NULL)
  {
    free(libro_lista);
  }

  return 0;
}

