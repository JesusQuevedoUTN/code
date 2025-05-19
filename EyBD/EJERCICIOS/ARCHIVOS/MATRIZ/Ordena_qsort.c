#include <stdio.h>
#include <stdlib.h>

int compararEnteros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int vec[] = {5, 2, 9, 1, 3};
    int n = 5;

    qsort(vec, n, sizeof(int), compararEnteros);

    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);

    return 0;
}

/*
typedef struct {
    int codigo;
    char nombre[30];
} Producto;

int compararProductosPorCodigo(const void *a, const void *b) {
    Producto *p1 = (Producto *)a;
    Producto *p2 = (Producto *)b;
    return p1->codigo - p2->codigo;
}

*/