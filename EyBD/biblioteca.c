#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar el autor
typedef struct {
    char nombre[50];
    char apellido[50];
} Autor;

// Estructura para almacenar el libro
typedef struct {
    char titulo[100];
    int anioPublicacion;
    Autor autor;
} Libro;

// Función para agregar un libro a la lista
void agregarLibro(Libro **libros, int *nLibros) {
    *nLibros += 1; // Aumentamos el contador de libros
    *libros = realloc(*libros, *nLibros * sizeof(Libro)); // Redimensionamos la memoria

    Libro nuevoLibro;
    printf("Introduce el título del libro: ");
    getchar(); // Para limpiar el buffer
    fgets(nuevoLibro.titulo, 100, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = 0; // Eliminar el salto de línea

    printf("Introduce el año de publicación: ");
    scanf("%d", &nuevoLibro.anioPublicacion);

    printf("Introduce el nombre del autor: ");
    getchar(); // Limpiar el buffer
    fgets(nuevoLibro.autor.nombre, 50, stdin);
    nuevoLibro.autor.nombre[strcspn(nuevoLibro.autor.nombre, "\n")] = 0;

    printf("Introduce el apellido del autor: ");
    fgets(nuevoLibro.autor.apellido, 50, stdin);
    nuevoLibro.autor.apellido[strcspn(nuevoLibro.autor.apellido, "\n")] = 0;

    // Guardamos el nuevo libro en la lista
    (*libros)[*nLibros - 1] = nuevoLibro;
    printf("Libro agregado correctamente.\n");
}

// Función para mostrar todos los libros
void mostrarLibros(Libro *libros, int nLibros) {
    if (nLibros == 0) {
        printf("No hay libros en la lista.\n");
        return;
    }

    for (int i = 0; i < nLibros; i++) {
        printf("Libro %d:\n", i + 1);
        printf("Título: %s\n", libros[i].titulo);
        printf("Año de publicación: %d\n", libros[i].anioPublicacion);
        printf("Autor: %s %s\n\n", libros[i].autor.nombre, libros[i].autor.apellido);
    }
}

// Función para modificar un libro existente
void modificarLibro(Libro *libros, int nLibros) {
    int index;
    printf("Introduce el número del libro a modificar (1-%d): ", nLibros);
    scanf("%d", &index);

    if (index < 1 || index > nLibros) {
        printf("El libro no existe.\n");
        return;
    }

    index--; // Para ajustar al índice del arreglo

    printf("Modificar el título del libro: ");
    getchar(); // Limpiar el buffer
    fgets(libros[index].titulo, 100, stdin);
    libros[index].titulo[strcspn(libros[index].titulo, "\n")] = 0;

    printf("Modificar el año de publicación: ");
    scanf("%d", &libros[index].anioPublicacion);

    printf("Modificar el nombre del autor: ");
    getchar(); // Limpiar el buffer
    fgets(libros[index].autor.nombre, 50, stdin);
    libros[index].autor.nombre[strcspn(libros[index].autor.nombre, "\n")] = 0;

    printf("Modificar el apellido del autor: ");
    fgets(libros[index].autor.apellido, 50, stdin);
    libros[index].autor.apellido[strcspn(libros[index].autor.apellido, "\n")] = 0;

    printf("Libro modificado correctamente.\n");
}

// Función para eliminar un libro
void eliminarLibro(Libro **libros, int *nLibros) {
    int index;
    printf("Introduce el número del libro a eliminar (1-%d): ", *nLibros);
    scanf("%d", &index);

    if (index < 1 || index > *nLibros) {
        printf("El libro no existe.\n");
        return;
    }

    index--; // Ajustar el índice al arreglo

    for (int i = index; i < *nLibros - 1; i++) {
        (*libros)[i] = (*libros)[i + 1]; // Desplazar libros
    }

    *nLibros -= 1; // Reducir el número de libros
    *libros = realloc(*libros, *nLibros * sizeof(Libro)); // Redimensionar la memoria
    printf("Libro eliminado correctamente.\n");
}

int main() {
    Libro *libros = NULL;  // Puntero a la lista de libros
    int nLibros = 0;       // Contador de libros
    int opcion;

    do {
        printf("\nGestión de Biblioteca\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Modificar libro\n");
        printf("4. Eliminar libro\n");
        printf("5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarLibro(&libros, &nLibros);
                break;
            case 2:
                mostrarLibros(libros, nLibros);
                break;
            case 3:
                modificarLibro(libros, nLibros);
                break;
            case 4:
                eliminarLibro(&libros, &nLibros);
                break;
            case 5:
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    // Liberar memoria dinámica
    free(libros);
    return 0;
}
