package ejercicio13;

import java.util.Random;

/*
Las tarjetas de crédito guardan el nombre de la entidad
financiera a la que pertenecen (únicamente Visa, MasterCard
o Maestro), el nombre de la entidad bancaria, el número de
tarjeta, el saldo disponible y los datos del titular (nombre,
apellido, fecha de nacimiento y domicilio)

Cada vez que se cree una nueva tarjeta, deberán indicarse todos estos datos.
 */
public class TarjetaDeCredito {
    
    private final int DIGITOS_TARJETA_INFERIOR = 1;
    private final int DIGITOS_TARJETA_SUPERIOR = 999999999; 
    private int numeroDeTarjeta;
    
    private EntidadFinanciera entidadFinanciera;
    private String nombreDelBanco;
    
    private double saldoDisponible;
    
    private Persona titular;
    private Domicilio domicilio;
    
    public TarjetaDeCredito(EntidadFinanciera entidadFinanciera, Persona titular, String nombreDelBanco, Domicilio domicilio) {
        this.numeroDeTarjeta = generarAleatorio();
        this.entidadFinanciera = entidadFinanciera;
        this.titular = titular;
        this.nombreDelBanco = nombreDelBanco;
        this.domicilio = domicilio;
    }
    
    public void abonar(double dinero){
        if (dinero>=0) {
            this.saldoDisponible = this.saldoDisponible + dinero;        
        }
    }
    
    public void retirarDinero(double dinero){
        if (this.saldoDisponible-dinero>=0){
            this.saldoDisponible = this.saldoDisponible - dinero;
        }
        else
        {
            System.out.println("Saldo insuficiente");
        }
    }
    
    public Persona getPersona(){
        return this.titular;
    }

    
    public double getSaldo(){
        return this.saldoDisponible;
    }
    
    private int generarAleatorio() {
        Random rd = new Random();
        return rd.nextInt(DIGITOS_TARJETA_INFERIOR, DIGITOS_TARJETA_SUPERIOR);
    }

    public void show(){
        System.out.println(toString());
    }
    
    @Override
    public String toString() {
        return "TarjetaDeCredito{" + "numeroDeTarjeta=" + numeroDeTarjeta + ", entidadFinanciera=" + entidadFinanciera + ", nombreDelBanco=" + nombreDelBanco + ", saldoDisponible=" + saldoDisponible + ", titular=" + titular + ", domicilio=" + domicilio + '}';
    }
}
