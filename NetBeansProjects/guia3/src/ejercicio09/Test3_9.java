package ejercicio09;

// Autor: Chisus
// Fecha de creación: 16/06/2025
import java.util.ArrayList;

public class Test3_9 {

    public static void main(String[] args) {
        // Crear insumos
        Insumos i1 = new Insumos("Teclado mecánico", "periférico", 20f, 10000f);
        Insumos i2 = new Insumos("Placa madre", "hardware", 35f, 50000f);
        Insumos i3 = new Insumos("Kit limpieza", "limpieza", 10f, 3000f);
        Insumos i4 = new Insumos("Monitor", "periférico", 25f, 70000f);

        // Crear servicios de armado
        ServicioDeArmado sa1 = new ServicioDeArmado(2);
        ServicioDeArmado sa2 = new ServicioDeArmado(4);
        ServicioDeArmado sa3 = new ServicioDeArmado(1);
        ServicioDeArmado sa4 = new ServicioDeArmado(5);

        // Crear servicios de reparación
        ServicioDeReparacion sr1 = new ServicioDeReparacion(1, 3); // simple
        ServicioDeReparacion sr2 = new ServicioDeReparacion(2, 2); // simple
        ServicioDeReparacion sr3 = new ServicioDeReparacion(4, 5); // complicado
        ServicioDeReparacion sr4 = new ServicioDeReparacion(5, 1); // complicado

        // Agregar todo al historial
        ArrayList<Facturable> historial = new ArrayList<>();
        historial.add(i1);
        historial.add(i2);
        historial.add(i3);
        historial.add(i4);
        historial.add(sa1);
        historial.add(sa2);
        historial.add(sa3);
        historial.add(sa4);
        historial.add(sr1);
        historial.add(sr2);
        historial.add(sr3);
        historial.add(sr4);

        // Crear instancia de Informatix
        Informatix tienda = new Informatix(historial);

        // Mostrar estadísticas
        System.out.println("Monto total facturado: $" + tienda.montoTotalFacturado());
        System.out.println("Cantidad de servicios simples: " + tienda.cantServiciosSimples());
    }
}
