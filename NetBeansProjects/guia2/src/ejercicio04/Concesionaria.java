package ejercicio04;

// Autor: Chisus
import java.util.ArrayList;

public class Concesionaria {

    private String nombre;
    private ArrayList<Vehiculo> vehiculos;

    public Concesionaria(String nombre) {
        this.nombre = nombre;
        this.vehiculos = new ArrayList<Vehiculo>();
    }

    public void mostrarVehiculos(TipodeVehiculo tipo) {
        for (Vehiculo v : vehiculos) {
            if (v.getTipo() == tipo) {
                System.out.println(v.toString());
            }
        }
    }

    public int cantidadDeVehiculosEnVenta(){
        return vehiculos.size();
    }
    
    public void mostrarVehiculos() {
        for (Vehiculo v : vehiculos) {
            System.out.println(v.toString());
        }
    }

    public String getNombre() {
        return nombre;
    }

    void agregarVehiculo(Vehiculo vehiculo) {
        vehiculos.add(vehiculo);
    }

    Vehiculo buscarVehiculo(String aBuscar) {
        Vehiculo buscar = null;
        int i = 0;
        boolean encontrar = false;
        while (!encontrar && i < vehiculos.size()) {
            if (seEncontro(i, aBuscar)) {
                buscar = vehiculos.get(i);
                encontrar = true;
            }
            i++;
        }
        return buscar;
    }

    private boolean seEncontro(int i, String aBuscar) {
        return vehiculos.get(i).getPatente().equals(aBuscar);
    }

    public void eliminarVehiculo(String patente) {
        vehiculos.removeIf(v -> v.getPatente().equals(patente));
    }
    
    @Override
    public String toString() {
        return "Concesionaria{" + "nombre=" + nombre + ", vehiculos=" + vehiculos + '}';
    }



}
