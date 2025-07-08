package ejercicio10;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class FuenteDeLenguajeDeMarcado extends Fuente {

    private int peso;

    FuenteDeLenguajeDeMarcado(int peso, String nombre, String ubicacion) {
        super(nombre, ubicacion);
        this.peso = peso;
    }

    @Override
    public double indiceCalidad() {
        final int valorDeCalidad = 450;
        return valorDeCalidad/peso;
    }

}
