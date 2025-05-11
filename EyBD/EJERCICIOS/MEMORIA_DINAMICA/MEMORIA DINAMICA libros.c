#include "../C/Libs/utils.h"

#define MENU_MIN 		1
#define MENU_MAX 		5
#define TITULO_LEN		100
#define AUTOR_LEN      	50

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
	char 	nombre[AUTOR_LEN];
	char 	apellido[AUTOR_LEN];
} Autor;

typedef struct
{
	char 	titulo[TITULO_LEN];
	int 	anioPublicacion;
	Autor 	autor;
} Libro;

//0
int menu();
void pausa();
//1
void agregarNuevoLibro(Libro**,int*);
//2
void mostrarListaDeLibros(Libro*,int);
//3
void modificarLibro(Libro**,int);
//4
void eliminarLibro(Libro**,int*);

//
void mostrarLibro(Libro,int);
void ingresarLibro(Libro*);


int main() {
	Libro* biblioteca = NULL;
	int longitud = 0;
    int opcion;
    
	do {
		opcion = menu();
		system("cls");
		
		switch (opcion) {
		case OPCION_SALIR:
		    break;

		case OPCION_ADD_LIBRO:
			agregarNuevoLibro(&biblioteca, &longitud);
			break;

		case OPCION_MOSTRAR_LIBROS:
			mostrarListaDeLibros(biblioteca, longitud);
			pausa();
			break;

		case OPCION_ACTUALIZAR_LIBRO:
			modificarLibro(&biblioteca, longitud);
			break;

		case OPCION_BORRAR_LIBRO:
			eliminarLibro(&biblioteca, &longitud);
			break;

		default:
            printf("NO DEBERIAS ESTAR AQUI");
		}

		system("cls");
	} while (opcion != OPCION_SALIR);  // 

	free(biblioteca);
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
		printf("- - - - BIBLIOTECA CHICHACHONA - - - -\n");
		printf("\t[0] Salir.\n");
		printf("\t[1] Agregar un libro nuevo.\n");
		printf("\t[2] Mostrar lista de libros.\n");
		printf("\t[3] Modificar un libro en la lista.\n");
		printf("\t[4] Eliminar un libro de la lista.\n");
		printf("- - - - BIBLIOTECA CHICHACHONA - - - -\n");
		scanf(" %d", &opcion);
		while(getchar()!='\n');
	} while(opcion <= MENU_MIN && opcion >= MENU_MAX);
	return opcion;
}

void pausa()
{
	fflush(stdin);
 	printf("Pulsa ENTER para continuar.\n");
 	while(getchar()!='\n');
}

//1
void agregarNuevoLibro(Libro* (*biblioteca), int (*contador))
{
	(*contador)++;
	(*biblioteca) = (Libro*)realloc( (*biblioteca), (*contador)*sizeof(Libro));
	
	if ((*biblioteca) == NULL)
	{
		printf("ERROR.");
	}
	else
	{
		ingresarLibro(&(*biblioteca)[(*contador)-1]);
	}
}

//2
void mostrarListaDeLibros(Libro* libro, int contador) {
	if (contador==0)
	{
		puts("Lista vacia, inserte algunos libros...\n");
	}
	else
	{
	printf("[%s]-[%-20s]-[%-5s]-[%-25s]-[%-25s]\n",
				"Ind",
				"Titulo",
				"Anyo",
				"Nombre",
				"Apellido");
		for(int i = 0; i<contador ; i++) {
			mostrarLibro(libro[i], i);
		}
		puts("");
	}
}

//3
void modificarLibro(Libro *(*libro), int contador){
	int idx;

	if (contador!=0)
	{
		do
		{
			printf("Qué libro desea eliminar?\n");
			mostrarListaDeLibros((*libro),contador);
			scanf("%d", &idx);	
			if(idx > contador || idx < 0)
			{
				printf("Indice fuera de rango [0 - %2d]\n", contador );
			}
		}while( ( contador < idx) || (idx < 0) );
		system("cls");
		ingresarLibro( &(*libro)[idx-1] );
		system("cls");
		printf("Nuevo libro:\n");
		mostrarLibro((*libro)[idx-1],idx-1);
	}
	else
	{
		printf("No hay libros en la biblioteca...\n");
	}
	pausa();
}

//4
void eliminarLibro(Libro *(*libro), int (*contador)){
	int idx;

	if ( (*contador) !=0)
	{
		do
		{
			printf("Qué libro desea eliminar?\n");
			mostrarListaDeLibros((*libro), (*contador) );
			scanf("%d", &idx);	
			if(idx >  (*contador)  || idx < 0)
			{
				printf("Indice fuera de rango [0 - %2d]\n",  (*contador)  );
			}
		}while( (  (*contador)  < idx) || (idx < 0) );
		system("cls");
		
		for (int i = (idx-1); i < (*contador); i++)
		{
			(*libro)[i] = (*libro)[i+1];
		}
		(*contador)--;
		(*libro) = (Libro*)realloc( (*libro), (*contador)*sizeof(Libro));
	}
	else
	{
		printf("No hay libros a eliminar...\n");
	}
	pausa();
}

//1s
void ingresarLibro(Libro* libro)
{
	printf("Ingrese el título del libro: ");
	scanf(" %[^\n]", libro->titulo);
	do
	{
		printf("Ingrese el año de publicación: ");
		scanf("%d", &libro->anioPublicacion);
		if (libro->anioPublicacion < -3000 || libro->anioPublicacion>2100)
		{
			printf("Fuera de rango [-3000 - 2100]\n");
		}
	} while (libro->anioPublicacion< -3000 || libro->anioPublicacion > 2100);
	printf("Ingrese el nombre del autor: ");
	scanf(" %[^\n]", libro->autor.nombre);
	printf("Ingrese el apellido del autor: ");
	scanf(" %[^\n]", libro->autor.apellido);
}

//2s
void mostrarLibro(Libro libro, int indice) {
	printf("[%3d]-[%-20s]-[%5d]-[%-25s]-[%-25s]\n",
		indice+1,
		libro.titulo,
		libro.anioPublicacion,
		libro.autor.nombre,
		libro.autor.apellido);
}