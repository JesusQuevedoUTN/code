package ejercicio09;

public class Domicilio {
    private String calle;
    private int altura;
    private String barrio;

    public Domicilio(String calle, int altura, String carrio) {
        this.calle = calle;
        this.altura = altura;
        this.barrio = carrio;
    }
    
    public String getCalle() {
        return calle;
    }

    public int getAltura() {
        return altura;
    }

    public String getCarrio() {
        return barrio;
    }
    
    @Override
    public String toString(){
        return "Calle: " + calle + "\nAltura: " + altura + "\nBarrio:" + barrio;
    }
    
}
