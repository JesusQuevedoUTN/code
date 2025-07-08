package infracciones;

import java.time.LocalDate;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class ExcesoDeVelocidad extends Infraccion {

    private final double importe = 100;

    public ExcesoDeVelocidad(LocalDate fecha) {
        super(fecha);
    }

    public double importe() {
        return super.getImporteUnidadFija() * this.importe;
    }

    public boolean caduco() {
        return false;
    }

}
