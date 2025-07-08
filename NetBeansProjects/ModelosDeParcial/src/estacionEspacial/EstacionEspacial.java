package EstacionEspacial;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class EstacionEspacial {

    private String nombre;
    private ArrayList<Nave> naves;

    public EstacionEspacial(String nombre, int puntosDeAtraque) {
        this.nombre = nombre;
        this.naves = new ArrayList<>(puntosDeAtraque);
    }

    public void mostrarManifiestos() {
        for (Nave n : naves) {
            n.manifiesto();
        }
    }

    public void estacionarNave(Nave nave) {
        if (validarEstacionamiento(nave)) {
            naves.add(nave);
        }
    }

    private boolean validarEstacionamiento(Nave nave) {
        return naves.size() < 5 && nave.puedeEstacionar();
    }

}
