package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025
public class Pieza {

    private TipoDePieza nombre;

    //CONSTRUCT
    public Pieza(TipoDePieza nombre) {
        this.nombre = nombre;
    }

    //GETTERS
    public TipoDePieza getNombre() {
        return nombre;
    }

    @Override
    public String toString() {
        return "Pieza{" + "nombre=" + nombre + '}';
    }

}
