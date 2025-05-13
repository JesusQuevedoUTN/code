package ejercicio03;

/*
3) Modelá la clase CuentaBancaria, la cual posea como atributos la clave bancaria uniforme (CBU), 
el tipo (caja de ahorro o cuenta corriente) y el saldo (inicialmente en 0). Luego, implementá métodos 
que permitan:
▪ Obtener el saldo actual.
▪ Depositar dinero en la cuenta (actualizando el saldo).
▪ Extraer dinero de la cuenta (actualizando el saldo). Solo puede quedar en saldo negativo si es 
cuenta corriente.
▪ Obtener los últimos 3 dígitos del CBU.
 */
public class Test {

    public static void main(String[] args) {
        CuentaBancaria jesus = new CuentaBancaria(42932604, "Cuenta Corriente");
        System.out.println(jesus.toString());
        System.out.println("");
        
        jesus.depositarDinero(5000);
        System.out.println(jesus.toString());
        System.out.println("");
        
        jesus.extraerDinero(200);
        System.out.println(jesus.toString());
        System.out.println("");
        
        jesus.extraerDinero(5200);
        System.out.println(jesus.toString());
        System.out.println("");

        System.out.println(jesus.ultimosDigitos());
    }

}