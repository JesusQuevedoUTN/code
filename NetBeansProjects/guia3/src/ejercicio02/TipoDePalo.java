package ejercicio02;

// Autor: Chisus
// Fecha de creación: 27/05/2025
public enum TipoDePalo {
    CORAZON(TipoDeColor.ROJO),
    TREBOL(TipoDeColor.NEGRO),
    PICA(TipoDeColor.NEGRO),
    DIAMANTE(TipoDeColor.ROJO);

    private final TipoDeColor color;

    TipoDePalo(TipoDeColor color) {
        this.color = color;
    }

}
