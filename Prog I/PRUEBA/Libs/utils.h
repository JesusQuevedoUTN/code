#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h> //stdio.h significa standar input-output. Header(caneceras)
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef char cadena[50]; 
typedef char oracion[500]; 



//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER


//INT
//Mensaje+INT
int leerEntero(cadena mensaje);

//FLOAT
//Mensaje+FLOAT
float leerFloat(cadena mensaje);

//CHAR
//Mensaje+CHAR
char leerCaracter(cadena mensaje);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER ENTRE...


//min + MAX + mensaje
int leerEnteroEntre(int valorMin,int valorMax,cadena mensaje);
//min + MAX + mensaje
float leerFloatEntre(float valorMin, float valorMax, cadena mensaje);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//MAYOR A...


//Mayor a... + Mensaje
int leerEnteroMayorA(int numero,cadena mensaje);
int leerFloatMayorA(float numero,cadena mensaje);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CONFIRMAR

// [S/N]
int confirmaUsuario(cadena mensaje);
// a=a
int esLetra(char letra);
// meter vector y posicion
int esPalabra(char vec[], int x);
// num
int esPrimo(int primo);
// chars
int sonIgualesCaracteres(char x, char y);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//PROMEDIO

// a/b
float promedio(int total, int parcial);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CAMBIAR POSICION

// a<- aux ->b
void cambiarPosicionDeEnteros(int *x, int *y);
void cambiarPosicionDeCaracteres(char *x, char *y);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//VECTORES

// vector
void inicializarVectorDeEnteros(int vec[], int cant);
//mensaje + vec + long
void leerVectorDeEnteros(cadena mensaje, int vec[], int cant);
//mensaje + vec + long
void leerVectorDeFloats(cadena mensaje, float vec[], int cant);
//mensaje + vec + long
void leerVectorDeCaracteres(cadena mensaje, char vec[], int cant);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//VECTORES ENTRE

// min + maxmensaje + vec + long
void leerVectorDeEnterosEntre(int valorMin, int valorMax, cadena mensaje, int vec[], int cant);
// min + maxmensaje + vec + long
void leerVectorDeFloatsEntre(float valorMin, float valorMax, cadena mensaje, float vec[], int cant);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//MOSTRAR VECTOR
// vec+long
void mostrarVectorDeEnteros(int vec[], int cant);
// vec+long
void mostrarVectorDeFloats(float vec[], int cant);
// vec+long
void mostrarVectorDeCaracteres(char vec[], int cant);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//ORDENAR VECTOR ASC Y DESC

//vec + long
void ordenarVectorDeEnterosAscendente(int vec[], int cant);
//vec + long
void ordenarVectorDeEnterosDescendente(int vec[], int cant);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CONTADORVECTORES

// vec + long
int contadorDePalabras(char vec[], int cant);
// vec + long
int contadorDeLetras(char vec[], int cant);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CADENAS

// puts Mensaje + cadena
void leerCadena(cadena mensaje, cadena target);
// puts Mensaje + cadena
void leerCadenaEntre(int minLength, int maxLength, cadena mensaje, cadena target);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//MATRICES

//mensaje, cant filas y columnas y la matriz
void leerMatrizDeEnteros(cadena mensaje, int f, int c, int mat[f][c]);
//mensaje, cant filas y columnas y la matriz
void leerMatrizDeFloats(cadena mensaje, int f, int c, float mat[f][c]);
// Muestra en forma de matriz INT con formato [f][c]
void mostrarMatrizDeEnteros(int f, int c, int mat[f][c]);
// Muestra en forma de matriz FLOAT con formato [f][c]
void mostrarMatrizDeFloats(int f, int c, float mat[f][c]);

//abre archivo, puntero, ubicacion, modo
void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo);
//cierra archivo, puntero
void cerrarArchivo(FILE* pArch, cadena ruta);

void limpiarCadena(cadena texto);


/*               %%%%%=                   
               @@@@@@@@   =@@%%-          
              @@@@@@@@@@%@@@@@@@          
             @@@@@@@@@@@@@@@@@@@@@%%%     
           %@@@@@@@@@@@@@@@@@@@@@@@@@%    
         %@@@@@@@@@@@@@@@@@@@@@@@@@@+     
        #@@@@@@@@@@@@@@@@@@@@@@@@%*       
       %@@@@@@@@@@@@@@@@@@@@@@@@          
      %@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%     
     @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@.  
    @@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@  
   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  
   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  
    %%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#    
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@       
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*     
     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+     
     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
      %%@@@@@@@@@@@@@@@@@@@@@@%%%@        
         *%%%%@%@%%%%%%%%%@%              */
//0-0-0-0-0-0-0-0-0 Jessus Quev 0-0-0-0-0-0-0-0-0-0-0 
void MARCA_DE_AGUA();

#include"utils.c"
#endif//UTILS_H_INCLUDED
