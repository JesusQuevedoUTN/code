package ejercicio08;

// Autor: Chisus
// Fecha de creación: 17/05/2025
public class Pieza {

    private TipoDePieza nombre;
    private Estado estado;

    //CONSTRUCT
    public Pieza(TipoDePieza nombre, Estado estado) {
        this.nombre = nombre;
        this.estado = estado;
    }

    //GETTERS
    public TipoDePieza getNombre() {
        return nombre;
    }

    public Estado getEstado() {
        return estado;
    }

    //METODOS
    public void dañar() {
        this.estado = Estado.DANIADO;
    }

    @Override
    public String toString() {
        return nombre + ". Estado= " + estado.name();
    }

}
