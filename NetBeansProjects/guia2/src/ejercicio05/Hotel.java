package ejercicio05;

// Autor: Chisus
// Fecha de creación: 01/06/2025
import java.util.ArrayList;

public class Hotel {

    private String nombre;
    private String direccion;
    private ArrayList<Habitacion> habitaciones;

    public Hotel(String nombre, String direccion) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.habitaciones = new ArrayList<Habitacion>();
    }

    public ArrayList<Habitacion> obtenerHabitacionesDisponibles() {
        ArrayList<Habitacion> disponibles = new ArrayList<Habitacion>();
        for (Habitacion h : habitaciones) {
            if (!h.estaOcupada()) {
                disponibles.add(h);
            }
        }
        return disponibles;
    }

    public double realizarCheckout(int numeroHabitacion) {
        int i = 0;
        double checkout = -1;
        boolean seEncontro = false;
        while(i < habitaciones.size() && habitaciones.get(i).getNumero() != numeroHabitacion && !seEncontro){
            i++;
        }
        if (i < habitaciones.size() && habitaciones.get(i)!=null) {
            checkout = habitaciones.get(i).calcularTotal();
        }
        return checkout;
    }
    
    public void reservar(Cliente cliente, int numeroHabitacion){
        int i = 0;
        Habitacion aBuscar = null;
        boolean seEncontro = false;
        while(i<habitaciones.size() && !seEncontro){
            if (habitaciones.get(i).getNumero()==numeroHabitacion) {
                aBuscar = habitaciones.get(i);
                seEncontro = true;
            }
            i++;
        }
        if (seEncontro && aBuscar != null) {
            aBuscar.reservarCliente(cliente);
        }
    }

    public void addHabitaciones(ArrayList<Habitacion> habitaciones) {
        this.habitaciones.addAll(habitaciones);
    }


    
    
}
