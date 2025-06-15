package ejercicio04;

public class Vehiculo {

    private String patente;
    private float precio;
    private TipodeVehiculo tipo;

    public Vehiculo(String patente, float precio, TipodeVehiculo tipo) {
        this.patente = patente;
        this.precio = precio;
        this.tipo = tipo;
    }

    public TipodeVehiculo getTipo() {
        return tipo;
    }

    public String getPatente() {
        return patente;
    }

    public float getPrecio() {
        return precio;
    }
    
    
    @Override
    public String toString() {
        return "Vehiculo{" + "patente=" + patente + ", precio=" + precio + '}';
    }

}
