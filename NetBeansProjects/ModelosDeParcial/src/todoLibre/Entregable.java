package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public interface Entregable {

    public Domicilio origen();

    public Domicilio destino();

    public default boolean envioGratis() {
        return false;
    }

}
