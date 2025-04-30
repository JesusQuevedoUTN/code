package palitos;

import static palitos.EntradaSalida.*;

public class Jugador {

    private String nombre;

    public Jugador(int i) {
        do {
            nombre = leerCadena("Jugador Nro. " + i + ", cómo te llamas?");
        } while (nombre.equals(""));
    }

    public void jugar(PilaDePalitos p) {
        int n;
        do {
            n = leerEntero(p.ofrecerQuitar(nombre));
        } while (p.imposibleQuitar(n));
        p.quitar(n);
    }

    public void cantarVictoria() {
        mostrarMensaje(nombre + " es el vencedor!");
    }
}
