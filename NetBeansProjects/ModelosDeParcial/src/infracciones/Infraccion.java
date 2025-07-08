package infracciones;

import java.time.LocalDate;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Infraccion {

    private LocalDate fecha;
    private final double importeUnidadFija = 60.5;

    public Infraccion(LocalDate fecha) {
        this.fecha = fecha;
    }

    public abstract double importe();

    public abstract boolean caduco();

    public LocalDate getFecha() {
        return fecha;
    }

    public double getImporteUnidadFija() {
        return importeUnidadFija;
    }

}
