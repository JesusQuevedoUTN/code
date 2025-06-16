package ejercicio08;

import java.time.LocalDate;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class PersonalDeSalarioFijo extends Personal {

    private float sueldoBasico;

    public PersonalDeSalarioFijo(float sueldoBasico, int DNI, String nombre, String apellido, int ingreso) {
        super(DNI, nombre, apellido, ingreso);
        this.sueldoBasico = sueldoBasico;
    }

    @Override
    public float salario() {
        int antiguedad = calcularAntiguedad();
        float aumento = 1.0f; // por defecto, sin aumento

        if (antiguedad >= 2 && antiguedad <= 5) {
            aumento = 1.05f;
        } else if (antiguedad >= 6 && antiguedad <= 10) {
            aumento = 1.10f;
        } else if (antiguedad > 10) {
            aumento = 1.15f;
        }

        return sueldoBasico * aumento;
    }

}
