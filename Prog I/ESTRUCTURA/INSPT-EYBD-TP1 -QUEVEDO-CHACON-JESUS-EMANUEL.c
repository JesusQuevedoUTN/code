#include "codigo_examen.c"

//1. Mostrar los corredores
//2. Mostrar los tiempos de carrera

//Programa Corredor Tiempo

int main()
{
    Programa    aplicacion = { "NATASHA ALABRA" , "REINO CHAMPI" , 1.0 };
    Corredor    venidor = { 69 , "JESUS" , "QUEVEDO" , "River Plate" };
    Tiempo      minutos = { 1 , 69 , 2.645 };

    menu(aplicacion);
    mostrarCorredor(venidor);
    mostrarTiempo(minutos);

    return 0;
}
