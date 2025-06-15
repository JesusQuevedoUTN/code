package ejercicio05;

// Autor: Chisus

import java.util.ArrayList;

// Fecha de creación: 01/06/2025
public class Cliente {

    private String nombre;
    private int estadiaEnDias;
    private ArrayList<Adiciones> adicionales;

    public Cliente(String nombre, int estadiaEnDias) {
        this.nombre = nombre;
        this.estadiaEnDias = estadiaEnDias;
        this.adicionales = new ArrayList<Adiciones>();
    }
    


    public Cliente(String nombre, int estadiaEnDias, ArrayList<Adiciones> adiciones) {
    this.nombre = nombre;
    this.estadiaEnDias = estadiaEnDias;
    this.adicionales = adiciones;
    }

    public ArrayList<Adiciones> getAdicionales() {
        return adicionales;
    }
    
    public String getNombre() {
        return nombre;
    }

    public int getEstadiaEnDias() {
        return estadiaEnDias;
    }

    public double calcularAdiciones() {
        double precio = 0;
        if (adicionales.size()>0) {
            for (Adiciones a : adicionales) {
                precio = precio + a.getPrecio();
            }
        }
        return precio * estadiaEnDias;
    }
}
