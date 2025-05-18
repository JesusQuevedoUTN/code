package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025

public class Pieza {
    private TipoDePieza nombre;
    private boolean operativo;

    public Pieza(TipoDePieza nombre) {
        this.nombre = nombre;
    }

    public TipoDePieza getNombre() {
        return nombre;
    }

    public boolean isOperativo() {
        return operativo;
    }
}
