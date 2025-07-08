package EstacionEspacial;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Cargo extends Nave {

    private String descripcion;
    private double volumen;

    public Cargo(String descripcion, double volumen, String planetaDeOrigen, int cantidadDeTripulantes) {
        super(planetaDeOrigen, cantidadDeTripulantes);
        this.descripcion = descripcion;
        this.volumen = volumen;
    }

    @Override
    public void manifiesto() {
        System.out.println(descripcion + "(volumen " + volumen + "m3)");
    }

    @Override
    public boolean puedeEstacionar() {
        return this.volumen < 100;
    }

}
