package ejercicio09;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class ServicioDeReparacion extends Servicios {

    private int dificultad;
    private final int valorPorHora = 180;

    public ServicioDeReparacion(int dificultad, int cantidadDeHoras) {
        super(cantidadDeHoras);
        this.dificultad = dificultad;
    }

    public int dificultad() {
        return this.dificultad;
    }

    public double montoTotalFacturado() {
        double total = 0, porcentaje = valorPorHora * super.getCantidadDeHoras();
        if (dificultad >= 3) {
            total = Matematica.sumarPorcentaje(Matematica.sumarPorcentaje(porcentaje, 25), 10.5);
        } else {
            total = Matematica.sumarPorcentaje(porcentaje, 10.5);
        }
        return total;
    }

}
