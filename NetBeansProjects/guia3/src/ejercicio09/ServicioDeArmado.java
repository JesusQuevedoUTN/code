package ejercicio09;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class ServicioDeArmado extends Servicios {

    private final int valorPorHora = 250;

    public ServicioDeArmado(int cantidadDeHoras) {
        super(cantidadDeHoras);
    }

    @Override
    public double montoTotalFacturado() {
        return Matematica.sumarPorcentaje((valorPorHora * super.getCantidadDeHoras()), 10.5);
    }

}
