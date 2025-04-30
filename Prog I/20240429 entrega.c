#include "codigo.c"

//1. mostrar el archivo de texto
//2. generar un archivo binario que contenga los nombres del empleado y salario solo de VENTAS
//3. generar un informe con los que tienen oficiio EMPLEADO (empleados.txt) y otros con los demas empleados (otro.txt)


int main()
{
    cadena ruta = "../empleados.csv", modo = "rb";
    FILE* documento;
    Empleado empleados[MAX];
    
    abrirArchivo(&documento,ruta, modo);
    
    //1
    mostrarArchivo(documento, empleados);
    //2
    //generarArchivoBinario(documento, "VENTAS", "../nombres.dat");
    //3
    //generarInforme(documento,"EMPLEADO", "../empleados.txt", "../otro.txt");

    cerrarArchivo(documento,ruta);
    
    return 0;
}