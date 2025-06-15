package ejercicio04;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Marca {

    private String nombre;
    private ArrayList<Concesionaria> consesionarias;

    public Marca(String nombre) {
        this.nombre = nombre;
        this.consesionarias = new ArrayList<Concesionaria>();
    }

    public void mostrarVehiculos() {
        System.out.println("=== Vehiculos en cada concesionaria ===");
        for (Concesionaria c : consesionarias) {
            System.out.println("Concesionaria: " + c.getNombre());
            c.mostrarVehiculos();
            System.out.println("");
        }
    }

    public ArrayList<Concesionaria> obtenerConcesionariaMaxVeh() {
        ArrayList<Concesionaria> maxima = new ArrayList<Concesionaria>();
        int ventaMaxima = 0;
        for (Concesionaria c : consesionarias) {
            if (compararVentas(c, ventaMaxima) == 0) {
                maxima.add(c);
            } else if (compararVentas(c, ventaMaxima) > 0) {
                maxima.clear();
                maxima.add(c);
            }
        }
        return maxima;
    }

    private static int compararVentas(Concesionaria c, int ventaMaxima) {
        return c.cantidadDeVehiculosEnVenta() - ventaMaxima;
    }

    public void borrarVehiculo(String patente) {
        for (Concesionaria c : consesionarias) {
            Vehiculo v = c.buscarVehiculo(patente);
            if (v != null) {
                c.eliminarVehiculo(patente);
                return;
            }
        }
    }

    private Vehiculo buscarVehiculo(String patente) {
        Vehiculo buscar = null;
        int i = 0;
        boolean encontrar = false;

        while (!encontrar && i < consesionarias.size()) {
            buscar = consesionarias.get(i).buscarVehiculo(patente);
            if (buscar != null) {
                encontrar = true;
            }
            i++;
        }
        return buscar;
    }

    public void cambiarVehiculoDeConcesionaria(String patente, String nombreNuevaConcesionaria) {
        for (Concesionaria c : consesionarias) {
            Vehiculo v = c.buscarVehiculo(patente);
            if (v != null) {
                c.eliminarVehiculo(patente); // Sacar de la actual
                buscarConcesionaria(nombreNuevaConcesionaria).agregarVehiculo(v); // Agregar a la nueva
                return;
            }
        }
    }

    void agregarConcesionaria(Concesionaria concesionaria) {
        consesionarias.add(concesionaria);
    }

    Concesionaria buscarConcesionaria(String aBuscar) {
        Concesionaria buscar = null;
        int i = 0;
        boolean encontrar = false;
        while (!encontrar && i < consesionarias.size()) {
            if (seEncontro(i, aBuscar)) {
                buscar = consesionarias.get(i);
                encontrar = true;
            }
            i++;
        }
        return buscar;
    }

    private boolean seEncontro(int i, String aBuscar) {
        return consesionarias.get(i).getNombre().equals(aBuscar);
    }

}
