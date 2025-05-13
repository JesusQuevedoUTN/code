package ejercicio13;

/*
13) Se desea implementar la lógica de un dispositivo
POSNET que procesa pagos con tarjetas de crédito. 
 */
public class Principal {

    public static void main(String[] args) {
        /*
        B) Desarrollar el método main del proyecto y generar las instancias necesarias para poder
efectuar un pago de $10000 en 5 cuotas, usando una tarjeta de crédito con saldo disponible
de $15000 (el resto de los datos, pueden inventarse a tu gusto).
         */
        Fecha nacimientoExequiel = new Fecha(2, 6, 1976);
        Persona papucho = new Persona("Edgardo", "Exequiel", nacimientoExequiel);
        Domicilio casa = new Domicilio("Benito Alvarez", 324, "La Matanza");
        TarjetaDeCredito tarjetaQuevedo = new TarjetaDeCredito(EntidadFinanciera.MASTER_CARD, papucho, "Banco Nacion", casa);
        Posnet dispositivo = new Posnet();
        Ticket papel;
        
        tarjetaQuevedo.abonar(15000);
        
        papel = dispositivo.efectuarSaldo(tarjetaQuevedo, 10000, 5);
        papel.show();
        tarjetaQuevedo.show();
    }

}
