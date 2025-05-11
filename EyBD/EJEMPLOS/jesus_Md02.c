#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char apellido[50];
} Autor;

typedef struct {
    char titulo[100];
    int anioPublicacion;
    Autor autor;
} Libro;

int menu(void);
void agregarLibro(int *, Libro **);
void modificarLibro(int, Libro **);
void eliminarLibro(int *, Libro **);
void mostrarLibros(int, Libro *);

int main() {
    int op;
    Libro *libros = NULL;
    int cantLibros = 0;

    do {
        op = menu();
        system("cls");
        switch (op) {
            case 1:
                agregarLibro(&cantLibros, &libros);
                break;
            case 2:
                mostrarLibros(cantLibros, libros);
                system("pause");
                break;
            case 3:
                modificarLibro(cantLibros, &libros);
                break;
            case 4:
                eliminarLibro(&cantLibros, &libros);
                break;
        }
    } while (op != 5);
    
    free(libros);
    return 0;
}

int menu() {
    int op;
    do {
        printf("\n\t\t\t MENU DE OPCIONES\n");
        printf("\n\t\t - Agregar Libro            <1>\n");
        printf("\n\t\t - Mostrar Libros           <2>\n");
        printf("\n\t\t - Modificar Libro          <3>\n");
        printf("\n\t\t - Eliminar Libro           <4>\n");
        printf("\n\t\t - Salir                    <5>\n");
        printf("\n\t\t   Ingrese Opcion [1-5]:  ");
        scanf("%d", &op);
    } while (op < 1 || op > 5);
    return op;
}

void agregarLibro(int *numLibros, Libro **libros) {
    *numLibros += 1;
    *libros = (Libro *)realloc(*libros, (*numLibros) * sizeof(Libro));
    
    if (*libros == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    
    printf("\nIngrese el título del libro: ");
    scanf(" %[^\n]", (*libros)[*numLibros - 1].titulo);
    printf("Ingrese el año de publicación: ");
    scanf("%d", &(*libros)[*numLibros - 1].anioPublicacion);
    printf("Ingrese el nombre del autor: ");
    scanf(" %[^\n]", (*libros)[*numLibros - 1].autor.nombre);
    printf("Ingrese el apellido del autor: ");
    scanf(" %[^\n]", (*libros)[*numLibros - 1].autor.apellido);
}

void mostrarLibros(int numLibros, Libro *libros) {
    if (numLibros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
    for (int i = 0; i < numLibros; i++) {
        printf("\nLibro %d:\n", i + 1);
        printf("Título: %s\n", libros[i].titulo);
        printf("Año de Publicacion: %d\n", libros[i].anioPublicacion);
        printf("Autor: %s %s\n", libros[i].autor.nombre, libros[i].autor.apellido);
    }
}

void modificarLibro(int numLibros, Libro **libros) {
    int idx;
    if (numLibros == 0) {
        printf("No hay libros para modificar.\n");
        return;
    }
    printf("Ingrese el numero de libro a modificar (1-%d): ", numLibros);
    scanf("%d", &idx);
    if (idx < 1 || idx > numLibros) {
        printf("Número inválido.\n");
        return;
    }
    idx--; 
    // aca reducimos porque sino el usuario 
    //lo deja pasado en 1

    printf("\nIngrese el nuevo título: ");
    scanf(" %[^\n]", (*libros)[idx].titulo);
    printf("Ingrese el nuevo año de publicación: ");
    scanf("%d", &(*libros)[idx].anioPublicacion);
    printf("Ingrese el nuevo nombre del autor: ");
    scanf(" %[^\n]", (*libros)[idx].autor.nombre);
    printf("Ingrese el nuevo apellido del autor: ");
    scanf(" %[^\n]", (*libros)[idx].autor.apellido);
}

void eliminarLibro(int *numLibros, Libro **libros) {
    int idx;
    if (*numLibros == 0) {
        printf("No hay libros para eliminar.\n");
        return;
    }
    printf("Ingrese el número de libro a eliminar (1-%d): ", *numLibros);
    scanf("%d", &idx);
    if (idx < 1 || idx > *numLibros) {
        printf("Número inválido.\n");
        return;
    }
    idx--;
    for (int i = idx; i < *numLibros - 1; i++) {
        (*libros)[i] = (*libros)[i + 1];
    }
    *numLibros -= 1;
    *libros = (Libro *)realloc(*libros, (*numLibros) * sizeof(Libro));
    if (*numLibros > 0 && *libros == NULL) {
        printf("Error al reasignar memoria.\n");
        exit(1);
    }
    printf("Libro eliminado correctamente.\n");
}
