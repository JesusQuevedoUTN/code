#include "Libs/utils.h"
/*
9) (VER TEMPLATE) Un taller mecánico desea visualizar algunos datos sobre los automóviles que
tiene registrados. De cada uno de ellos se sabe:
▪ Patente
▪ Marca y modelo
▪ Kms. recorridos
▪ Datos del motor
Del motor se saben los siguientes datos, de forma independiente:
▪ Número ▪ Cilindrada ▪ Tipo
Realizá un programa que permita listar:
A) Marca-modelo y cilindrada de los automóviles con cilindrada mayor a 1.8.
B) Números de motor de tipo Diesel.
C) Patente y tipo de motor de los automóviles con menos de 10000 kms. recorridos
*/

// Definir el/los structs
// Definir prototipos de las funciones

#define CANT_AUTOS 8 // NO MODIFICAR

typedef struct 
{
    cadena numero;
    double cilindrada;
    cadena tipo;
}Motor;

typedef struct 
{
    cadena patente;
    cadena marca;
    int km;
    Motor datos;
}Auto;

//A
void mostrarMayorA(Auto coches[]);
void mostrarCoche(Auto coche);
//B
void diesel(Auto coche[]);
void mostrarMotor(Auto coche);
//C
void masDeMil(Auto coche[]);

int main () {

    /* NO MODIFICAR LOS DATOS */
    Auto autos[] = {  {"99MZB56","Ford Fiesta",       31716,  {"656740643971",1.6,"Nafta"}    },
                      {"93TGP72","Volkswagen Gol",    24507,  {"620683689225",1.4,"Nafta"}    },        
                      {"17FFM19","Peugeot 207",       2235,   {"996627052576",1.6,"Diesel"}   },    //B//C
                      {"46PHV16","Fiat Siena",        7686,   {"840695252470",2.0,"Nafta"}    }, //A   //C
                      {"51GIJ93","Chevrolet Astra",   48648,  {"177398540898",2.0,"Nafta"}    }, //A
                      {"10SYY34","Ford Focus",        52223,  {"191935834594",1.8,"Diesel"}   }, //A//B
                      {"63AEO63","Citroen C4",        43545,  {"523891265769",1.6,"Diesel"}   },    //B
                      {"38JOZ38","Volkswagen Golf",   28701,  {"529629178123",2.0,"Nafta"}    }};//A

    mostrarMayorA(autos);
    puts("");
    diesel(autos);
    puts("");
    masDeMil(autos);
    return 0;
}

//A) Marca-modelo y cilindrada de los automóviles con cilindrada mayor a 1.8.
void mostrarMayorA(Auto coche[]){
    for (int i = 0; i < CANT_AUTOS; i++)
    {
        mostrarCoche(coche[i]);
    }
}
void mostrarCoche(Auto coche){
    if (coche.datos.cilindrada >= 1.8)
    {
        puts(coche.marca);
    }
}
//B) Números de motor de tipo Diesel.
void diesel(Auto coche[]){
    for (int i = 0; i < CANT_AUTOS; i++)
    {
        mostrarMotor(coche[i]);
    }
}
void mostrarMotor(Auto coche){
    if (!strcmp(coche.datos.tipo,"Diesel"))
    {
        puts(coche.datos.numero);
    }
}
//C)Patente y tipo de motor de los automóviles con menos de 10000 kms. recorridos
void masDeMil(Auto coche[]){
    for (int i = 0; i < CANT_AUTOS; i++)
    {
        if (coche[i].km < 10000)
        {
            puts(coche[i].patente);
            puts(coche[i].datos.tipo);
        }
        puts("");
    }
}