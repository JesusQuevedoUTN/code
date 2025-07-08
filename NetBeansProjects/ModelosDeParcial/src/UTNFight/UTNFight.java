package UTNFight;

import java.util.ArrayList;
import java.util.Random;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class UTNFight {

    private ArrayList<Jugador> jugadores;

    public UTNFight() {
        this.jugadores = new ArrayList();
    }

    public void addJugador(Jugador jugador) {
        this.jugadores.add(jugador);
    }

    
    /*
    - se elige al azar quien empieza
    - ataque a defensa
    - siguiente turno invertir roles
    - repetir mientras que uno tenga vida > 0
    */
    public void batallar(Jugador jugador1, Jugador jugador2) {
        Random rand = new Random();
        if (rand.nextInt(1,2) == 1) {
            while(jugador1.vivo() && jugador2.vivo() ){
                
            }
        }else{
            
        }
        
    }

    public Resumen getResumenDe(Jugador jugador) {
        return jugador.getResumenDePartidas();
    }
}
