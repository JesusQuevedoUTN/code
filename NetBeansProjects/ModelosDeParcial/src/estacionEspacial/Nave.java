package EstacionEspacial;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Nave {

    private String planetaDeOrigen;
    private int cantidadDeTripulantes;

    public Nave(String planetaDeOrigen, int cantidadDeTripulantes) {
        this.planetaDeOrigen = planetaDeOrigen;
        this.cantidadDeTripulantes = cantidadDeTripulantes;
    }

    public abstract void manifiesto();

    public abstract boolean puedeEstacionar();

    public int getCantidadDeTripulantes() {
        return cantidadDeTripulantes;
    }

}
