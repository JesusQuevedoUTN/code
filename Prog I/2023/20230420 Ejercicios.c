#include<stdio.h>

int main()
{
    //1. Realizá  un  programa  que  muestre  todos  los  números  enteros  del 1 al 100,  y  luego,  los  mismos números, pero en orden inverso.
    /*for(int i=1;i<=100;i++){
    printf("%d \n", i);*/

    /*2. Realizá un programa que permita al usuario ingresar dos números enteros num1y num2, donde el primero siempre deberá ser menor o igual al segundo. La computadora
    debe mostrar la secuencia de números existentes entre ambos:
            a. Incluyéndolos    b. Excluyendolos*/
    /*int a, b;
    printf("Ingrese un valor\n");
    scanf("%d", &a);
    printf("Ahora ingrese un valor MAYOR que el primero\n");
    scanf("%d", &b);

 

    if(a<b){
        printf("\nSecuencia excluyendo los numeros\n");
        for(int i=a+1;i<b;i++){
            printf ("%d\n", i);
        }
        printf("\nSecuencia incluyendo los numeros\n");
        for(int i=a;i<=b;i++){
            printf ("%d\n", i);
        }
    }
    else{
        printf("Dije MAYOR");
    }*/

    //3. Realizá  un  programa  que  permita  al  usuario  ingresar unnúmeroentero nentre 1y 10.  La computadora debe mostrarla tabla de multiplicar de n.
    /*const int MENOR=1;
const int MAYOR=10;

 

int n;
printf("Ingrese un numero del 1 al 10\n");
scanf("%d", &n);
printf("\nSecuencia\n");
if(n<=MAYOR && n>=MENOR){
for (int i=1;n*i<=100;i++){
    printf("%d \n", i*n);
}
}
else{
    printf("Te zarpaste");
}*/

    //4. Realizá  un  programa  que  permita  al  usuario ingresar 5edades. La  computadora  debe  indicar cuántas edades fueron valores impares mayores que 18.
    /*const int CANT_VECES = 5;
    const int EDAD_BUSCADA = 18;
    int edad;
    int contEdadesQueCumplen = 0;
    for (int cont = 1; cont <= CANT_VECES; cont++) {
        printf("Ingrese la edad nro %d: ", cont);
        scanf("%d", &edad);
        // Proceso la edad
        if (edad % 2 != 0 && edad >= EDAD_BUSCADA) {
            contEdadesQueCumplen++;
        }        
    }
    printf("Hubo %d edades impares mayores que %d\n",contEdadesQueCumplen,EDAD_BUSCADA);*/

    /*5. Realizá un programa que permita al usuario ingresar un númeroenterocant. Acto seguido, que permitaingresar cantnúmeros reales,   correspondientes   a   las ventas
    realizadas   por   cierto vendedor. La computadora debe mostrarel total de las ventas.*/
    /*int num, ventas, totalVentas=0;
printf("Cuantas ventas hubo?\n");
scanf("%d", &num);
for(int i=0;i!=0 && i<=num;i++){
    printf("Ingresar una venta\n");
    scanf("%d", &ventas);
    totalVentas = totalVentas+ventas;
    i++;
}
    printf("Ganaste $%d", totalVentas);*/

    /*6. Realizá un programa que permita al usuario ingresar un númeroenterocant. Acto seguido, que permitaingresar cantnúmeros reales, correspondientes a las estaturas de
    un equipo de jugadores de baloncesto (en metros). La computadora debe mostrarla estaturapromedio.*/
    /*int num, ventas, totalVentas=0;
printf("Cuantas ventas hubo?\n");
scanf("%d", &num);
for(int i=0;i!=0 && i<=num;i++){
    printf("Ingresar una venta\n");
    scanf("%d", &ventas);
    totalVentas = totalVentas+ventas;
    i++;
}
    printf("Ganaste $%d", totalVentas);*/

    /*7. Realizá un programa que permita al usuario ingresar un número entero cant. Acto seguido, que permitaingresar cantnúmerosenteros. La computadora debe mostrarcuál
    fue el mayornúmeroy en qué posiciónapareció.*/
    /*int num, ventas, totalVentas=0;
printf("Cuantas ventas hubo?\n");
scanf("%d", &num);
for(int i=0;i!=0 && i<=num;i++){
    printf("Ingresar una venta\n");
    scanf("%d", &ventas);
    totalVentas = totalVentas+ventas;
    i++;
}
    printf("Ganaste $%d", totalVentas);*/

    //8. Realizá un programa que permita al usuario ingresar un  número natural. La computadora debe mostrarel factorial del número.
    /*int factorial, resultado = 1;
    printf("Ingresa un numero natural:\n");
    scanf("%d", &factorial);
    for (int i = 1; i<factorial; i++)
    {
        resultado = resultado + i*resultado;
    }
    printf("El resultado es %d", resultado);*/
    

    //ESTE ES IMPORTANTE IMPORTANTE PORQUE ENSEÑA A HACER UN CODIGO BIEN HECHO, PORQUE EL WHILE AQUI SE DEBE USAR PORQUE PARA USAR EL FOR, SE DEBE TRUCAR, Y ESO ESTA MAL
    /*9. Realizá un programa que permita al usuario ingresar un número natural n. La computadoradebe mostrar los  primeros nmúltiplos  de 3excepto  aquellos  que  sean  a
    la  vez  múltiplos  de 5.*/
    /*int multi, cant;

    multi = 0;

    printf("Cuantos multiplos queres: ");
    scanf("%d", &cant);

    int cont = 1;
    while (cont <= cant) {
        multi += 3; // multi = multi + 3;
        if (multi % 5 != 0) {
            printf("%d ", multi);
            cont++; // Solo cuenta si lo muestro, sino se queda quieto
        }
    }

    // No es semántico: La cabecera del for expresa una cantidad de ciclos, pero en la ejecución serán más...
    /*for (int cont = 1; cont <= cant; cont++) {
        multi += 3; // multi = multi + 3;
        if (multi % 5 != 0) {
            printf("%d ", multi);
        } else {
            //cont--; // Forma 1
            cant++; // Forma 2
        }
    }*/

    return 0;
}

