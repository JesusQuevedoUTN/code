package ejercicio06;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Pelicula {

    private String titulo;
    private int estreno;

    public Pelicula(String titulo, int estreno) {
        this.titulo = titulo;
        this.estreno = estreno;
    }

    public String getTitulo() {
        return titulo;
    }

    public boolean esEstreno() {
        return 2025 - this.estreno <= 1;
    }

}
