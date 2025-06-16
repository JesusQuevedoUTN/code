package ejercicio08;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class PersonalConComision extends Personal {

    final private int salarioMinimo = 20000;
    private int numeroDeClientesCaptados;
    private float montoACobrarPorCliente;

    public PersonalConComision(float montoACobrarPorCliente, int DNI, String nombre, String apellido, int ingreso) {
        super(DNI, nombre, apellido, ingreso);
        this.montoACobrarPorCliente = montoACobrarPorCliente;
    }

    public void venta() {
        numeroDeClientesCaptados++;
    }

    public int getNumeroDeClientesCaptados() {
        return numeroDeClientesCaptados;
    }

    @Override
    public float salario() {
        float total = numeroDeClientesCaptados * montoACobrarPorCliente;
        return total > salarioMinimo ? total : salarioMinimo;
    }

}
