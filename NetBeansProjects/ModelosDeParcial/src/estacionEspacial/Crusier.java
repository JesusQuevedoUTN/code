package EstacionEspacial;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Crusier extends Nave {

    private int cantidadDePasajeros;

    public Crusier(int cantidadDePasajeros, String planetaDeOrigen, int cantidadDeTripulantes) {
        super(planetaDeOrigen, cantidadDeTripulantes);
        this.cantidadDePasajeros = cantidadDePasajeros;
    }

    @Override
    public void manifiesto() {
        int porcentajeDePasajeros = cantidadDePasajeros * 100 / (super.getCantidadDeTripulantes() + cantidadDePasajeros);
        System.out.println("Porcentaje de pasajeros: " + porcentajeDePasajeros + "%");
    }

    @Override
    public boolean puedeEstacionar() {
        return this.cantidadDePasajeros > 0;
    }

}
