package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public abstract class OrdenDeCompra implements Entregable {

    private int numero = 0;
    private double monto;
    private Usuario comprador;
    private Usuario vendedor;

    public OrdenDeCompra(double monto, Usuario comprador, Usuario vendedor) {
        this.numero++;
        this.monto = monto;
        this.comprador = comprador;
        this.vendedor = vendedor;
    }

    @Override
    public Domicilio origen() {
        return vendedor.getDomicilio();
    }

    public boolean mismoComuna() {
        return origen().getComuna() == destino().getComuna();
    }

    public Usuario getComprador() {
        return comprador;
    }

    public Usuario getVendedor() {
        return vendedor;
    }

}
