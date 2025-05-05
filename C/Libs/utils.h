#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include<stdio.h> //stdio.h significa standar input-output. Header(caneceras)
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void limpiarBuffer();

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER

int LeerEntero();
float LeerFloat();
char LeerCaracter();

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//LEER ENTRE...


//min + MAX + mensaje
int LeerEnteroEntre(int,int);
//min + MAX + mensaje
float LeerFloatEntre(float,float);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CONFIRMAR

// a=a
int esLetra(char);
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
void inicializarVectorDeEnteros(int*,int);
//mensaje + vec + long
void leerVectorDeEnteros(char*,int*,int);
//mensaje + vec + long
void leerVectorDeFloats(char*,float*,int);
//mensaje + vec + long
void leerVectorDeCaracteres(char*,char*,int);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//ORDENAR VECTOR ASC Y DESC

//vec + long
void ordenarVectorDeEnterosAscendente(int*, int);

//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//CONTADORVECTORES

// vec + long
int contadorDeLetras(char*, int);


//0-0-0-0-0-0-0-0-0 SEPARADOR 0-0-0-0-0-0-0-0-0-0-0
//char*S

// puts Mensaje + char*
void leerCadena(char*, char*);


#endif//UTILS_H_INCLUDED