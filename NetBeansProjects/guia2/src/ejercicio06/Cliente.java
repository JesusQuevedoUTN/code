package ejercicio06;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Cliente {

    private String DNI;
    private String nombre;
    private boolean deuda;
    private Servicios servicio;
    private ArrayList<Pelicula> peliculas;

    public Cliente(String DNI, String nombre, Servicios servicio) {
        this.DNI = DNI;
        this.nombre = nombre;
        this.servicio = servicio;
        ArrayList<Pelicula> peliculas = new ArrayList<Pelicula>();
    }

    public void seEndeudo() {
        deuda = true;
    }

    public void pago() {
        deuda = false;
    }

    public String getDNI() {
        return DNI;
    }

    public double obtenerSaldo() {
        return deuda ? servicio.getPrecio() : -servicio.getPrecio();
    }

    public boolean esDeudor() {
        return obtenerSaldo() > 0;
    }

    public boolean esPremiun() {
        return servicio == Servicios.PREMIUN;
    }

}
