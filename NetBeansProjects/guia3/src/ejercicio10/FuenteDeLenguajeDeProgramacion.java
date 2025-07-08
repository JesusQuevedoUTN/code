package ejercicio10;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class FuenteDeLenguajeDeProgramacion extends Fuente {

    private ArrayList<Metodo> metodos;

    public FuenteDeLenguajeDeProgramacion(String nombre, String ubicacion) {
        super(nombre, ubicacion);
        this.metodos = new ArrayList<Metodo>();
    }

    @Override
    public double indiceCalidad() {
        // Método a resolver...
        return 0;
    }

    public void mostrarMetodo(String nombre) {
        for (Metodo m : metodos) {
            if (m.getNombre().equals(nombre)) {
                m.mostrar();
            }
        }
    }

    public boolean buscarMetodo(String nombre) {
        boolean encontrado = false;
        for (Metodo m : metodos) {
            if (m.getNombre().equals(nombre)) {
                encontrado = true;
            }
        }
        return encontrado;
    }

    void agregarMetodo(Metodo m1) {
        this.metodos.add(m1);
    }

}
