package UTNFight;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Guerrero extends Personaje {

    private double fuerza;

    public Guerrero(double fuerza, String nombre) {
        super(nombre);
        this.fuerza = fuerza;
    }

    @Override
    public double ataque(Personaje rival) {
        return super.getPuntosDeVida() < 20 ? this.fuerza * 1.10 : this.fuerza;
    }

}
