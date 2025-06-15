package ejercicio02;

import java.util.ArrayList;
import java.util.List;

// Autor: Chisus
// Fecha de creación: 27/05/2025
class Mazo {

    private List<Carta> cartas;

    public Mazo() {
        this.cartas = new ArrayList<Carta>();
    }

    public void mostrar(){
        
    }
    
    public void agregarCarta(Carta carta) {
        cartas.add(carta);
    }

    public List<Carta> getCartas() {
        return cartas;
    }

    //METODOS
    public ArrayList<Carta> primerasNCartasSegunPalo(TipoDePalo tp, int n){
        return null;
    }

    public int posJoker() {
        return -1;
    }

    public void mezclar(){
        
    }
    
    public void mostrarRepartidas (int nJugadores, int cartasXJugador){
        
    }
}
