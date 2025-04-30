#include <stdio.h>

// /* 1. Realizá un programa que permita al usuario ingresar un número entero. La computadora debe
// informar el número opuesto1 y el número inverso2 del ingresado*/
// int main(int argc, char const *argv[])
// {
//     int n, o;
//     float i;
//     printf ("Ingrese un numero entero\n");
//     scanf ("%d", &n);
//     o = n*-1;
//     i = 1.0/n;
//     printf ("Entero:  %d \n", n);
//     printf ("Opuesto:  %d \n", o);
//     printf ("Inverso:  %f \n", i);
//     return 0;
// }

// /* 2. Realizá un programa que permita al usuario ingresar 3 notas pertenecientes a tres trimestres
//  distintos para cierto alumno. La computadora debe mostrar la nota promedio.*/
// int main(int argc, char const *argv[])
// {
//     int pt, st, tt;
//     float p=3;
//     printf ("Notas Jesus Quevedo: \n");
//     scanf ("%d", &pt);
//     scanf ("%d", &st);
//     scanf ("%d", &tt);
//     p = (pt+st+tt)/3;
//     printf ("Promedio: %1.2f", p);
//     return 0;
// }

// /* 3. Realizá un programa que permita al usuario ingresar el valor salarial de una hora de trabajo y la
// cantidad de horas trabajadas por día. La computadora debe mostrar el valor del salario semanal,
// asumiendo que trabaja todos los días hábiles y media jornada los sábados. */
// /*  - cuanto gana por hora?
//     - cuanto trabaja por dia? */
//     int main(int argc, char const *argv[])
//     {
//         float sueldo, salarioHoras;
//         int horasTrabajadas, totalHoras;
//         printf("Cuanto gana por hora? \n");
//         scanf ("%f", &sueldo);
//         printf("Cuanto trabaja por dia? \n");
//         scanf ("%d", &horasTrabajadas);
//         totalHoras = (horasTrabajadas*5)+(horasTrabajadas/2);
//         salarioHoras = totalHoras*sueldo;
//         printf("En total ganas: %.2f", salarioHoras);
//         return 0;
//     }

// /* 4. Realizá un programa que permita al usuario ingresar valores del mismo tipo para las variables a
//  y b. Una vez cargadas, la computadora debe mostrar ambas variables por pantalla, intercambiar
//  entre sí sus valores (que lo cargado en a quede en b, y viceversa), y volver a mostrarlas. */
//     int main(int argc, char const *argv[])
//     {
//         int a, b, aux;
//         printf("Ingrese dos valores: \n");
//         scanf("%d %d", &a, &b);
//         printf("a= %d b= %d\n", a, b);
//         aux= a;
//         a = b;
//         b = aux;
//         printf("a= %d b= %d", a, b);
//         return 0;
// }

// /* 5. Realizá un programa que permita al usuario ingresar el valor unitario de cierto artículo y la
//  cantidad de artículos vendidos por un vendedor, del cual se sabe que gana un sueldo fijo de $14000
//  más el 16% del monto total vendido. Con tales datos, la computadora debe calcular el sueldo
//  mensual del vendedor y mostrarlo. */
// int main(int argc, char const *argv[])
// {
//     float valorU, sueldo = 14000;
//     int cantidad;
//     printf("Cuanto vale el artitulo?\n");
//     scanf("%f", &valorU);
//     printf("Cuanto se vendio?\n");
//     scanf("%d", &cantidad);
//     sueldo = sueldo+((valorU*cantidad)*.16);
//     printf("El sueldo del vendedor es de $%.2f", sueldo);
//     return 0;
// }

// /* 6. Realizá un programa que permita al usuario ingresar el ancho y el largo de un terreno en metros
//  y el valor del metro cuadrado de tierra. La computadora debe mostrar el valor total del terreno y la
//  cantidad de metros de alambre que serían necesarios para cercarlo completamente en tres pasadas.*/
// int main(int argc, char const *argv[])
// {
//     float ancho, largo, metro, valor, alambre;
//     printf("Defina ancho y largo: \n");
//     scanf ("%f %f", &ancho, &largo);
//     printf("Cuanto vale el metro cubico?: \n");
//     scanf ("%f", &metro);
//     valor = (ancho*largo)*metro;
//     alambre = (ancho*2 + largo*2)*3;
//     printf("Valor del terreno: %.2f \nCantidad de alambre necesaria: %.2f", valor, alambre);
//    return 0;
// }

// /* 7. Realizá un programa que permita al usuario ingresar dos números enteros. La computadora debe
// mostrar los resultados de las 4 operaciones matemáticas básicas con tales números. */
// int main(int argc, char const *argv[])
// {
//     float x, y, division;
//     printf ("Ingresa dos enteros:\n");
//     scanf("%f %f", &x, &y);   
//     division = x/y;
//     printf ("Suma: %.f \nResta: %.f \nMultiplicacion: %.f \nDivision: %f", x+y, x-y, x*y, division);
//     return 0;
// }

// /* 8. Realizá un programa que permita al usuario ingresar dos números enteros, que representan las
// medidas en grados de dos ángulos interiores de cierto triángulo. La computadora debe mostrar el
// valor en grados del ángulo restante. */
// int main(int argc, char const *argv[])
// {
//     float faltante = 180, angulo, angel;
//     printf("Ingresa dos de los angulos de un triangulo:\n");
//     scanf ("%f %f", &angulo, &angel);
//     if (178>=angel>0 && 178>=angulo>0 )
//     {
//         faltante = faltante - angel - angulo;
//         printf("El angulo faltante equivale a: %.2f\n", faltante);
//     }
//     else{
//         printf("Error, no trolee hermano");
//     }
//     return 0;    
// }