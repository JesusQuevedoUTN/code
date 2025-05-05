#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int *arr,i;
    arr = (int*) malloc(10 * sizeof(int));
    srand(time(NULL));// semilla aleatoria
    if (arr == NULL) {
        return 1;
    }
    for(i=0;i<sizeof(arr);i++)
    {
        arr[i]=rand()%(100-1+1)+1;
        printf("%d\n",arr[i]);
    }
    arr = (int*) realloc(arr, 20 * sizeof(int)); // Cambiar el tamaño para 20 enteros
    if (arr == NULL) {
        // Manejo de error
        return 1;
    }
    // Uso de la memoria
    free(arr); // Liberar la memoria
    return 0;
}
