package ejercicio09;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Vehiculo {

    private String patente;
    private Llave llave;
    private ArrayList<Persona> listaDePersonas;
    private int deuda;
    
    private final int MAXIMA_DEUDA_PERMITIDA = 3; // MESES

    public Vehiculo(String patente, ArrayList<Persona> listaDePersonas) {
        this.patente = patente;
        this.llave = new Llave(patente);
        this.listaDePersonas = listaDePersonas;
        this.deuda = 0;
    }

    public String getPatente() {
        return patente;
    }
    
    public Llave tomarLave(){
        Llave buscar = null;
        if (this.llave != null){
            buscar = this.llave;
        }
        else{
            System.out.println("Aquí no hay llave...");
        }
        return buscar;
    }

    public boolean estaAutorizada(int DNI){
        boolean estaAutorizada = false;
        int i = 0;
        while (i < listaDePersonas.size() && !estaAutorizada) {
            if (listaDePersonas.get(i).getDNI() == DNI) {
                estaAutorizada = !estaAutorizada;
            }
            i++;
        }
        return estaAutorizada;
    }
    
    public void devolverLlave(Llave llave) {
        if (llave.getPatente().equals(this.patente)) {
            this.llave = llave;
        }
        else{
            System.out.println("Esta no es tu llave...");
        }
    }
    
    public int getMesesAdeudados() {
        return this.deuda;
    }

    boolean estaEstacionado() {
        return this.llave != null;
    }

    public void noPago(int meses){
        this.deuda = this.deuda + meses;
    }
    
    public void pago(int meses){
        this.deuda = this.deuda - meses;
    }
    
    boolean tieneDeuda() {
        return this.deuda >= MAXIMA_DEUDA_PERMITIDA;
    }
}
