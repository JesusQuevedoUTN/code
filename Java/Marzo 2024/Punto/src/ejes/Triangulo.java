package ejes;

public class Triangulo {

    private final Punto punto1;
    private final Punto punto2;
    private final Punto punto3;

    public Triangulo(Punto punto1, Punto punto2, Punto punto3) {
        this.punto1 = punto1;
        this.punto2 = punto2;
        this.punto3 = punto3;
    }

    public void mostrar() {
        if ( (punto1 != punto2) && (punto1 != punto3) && (punto2 != punto3) )
        {
        System.out.println("El triangulo esta formado por los puntos" + punto1.mostrar() + punto2.mostrar() + " y " + punto3.mostrar());            
        }
        else
        System.out.println("Que concha esperas si 2 puntos o mas estan mal?");
    }
}
