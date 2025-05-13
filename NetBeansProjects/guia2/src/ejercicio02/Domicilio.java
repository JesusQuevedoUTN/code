package ejercicio02;
import ejercicio01.*;

public class Domicilio {

    private String calle;
    private int numero;
    private String barrio;

    public Domicilio(String calle, int numero, String barrio) {
        // Este constructor debería llamar a los setters asociados a cada atributo...
        this.calle = calle;
        this.numero = numero;
        this.barrio = barrio;
    }
    
    
    public String getBarrio(){
        return this.barrio;
    }

    public String getCalle() {
        return calle;
    }

    public int getNumero() {
        return numero;
    }
    
    

    @Override
    public String toString() {
        return "Domicilio{" + "calle=" + calle + ", numero=" + numero + ", barrio=" + barrio + '}';
    }

}
