#include <stdio.h>


/*1 Realizá  un  programa  que  permita  al  usuario  ingresar un  número  entero.  La  computadora
    debe indicar si se trata de un número par o impar*/
    /*int main(int argc, char const *argv[])
    {
        int a;
        printf("Ingrese un numero\n");
        scanf("%d", &a);
        if (a%2 == 0)
        {
            printf("El numero es par");
        }
        else
        {
            printf("El numero es impar");
        }
        return 0;
    }*/
    

/*2 Realizá un programa que permita al usuario ingresar la cantidad de inscriptos a una conferencia
    y  la  cantidad  de  asientos  disponibles en el  auditorio.  La  computadora  debe  indicar  si
    alcanzan  los asientos,  en  caso  contrario,  indicar  cuántos  faltan  para  que  todos  los
    inscriptos  puedan  sentarse*/
    /*int main(int argc, char const *argv[])
    {
        int asientosDeLaConferencia, inscriptosALaConferencia;
        printf("Cuantos inscriptos hay?\n");
        scanf("%d", &inscriptosALaConferencia);
        printf("y cuantos asientos hay disponibles?\n");
        scanf("%d", &asientosDeLaConferencia);
        
        if (inscriptosALaConferencia < asientosDeLaConferencia)
        {
            printf ("Los asisntos alcanzan <3");
        }
        else{
            printf("Busca %d asientos", inscriptosALaConferencia-asientosDeLaConferencia);
        }
        return 0;
    }*/


/*3 Realizá un programa que permita al usuario ingresar dos números enteros. La computadora debe
    indicar cuál de ellos es el mayor*/
    /*int main(int argc, char const *argv[])
    {
        int a, b;
        printf("Ingresa dos valores\nA:");
        scanf("%d",&a);
        printf("B:");
        scanf("%d",&b);
        
        if (a>b)
        {
            printf("\nMayor: %d \nMenor: %d", a, b);
        }
        if (a<b)
        {
            printf("\nMayor: %d \nMenor: %d", b, a);
        }        
        if (a==b)
        {
            printf("\nSon iguales, no jodas, te voy a pegar un baile morboso"); 
        }
        return 0;
    }*/
    

/*4 Realizá un programa que permita al usuario ingresar tres números enteros. La computadora debe
    indicar cuál de ellos es el mayor*/
    /*int main(int argc, char const *argv[])
    {
        int a, b, c;
        printf("Ingresa 3 valores:\nA:");
        scanf("%d",&a);
        printf("B:");
        scanf("%d",&b);
        printf("C:");
        scanf("%d",&c);

        
        if (a>b && a>c)
        {
            printf("\nMayor: %d", a);
        }
        if (b>a && b>c)
        {
            printf("\nMayor: %d", b);
        }
        if (c>b && c>a)
        {
            printf("\nMayor: %d", c);
        }
        if ((a==b && a>c) || (a==c && a>b))
        {
            printf("\nMayor: %d", a);
        }        
        if ((b==c) && b>a)
        {
            printf("\nMayor: %d", b);
        }
        
        if (a==b && b==c)
        {
            printf("\nwacho son iguales dejate de joder"); 
        }
        return 0;
    }*/
    

/*5 Realizá  un  programa  que  permita  al  usuario  ingresar  su  edad  (entre 1y 120años)  y
    su  género ('F'para mujeres, 'M'para hombres). La computadora debe indicar si la persona está
    en edad de jubilarse1.  En  caso  de  haber  ingresado  valores  erróneos  (edad  fuera  de
    rango  o  género  inválido), informar tal situación*/
    //HECHO POR EL PROFE
    /*int main() {

    const char FEMENINO = 'F';
    const char MASCULINO = 'M';
    const int EDAD_1 = 60;
    const int EDAD_2 = 65;
    const int EDAD_MIN = 1;
    const int EDAD_MAX = 120;

    int edad;
    char genero;

    printf("Ingrese una edad: ");
    scanf("%d", &edad);
    
    if (edad >= EDAD_MIN && edad <= EDAD_MAX){
        printf("\nIngrese un genero: ");
        scanf(" %c", &genero);
        if (genero == FEMENINO || genero == MASCULINO){
            if (edad>= EDAD_2 || (genero == FEMENINO && edad >= EDAD_1)){
                printf("\nSe jubila.");
            } else {
                printf("\nNo se jubila."); //Agregar edad para jubilarse.
            }
        } else {
            printf("\nEl genero es invalido.");
        }
    } else {
        printf("\nLa edad es invalida.");
    }
    return 0;
}*/

    
/*6 Realizá un programa que permita al usuario ingresar la edad y el sueldo de cierto empleado.
La computadora  muestra  el  monto  del  aporte  al  sindicato  que  se  debe  descontar  del 
salario  del empleado, según el siguiente cuadro:
       Escala salarial          Porcentaje a descontar
       Menos de $20000                  0.7%
    Entre $20000 y $29999               1.4%
    Entre $30000 y $39999               2.1%
          $40000 o más                  2.8%
Además,  si  la  persona  tiene  30  años  o  menos,  se  cobra  un  30%  adicional  del  valor
del  aporte*/
/*int main()
{
    const float MENOS_DE_20K = .007;        //0.7%
    const float ENTRE_20K_Y_29K = .014;     //1.4%
    const float ENTRE_30K_Y_39K = .021;     //2.1%
    const float MAS_DE_40K = .028;          //2.8%
    
    const int ESCALA2 = 20000;   
    const int ESCALA3 = 30000;   
    const int ESCALA4 = 40000;   

    const float MENOS_DE_30_ANIOS = .3;       //30%
    const int EDAD = 30; 

    int edad;
    float sueldo;
    
    printf("Cuantos anios tiene el empleado?\n");
    scanf("%d", &edad);
    printf("Cuanto gana?\n");
    scanf("%f", &sueldo);

        if (sueldo > 0 && sueldo < ESCALA2 )
        {
            if (edad > EDAD)
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*MENOS_DE_20K);
            }
            else
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*MENOS_DE_20K+sueldo*MENOS_DE_20K*MENOS_DE_30_ANIOS);
            }
        }

        
        if (sueldo > ESCALA2 && sueldo < ESCALA3)
        {
            if (edad > EDAD)
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*ENTRE_20K_Y_29K);
            }
            else
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*ENTRE_20K_Y_29K+sueldo*ENTRE_20K_Y_29K*MENOS_DE_30_ANIOS);
            }
        }

        if (sueldo > ESCALA3 && sueldo < ESCALA4)
        {
            if (edad > EDAD)
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*ENTRE_30K_Y_39K);
            }
            else
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*ENTRE_30K_Y_39K+sueldo*ENTRE_30K_Y_39K*MENOS_DE_30_ANIOS);
            }
        }

        if (sueldo > ESCALA4)
        {
            if (edad > EDAD)
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*MAS_DE_40K);
            }
            else
            {
                printf("Monto del aporte al sindicato: %.2f", sueldo*MAS_DE_40K+sueldo*MAS_DE_40K*MENOS_DE_30_ANIOS);
            }
        }

    return 0;
}*/


/*7 Realizá  un  programa  que  permita  al  usuario  ingresar  tres  números.  La  computadora  
debe mostrarlos ordenados de menor a mayor*/
/*int main()
{
    int a, b, c, mayor, medio, menor;
    printf("Ingrese tres valores\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a>b && a>c)
    {
        mayor=a;
            if (b>c)
            {
                medio=b;
                menor=c;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
            else
            {
                medio=c;
                menor=b;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
            
    }
    if (b>c && b>c)
    {
        mayor=b;
            if (a>c)
            {
                medio=a;
                menor=c;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
            else
            {
                medio=c;
                menor=a;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
    }
    if (c>a && c>b)
    {
        mayor=c;
            if (a>b)
            {
                medio=a;
                menor=b;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
            else
            {
                medio=b;
                menor=a;
                printf("Mayor: %d\nMedio: %d\nMenor: %d", mayor,medio, menor);
            }
    }

    return 0;
}*/


/*8 Realizá un programa que permita al usuario ingresar dos números enteros. La computadora debe
indicar si el mayor es divisible por el menor*/
 /*int main()
{
    int a, b, mayor, menor;
    printf("Ingrese dos numeros enteros\n");
    scanf("%d %d", &a, &b);
    if (a-b > 0)
    {
        mayor = a;
        menor = b;
    }
    else
    {
        mayor = b;
        menor = a;
    }

    if (mayor%menor == 0)
    {
        printf("%d es divisible por %d", mayor, menor);
    }
    else
    {
        printf("%d no es indivisible por %d", mayor, menor);
    }
    

    return 0;
}*/


/*9 Realizá  un  programa  que  permita  al  usuario  ingresar  los  lados a, by cde  un  triángulo.
La computadora  informa  si  el  triángulo  es  o  no  válido.  En  caso  afirmativo,  además
informa  si  es equilátero, isósceles o escaleno.*/
/*int main()
{
    float a,b,c;
    printf("Ingrese los lados del triangulo\n");
    scanf ("%f %f %f", &a, &b, &c);
    if ((a+b+c) == 180)
    {
        if (a==b && b==c)
        {
            printf("es un triangulo equilatero");
        }
        if (a==b && a!=c || b==c && a!=c || a==c && a!=c)
        {
            printf("es un triangulo isoceles");
        }
            else
        {
            printf("es un triangulo escaleno");
        }
        
    }
    else
    {
        printf("los angulos internos de un trianguno no pueden medir menos de 180 grados o exederlos");
    }
    
    return 0;
}*/


/*10 Realizá  un  programa  que  permita  al  usuario  ingresar  un  número  entero  entre 1 y 12.
La computadora debe mostrar por pantalla el nombre del mes del año que representa tal número. Si
se ingresa un número fuera de rango, debe mostrar un error.*/
/* int main()
{
    int num;
    printf("Ingrese el numero de un mes del anio \n");
    scanf("%d", &num);
    
    printf("El mes es ");
    switch (num)
    {
    case 1:
        printf("Enero"); 
        break;
    
    case 2:
        printf("Febrero"); 
        break;
            
    case 3:
        printf("Marzo"); 
        break;
            
    case 4:
        printf("Abril"); 
        break;
            
    case 5:
        printf("Mayo"); 
        break;
            
    case 6:
        printf("Junio"); 
        break;
            
    case 7:
        printf("Julio"); 
        break;

    case 8:
        printf("Agosto"); 
        break;

    case 9:
        printf("Septiembre"); 
        break;

    case 10:
        printf("Octubre"); 
        break;

    case 11:
        printf("Noviembre"); 
        break;

    case 12:
        printf("Diciembre"); 
        break;

    default:
        break;
    }
        
    if (num>12 || num<11)
    {
        printf("invalido");
    }

    return 0;
}*/


/*11 Realizá un programa que permita al usuario ingresar una letra, correspondiente a un dígito del
sistema de numeración romano. La computadora debe mostrar su correspondiente valor decimal. Si  se
ingresa  una  letra  inexistente,  la  computadora  debe  informar  que  no  existe  tal  dígito.*/
/* int main()
{
    int valor;
    char letra;
    printf("Ingrese un valor romano\n");
    fflush(stdin);
    scanf("%c", &letra);
    
    switch (letra)
    {
    
    case 'I':
    case 'i':
        valor=1;
        break;
    
    case 'V':
    case 'v':
        valor=5;
        break;
    
    case 'X':
    case 'x':
        valor=10;
        break;
    
    case 'L':
    case 'l':
        valor=50;
        break;
    
    case 'C':
    case 'c':
        valor=100;
        break;
    
    case 'D':
    case 'd':
        valor=500;
        break;
    
    case 'M':
    case 'm':
        valor=1000;
        break;

    default:
        valor=0;
    }

    printf("El valor es ");
    if (valor!=0)
    {
        printf("%d\n", valor);
    }
    else
    {
        printf("invalido\n");
    }
    
    
    return 0;
} */

/*12 Realizá un programa que permita al usuario ingresar el día y el mes de su cumpleaños (de manera
independiente). La computadora debe indicar cuál es su signo del zodiaco. Deben validarse tanto el
día como el mes*/
/*int main()
{
    int mes, dia;
    printf("Ingrese un mes valido\n");
    scanf("%d",&mes);
    if (mes>=1 && mes<=12)
    {
        printf("Ingrese un dia valido\n");
        scanf("%d", &dia);

                if (mes==1)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=19)
                {
                    printf("Su signo zodiacal es: CAPRICORNIO");
                }
                else
                {
                    printf("Su signo zodiacal es: ACUARIO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        
            
                if (mes==2)
        {
            if (dia>=1 && dia <=29)
            {
                if (dia<=18)
                {
                    printf("Su signo zodiacal es: ACUARIO");
                }
                else
                {
                    printf("Su signo zodiacal es: PISCIS");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        
                if (mes==3)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=20)
                {
                    printf("Su signo zodiacal es: PISCIS");
                }
                else
                {
                    printf("Su signo zodiacal es: ARIES");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==4)
        {
            if (dia>=1 && dia <=30)
            {
                if (dia<=19)
                {
                    printf("Su signo zodiacal es: ARIES");
                }
                else
                {
                    printf("Su signo zodiacal es: TAURO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        


                if (mes==5)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=20)
                {
                    printf("Su signo zodiacal es: TAURO");
                }
                else
                {
                    printf("Su signo zodiacal es: GEMINIS");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==6)
        {
            if (dia>=1 && dia <=30)
            {
                if (dia<=20)
                {
                    printf("Su signo zodiacal es: GEMINIS");
                }
                else
                {
                    printf("Su signo zodiacal es: CANCER");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==7)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=22)
                {
                    printf("Su signo zodiacal es: CANCER");
                }
                else
                {
                    printf("Su signo zodiacal es: LEO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==8)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=22)
                {
                    printf("Su signo zodiacal es: LEO");
                }
                else
                {
                    printf("Su signo zodiacal es: VIRGO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==9)
        {
            if (dia>=1 && dia <=30)
            {
                if (dia<=22)
                {
                    printf("Su signo zodiacal es: VIRGO");
                }
                else
                {
                    printf("Su signo zodiacal es: LIBRA");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }    
    

                if (mes==10)
        {
            if (dia>=1 && dia <=31)
            {
                if (dia<=22)
                {
                    printf("Su signo zodiacal es: LIBRA");
                }
                else
                {
                    printf("Su signo zodiacal es: ESCORPIO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }        

                if (mes==11)
        {
            if (dia>=1 && dia <=30)
            {
                if (dia<=23)
                {
                    printf("Su signo zodiacal es: ESCORPIO");
                }
                else
                {
                    printf("Su signo zodiacal es: SAGITARIO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        }

                if (mes==12)
            {
            if (dia>=1 && dia <=31)
            {
                if (dia<=21)
                {
                    printf("Su signo zodiacal es: SAGITARIO");
                }
                else
                {
                    printf("Su signo zodiacal es: CAPRICORNIO");
                }   
            }
            else
            {
                printf("Ingrese un dia VALIDO");
            }
        
            }
    }
    else
    {
        printf("Ingrese un mes VALIDO");
    }
    
    return 0;
}*/
    //HECHO MAL
/*    int main()
    {
        int mes, dia;
        printf("Ingrese un mes valido\n");
        scanf("%d", &mes);

        if (mes>=1 && mes<=12)
        {
            printf("Ingrese un dia valido\n");
            scanf("%d", &dia);
            
            if (dia<=30 && dia>=1)
            {
                switch (mes)
            {
            case 1:
                if (dia<=30 && dia>=1)
                {
                    if (dia<=15)
                    {
                        printf("Su signo es Sagitario");
                    }
                    else
                    {
                        
                        printf("Su signo es Capricornio");
                    }
                    
                }
                break;

            case 2:
                if (dia<=30 && dia>=1)
                {
                    if (dia<=15)
                    {
                        printf("Su signo es Capricornio");
                    }
                    else
                    {
                        
                        printf("Su signo es Urano");
                    }
                    
                }
                break;
            
            case 3:
                if (dia<=30 && dia>=1)
                {
                    if (dia<=15)
                    {
                        printf("Su signo es Urano");
                    }
                    else
                    {
                        
                        printf("Su signo es Libra");
                    }
                    
                }
                break;
//ACA ME CANSÉ, YA VEO QUE TODO FUNCIONA, DEBERIA PONER DESDE EL 1 AL 12 Y LOS DATOS CORRECTOS, PERO COMO YA LO HICE AL MODO LARGO YO YA LO DEJO ASI
            default:
                break;
            }
            }
            else
            {
                printf("Ingrese un dia VALIDO\n");
            }
            
            
        }
        else
        {
            printf("ingrese un mes VALIDO");
        }
        

        return 0;
    }*/
    