package ejercicio02;

// Autor: Chisus
// Fecha de creación: 27/05/2025
class CartaConNumero extends CartaConPalo {

    private int numero;

    public CartaConNumero(int numero, TipoDePalo palo) {
        super(palo);
        this.numero = numero;
    }

}
