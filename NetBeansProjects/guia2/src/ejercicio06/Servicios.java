package ejercicio06;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public enum Servicios {
    ESTANDAR(9999.59),
    PREMIUN(21999.99);

    private double precio;

    Servicios(double precio) {
        this.precio = precio;
    }

    public double getPrecio() {
        return precio;
    }
}
