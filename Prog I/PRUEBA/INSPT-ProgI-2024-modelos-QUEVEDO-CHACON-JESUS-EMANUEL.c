#include "codigo_examen.c"
/*
Primero se debe poder leer el coche con scanf, luego mostrar el m�s viejo, y finalmente poder mostrar los mismos modelos
*/

int main()
{
    Auto coche[BUFFER];
    cadena ruta = "../modelos.txt";

    int cantidadReal = cargarDatos(coche, ruta);
    modeloAntiguo(coche, cantidadReal);
    listarAutos(coche, cantidadReal);
    return 0;
}

