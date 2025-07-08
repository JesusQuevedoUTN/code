package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class PuertaAPuerta extends OrdenDeCompra {

    public PuertaAPuerta(double monto, Usuario comprador, Usuario vendedor) {
        super(monto, comprador, vendedor);
    }

    @Override
    public Domicilio destino() {
        return super.getComprador().getDomicilio();
    }

    @Override
    public boolean envioGratis() {
        return super.getComprador().getDomicilio() == super.getVendedor().getDomicilio();
    }

}
