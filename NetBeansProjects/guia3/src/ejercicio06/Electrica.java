
public class Electrica extends Bicicleta {

    private int potencia;

    public Electrica(int potencia, String marca, String modelo, int kms) {
        super(marca, modelo, kms);
        this.potencia = potencia;
    }

    @Override
    public boolean prestarServicios() {
        final int MENOS_DE_LO_PEDIDO = 250;
        return this.potencia < MENOS_DE_LO_PEDIDO && super.prestarServicios();
    }

    @Override
    public String toString() {
        return "Electrica{" + "potencia=" + potencia + '}';
    }
    
    

}
