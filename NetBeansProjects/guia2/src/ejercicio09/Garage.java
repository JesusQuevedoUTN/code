package ejercicio09;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Garage {

    private char id;
    private ArrayList<Vehiculo> vehiculosEstacionados;
    private Tablero tablero;

    public Garage(char id, ArrayList<Vehiculo> vehiculosEstacionados, Tablero tablero) {
        this.id = id;
        this.vehiculosEstacionados = vehiculosEstacionados;
        this.tablero = tablero;
    }

    //
    public Resultado estacionarVehiculo(String patente) {
        return Resultado.deEstacionar(buscarVehiculo(patente));
    }

    public Vehiculo buscarVehiculo(String patente) {
        Vehiculo aBuscar = null;
        boolean seEncuentra = false;
        int i = 0;
        while (i < vehiculosEstacionados.size() && !seEncuentra) {
            if (vehiculosEstacionados.get(i).getPatente().equals(patente)) {
                seEncuentra = !seEncuentra;
                aBuscar = vehiculosEstacionados.get(i);
            }
            i++;
        }
        return aBuscar;
    }

    //
    public boolean esPersonaAutorizada(int DNI) {
        boolean estaAutorizada = false;
        int i = 0;
        while (i < vehiculosEstacionados.size() && !estaAutorizada) {
            if (vehiculosEstacionados.get(i).estaAutorizada(DNI)) {
                estaAutorizada = !estaAutorizada;
            }
            i++;
        }
        return estaAutorizada;
    }

    //
    @Override
    public String toString() {
        return "Garage{" + "ID= " + id + ", vehiculosEstacionados= " + cantVehiculosEstacionados();
    }

    private int cantVehiculosEstacionados() {
        int i = 0;
        for (Vehiculo v : vehiculosEstacionados) {
            if (v.estaEstacionado()) {
                i++;
            }
        }
        return i;
    }

}
