#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include<stdio.h> //stdio.h significa standar input-output. Header(caneceras)
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


typedef char* cadena [50];

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER


//INT
//Mensaje+INT
int LeerEntero(char*);
//*INT+Mensaje
void LeerEnteroVoid(int*,char*);

//FLOAT
//Mensaje+FLOAT
float LeerFloat(char*);
//*FLOAT+Mensaje
void LeerFloatVoid(float*,char*);

//CHAR
//Mensaje+CHAR
char LeerCaracter(char*);
void LeerCaracterVoid(char*,char*);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER ENTRE...


//min + MAX + mensaje
int LeerEnteroEntre(int,int,char*);
//min + MAX + mensaje
float LeerFloatEntre(float,float,char*);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//MAYOR A...


//Mayor a... + Mensaje
int LeerEnteroMayorA(int,char*);
int LeerFloatMayorA(float,char*);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CONFIRMAR

// [S/N]
int confirmaUsuario(char*);
// a=a
int esLetra(char);
// meter vector y posicion
int esPalabra(char[], int);
// num
int esPrimo(int);
// chars
int sonIgualesCaracteres(char, char);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//PROMEDIO

// a/b
float promedio(int, int);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CAMBIAR POSICION

// a<- aux ->b
void cambiarPosicionDeEnteros(int*, int*);
void cambiarPosicionDeCaracteres(char*, char*);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//VECTORES

// vector
void inicializarVectorDeEnteros(int[],int);
//mensaje + vec + long
void leerVectorDeEnteros(char*,int[],int);
//mensaje + vec + long
void leerVectorDeFloats(char*,float[],int);
//mensaje + vec + long
void leerVectorDeCaracteres(char*,char[],int);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//VECTORES ENTRE

// min + maxmensaje + vec + long
void leerVectorDeEnterosEntre(int,int,char*, int[], int);
// min + maxmensaje + vec + long
void leerVectorDeFloatsEntre(float valorMin, float valorMax, char* mensaje, float vec[], int cant);

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
//char*S

// puts Mensaje + char*
void leerCadena(char*, char*);
// puts Mensaje + char*
void leerCadenaEntre(int, int, char*, char*);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//MATRICES

//mensaje, cant filas y columnas y la matriz
void leerMatrizDeEnteros(char* mensaje, int f, int c, int mat[f][c]);
//mensaje, cant filas y columnas y la matriz
void leerMatrizDeFloats(char* mensaje, int f, int c, float mat[f][c]);
// Muestra en forma de matriz INT con formato [f][c]
void mostrarMatrizDeEnteros(int f, int c, int mat[f][c]);
// Muestra en forma de matriz FLOAT con formato [f][c]
void mostrarMatrizDeFloats(int f, int c, float mat[f][c]);



#include"utils.c"
#endif//UTILS_H_INCLUDED
