package ejercicio05;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Audio extends Multimedia {

    private String artista;
    private String album;
    private FormatoAudio formato;

    public Audio(String artista, String album, FormatoAudio formato, int duracion, String nombre, int peso, String localizacion, boolean abierto) {
        super(duracion, nombre, peso, localizacion, abierto);
        this.artista = artista;
        this.album = album;
        this.formato = formato;
    }

    @Override
    public String toString() {
        return "Audio{" + "artista=" + artista + ", album=" + album + ", formato=" + formato + '}';
    }

}
