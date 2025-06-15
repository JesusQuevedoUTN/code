
public class Bicicleta {

    private String marca;
    private String modelo;
    private int kms;
    
    public Bicicleta(String marca, String modelo, int kms) {
        this.marca = marca;
        this.modelo = modelo;
        this.kms = kms;
        
    }

    public boolean prestarServicios() {
        final int MENOS_DE_LO_PEDIDO = 2000;
        return kms<MENOS_DE_LO_PEDIDO;
    }

    @Override
    public String toString() {
        return "Bicicleta{" + "marca=" + marca + ", modelo=" + modelo + ", kms=" + kms + '}';
    }
}
