package ejercicio05;

// Autor: Chisus
// Fecha de creación: 01/06/2025

public class Habitacion {

    private int numero;
    private double precio;
    private boolean ocupada;
    private Cliente huesped;

    public Habitacion(int numero, double precio) {
        this.numero = numero;
        this.precio = precio;
    }

    public int getNumero() {
        return numero;
    }

    public void reservarCliente(Cliente huesped){
        this.huesped = huesped;
        this.ocupada = true;
    }
    
    public double calcularTotal() {
        return huesped.getEstadiaEnDias()*precio + huesped.calcularAdiciones();
    }

    public boolean estaOcupada() {
        return ocupada;
    }

    
}
