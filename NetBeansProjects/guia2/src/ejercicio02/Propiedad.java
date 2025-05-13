
package ejercicio02;


class Propiedad {
    private Domicilio domicilio;
    private double precio;
    private TipoDeInmoviliaria tipo;

    public Propiedad(Domicilio domicilio, double precio, TipoDeInmoviliaria tipo) {
        this.domicilio = domicilio;
        this.precio = precio;
        this.tipo = tipo;
    }

    public Domicilio getDomicilio() {
        return domicilio;
    }

    public String getCalle(){
        return this.domicilio.getCalle();
    }
    
    public int getAltura(){
        return this.domicilio.getNumero();
    }
    
    public double getPrecio() {
        return this.precio;
    }

    public TipoDeInmoviliaria getTipo() {
        return tipo;
    }

    @Override
    public String toString() {
        return "Propiedad{" + "domicilio=" + domicilio + ", precio=" + precio + ", tipo=" + tipo + '}';
    }

}
