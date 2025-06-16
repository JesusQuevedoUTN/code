package ejercicio07;

// Autor: Chisus
// Fecha de creación: 15/06/2025
/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class TrianguloEquilatero extends Figura {

    private double lado;

    public TrianguloEquilatero(double lado, String color) {
        super(color);
        this.lado = lado;
    }

    @Override
    public double area() {
        return (Math.sqrt(3) / 4) * Math.pow(lado, 2);
    }

    @Override
    public double perimetro() {
        return 3 * lado;
    }

}
