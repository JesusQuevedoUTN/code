package clase20_5;

public class Test {

    public static void main(String[] args) {
        // Crear un objeto Motor
        Motor motor = new Motor("12345", 2.0);

        // Crear un objeto Auto, que hereda de Vehiculo
        Auto miAuto = new Auto("Toyota", "Renault", "ABC123", motor);

        // Llamamos a métodos heredados de Vehiculo
        miAuto.encender();   // Heredado de Vehiculo
        miAuto.acelerar();   // Heredado de Vehiculo
        miAuto.frenar();     // Heredado de Vehiculo

        // Crear un aire acondicionado para el auto
        miAuto.prenderAire();  // Método de Auto

        miAuto.mostrar();
        // Us
    }
}
