package ejercicio08;

// Autor: Chisus
// Fecha de creación: 15/06/2025
import java.util.ArrayList;

public class Test_3_8 {

    public static void main(String[] args) {
        // Creamos empleados de ambos tipos
        PersonalDeSalarioFijo empFijo1 = new PersonalDeSalarioFijo(100000, 12345678, "Lucoa", "Perez", 2015);
        PersonalDeSalarioFijo empFijo2 = new PersonalDeSalarioFijo(85000, 87654321, "Marcos", "Gómez", 2023);

        PersonalConComision empCom1 = new PersonalConComision(5000, 11223344, "Sofaa", "Ramos", 2020);
        empCom1.venta();
        empCom1.venta();
        empCom1.venta(); // 3 clientes

        PersonalConComision empCom2 = new PersonalConComision(2500, 44332211, "Diego", "Lopez", 2019);
        for (int i = 0; i < 10; i++) {
            empCom2.venta(); // 10 clientes
        }
        // Agregamos a la lista
        ArrayList<Personal> empleados = new ArrayList<>();
        empleados.add(empFijo1);
        empleados.add(empFijo2);
        empleados.add(empCom1);
        empleados.add(empCom2);

        // Creamos empresa
        Nintento N = new Nintento(empleados);

        // Mostramos salarios
        N.mostrarSalarios();

        PersonalConComision maximo = N.empleadoConMasClientes();
        if (maximo != null) {
            System.out.println("El empleado que tuvo mas clientes es: " + maximo.nombreCompleto());
            System.out.println("Cantidad de clientes: " + maximo.getNumeroDeClientesCaptados());
        }

        // NO LLAMAMOS a empleadoConMasClientes(), lo terminás vos :)
    }
}
