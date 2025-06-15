package ejercicio09;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Tablero {

    private ArrayList<Llave> llaves;

    public Tablero(ArrayList<Llave> llaves) {
        this.llaves = llaves;
    }

    public Llave devolverLlave(String patente) {
        Llave lABuscar = null;
        boolean seEncuentra = false;
        int i = 0;
        while (i < llaves.size() && !seEncuentra) {
            if (llaves.get(i).getPatente().equals(patente)) {
                seEncuentra = !seEncuentra;
                lABuscar = llaves.get(i);
            }
            i++;
        }
        return lABuscar;
    }

}
