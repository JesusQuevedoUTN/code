package ejercicio09;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Servicios implements Facturable {

    private int cantidadDeHoras;

    public Servicios(int cantidadDeHoras) {
        this.cantidadDeHoras = cantidadDeHoras;
    }

    public int getCantidadDeHoras() {
        return cantidadDeHoras;
    }

}
