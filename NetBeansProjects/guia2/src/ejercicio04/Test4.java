/*
che mira, ahora el ejercicio se detiene cuando hago borrar y cuando hago cambiar concesionaria, ayudame, tipo, nisiquiera avanza y no se el porque
*/

package ejercicio04;

// Autor: Chisus
import java.util.ArrayList;

// Fecha de creación: 01/06/2025
public class Test4 {

    public static void main(String[] args) {
        //INICIAMOS LA MARCA
        Marca marca = new Marca("Renault");

        //LA CARGAMOS
        cargarConcesionarias(marca);

        //MOSTRAMOS TODOS LOS COCHES
        marca.mostrarVehiculos();

        //SUCURSAL CON MÁS VEHICULOS
        concesionariaConMasVehiculos(marca);

        //BORRAR VEHICULO
        borrarVehiculo(marca, "CCC333");
        System.out.println("\nMOSTRANDO SIN UN VEHICULO");
        marca.mostrarVehiculos();

        //CAMBIAR VEHICULO
        System.out.println("\n=== Cambiando vehículo 'FFF666' de 'SRL' a 'Autos Cielo' ===");
        marca.cambiarVehiculoDeConcesionaria("FFF666", "Autos Cielo");
        System.out.println("\nMOSTRANDO CON UN VEHICULO CAMBIADO");
        marca.mostrarVehiculos();

    }

    static void cargarConcesionarias(Marca marca) {
        Concesionaria c1 = new Concesionaria("Autos del Norte");
        c1.agregarVehiculo(new Vehiculo("AAA111", 10000, TipodeVehiculo.AUTO));
        c1.agregarVehiculo(new Vehiculo("BBB222", 15000, TipodeVehiculo.CAMIONETA));

        Concesionaria c2 = new Concesionaria("Ruedas SA");
        c2.agregarVehiculo(new Vehiculo("CCC333", 13000, TipodeVehiculo.UTILITARIO));
        c2.agregarVehiculo(new Vehiculo("DDD444", 18000, TipodeVehiculo.AUTO));
        c2.agregarVehiculo(new Vehiculo("EEE555", 16000, TipodeVehiculo.CAMIONETA));

        Concesionaria c3 = new Concesionaria("Velocidad SRL");
        c3.agregarVehiculo(new Vehiculo("FFF666", 20000, TipodeVehiculo.UTILITARIO));
        c3.agregarVehiculo(new Vehiculo("GGG777", 11000, TipodeVehiculo.AUTO));
        c3.agregarVehiculo(new Vehiculo("HHH888", 12000, TipodeVehiculo.CAMIONETA));
        c3.agregarVehiculo(new Vehiculo("III999", 17000, TipodeVehiculo.AUTO));

        Concesionaria c4 = new Concesionaria("Autos Cielo");
        c4.agregarVehiculo(new Vehiculo("JJJ000", 19000, TipodeVehiculo.CAMIONETA));
        c4.agregarVehiculo(new Vehiculo("KKK111", 14000, TipodeVehiculo.AUTO));

        marca.agregarConcesionaria(c1);
        marca.agregarConcesionaria(c2);
        marca.agregarConcesionaria(c3);
        marca.agregarConcesionaria(c4);
    }

    static void concesionariaConMasVehiculos(Marca marca) {
        System.out.println("\n=== Concesionaria(s) con más vehículos ===");
        ArrayList<Concesionaria> maxVeh = marca.obtenerConcesionariaMaxVeh();
        for (Concesionaria c : maxVeh) {
            System.out.println("- " + c.getNombre());
        }
    }

    private static void borrarVehiculo(Marca marca, String ccC333) {
        System.out.println("\n=== Borrando vehículo con patente 'CCC333' ===");
        marca.borrarVehiculo("CCC333");
    }

}
