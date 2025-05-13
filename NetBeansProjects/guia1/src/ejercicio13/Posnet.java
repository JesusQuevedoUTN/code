package ejercicio13;

/*
A la hora de abonar, el POSNET recibiría la tarjeta con la que
desea hacerse el pago, junto con el monto que se desea
abonar y la cantidad de cuotas (de 1 a 6).
Si el pago es en 1 cuota, no se genera ningún recargo, de lo contrario, el monto se incrementará en
un 3% por cada cuota superior a 1. (Ejemplo: Pagar en 4 cuotas representará un 9% de incremento).
El POSNET debe chequear que la tarjeta tenga saldo suficiente para poder efectuar el pago junto
con el recargo, si hubiese. 
 */
public class Posnet {

    final private int CUOTA_INFERIOR = 1;
    final private int CUOTA_SUPERIOR = 6;
    final private double AUMENTO_DE_CUOTA = 0.03;
    private double abono;
    private int cantidadDeCuotas;
    private TarjetaDeCredito tarjera;

    public Ticket efectuarSaldo(TarjetaDeCredito tarjeta, double monto, int cuotas) {
        Ticket ticket;
        if (sePuedeEfectuar(tarjeta, monto, cuotas)) {
            ticket = new Ticket(tarjeta.getPersona(), calcularSaldo(monto, cuotas), calcularSaldo(monto, cuotas)/cuotas);
            tarjeta.retirarDinero(calcularSaldo(monto, cuotas));
        } else {
            ticket = null;
        }
        return ticket;
    }

    private boolean sePuedeEfectuar(TarjetaDeCredito tarjeta, double monto, int cuotas){
        double saldo = calcularSaldo(monto, cuotas); 
        return (tarjeta.getSaldo()-saldo) >= 0;
    }
    
    private double calcularSaldo(double monto, int cuotas){
        double saldo = monto;
        if (cuotas>CUOTA_INFERIOR) {
            saldo = saldo + (saldo * (AUMENTO_DE_CUOTA*(cuotas-CUOTA_INFERIOR)));
        }
        return saldo;
    }
    
    private int getSaldo() {
        // Método a resolver...
        return 0;
    }

    private int chequearSaldo() {
        // Método a resolver...
        return 0;
    }

}
