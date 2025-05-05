#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* cadena;

#define MENU_MIN 1
#define MENU_MAX 5
#define LIBRO_TITULO_LEN      40
#define AUTOR_NOMBRE_LEN      40
#define AUTOR_APELLIDO_LEN AUTOR_NOMBRE_LEN

#define NOMBRE_POR_DEFECTO    "<sin nombre>"
#define APELLIDO_POR_DEFECTO  "<sin apellido>"
#define TITULO_POR_DEFECTO    "<sin titulo>"

enum {OPCION_SALIR,
      OPCION_ADD_LIBRO,
      OPCION_MOSTRAR_LIBROS,
      OPCION_ACTUALIZAR_LIBRO,
      OPCION_BORRAR_LIBRO};

typedef struct
{
	cadena nombre;
	cadena apellido;
} Autor;

typedef struct
{
	cadena titulo;
	int anioPublicacion;
	Autor autor;
} Libro;

/*
- Estructura Autor, nombre y apellido (cadenas de caracteres).
- Libro tC-tulo (cadena de caracteres), anioPublicacion (entero), dato Autor.
- No olvides liberar la memoria dinC!mica al finalizar el programa.
*/

//0
int menu();
void pausa();
void liberarMemoria(Libro*, int);
//1
void agregarNuevoLibro(Libro**, int*);
void inicializarLibro(Libro*);
void leerLibro(Libro*);
void leerCadena(char*, int);
void leerEntero(int*);


//2
void mostrarListaDeLibros(Libro[], int);
void mostrarLibro(Libro, int);
bool existe(char*);
void cargarCadena(cadena, cadena);
void cargarEntero(int*);

//3
//4


int main() {
	Libro* biblioteca = malloc(sizeof(Libro));
	int longitud = 0;
    int opcion;
    
	do {
		opcion = menu();
		switch (opcion) {
		case OPCION_SALIR:
		    break;
		case OPCION_ADD_LIBRO:
			agregarNuevoLibro(&biblioteca, &longitud);
			break;

		case OPCION_MOSTRAR_LIBROS:
			mostrarListaDeLibros(biblioteca, longitud);
			break;

		case OPCION_ACTUALIZAR_LIBRO:
			//modificarLibro(biblioteca, longitud);
			break;

		case OPCION_BORRAR_LIBRO:
			//eliminarLibro(biblioteca, &longitud);
			break;
		default:
            printf("NO DEBERIAS ESTAR AQUI");
		}

	} while (opcion != OPCION_SALIR);  // 

    liberarMemoria(&biblioteca, longitud);
	return 0;
}

/*
- Escribe un programa que implemente un menC: CRUD (Crear,
Leer, Actualizar, Eliminar) para gestionar una lista de libros.
Utiliza memoria dinC!mica para almacenar la lista de libros.
*/
//MENU

int menu() {
	int opcion;
	do {
		printf("- - - - BIBLIOTECA CHICHONA - - - -\n");
		printf(" [0] Salir.\n");
		printf(" [1] Agregar un libro nuevo.\n");
		printf(" [2] Mostrar lista de libros.\n");
		printf(" [3] Modificar un libro en la lista.\n");
		printf(" [4] Eliminar un libro de la lista.\n");
		printf("- - - - BIBLIOTECA CHICHONA - - - -\n");
		scanf(" %d", &opcion);
		while(getchar()!='\n');
	} while(opcion <= MENU_MIN && opcion >= MENU_MAX);
	return opcion;
}

void pausa()
{
  printf("Pulsa ENTER para continuar.\n");
  while(getchar()!='\n');
}

void liberarMemoria(Libro *biblioteca, int contador)
{
	if (biblioteca!=NULL)
	{
		for (int i = 0; i < contador; i++)
		{
			free(biblioteca[i].titulo);
			free(biblioteca[i].autor.apellido);
			free(biblioteca[i].autor.nombre);
		}
	}
}


//2
void mostrarListaDeLibros(Libro libro[], int contador) {
	if (contador==0)
	{
		puts("Lista vacia, inserte algunos libros...\n");
	}
	else
	{
	printf("[%s]-[%-20s]-[%-5s]-[%-25s]-[%-25s]\n","Ind","Titulo","Anyo","Nombre","Apellido");
		for(int i = 0; i<contador ; i++) {
			if(existe(libro[i].titulo))
			{
				mostrarLibro(libro[i], i);
			}
		}
		puts("");
	}
	pausa();
}

void mostrarLibro(Libro libro, int indice) {
	printf("[%3d]-[%-20s]-[%5d]-[%-25s]-[%-25s]\n",
		indice+1,
		libro.titulo,
		libro.anioPublicacion,
		libro.autor.nombre,
		libro.autor.apellido);
	}
	
bool existe(char* texto)
{
	return strcmp(texto,"<sin titulo>");
}
	
	
//1
void agregarNuevoLibro(Libro** biblioteca, int* contador)
{
	*contador = *contador + 1;
	*biblioteca = realloc(biblioteca,sizeof(Libro)* (*contador));
	
	if (*biblioteca==NULL)
	{
		printf("ERROR");
	}
	else
	{
	Libro nuevoLibro;
	inicializarLibro(&nuevoLibro);
	
	leerLibro(&nuevoLibro);
	*biblioteca[*contador] = nuevoLibro;
	}
}

void inicializarLibro(Libro* inicializar)
{
	inicializar = (Libro*) malloc(sizeof(Libro));
	inicializar->anioPublicacion = 0;
	strcpy( inicializar->autor.nombre,     NOMBRE_POR_DEFECTO);
	strcpy( inicializar->autor.apellido,   APELLIDO_POR_DEFECTO);
	strcpy( inicializar->titulo,           TITULO_POR_DEFECTO);
}


void leerLibro(Libro *cuaderno)
{
	printf("Que libro desea leer?: %s", cuaderno->titulo);
	leerCadena(cuaderno->titulo,LIBRO_TITULO_LEN);
	
	printf("En que anio salio?:");
	leerEntero(&cuaderno->anioPublicacion);
	
	printf("Apellido?: %s", cuaderno->autor.nombre);
	leerCadena(cuaderno->autor.nombre,AUTOR_NOMBRE_LEN);

	
	printf("Nombre?: %s", cuaderno->autor.apellido);
	leerCadena(cuaderno->autor.apellido,AUTOR_APELLIDO_LEN);
}

void leerCadena(char* texto, int longitud){
	texto = malloc(sizeof(char)*longitud);
	char* nuevo = malloc(sizeof(char)*longitud);
	gets(nuevo);
	strcpy(texto,nuevo);
}

void leerEntero(int* numero) {
	scanf(" %d", numero);
}


/*
void modificarLibro(Libro libro[]){

}

void eliminarLibro(Libro libro[], int* contador){

}*/