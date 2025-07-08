package UTNFight;

// Autor: Chisus
// Fecha de creación: 06/07/2025
class Resumen {

    private int cantidadDeVictorias;
    private int cantidadDeDerrotas;

    public void addResultado(ResultadoDePartida resultado) {
        if (resultado == ResultadoDePartida.VICTORIA) {
            cantidadDeVictorias++;
        } else {
            cantidadDeDerrotas++;
        }

    }

    public int getCantidadDeVictorias() {
        return cantidadDeVictorias;
    }

    public int getCantidadDeDerrotas() {
        return cantidadDeDerrotas;
    }
    
    

}
