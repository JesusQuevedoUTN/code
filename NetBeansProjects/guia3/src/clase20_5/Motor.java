package clase20_5;

public class Motor {

    private String numero;
    private double cilindrada;

    public Motor(String numero, double cilindrada) {
        this.numero = numero;
        this.cilindrada = cilindrada;
    }

    public void arrancar() {
        System.out.println("arrancó");
    }

    @Override
    public String toString() {
        return "Motor{" + "numero=" + numero + ", cilindrada=" + cilindrada + '}';
    }

}
