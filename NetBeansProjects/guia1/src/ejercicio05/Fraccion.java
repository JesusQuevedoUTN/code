package ejercicio05;

public class Fraccion {

    private int numerador;
    private int denominador;

    private String PROPIA = "Fraccion Propia";
    private String IMPROPIA = "Fraccion Impropia";
    private String APARENTE = "Fraccion Aparente";

//CONSTRUCT
    public Fraccion(int numerador, int denominador) {
        this.numerador = numerador;
        setDenominador(denominador);
    }

//SETTER
    private void setDenominador(int x) {
        if (x != 0) {
            this.denominador = x;
        }
    }

//GETTER
    public double getDecimal() {
        return numerador / (double) denominador;
    }

    public int getNumerador() {
        return numerador;
    }

    public int getDenominador() {
        return denominador;
    }

//ATRIBUTES
    public void sumarEntero(int entero) {
        numerador = numerador + entero * denominador;
    }

    public void sumarFraccion(Fraccion suma) {
        this.numerador = this.numerador*suma.getDenominador() + this.denominador*suma.getNumerador();
        this.denominador = this.denominador * suma.getDenominador();
    }

    private void simplificarFraccion() {

    }

    public String tipoDeFraccion() {
        String x = "Ninguna";
        if (numerador % denominador == 0) {
            x = APARENTE;
        } else if (numerador > denominador) {
            x = IMPROPIA;
        } else {
            x = IMPROPIA;
        }
        return x;
    }

    public void mostrar(){
        System.out.println(toString());
    }
    
    @Override
    public String toString() {
        return numerador + "/" + denominador;
    }

}
