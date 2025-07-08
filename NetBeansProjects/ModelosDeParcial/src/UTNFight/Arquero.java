package UTNFight;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Arquero extends Personaje {

    private int cantidadDeFlechas = 10;
    private double potenciaDeArco;

    public Arquero(double potenciaDeArco, String nombre) {
        super(nombre);
        this.potenciaDeArco = potenciaDeArco;
    }

    @Override
    public double ataque(Personaje rival) {
        double ataque = 0;
        if (cantidadDeFlechas > 0) {
            this.cantidadDeFlechas--;
            ataque = this.potenciaDeArco;
        }
        return ataque;
    }

}
