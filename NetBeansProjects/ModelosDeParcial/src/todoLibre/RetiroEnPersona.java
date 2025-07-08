package todoLibre;

/**
 * Código generado por la app UXFtoJava by Charly Cimino
 *
 * @see https://github.com/CharlyCimino/uxf-to-java
 */
public class RetiroEnPersona extends OrdenDeCompra {

    private Domicilio sucursal;

    public RetiroEnPersona(Domicilio sucursal, double monto, Usuario comprador, Usuario vendedor) {
        super(monto, comprador, vendedor);
        this.sucursal = sucursal;
    }

    @Override
    public Domicilio destino() {
        return this.sucursal;
    }

    @Override
    public boolean envioGratis() {
        return super.envioGratis();
    }
}
