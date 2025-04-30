#include "Libs/utils.h"

const int MESAS = 15;
const int MIN_COM = 1;
const int MAX_COM = 4;
const char EFECTIVO = 'E';
const char DEBITO = 'D';
const char CREDITO = 'C';
const int MIN_CRE = 1;
const int MAX_CRE = 12;
const float COSTO = 10;
const float COSTO_NINIOS = 5;
const float DEBITO_EXTRA = 1.05;        //5%
const float CREDITO_EXTRA_MENOS = 0.02; //2%
const float CREDITO_EXTRA_MAS = 0.03;   //3%

char registrarPago(cadena mensaje);
float cargoExtra(char pago, int cuotas, int abono);


int main()
{
    int TotalMesa=0, ninio=0, cuotas=0, costoMesa=0;

    mostrar("Hola bienvenido al sistema del restaurante, vamos a registrar las mesas");

    for (int i = 1; i <= MESAS; i++)
    {
        //Registrar Datos
        printf("\n- = - Mesa %d - = - ", i);
        int sal = registrarNumeroEntre(MIN_COM , MAX_COM, "Cuantos comieron a la mesa?");
        if (!(sal==1))
        {ninio = registrarNumeroEntre((MIN_COM-1), (sal-1),"Cuantos fueron ninios?");}
        char pago = registrarPago("Como desea abonar el pago?\nE. Efectivo     C. Credito      D. Debito");
        if (pago == CREDITO)
        {cuotas = registrarNumeroEntre(MIN_CRE , MAX_CRE, "En cuantas cuotas abonara su pago?");}

        //Procesos
        costoMesa=COSTO;
        TotalMesa+=(costoMesa*sal - COSTO_NINIOS*ninio);
        float x = cargoExtra(pago , cuotas, TotalMesa);
        printf("%.2f", x);

        TotalMesa=0;
        ninio=0;
    }
    
    return 0;
}

char registrarPago(cadena mensaje){
    char pago;
    printf("\n%s\n", mensaje);
    
    do
    {
        fflush(stdin);
        scanf("%c", &pago);
        if (pago!=EFECTIVO && pago!=EFECTIVO+32 && pago!=DEBITO && pago!=DEBITO+32 && pago!=CREDITO && pago!=CREDITO+32)
        {
            mostrar("ERROR. solo puede ser Efectivo (E), Credito (C), o Debito (D)");
        }
        
    } while (!(pago==EFECTIVO || pago==EFECTIVO+32 || pago==DEBITO || pago==DEBITO+32 || pago==CREDITO || pago==CREDITO+32));
    

    return pago;
}

float cargoExtra(char pago, int cuotas, int aporte){
    float abono;
    if (pago==DEBITO || pago==DEBITO+32)
    {
        abono=aporte*DEBITO_EXTRA*1.0;
    }
    if (pago==CREDITO || pago==CREDITO+32)
    {
        if (cuotas>=6)
        {
            abono=aporte+(aporte*1.0*CREDITO_EXTRA_MENOS*cuotas);
        }//10+10*(0.03)*7
        else
        {
            abono=aporte+aporte*1.0*CREDITO_EXTRA_MAS*cuotas;
        }
        
    }
    return abono;
}