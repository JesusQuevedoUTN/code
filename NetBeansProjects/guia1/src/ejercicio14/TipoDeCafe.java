package ejercicio14;

public enum TipoDeCafe {
    EXPRESSO(0, TexturaDeLeche.NORMAL),
    LATTE(2, TexturaDeLeche.ESPUMOSA),
    LAGRIMA(3, TexturaDeLeche.LIQUIDA);

    private int cantLeche;
    private TexturaDeLeche textura;

    private TipoDeCafe(int cantLeche, TexturaDeLeche textura) {
        this.cantLeche = cantLeche;
        this.textura = textura;
    }

    public int getCantLeche() {
        return this.cantLeche;
    }

    private TexturaDeLeche getTextura() {
        return textura;
    }

    @Override
    public String toString() {
        return "TipoDeCafe{" + "cantLeche=" + cantLeche + ", textura=" + textura + '}';
    }
}
