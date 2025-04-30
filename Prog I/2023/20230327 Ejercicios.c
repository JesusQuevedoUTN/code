#include<stdio.h>

int main()
{
    //10.Realizá  un  programa  que  permita  validar  una  nota  de  examen. Se  espera  que  lanotaque  el usuario ingreseseaun número comprendido entre 0y 10.
    //La misma debe ser tantas veces ingresada como sean necesarias hasta que quedecomprendida dentro del rango descripto
    /*const int MIN_NOTA = 0;
    const int MAX_NOTA = 10;
    int nota;
    
    printf("Ingrese nota entre %d y %d: ", MIN_NOTA, MAX_NOTA);
    scanf("%d", &nota);
    while ( !(nota >= MIN_NOTA && nota <= MAX_NOTA) ) {
        printf("ERROR. Ingrese nota entre %d y %d: ", MIN_NOTA, MAX_NOTA);
        scanf("%d", &nota);
    }

    printf("Seguimos adelante con una nota %d\n", nota);*/
    
    //11.Realizá un programa que permita validar una nota de examen para cierta academia, de la misma manera que el ejercicio anterior, pero con la siguientes
    //nueva directiva:
    //Las notas válidas deberán ser el 2 y el rango comprendido entre el 4 y el 10
    /*const int MINIMO = 4;
    const int MAXIMO = 10;
    const int EXCEPCION = 2;
    int nota;
    printf("Ingrese la nota de su examen, esta debe estar entre %d y %d, o, ser %d\n", MINIMO, MAXIMO, EXCEPCION);
    scanf("%d", &nota);

    if (!((nota>=MINIMO && nota<=MAXIMO) || (nota==EXCEPCION)))
    {
        do
    {
        printf("La nota es INVALIDA meta un valor que sea %d, o que este entre %d y %d\n", EXCEPCION, MINIMO, MAXIMO);
        scanf("%d", &nota);
    } while (!((nota>=MINIMO && nota<=MAXIMO) || (nota==EXCEPCION)));

    }
    
    printf("La nota %d es valida", nota);*/
    
    //12.Realizáun programa que permita validar una opción ingresada. La computadora preguntará al usuario si desea continuar una operación de la forma
    //"¿Deseás continuar? [S/N]". Se espera que el usuario ingrese  una 'S'o una 'N'(incluir las minúsculas). La opción debe ser tantas veces ingresada   como
    //sean   necesarias   hasta   que   quede   comprendida   dentro   de   las   posibilidades esperadas.  Realizá  este  ejercicio  en  dos  versiones:  con
    //ciclo whiley  con  ciclo do-while
    /*const char SI = 'S';
    const char NO = 'N';
    char validar;
    printf("Desea continua? [%c/%c]\n", SI, NO);
    fflush(stdin);
    scanf("%c", &validar);

    if ((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32))
    {
        printf("Muchas Gracias");
    }*/
    
    //a. 
    /*if (!((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32)))
    {
        while (!((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32)))
        {
            printf("Acepte [%c/%c] \n", SI, NO);
            fflush(stdin);
            scanf("%c", &validar);
        }
        printf("Muchas Gracias por su paciencia");
    }*/

    //b.
    /*if (!((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32)))
    {
        do
        {
            printf("Acepte [%c/%c] \n", SI, NO);
            fflush(stdin);
            scanf("%c", &validar);
        } while (!((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32)));
        
        printf("Muchas Gracias por su paciencia");

    }*/
    

    //13.Realizá un programa que permita al usuario ingresar números hasta que se introduzca un 0. La computadoradebe mostrarelnúmeromáximo y el número mínimo
    /*const int DETENER=0;
    int minimo, maximo, numero;
    printf("Introduzca la cantidad de numeros que quiera, pulse %d cuando quiera detenerse\n", DETENER);
    scanf("%d", &numero);
    minimo=numero;
    maximo=numero;

    if (numero!=0)
    {
        do
        {
        scanf("%d", &numero);
        if (numero<minimo)
        {
            minimo=numero;
        }
        if (numero>maximo)
        {
            maximo=numero;
        }
        } while (numero!=0); 
    }
    printf("El minimo es: %d\nEl maximo es: %d", minimo, maximo);*/
    
    //14.Realizá  un  programa  que  permita  al  usuario  ingresar personas  (para  cada  una, la  inicial  de  su nombreysuedad). La  carga  termina  cuando
    //en la  inicial  delnombre  de  la  persona  se  ingresa  un asterisco ('*').La computadora debeindicar quién esla persona más joven.
    /*const char TERMINAR = '*';
    char inicial, nombre = ' ';
    int edad, joven = -1;

    printf("Bienvenido al sistema de edades, ingrese una inicial y un nombre para indicar quien es el mejor,\npulse ''%c'' para detener el sistema\n", TERMINAR);
    
    do
    {
        printf("Ingrese una inicial\n");
        fflush(stdin);
        scanf("%c", &inicial);
        
        if (inicial!=TERMINAR)
        {
            printf("Ingrese la edad\n");
            fflush(stdin);
            scanf("%d", &edad);
            if (edad<joven || joven==-1)
            {
                joven=edad;
                nombre=inicial;
            }
            
        }
        
    } while (inicial!=TERMINAR);
    
    if (joven!=-1)
    {
        printf("El menor es %c, y tiene %d anos\n", nombre, joven);
    }
    else
    {
        printf("Gracias y replantee su vida\n");
    }*/

    
    //15.Realizá un programa que permita al usuario ingresar números mientras el promedio entre todos los  ingresados sea  menor  a 20. La  computadora  debe
    //indicar  la  cantidad  de  valores  leídos.
        /*const float MENOR = 20.00;
        float promedio=0.00, valor, i=0.00;
        printf("Ingrese la cantidad de valores que desee mientras el promedio siga dando menos de %d\n", MENOR);

        do
        {
            i++;
            printf("Ingrese un valor\n");
            fflush(stdin);
            scanf("%f.2", &valor);
            promedio=(valor+promedio)/i;
            printf("El promedio es: %.2f\n", promedio);
        } while (promedio<MENOR);
        
        printf("En total se leyeron %.0f valores, bien hecho", i);*/
    
    //ESTE ME DIO PAJA HACER QUE CORROBORE QUE SOLO SEA SI O NO, SOLO HACE EL SI
    //16.Realizá  un  programa  que  permita  al  usuario  ingresar  números  enteros. Por  cada  cargadebepreguntarsi se desea seguir ingresando, de la forma
    //"¿Deseásingresar otro número? [S/N]". La  carga  de  datos  finaliza  cuando  se  detecta  una 'n'o 'N'. Reutilizá  el  algoritmo  realizado  en  el
    //ejercicio 12)para  validar  la  opción  ingresada. La  computadora  debe  mostrar el  porcentaje  de números pares ingresado
    /*const char SI = 'S';
    const char NO = 'N';
    char validar;
    int numero, pares;
    float o=0, i=0, promedio;

    do
    {
        printf("Desea ingresar un numero? [%c/%c]\n", SI, NO);
        fflush(stdin);
        scanf("%c", &validar);

        if (validar==SI || validar==SI+32)
        {
            printf("Ingrese un numero\n");
            fflush(stdin);
            scanf("%d", &numero);
            promedio=promedio+numero;
            if (numero%2==0)
            {
                i++;
            }  
            o++;
        } 
    } while ((validar==SI) || (validar==SI+32));
    
    if (i==0)
    {
        printf("Ninguno es par");
    }
    else
    {
    printf("%.2f por ciento de los numeros son pares", (i*100/o));
    }*/

    //17.Realizá  un  programa  que  permita  al  usuario ingresar  la  cantidad  de  cierto  artículo  y  el  precio unitario de dicho artículo. Por cada carga
    //debe preguntar si se desea seguir ingresando de la forma "¿Deseásingresar otro artículo? [S/N]". La carga de datos finaliza cuando se detecta una 'n'o 'N'.
    //Reutilizá  el  algoritmo  realizado  en  el  ejercicio 12)para  validar  la  opción  ingresada. La computadora debe mostrar el monto total del ticket
    
    /*const char SI = 'S';
    const char NO = 'N';
    char validar;
    float precio=0, cantidad, ticket=0;

    do
    {
    printf("Quiere ingresar un producto? [%c/%c]\n", SI, NO);
    fflush(stdin);
    scanf("%c", &validar);
    
    if ((validar==SI || validar==SI+32))
    {
        printf("Ingrese el precio\n");
        fflush(stdin);
        scanf("%f", &precio);
        printf("Ingrese la cantidad que hay\n");
        fflush(stdin);
        scanf("%f", &cantidad);
        ticket=ticket+precio*cantidad;
    }

    if ((validar==NO || validar==NO+32) && precio==0) {printf("Al menos lo dijo");}
    if ((validar==NO || validar==NO+32) && precio!=0) {printf("Gracias\n\n");}
    if (!((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32))) {printf("Bueno, pudo ser peor, pero vuelva a empezar\n\n");}
    } while (validar==SI || validar==SI+32 || !((validar==SI || validar==SI+32) || (validar==NO || validar==NO+32)));

    if (precio!=0)
    {
        printf("El monto del ticket es de %.2f$", ticket);
    }*/
    

    return 0;
}
