/*
  Materia : Estructura y base de datos
  Autor   : Alberto Mart�n Capurro
  Fecha   : 24 - 04 - 2025

  Gesti�n de Biblioteca
  Descripci�n:
  * Crea una estructura llamada Autor con los campos nombre y apellido
    (cadenas de caracteres).

  * Crea una estructura llamada Libro con los campos t�tulo
    (cadena de caracteres), anioPublicacion (entero) y un campo autor
    de tipo Autor.

  * Escribe un programa que implemente un men� CRUD (Crear, Leer, Actualizar, Eliminar)
    para gestionar una lista de libros.
    Utiliza memoria din�mica para almacenar la lista de libros.

  * Desarrollar un men� interactivo el men� debe permitir:
    * Agregar un nuevo libro.
    * Mostrar la lista de libros.
    * Modificar la informaci�n de un libro existente. (si no me tendr� que
      avisar que no existe).
    * Eliminar un libro de la lista.

  * No olvides liberar la memoria din�mica al finalizar el programa.
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
} Autor;

typedef struct st_libro
{
  char      titulo   [LIBRO_TITULO_LEN];
  int       anioPublicacion;
  Autor   autor;
} Libro;

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


void crearLibro      (Libro **libroRef);
void cargarLibro     (Libro  *libroRef);
void leerCadena      (char *buffer, int bufferLen);

void libroAgregar    (Libro **libroLista, int *len);
void librosMostrar   (Libro  *libroLista, int *len);
void libroModificar  (Libro  *libroLista, int *len);
void libroEliminar   (Libro **libroLista, int *len);


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

void crearLibro(Libro **libroRef)
{
  //t_libro *libroPtr = (t_libro*) malloc(sizeof(t_libro));
  *libroRef = (Libro*) malloc(sizeof(Libro));
  //(*libroRef)->anioPublicacion = rand()%(0+25+1)+2000;
  (*libroRef)->anioPublicacion =        ANIO_POR_DEFECTO;
  strcpy( (*libroRef)->autor.nombre,     NOMBRE_POR_DEFECTO);
  strcpy( (*libroRef)->autor.apellido,   APELLIDO_POR_DEFECTO);
  strcpy( (*libroRef)->titulo,           TITULO_POR_DEFECTO);
  cargarLibro(*libroRef);
}

//leer_cadena(libroRef->autor.nombre, AUTOR_NOMBRE_LEN);
void leerCadena(char *buffer, int bufferLen)
{
  char c;
  int  char_count = 0;
  while( (c = getchar())!= '\n' && char_count < bufferLen - 1)
  {
    buffer[char_count++] = c;
  }
  buffer[char_count] = '\0';
  if(c != '\n')
    while(getchar()!='\n'){};
}

void cargarLibro(Libro *libroRef)
{
  char titulo[LIBRO_TITULO_LEN] = "";
  do
  {
    printf("Ingresar nuevo titulo libro: %s\n", libroRef->titulo);
    leerCadena(titulo, LIBRO_TITULO_LEN);
  }
  while( !strcmp(titulo, "") );

  int anio = ANIO_POR_DEFECTO;
  do
  {
    printf("Ingresar anio de libro: %d\n", libroRef->anioPublicacion);
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
    printf("Ingresar nombre autor: %s\n", libroRef->autor.nombre);
    leerCadena(autor_nombre, AUTOR_NOMBRE_LEN);
  }
  while( !strcmp(autor_nombre, "") );

  char autor_apellido[AUTOR_APELLIDO_LEN] = "";
  do
  {
    printf("Ingresar apellido autor: %s\n", libroRef->autor.apellido);
    leerCadena(autor_apellido, AUTOR_APELLIDO_LEN);
  }
  while( !strcmp(autor_apellido, "") );

  libroRef->anioPublicacion = anio;
  strcpy(libroRef->titulo         , titulo);
  strcpy(libroRef->autor.nombre   , autor_nombre);
  strcpy(libroRef->autor.apellido , autor_apellido);

}

void libroAgregar(Libro **libroLista, int *len)
{
  printf("\nAGREGA\n");
  //printf(" len %d\n", *len);
  //construir libro
  //t_libro *libroPtr = (t_libro*) malloc(sizeof(t_libro));
  //libroPtr->anioPublicacion = rand()%(0+25+1)+2000;
  //strcpy( libroPtr->autor.nombre,    "nombre");
  //strcpy( libroPtr->autor.apellido,  "apellido");
  //strcpy( libroPtr->titulo,          "el titulo");

  Libro *libroPtr = NULL;

  crearLibro(&libroPtr);

  Libro *libroTemp = realloc( *libroLista, sizeof(Libro) * (*len + 1));
  if(libroTemp == NULL)
  {
    printf("Error de asignacion de memoria\n");
    exit(-2);
  }
  *libroLista = libroTemp;

  (*libroLista)[*len] = *libroPtr;

  free(libroPtr);
  (*len)++;
}

void librosMostrar (Libro *libroLista, int *len)
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
             libroLista[i].titulo,
             libroLista[i].anioPublicacion,
             libroLista[i].autor.nombre,
             libroLista[i].autor.apellido);
    }
    printf("\n");
  }
  pausa();
}

void libroModificar(Libro *libroLista, int *len)
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
      printf("Ingresar nuevo titulo libro: %s\n", libroLista[indice].titulo);
      leerCadena(titulo, LIBRO_TITULO_LEN);
    }
    while( !strcmp(titulo, "") );

    int anio = ANIO_POR_DEFECTO;
    do
    {
      printf("Ingresar anio de libro: %d\n", libroLista[indice].anioPublicacion);
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
      printf("Ingresar nombre autor: %s\n", libroLista[indice].autor.nombre);
      leerCadena(autor_nombre, AUTOR_NOMBRE_LEN);
    }
    while( !strcmp(autor_nombre, "") );

    char autor_apellido[AUTOR_APELLIDO_LEN] = "";
    do
    {
      printf("Ingresar apellido autor: %s\n", libroLista[indice].autor.apellido);
      leerCadena(autor_apellido, AUTOR_APELLIDO_LEN);
    }
    while( !strcmp(autor_apellido, "") );

    if( (*len) > 0 && (*len) > indice)
    {
      libroLista[indice].anioPublicacion      = anio;
      strcpy(libroLista[indice].titulo         , titulo);
      strcpy(libroLista[indice].autor.nombre   , autor_nombre);
      strcpy(libroLista[indice].autor.apellido , autor_apellido);
    }
  }
  else
  {
    printf("La lista esta vacia\n");
  }
}

void libroEliminar (Libro **libroLista, int *len)
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
        (*libroLista)[i] = (*libroLista)[i+1];
      }

      Libro *libroTemp = realloc( *libroLista, sizeof(Libro) * (*len - 1));
      if(libroTemp == NULL)
      {
        printf("Error de asignacion de memoria\n");
        exit(-1);
      }
      *libroLista = libroTemp;

      //*libroLista = realloc( *libroLista, sizeof(t_libro) * (*len - 1));
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
  Libro *libroLista  = NULL;
  int     libroLen     = 0;

  int opcion = -1;
  do
  {
    opcion = menu();
    printf("\nProcesando opcion: %d\n", opcion);

    // * Agregar un nuevo libro.
    // * Mostrar la lista de libros.
    // * Modificar la informaci�n de un libro existente. (si no me tendr� que
    //   avisar que no existe).
    // * Eliminar un libro de la lista.

    switch(opcion)
    {
      case OPCION_SALIR:
        break;
      case OPCION_ADD_LIBRO:
          libroAgregar(&libroLista, &libroLen);
          break;
      case OPCION_MOSTRAR_LIBROS:
          librosMostrar(libroLista, &libroLen);
          break;
      case OPCION_ACTUALIZAR_LIBRO:
          libroModificar(libroLista, &libroLen);
          break;
      case OPCION_BORRAR_LIBRO:
          libroEliminar(&libroLista, &libroLen);
          break;
      default:
        printf("NO DEBERIAS ESTAR AQUI");
    }

  }
  while(opcion != OPCION_SALIR);

  if(libroLista != NULL)
  {
    free(libroLista);
  }

  return 0;
}

