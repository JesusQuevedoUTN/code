package perros;

public class Universo {

    private static Perro dogoArgentino;
    private static Perro pastorIngles;

    public static void main(String[] args) {
        dogoArgentino = new Perro("Guau guau!");
        pastorIngles = new Perro("Woof woof!");
        dogoArgentino.ladrar();
        pastorIngles.ladrar();
    }
}
