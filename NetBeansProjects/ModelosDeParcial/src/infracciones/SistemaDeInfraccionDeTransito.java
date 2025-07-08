package infracciones;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class SistemaDeInfraccionDeTransito {

    private ArrayList<Reclamo> reclamos;

    public SistemaDeInfraccionDeTransito(ArrayList<Reclamo> reclamos) {
        this.reclamos = reclamos;
    }

    public double importeTotal() {
        double total = 0;
        for (Reclamo r : reclamos) {
            total += r.importe();
        }
        return total;
    }

    public int cantidadDeInfraccionesCaducadas() {
        int cantidad = 0;
        for (Reclamo r : reclamos) {
            if (r.caduco()) {
                cantidad++;
            }
        }
        return cantidad;
    }

}
