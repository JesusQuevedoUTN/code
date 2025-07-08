package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Domicilio {

    private String calle;
    private int altura;
    private int comuna;

    public Domicilio(String calle, int altura, int comuna) {
        this.calle = calle;
        this.altura = altura;
        this.comuna = comuna;
    }

    public int getComuna() {
        return comuna;
    }

}
