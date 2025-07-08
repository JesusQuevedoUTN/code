package UTNFight;

import java.util.Random;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Personaje {

    private String nombre;
    private int puntosDeVida = 100;

    public Personaje(String nombre) {
        this.nombre = nombre;
    }

    public abstract double ataque(Personaje rival);

    public void defensa(double ataque) {
        Random r = new Random();
        this.puntosDeVida -= ataque * r.nextDouble();
    }

    public int getPuntosDeVida() {
        return puntosDeVida;
    }

    public boolean vivo(){
        return puntosDeVida>0;
    }
    
}
