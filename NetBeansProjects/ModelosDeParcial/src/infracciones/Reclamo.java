package infracciones;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Reclamo {

    private int numero = 0;
    private int dniDelReclamante;
    private Infraccion infraccionReclamada;

    public Reclamo(int dniDelReclamante, Infraccion infraccionReclamada) {
        this.numero++;
        this.dniDelReclamante = dniDelReclamante;
        this.infraccionReclamada = infraccionReclamada;
    }

    public boolean caduco() {
        return infraccionReclamada.caduco();
    }

    public double importe() {
        return infraccionReclamada.importe();
    }

}
