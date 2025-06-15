package ejercicio05;

// Autor: Chisus
// Fecha de creación: 01/06/2025

public enum Adiciones {
    DESAYUNO(100),
    ROOM_SERVICE(275.25),
    TRASLADO(300.50);

    private double precio;
    private int fecha;

    Adiciones(double precio) {
        this.precio = precio;
    }

    public double getPrecio() {
        return precio;
    }
}
