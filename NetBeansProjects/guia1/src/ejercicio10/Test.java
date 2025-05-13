package ejercicio10;

/**
10) Refactoreá la clase CuentaBancaria del ejercicio 2), agregando el atributo titular, que 
representa a la persona titular de la cuenta, y el atributo fechaDeApertura.

 */
public class Test {

    public static void main(String[] args) {
        Persona chisus = new Persona("Jesus", "Quevedo");
        Fecha apertura = new Fecha();
        CuentaBancaria jesus = new CuentaBancaria(42932604,"Cuenta Corriente", chisus, apertura);
        

        jesus.depositarDinero(5000);
        jesus.show();
        
        
        System.out.println("");
        
        jesus.extraerDinero(200);
        jesus.show();
        
        System.out.println("");
        
        jesus.extraerDinero(5200);
        jesus.show();
    }
    
}
