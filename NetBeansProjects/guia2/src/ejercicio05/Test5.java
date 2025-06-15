package ejercicio05;

// Autor: Chisus

import java.util.ArrayList;

// Fecha de creación: 01/06/2025
public class Test5 {

    public static void main(String[] args) {
        // Crear hotel
        Hotel hotel = new Hotel("Mangea", "Calle Fantasía 123");

        // Crear habitaciones
        Habitacion h1 = new Habitacion(101, 1000);
        Habitacion h2 = new Habitacion(102, 1200);
        Habitacion h3 = new Habitacion(103, 1500);

        // Agregarlas al hotel (usamos reflexión temporalmente, o agregá un método si preferís)
        ArrayList<Habitacion> habitaciones = new ArrayList<>();
        habitaciones.add(h1);
        habitaciones.add(h2);
        habitaciones.add(h3);
        hotel.addHabitaciones(habitaciones);

        

        // Agregar adicionales
        ArrayList<Adiciones> adicion = new ArrayList<>();
        adicion.add(Adiciones.DESAYUNO);
        adicion.add((Adiciones.TRASLADO));
        
        // Crear cliente
        Cliente lucia = new Cliente("Lucía", 3, adicion);

        // Ocupar habitación 101
        hotel.reservar(lucia, 101);

        // Ver habitaciones disponibles
        System.out.println("Habitaciones disponibles:");
        for (Habitacion hab : hotel.obtenerHabitacionesDisponibles()) {
            System.out.println(" - Habitación " + hab.getNumero());
        }

        // Realizar checkout
        double total = hotel.realizarCheckout(101);
        if (total != -1) {
            System.out.println("Total a pagar por la habitación 101: $" + total);
        } else {
            System.out.println("No se pudo hacer el checkout.");
        }
    }

}
