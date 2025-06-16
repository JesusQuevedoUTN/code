package ejercicio07;

public class Test7 {

    public static void main(String[] args) {
        GrupoDeFiguras gf = new GrupoDeFiguras();
        gf.agregarFigura(new Circunferencia(3, "Rojo"));
        gf.agregarFigura(new TrianguloEquilatero(5, "Verde"));
        gf.agregarFigura(new Rectangulo(2, 6, "Azul"));
        gf.mostrarInfoDeFiguras();
    }

}
