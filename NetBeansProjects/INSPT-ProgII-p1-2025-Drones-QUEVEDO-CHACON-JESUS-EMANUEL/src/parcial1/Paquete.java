package parcial1;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Paquete {

    private double peso;
    private double volumenCm3;

    public Paquete(double peso, double volumenCm3) {
        // Debería llamar a cada setter con su validación, pero lo omitimos para simplificar la solución.
        this.peso = peso;
        this.volumenCm3 = volumenCm3;
    }

    public double getPeso() {
        return peso;
    }
}
