package ejercicio02;

// Autor: Chisus
// Fecha de creación: 27/05/2025
public class Carta {

    protected boolean deFrente;

    public Carta() {
        this.deFrente = true;
    }

    public void darVuelta() {
        this.deFrente = !this.deFrente;
    }

    public String mostrar() {
        return deFrente ? this.toString() : "Carta boca abajo";
    }
}
