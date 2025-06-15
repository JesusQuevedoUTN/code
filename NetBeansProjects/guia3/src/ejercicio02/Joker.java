package ejercicio02;

// Autor: Chisus
// Fecha de creación: 27/05/2025

class Joker extends Carta {

    private boolean enColor;

    public Joker(boolean enColor) {
        this.enColor = enColor;
    }

    @Override
    public String toString() {
        return "Joker{" + "enColor=" + enColor + '}';
    }

    
}

