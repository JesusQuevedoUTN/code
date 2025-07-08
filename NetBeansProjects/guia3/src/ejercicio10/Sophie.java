package ejercicio10;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Sophie {

    private ArrayList<Programa> programas;

    public Sophie() {
        this.programas = new ArrayList<>();
    }
    
    

    public ArrayList programasPorDebajoDe(double calidadMinima) {
        ArrayList<Programa> porDebajo = new ArrayList<>();
        for (Programa p : programas) {
            if (p.indiceCalidad() < calidadMinima) {
                porDebajo.add(p);
            }
        }
        return porDebajo;
    }

    void agregarPrograma(Programa programa1) {
        this.programas.add(programa1);
    }

}
