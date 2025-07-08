package UTNFight;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        UTNFight utn = new UTNFight();

        ArrayList<Jugador> jugadores = new ArrayList(5);
        jugadores.add(new Jugador("Chisus", new Guerrero(25, "Great Tusk")));
        jugadores.add(new Jugador("Cheese", new Guerrero(30, "Garchomp")));
        jugadores.add(new Jugador("Chiza", new Guerrero(26, "Decidueye")));
        jugadores.add(new Jugador("Xixxu", new Guerrero(20, "Hitmonchan")));
        jugadores.add(new Jugador("Shisu", new Guerrero(24, "Gardevoir")));
        
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                utn.batallar(jugadores.get(i), jugadores.get(j));
            }
        }

        for (int i = 0; i < 5; i++) {
            Resumen r = jugadores.get(i).getResumenDePartidas();
            System.out.println(jugadores.get(i).getId());
            System.out.println("Cantidad de Victorias: " + r.getCantidadDeVictorias());
            System.out.println("Cantidad de Derrotas: " + r.getCantidadDeDerrotas());
            System.out.println("");
        }
    }

}
