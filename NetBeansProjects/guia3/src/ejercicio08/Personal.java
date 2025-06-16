package ejercicio08;

import java.time.Year;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class Personal {

    private int DNI;
    private String nombre;
    private String apellido;
    private int ingreso;

    public Personal(int DNI, String nombre, String apellido, int ingreso) {
        this.DNI = DNI;
        this.nombre = nombre;
        this.apellido = apellido;
        this.ingreso = ingreso;
    }

    public abstract float salario();

    public String nombreCompleto() {
        return nombre + " " + apellido;
    }

    public int getDNI() {
        return DNI;
    }

    public int calcularAntiguedad() {
        return Year.now().getValue() - ingreso;
    }

}
