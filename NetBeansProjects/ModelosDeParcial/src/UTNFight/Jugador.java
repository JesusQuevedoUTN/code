package UTNFight;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Jugador {

    private String id;
    private Personaje personajeFavorito;
    private ArrayList<Partida> historialDePartidas;

    public Jugador(String id, Personaje personajeFavorito) {
        this.id = id;
        this.personajeFavorito = personajeFavorito;
        this.historialDePartidas = new ArrayList();
    }

    public Resumen getResumenDePartidas() {
        Resumen total = new Resumen();
        for (Partida p : historialDePartidas) {
            total.addResultado(p.getResultado());
        }
        return total;
    }

    public String getId() {
        return id;
    }

    public boolean vivo(){
        return personajeFavorito.vivo();
    }
    
}
