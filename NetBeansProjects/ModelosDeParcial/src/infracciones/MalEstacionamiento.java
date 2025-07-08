package infracciones;

import java.time.LocalDate;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class MalEstacionamiento extends Infraccion {

    private final double importe = 20;
    private final double importeFijo = 300;

    public MalEstacionamiento(LocalDate fecha) {
        super(fecha);
    }

    public double importe() {
        return super.getImporteUnidadFija() * this.importe + this.importeFijo;
    }

    public boolean caduco() {
        return super.getFecha().plusDays(365).isBefore(LocalDate.now());
    }

}
