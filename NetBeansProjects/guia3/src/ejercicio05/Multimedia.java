package ejercicio05;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Multimedia extends Archivo {

    private int duracion;
    private boolean enReproducion;

    public Multimedia(int duracion, String nombre, int peso, String localizacion, boolean abierto) {
        super(nombre, peso, localizacion, abierto);
        this.duracion = duracion;
    }

    public void reproducir() {
        this.enReproducion = true;
    }

    public void parar() {
        this.enReproducion = false;
    }

    public int getDuracion() {
        return duracion;
    }

}
