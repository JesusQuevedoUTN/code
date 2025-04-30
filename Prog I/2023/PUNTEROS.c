#include "../../Libs/utils.h"

void multiplicar (int *x);
void leerColorRGB(int *red, int *green, int *blue);

int main()
{
    /*
    1.
    int a,b;
    a=10;
    b=20;
    printf("%d, %d\n", a, b);
    printf("%d, %d\n", &a, &b);

    int *p, *q;
    p = &a;
    
    printf("%d, %d\n", a, p);

    printf("%d, %d, %d\n", p, *p, &p);

    q = &a;

    printf("%d, %d, %d\n", q, *q, &q);

    *p = *p + 1;

    printf("%d, %d, %d\n", p, *p, &p);
    printf("%d, %d, %d\n", q, *q, &q);

    if (p == q) printf("P y Q contienen el mismo valor\n"); 
    else printf("P y Q contienen distinto valor\n"); 
    
    if (*p == *q) printf("Los contenidos apuntados desde P y Q son iguales\n"); 
    else printf("Los contenidos apuntados desde P y Q son distintos\n");

    q = &b;
    *q = 22;

    if (p == q) printf("P y Q contienen el mismo valor\n"); 
    else printf("P y Q contienen distinto valor\n"); 
    
    if (*p == *q) printf("Los contenidos apuntados desde P y Q son iguales\n"); 
    else printf("Los contenidos apuntados desde P y Q son distintos\n");

    printf("%d, %d, %d\n", p, *p, &p);
    printf("%d, %d, %d\n", q, *q, &q);
    */

   /*
   2.
    int a = 1, b = 3; 
    int c, *pa, *pb; 
     
    pa = &a; 
    *pa = 2 * a; 
    pb = &b; 
    c = 3 * (*pb - *pa); 
    printf("a=%d, b=%d, c=%d, *pa=%d, *pb=%d\n", a, b, c, *pa, *pb); 
   */
 
  /*
  3.
    int x = 5; 
    float y = 5; 
 
    int *xPtr = NULL; //obvio no apunta a nada debia ser &5
    printf ("%d", *xPtr); 
    //float *yPtr;
    xPtr = &y; //xPtr es un puntero de entero, este es de float, no son iguales
    printf ("%d", *xPtr);
  */

    /*
    4.
    int x = 5; 
    int *xx = &x; 
    *xx = *xx * x; 
    printf ("x vale %d y *xx vale %d", x, *xx);
    */

    /*
    5.
    int a, b, *p, *q, *r; 
    char c, d, *m, *n;
    b = 7; 
    a = 5; 
    q = &a; 
    p = q; 
    *p = b; 
 
    printf("*Q=%d\n\n", *q); 
 
    r = &b; 
    *r = *q; 
    printf("A=%d, b=%d, *p=%d, *q=%d, *r=%d\n\n", a, b, *p, *q, *r); 
 
    c = 'A'; 
    d = 'B'; 
    m = &c; 
    n = &d; 
    *m = *n; 
 
    if (m == n) printf("M y N apuntan a la misma direccion\n"); 
    else printf("M y N apuntan a direcciones distintas\n"); 
 
    printf("*M=%d\n", *m); 
    printf("\n");
    */

    /*
    6.
    int *p, a=1, b=8, **s; 
 
    p=&a; 
    b=*p+1; 
    s=&p; 
    printf("A=%d &A=%d\n\n",a,&a); 
    printf("B=%d &B=%d\n\n",b,&b); 
    printf("P=%d *P=%d &P=%d\n\n",p,*p,&p); 
    printf("S=%d *S=%d &S=%d\n\n",s,*s,&s); 
 
    *s=&b; 
    printf("Se ejecuto *S=&B\ny ahora\n\n");
    printf("S=%d *S=%d &S=%d\n\n",s,*s,&s); 
 
    **s=79; 
    printf("A=%d &A=%d\n\n",a,&a); 
    printf("B=%d &B=%d\n\n",b,&b); 
    printf("P=%d *P=%d &P=%d\n\n",p,*p,&p); 
     
    printf("\n");
    */

    /*
    7.
    int a, b;
    a=10;
    b=20;

    char c, d;
    c='A';
    d='E';

    int *p;
    p = &a;

    *p = 64;

    char *q;
    q = &c;

    *q = d;

    printf("%d, %d, %d, %d, %d, %d, %d, %d, %c, %c\n", p, &p, *p, q, &q, *q, a, b, c, d);

    q = p;

    printf("%d, %d, %d, %d, %d, %d, %d, %d, %c, %c\n", p, &p, *p, q, &q, *q, a, b, c, d);

    *p = *p + 2;

    printf("%d, %d, %d, %d, %d, %d, %d, %d, %c, %c\n", p, &p, *p, q, &q, *q, a, b, c, d);

    int **pp;

    *pp = &p;

    **pp = &b;

    printf("%d, %d, %d, %d, %d", p, *p, pp, *pp, **pp);
    */

    /*
    8.
    int x = 88; //mi diereccion es &x y yo soy el 88
    int *ptrl, **ptr2, ***ptr3, ****ptr4;

    ptrl = &x;    //ahora el valor que apunta es la direccion de x
    ptr2 = &ptrl; //ahrora apunta a la direcion del anterior
    ptr3 = &ptr2; //ahrora apunta a la direcion del anterior
    ptr4 = &ptr3; //ahrora apunta a la direcion del anterior

    //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d", x, &x, ptrl, *ptrl, ptr2, *ptr2, ptr3, *ptr3 ,ptr4, *ptr4);
    printf("%d, %d, %d, %d", *ptrl, **ptr2, ***ptr3 ****ptr4);
    */

    /*
    9.
    Creá  la  variable  entera  x  en  main  con  valor  10.  Luego,  pasala  como  argumento  de  la  función 
    duplicar,  la  cual  debés  definir  para  recibir  un  valor  entero  y  duplicar  su  valor  por  referencia. 
    Mostrá finalmente, en el main, el valor de x antes y después de la invocación de duplicar. 
    int x=10;
    printf("%d\n", x);
    multiplicar(&x);
    printf("%d", x);
    */

    /*
    10.
    10) Definí y probá desde el main la función leerColorRGB que reciba tres referencias a enteros por 
    parámetro, que representan los valores de cada canal (Red, Green, Blue). La función debe leer de la 
    consola un valor entero (entre 0 y 255) por cada canal y asignarlo. Mostrar finalmente, en el main, 
    los valores de cada canal tras la invocación de leerColorRGB. 
    int R, G, B;
    R=0;
    G=0;
    B=0;
    printf("Red= %d\nGreen= %d\nBlue= %d\n", R, G, B);
    leerColorRGB(&R, &G, &B);
    printf("\nRed= %d\nGreen= %d\nBlue= %d", R, G, B);
    */

    return 0;
}

//9.
void multiplicar (int *x){
  *x = *x*2;
}

//10
void leerColorRGB(int *red, int *green, int *blue){
  *red = leerEnteroEntre(0, 255, "\nRojo:");
  *green = leerEnteroEntre(0, 255, "\nVerde:");
  *blue = leerEnteroEntre(0, 255, "\nAzul:");
}