package ejercicio09;

import java.util.ArrayList;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Informatix {

    private ArrayList<Facturable> historialDeVentas;

    public Informatix(ArrayList<Facturable> historialDeVentas) {
        this.historialDeVentas = historialDeVentas;
    }
    
    public void addhistorialDeVentas(ArrayList<Facturable> historialDeVentas){
        this.historialDeVentas.addAll(historialDeVentas);
    }

    public double montoTotalFacturado() {
        double total = 0;
        for (Facturable hdv : historialDeVentas) {
            total += hdv.montoTotalFacturado();
        }
        return total;
    }

    public int cantServiciosSimples() {
        int cantidad = 0;
        final int simple = 2;
        for (Facturable hdv : historialDeVentas) {
            if (hdv instanceof ServicioDeReparacion sdr && sdr.dificultad() <= simple) {
                cantidad++;
            }
        }
        return cantidad;
    }

}
