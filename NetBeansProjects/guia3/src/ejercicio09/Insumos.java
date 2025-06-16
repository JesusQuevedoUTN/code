package ejercicio09;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class Insumos implements Facturable {

    private String nombre;
    private String tipo;
    private float porcentajeDeGanancia;
    private float precioDeLista;

    public Insumos(String nombre, String tipo, float porcentajeDeGanancia, float precioDeLista) {
        this.nombre = nombre;
        this.tipo = tipo;
        this.porcentajeDeGanancia = porcentajeDeGanancia;
        this.precioDeLista = precioDeLista;
    }

    @Override
    public double montoTotalFacturado() {
        return Matematica.sumarPorcentaje( Matematica.sumarPorcentaje(precioDeLista, porcentajeDeGanancia) , 21);
    }

}
