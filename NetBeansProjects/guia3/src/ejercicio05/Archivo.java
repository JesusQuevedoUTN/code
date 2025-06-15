package ejercicio05;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Archivo {

    private String nombre;
    private int peso;
    private String localizacion;
    private boolean abierto;

    public Archivo(String nombre, int peso, String localizacion, boolean abierto) {
        this.nombre = nombre;
        this.peso = peso;
        this.localizacion = localizacion;
        this.abierto = abierto;
    }

    public String getNombre() {
        return nombre;
    }

    public void abrir() {
        this.abierto = true;
    }

    public void cerrar() {
        this.abierto = false;
    }

    public void mover(String mover) {
        this.localizacion = mover;
    }

}
