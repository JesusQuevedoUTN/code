package ejercicio09;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class FooParking {

    private ArrayList<Garage> garages;

    public FooParking(ArrayList<Garage> garages) {
        this.garages = garages;
    }

    //
    public void obtenerInformeEstadoGarajes() {
        System.out.println("- - - - - - - - - - - - - -");
        for (Garage g : garages) {
            System.out.println(g.toString());
        }
        System.out.println("- - - - - - - - - - - - - -");
    }

}
