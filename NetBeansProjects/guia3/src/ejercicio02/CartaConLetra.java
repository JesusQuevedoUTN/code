package ejercicio02;

// Autor: Chisus
// Fecha de creación: 27/05/2025
class CartaConLetra extends CartaConPalo {

    private char letra;

    public CartaConLetra(char letra, TipoDePalo palo) {
        super(palo);
        this.letra = letra;
    }

}
