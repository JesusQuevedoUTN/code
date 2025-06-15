package ejercicio05;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Texto extends Archivo {

    private FormatoCodificacion codificacion;

    public Texto(FormatoCodificacion codificacion, String nombre, int peso, String localizacion, boolean abierto) {
        super(nombre, peso, localizacion, abierto);
        this.codificacion = codificacion;
    }

    public FormatoCodificacion getCodificacion() {
        return codificacion;
    }

    public void cifrar() {
        System.out.println("Cifrado el archivo " + super.getNombre());
    }

    @Override
    public String toString() {
        return "Texto: " + this.getClass().getSimpleName() + " (" + this.getCodificacion() + ")";
    }

}
