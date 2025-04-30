package palitos;

import static palitos.EntradaSalida.*;

public class UltimoPalitoPierde {

    private final Jugador j1;
    private final Jugador j2;
    private final PilaDePalitos p;

    public UltimoPalitoPierde(int i) {
        mostrarMensaje("Hay " + i + " palitos apilados."
                + "\nCada uno de los 2 jugadores sacará 1, 2 o 3 palitos por turno."
                + "\nEl jugador que saca el último palito pierde."
                + "\nSuerte!");
        p = new PilaDePalitos(i);
        j1 = new Jugador(1);
        j2 = new Jugador(2);
    }

    public void ejecutar() {
        while (p.partidaSigue()) {
            j1.jugar(p);
            if (p.jugadaGanadora()) {
                j1.cantarVictoria();
            } else if (p.jugadaPerdedora()) {
                j2.cantarVictoria();
            } else {
                j2.jugar(p);
                if (p.jugadaGanadora()) {
                    j2.cantarVictoria();
                } else if (p.jugadaPerdedora()) {
                    j1.cantarVictoria();
                }
            }
        }
    }
}
