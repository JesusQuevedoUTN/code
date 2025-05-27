package clase20_5;

public class Vehiculo {

    private String marca;
    private String modelo;
    private String patente;

    public Vehiculo(String marca, String modelo, String patente) {
        this.marca = marca;
        this.modelo = modelo;
        this.patente = patente;
    }
    
    public void acelerar() {
        System.out.println("acelero");
    }

    public void frenar() {
        System.out.println("freno");
    }

    public void encender() {
        System.out.println("encendio");
    }

    @Override
    public String toString() {
        return "Vehiculo{" + "marca=" + marca + ", modelo=" + modelo + ", patente=" + patente + '}';
    }
    
    
}
