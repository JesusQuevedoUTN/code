package ejes;

public class Punto {

    private int x;
    private int y;

    public Punto(int ejex, int ejey) {
        this.x = ejex;
        this.y = ejey;
    }

    public String mostrar() {
        return "(" + x + ", " + y + ")";
    }
}
