package ejercicio11;

import java.util.ArrayList;

/**
* Código generado por la app UXFtoJava by Charly Cimino
* @see https://github.com/CharlyCimino/uxf-to-java
*/
public class Inmobiliaria implements Interesado {

    private String nombre;
    private String mail;
    private double porcentajeDeComisionPorVenta;
    private String domicilio;
    private ArrayList<Inmueble> inmuebles;

    public Inmobiliaria(String nombre, String mail, double porcentajeDeComisionPorVenta, String domicilio) {
        this.nombre = nombre;
        this.mail = mail;
        this.porcentajeDeComisionPorVenta = porcentajeDeComisionPorVenta;
        this.domicilio = domicilio;
        this.inmuebles = new ArrayList<>();
    }

    public void agregarInmueble(Inmueble inmueble){
        this.inmuebles.add(inmueble);
    }
    
    @Override
    public void cambioDePrecio(String domicilio, double precioViejo, double precioNuevo) {
        System.out.println("Hemos recibido un mail a nuestra casilla " + mail  + " con el mensaje: " );
        System.out.println("El inmueble" + domicilio + " por el que ha demostrado interés cambió su precio de " + precioViejo + " a " + precioNuevo + "." );
    }

}