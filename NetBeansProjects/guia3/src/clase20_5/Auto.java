package clase20_5;

public class Auto extends Vehiculo {

    private boolean tieneAire;
    private Motor cacharro;

    public Auto(String marca, String modelo, String patente, Motor cacharro) {
        super(marca, modelo, patente);
        this.cacharro = cacharro;
    }

    public void prenderAire() {
        System.out.println("Aire prendido...");
    }

    void mostrar() {
        System.out.println(toString());
        
    }

    @Override
    public String toString() {
        return  "Auto{" + "tieneAire=" + tieneAire + ", " + cacharro + '}' + "\n" + super.toString();
    }

}
