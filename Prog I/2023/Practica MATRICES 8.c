#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

#define N 4

void zigzag(int mat[N][N]);
void zigzagV(int mat[N][N]);
int par(int i);
void mostrarVector(int vec[]);
void mostrarVectorAlReves(int vec[]);
void mostrarVectorDeEnterosInicioAFin(int vec[], int inicio, int fin);
void mostrarColumnaDeEnterosInicioAFin(int vec[], int inicio, int fin);


int main()
{
    int matriz[N][N] =  {
        { 1,2,3,4 }, 
        { 6,5,4,3 }, 
        { 9,6,6,9 }, 
        { 4,2,6,8 }
    };
    /*
    zigzag(matriz);
    puts("");
    zigzagV(matriz);
    puts("");
    espiral(matriz);
    */
    mostrarVectorDeEnterosInicioAFin(matriz[1], 1, 1);

    
    return 0;
}

void zigzag(int mat[N][N]){
    for (int i = 0; i < N; i++)
    {
        if (par(i))
        {
            mostrarVectorAlReves(mat[i]);
        }
        else
        {
            mostrarVector(mat[i]);
        }
        puts("");
    } 
}
void zigzagV(int mat[N][N]){
    for (int i = 0; i < N; i++)
    {
        if (i%2!=0)
        {
            for (int j = N-1; j >= 0; j--)
            {
                printf("%d ", mat[j][i]);
            }
        }
        else
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", mat[j][i]);
            }
        }
        puts("");
    }
}
int par(int i){
    return i%2!=0;
}
void mostrarVector(int vec[]) {
    for (int i = 0; i < N; i++)
    {
    printf("%d ", vec[i]);
    }
}
void mostrarVectorAlReves(int vec[]) {
    for (int j = N-1; j >= 0; j--)
    {
        printf("%d ", vec[j]);
    }
}


void espiral(int matriz[N][N]){
    int inicio, fin=N;
    for (int i = 0; i < (N*2)-1; i++)
    {
        inicio=i;
        mostrarVectorDeEnterosInicioAFin(matriz[N], inicio, fin);
        fin--;
    }
}


void mostrarVectorDeEnterosInicioAFin(int vec[], int inicio, int fin) {
    for (int i = inicio; i <= fin; i++)
    {
    printf("%d ", vec[i]);
    }
}
void mostrarColumnaDeEnterosInicioAFin(int vec[], int inicio, int fin) {
    for (int i = inicio; i < fin; i++)
    {
    printf("%d ", vec[i]);
    }
}