package ejercicio05;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Video extends Multimedia {

    private Pixeles tamano;
    private FormatoVideo formato;

    public Video(Pixeles tamano, FormatoVideo formato, int duracion, String nombre, int peso, String localizacion, boolean abierto) {
        super(duracion, nombre, peso, localizacion, abierto);
        this.tamano = tamano;
        this.formato = formato;
    }

    public boolean esTamanio(Pixeles calidad) {
        return tamano.getAltura() == calidad.getAltura() && tamano.getAncho() == calidad.getAncho();
    }

    @Override
    public String toString() {
        return "Video: " + super.toString() + ", Resolución: " + tamano.getAncho() + "x" + tamano.getAltura();
    }

}
