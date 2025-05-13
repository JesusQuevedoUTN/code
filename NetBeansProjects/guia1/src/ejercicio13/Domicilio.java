package ejercicio13;

public class Domicilio {

    private String calle;
    private int altura;
    private String barrio;

    public Domicilio(String calle, int altura, String barrio) {
        this.calle = calle;
        this.altura = altura;
        this.barrio = barrio;
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

    public void setNuevaDireccion(String calle, int altura, String barrio) {
        setCalle(calle);
        setAltura(altura);
        setBarrio(barrio);
    }

    public void setCalle(String calle) {
        this.calle = calle;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public void setBarrio(String barrio) {
        this.barrio = barrio;
    }

    @Override
    public String toString() {
        return "Calle: " + calle + "\nAltura: " + altura + "\nBarrio:" + barrio;
    }

}
