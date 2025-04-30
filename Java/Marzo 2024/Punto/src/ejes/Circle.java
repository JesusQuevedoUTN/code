package ejes;

public class Circle {

    private Punto centro;
    private double radio;

    public Circle(Punto centro, double radio) {
        this.centro = centro;
        this.radio = radio;
    }

    public void mostrar() {
        if (radio > 0) {
            System.out.println("Circulo con centro en " + centro.mostrar() + " y radio " + radio);            
        }
        else{
            System.out.println("Tenes que darme un radio positivo tarado");            
        }
    }
}
