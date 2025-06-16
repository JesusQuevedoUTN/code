package ejercicio08;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Nintento {

    private ArrayList<Personal> empleados;

    public Nintento(ArrayList<Personal> personal) {
        this.empleados = personal;
    }

    public void mostrarSalarios() {
        for (Personal e : empleados) {
            System.out.println(e.nombreCompleto());
            System.out.println("Salario: " + e.salario());
        }
    }

    /*
    aca igual, siento que lo pude armar mejor y tiene demasiadas funcones y demás
     */
    public PersonalConComision empleadoConMasClientes() {
        PersonalConComision mejor = null;

        for (Personal e : empleados) {
            if (e instanceof PersonalConComision p) {
                if (mejor == null || p.getNumeroDeClientesCaptados() > mejor.getNumeroDeClientesCaptados()) {
                    mejor = p;
                }
            }
        }

        return mejor;
    }
}
