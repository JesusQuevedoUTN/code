/*
cargar una matriz cuadrada de 5x5
con valores aleatorios entre 1 y 100
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
void CargarMatriz(int[N][N]);
void InformarMatriz(int[N][N]);
void ordenar(int [],int );
void pausa(void);
void cargarVector(int [N][N], int [N*N]);
void cargarMatrizOrdenada(int [N][N],int [N]);

int main()
{
    int mat[N][N]={0};
    int aux[N*N];
    srand(time(NULL));
    printf("\nMatriz Vacia\n");
    InformarMatriz(mat);
    pausa();
    CargarMatriz(mat);
    printf("\nMatriz Cargada\n");
    InformarMatriz(mat);
    cargarVector(mat,aux);
    ordenar(aux,N*N);
    cargarMatrizOrdenada(mat,aux);
    printf("\nMatriz Ordenada\n");
    InformarMatriz(mat);
    pausa();
    return 0;
}

void CargarMatriz(int m[N][N])
{
    int i,j,cs=100,ci=1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            m[i][j]=rand()%(cs-ci+1)+ci;
        }
    }
}
void InformarMatriz(int m[N][N])
{
// visualizamos la matriz
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}
void cargarVector(int Matriz[N][N], int vec[N*N]) 
{
    int cont=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
        {
           vec[cont]=Matriz[i][j];
           cont++;
        }
    }
}
void cargarMatrizOrdenada(int matriz[N][N],int vec[N])
{
    int c=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j] = vec[c];
            c++;
        }
    }
}
void ordenar(int x[],int y)		
{		
	// y posse laa cantidad de valores a Ordenar
    int i,cota=y-1,k=1,aux;	// k es una bandera, que me indica que se termino de ordenar
	while(k)	
	{	
	        k=0;	// partimos del supuesto que esta ordenado
	        for(i=0;i<cota;i++)	
	        {	
	            if(x[i]>x[i+1])	
	            {	
	                // aqui se produce el swap
                    aux=x[i];	
	                x[i]=x[i+1];	
	                x[i+1]=aux;	
	                k=i;	// aqui k toma el valor donde fue ordenado por ultima vez
	            }	
	       }	
	cota=k;	// aqui se lo pasa a cota, con lo cual lo limita en las iteracioners
	}	
}	
void pausa(void)
{
    printf("\nPresione Enter para continuar...");
    fflush(stdin);
    getchar();
}