package ejercicio13;

/*
En caso de éxito, debe generar y retornar (no mostrar) un ticket donde
consten los siguientes datos:
▪ Nombre y apellido del cliente.
▪ Monto total a pagar.
▪ Monto de cada cuota.
Si la operación no tuvo éxito, se retornará null.
 */
public class Ticket {

    private Persona cliente;
    private double montoTotal;
    private double montoCuota;

    public Ticket(Persona cliente, double montoTotal, double montoCuota) {
        this.cliente = cliente;
        this.montoTotal = montoTotal;
        this.montoCuota = montoCuota;
    }

    public void show(){
        System.out.println(toString());
    }
    
    @Override
    public String toString() {
        return "Ticket{" + "cliente=" + cliente + ", montoTotal=" + montoTotal + ", montoCuota=" + montoCuota + '}';
    }

    
}
